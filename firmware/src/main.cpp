#include <Arduino.h>
#include <math.h>
#include "config.h"
#include "balance_controller.h"

uint32_t last_loop_time = 0;
bool imu_ok = false;
bool servos_enabled = false;

static int16_t degToCounts(float deg) {
    float raw = (float)EndoskeletonConfig::SERVO_CENTER_COUNT
              + (deg * EndoskeletonConfig::STEPS_PER_DEGREE);
    if (raw < 0.0f) raw = 0.0f;
    if (raw > 4095.0f) raw = 4095.0f;
    return (int16_t)raw;
}

bool solveLegIK(float target_x, float target_y, LegAngles &out) {
    float r_sq = (target_x * target_x) + (target_y * target_y);
    float r = sqrtf(r_sq);
    float l1 = EndoskeletonConfig::L1;
    float l2 = EndoskeletonConfig::L2;
    float max_reach = l1 + l2;
    float min_reach = fabsf(l1 - l2);

    if (r > max_reach || r < min_reach || r < 1.0f) {
        return false;
    }

    float cos_knee = (r_sq - (l1 * l1) - (l2 * l2)) / (2.0f * l1 * l2);
    cos_knee = constrain(cos_knee, -1.0f, 1.0f);
    float knee_rad = acosf(cos_knee);

    float alpha = atan2f(target_x, -target_y);
    float beta = atan2f(l2 * sinf(knee_rad), l1 + (l2 * cos_knee));
    float hip_rad = alpha - beta;
    float ankle_rad = -(hip_rad + knee_rad);

    const float rad2deg = 180.0f / (float)M_PI;
    out.hip_pitch_deg   = hip_rad * rad2deg;
    out.knee_deg        = knee_rad * rad2deg;
    out.ankle_pitch_deg = ankle_rad * rad2deg;
    return true;
}

void sendBusServoPosition(HardwareSerial &bus, uint8_t servo_id, int16_t position_raw, uint16_t time_ms) {
    uint8_t packet[11];
    packet[0] = 0xFF;
    packet[1] = 0xFF;
    packet[2] = servo_id;
    packet[3] = 0x07;
    packet[4] = 0x03;
    packet[5] = EndoskeletonConfig::STS_REG_GOAL_POSITION;
    packet[6] = (uint8_t)(position_raw & 0xFF);
    packet[7] = (uint8_t)((position_raw >> 8) & 0xFF);
    packet[8] = (uint8_t)(time_ms & 0xFF);
    packet[9] = (uint8_t)((time_ms >> 8) & 0xFF);

    uint8_t checksum = 0;
    for (int i = 2; i <= 9; i++) {
        checksum += packet[i];
    }
    packet[10] = ~checksum;

    if (EndoskeletonConfig::BUS_USE_DIR_PIN) {
        digitalWrite(EndoskeletonConfig::PIN_BUS_DIR, HIGH);
    }
    bus.write(packet, sizeof(packet));
    bus.flush();
    if (EndoskeletonConfig::BUS_USE_DIR_PIN) {
        digitalWrite(EndoskeletonConfig::PIN_BUS_DIR, LOW);
    }
}

static void setServoEnable(bool on) {
    servos_enabled = on;
    uint8_t level = on
        ? (EndoskeletonConfig::SERVO_ENABLE_ACTIVE_HIGH ? HIGH : LOW)
        : (EndoskeletonConfig::SERVO_ENABLE_ACTIVE_HIGH ? LOW : HIGH);
    digitalWrite(EndoskeletonConfig::PIN_SERVO_ENABLE, level);
}

void setup() {
    Serial.begin(EndoskeletonConfig::SERIAL_DEBUG_BAUD);

    pinMode(EndoskeletonConfig::PIN_STATUS_LED, OUTPUT);
    pinMode(EndoskeletonConfig::PIN_SERVO_ENABLE, OUTPUT);
    pinMode(EndoskeletonConfig::PIN_BUS_DIR, OUTPUT);
    digitalWrite(EndoskeletonConfig::PIN_BUS_DIR, LOW);
    setServoEnable(false);

    Serial1.begin(EndoskeletonConfig::BUS_SERVO_BAUD, SERIAL_8N1,
                  EndoskeletonConfig::PIN_BUS_RX, EndoskeletonConfig::PIN_BUS_TX);

    imu_ok = initIMU();
    if (!imu_ok) {
        Serial.println("[ERROR] IMU init failed. Enable stays OFF.");
    } else {
        Serial.println("[OK] IMU up. Asserting servo enable.");
        setServoEnable(true);
    }

    last_loop_time = millis();
}

void loop() {
    uint32_t now = millis();
    if ((now - last_loop_time) < EndoskeletonConfig::LOOP_PERIOD_MS) {
        return;
    }
    float dt = (now - last_loop_time) / 1000.0f;
    last_loop_time = now;

    if (imu_ok) {
        updateOrientation(dt);
    }

    BalanceOffsets trim = {0.0f, 0.0f};
    if (imu_ok) {
        trim = computeStabilizationTrim(0.0f, 0.0f, dt);
    }

    if (!servos_enabled) {
        return;
    }

    LegAngles left_leg, right_leg;
    if (!solveLegIK(EndoskeletonConfig::STANCE_X_MM, EndoskeletonConfig::STANCE_Y_MM, left_leg)) {
        return;
    }
    right_leg = left_leg;

    float l_ankle_p = left_leg.ankle_pitch_deg + trim.pitch_trim_deg;
    float l_hip_p   = left_leg.hip_pitch_deg   - (trim.pitch_trim_deg * 0.5f);
    float r_ankle_p = right_leg.ankle_pitch_deg + trim.pitch_trim_deg;
    float r_hip_p   = right_leg.hip_pitch_deg   - (trim.pitch_trim_deg * 0.5f);

    float l_ankle_r = trim.roll_trim_deg;
    float l_hip_r   = trim.roll_trim_deg * 0.5f;
    float r_ankle_r = -trim.roll_trim_deg;
    float r_hip_r   = -trim.roll_trim_deg * 0.5f;

    sendBusServoPosition(Serial1, LEFT_LEG.hip_pitch,   degToCounts(l_hip_p), 10);
    sendBusServoPosition(Serial1, LEFT_LEG.knee,        degToCounts(left_leg.knee_deg), 10);
    sendBusServoPosition(Serial1, LEFT_LEG.ankle_pitch, degToCounts(l_ankle_p), 10);
    sendBusServoPosition(Serial1, LEFT_LEG.hip_roll,    degToCounts(l_hip_r), 10);
    sendBusServoPosition(Serial1, LEFT_LEG.ankle_roll,  degToCounts(l_ankle_r), 10);

    sendBusServoPosition(Serial1, RIGHT_LEG.hip_pitch,   degToCounts(r_hip_p), 10);
    sendBusServoPosition(Serial1, RIGHT_LEG.knee,        degToCounts(right_leg.knee_deg), 10);
    sendBusServoPosition(Serial1, RIGHT_LEG.ankle_pitch, degToCounts(r_ankle_p), 10);
    sendBusServoPosition(Serial1, RIGHT_LEG.hip_roll,    degToCounts(r_hip_r), 10);
    sendBusServoPosition(Serial1, RIGHT_LEG.ankle_roll,  degToCounts(r_ankle_r), 10);

    static uint8_t hb_counter = 0;
    if (++hb_counter >= 50) {
        hb_counter = 0;
        digitalWrite(EndoskeletonConfig::PIN_STATUS_LED,
                     !digitalRead(EndoskeletonConfig::PIN_STATUS_LED));
    }
}
