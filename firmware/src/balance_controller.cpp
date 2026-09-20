#include "balance_controller.h"
#include <Arduino.h>
#include <Wire.h>
#include <math.h>

float robot_pitch_deg = 0.0f;
float robot_roll_deg  = 0.0f;

static float last_pitch_error = 0.0f;
static float last_roll_error  = 0.0f;

bool initIMU() {
    Wire.begin(21, 22); // SDA=21, SCL=22
    Wire.setClock(400000);

    Wire.beginTransmission(BalanceConfig::IMU_ADDR);
    Wire.write(0x6B); // PWR_MGMT_1
    Wire.write(0x00); // Wake up IMU
    if (Wire.endTransmission() != 0) {
        return false;
    }

    // Configure Gyro Full Scale (+/- 500 deg/s)
    Wire.beginTransmission(BalanceConfig::IMU_ADDR);
    Wire.write(0x1B);
    Wire.write(0x08);
    Wire.endTransmission();

    // Configure Accel Full Scale (+/- 4g)
    Wire.beginTransmission(BalanceConfig::IMU_ADDR);
    Wire.write(0x1C);
    Wire.write(0x08);
    Wire.endTransmission();

    return true;
}

void updateOrientation(float dt) {
    Wire.beginTransmission(BalanceConfig::IMU_ADDR);
    Wire.write(0x3B);
    Wire.endTransmission(false);
    Wire.requestFrom((uint8_t)BalanceConfig::IMU_ADDR, (size_t)14, true);

    if (Wire.available() < 14) return;

    int16_t raw_ax = (Wire.read() << 8) | Wire.read();
    int16_t raw_ay = (Wire.read() << 8) | Wire.read();
    int16_t raw_az = (Wire.read() << 8) | Wire.read();
    Wire.read(); Wire.read(); // Skip temp
    int16_t raw_gx = (Wire.read() << 8) | Wire.read();
    int16_t raw_gy = (Wire.read() << 8) | Wire.read();
    int16_t raw_gz = (Wire.read() << 8) | Wire.read();

    float ax = (float)raw_ax / 8192.0f;
    float ay = (float)raw_ay / 8192.0f;
    float az = (float)raw_az / 8192.0f;

    float gyro_rate_x = (float)raw_gx / 65.5f; // Roll rate
    float gyro_rate_y = (float)raw_gy / 65.5f; // Pitch rate

    float accel_pitch = atan2f(-ax, sqrtf(ay * ay + az * az)) * (180.0f / M_PI);
    float accel_roll  = atan2f(ay, az) * (180.0f / M_PI);

    robot_pitch_deg = BalanceConfig::FILTER_ALPHA * (robot_pitch_deg + gyro_rate_y * dt) 
                    + (1.0f - BalanceConfig::FILTER_ALPHA) * accel_pitch;

    robot_roll_deg  = BalanceConfig::FILTER_ALPHA * (robot_roll_deg + gyro_rate_x * dt) 
                    + (1.0f - BalanceConfig::FILTER_ALPHA) * accel_roll;
}

BalanceOffsets computeStabilizationTrim(float target_pitch, float target_roll, float dt) {
    float pitch_err = target_pitch - robot_pitch_deg;
    float roll_err  = target_roll - robot_roll_deg;

    float d_pitch = (pitch_err - last_pitch_error) / dt;
    float d_roll  = (roll_err - last_roll_error) / dt;

    last_pitch_error = pitch_err;
    last_roll_error  = roll_err;

    BalanceOffsets offsets;
    offsets.pitch_trim_deg = constrain(
        (pitch_err * BalanceConfig::KP_PITCH) + (d_pitch * BalanceConfig::KD_PITCH),
        -BalanceConfig::MAX_TRIM_DEG, 
         BalanceConfig::MAX_TRIM_DEG
    );

    offsets.roll_trim_deg = constrain(
        (roll_err * BalanceConfig::KP_ROLL) + (d_roll * BalanceConfig::KD_ROLL),
        -BalanceConfig::MAX_TRIM_DEG, 
         BalanceConfig::MAX_TRIM_DEG
    );

    return offsets;
}
