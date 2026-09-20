#include <Arduino.h>
#include <math.h>
#include "config.h"
#include "balance_controller.h"

uint32_t last_loop_time = 0;

// Analytical 2D Sagittal Inverse Kinematics
bool solveLegIK(float target_x, float target_y, LegAngles &out) {
    float r_sq = (target_x * target_x) + (target_y * target_y);
    float l1 = EndoskeletonConfig::L1;
    float l2 = EndoskeletonConfig::L2;

    float max_reach = l1 + l2;
    if (sqrtf(r_sq) > max_reach || sqrtf(r_sq) < fabsf(l1 - l2)) {
        return false;
    }

    float cos_knee = (r_sq - (l1 * l1) - (l2 * l2)) / (2.0f * l1 * l2);
    cos_knee = constrain(cos_knee, -1.0f, 1.0f);
    float knee_rad = acosf(cos_knee);

    float alpha = atan2f(target_x, -target_y);
    float beta = atan2f(l2 * sinf(knee_rad), l1 + (l2 * cos_knee));
    float hip_rad = alpha - beta;

    float ankle_rad = -(hip_rad + knee_rad);

    out.hip_pitch_deg   = hip_rad * (180.0f / M_PI);
    out.knee_deg        = knee_rad * (180.0f / M_PI);
    out.ankle_pitch_deg = ankle_rad * (180.0f / M_PI);

    return true;
}

// Assemble and transmit half-duplex bus servo packet
void sendBusServoPosition(HardwareSerial &bus, uint8_t servo_id, int16_t position_raw, uint16_t time_ms) {
    uint8_t packet[10];
    packet[0] = 0xFF;
    packet[1] = 0xFF;
    packet[2] = servo_id;
    packet[3] = 0x07;
    packet[4] = 0x03; // Write instruction
    packet[5] = (uint8_t)(position_raw & 0xFF);
    packet[6] = (uint8_t)((position_raw >> 8) & 0xFF);
    packet[7] = (uint8_t)(time_ms & 0xFF);
    packet[8] = (uint8_t)((time_ms >> 8) & 0xFF);

    uint8_t checksum = 0;
    for (int i = 2; i <= 8; i++) {
        checksum += packet[i];
    }
    packet[9] = ~checksum;

    bus.write(packet, sizeof(packet));
}

void setup() {
    Serial.begin(EndoskeletonConfig::SERIAL_DEBUG_BAUD);
    Serial1.begin(EndoskeletonConfig::BUS_SERVO_BAUD, SERIAL_8N1, 
                  EndoskeletonConfig::PIN_BUS_RX, EndoskeletonConfig::PIN_BUS_TX);

    pinMode(EndoskeletonConfig::PIN_STATUS_LED, OUTPUT);

    if (!initIMU()) {
        Serial.println("[ERROR] IMU initialization failed on I2C bus!");
    } else {
        Serial.println("[OK] IMU online. Initializing balance controller.");
    }

    last_loop_time = millis();
}

void loop() {
    uint32_t now = millis();
    if (now - last_loop_time >= 10) { // 100 Hz fixed loop rate
        float dt = (now - last_loop_time) / 1000.0f;
        last_loop_time = now;

        // 1. Update fused pitch and roll angles
        updateOrientation(dt);

        // 2. Compute dynamic PD balance offsets (target = 0 deg upright)
        BalanceOffsets trim = computeStabilizationTrim(0.0f, 0.0f, dt);

        // 3. Solve baseline standing stance (-15mm forward X, -200mm downward Z)
        LegAngles left_leg, right_leg;
        if (solveLegIK(-15.0f, -200.0f, left_leg) && solveLegIK(-15.0f, -200.0f, right_leg)) {

            // 4. Inject stabilization trim directly into ankle and hip pivots
            float final_l_ankle = left_leg.ankle_pitch_deg + trim.pitch_trim_deg;
            float final_l_hip   = left_leg.hip_pitch_deg   - (trim.pitch_trim_deg * 0.5f);

            float final_r_ankle = right_leg.ankle_pitch_deg + trim.pitch_trim_deg;
            float final_r_hip   = right_leg.hip_pitch_deg   - (trim.pitch_trim_deg * 0.5f);

            // Convert to bus servo step counts
            int16_t l_hip_raw   = (int16_t)(EndoskeletonConfig::SERVO_CENTER_COUNT + (final_l_hip * EndoskeletonConfig::STEPS_PER_DEGREE));
            int16_t l_knee_raw  = (int16_t)(EndoskeletonConfig::SERVO_CENTER_COUNT + (left_leg.knee_deg * EndoskeletonConfig::STEPS_PER_DEGREE));
            int16_t l_ankle_raw = (int16_t)(EndoskeletonConfig::SERVO_CENTER_COUNT + (final_l_ankle * EndoskeletonConfig::STEPS_PER_DEGREE));

            int16_t r_hip_raw   = (int16_t)(EndoskeletonConfig::SERVO_CENTER_COUNT + (final_r_hip * EndoskeletonConfig::STEPS_PER_DEGREE));
            int16_t r_knee_raw  = (int16_t)(EndoskeletonConfig::SERVO_CENTER_COUNT + (right_leg.knee_deg * EndoskeletonConfig::STEPS_PER_DEGREE));
            int16_t r_ankle_raw = (int16_t)(EndoskeletonConfig::SERVO_CENTER_COUNT + (final_r_ankle * EndoskeletonConfig::STEPS_PER_DEGREE));

            // Transmit to Left Leg
            sendBusServoPosition(Serial1, LEFT_LEG.hip_pitch, l_hip_raw, 10);
            sendBusServoPosition(Serial1, LEFT_LEG.knee, l_knee_raw, 10);
            sendBusServoPosition(Serial1, LEFT_LEG.ankle_pitch, l_ankle_raw, 10);

            // Transmit to Right Leg
            sendBusServoPosition(Serial1, RIGHT_LEG.hip_pitch, r_hip_raw, 10);
            sendBusServoPosition(Serial1, RIGHT_LEG.knee, r_knee_raw, 10);
            sendBusServoPosition(Serial1, RIGHT_LEG.ankle_pitch, r_ankle_raw, 10);
        }

        // Toggle heartbeat LED every 50 iterations (~500 ms)
        static uint8_t hb_counter = 0;
        if (++hb_counter >= 50) {
            hb_counter = 0;
            digitalWrite(EndoskeletonConfig::PIN_STATUS_LED, !digitalRead(EndoskeletonConfig::PIN_STATUS_LED));
        }
    }
}
