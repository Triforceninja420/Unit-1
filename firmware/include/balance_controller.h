#pragma once
#include <stdint.h>

namespace BalanceConfig {
    constexpr uint8_t IMU_ADDR   = 0x68;
    constexpr float LOOP_DT      = 0.01f;   // 100 Hz loop period (10 ms)
    constexpr float FILTER_ALPHA = 0.98f;

    // PD Gains for silicone elasticity compensation
    constexpr float KP_PITCH     = 0.85f;
    constexpr float KD_PITCH     = 0.04f;
    constexpr float KP_ROLL      = 0.70f;
    constexpr float KD_ROLL      = 0.03f;

    constexpr float MAX_TRIM_DEG = 12.0f;
}

struct BalanceOffsets {
    float pitch_trim_deg;
    float roll_trim_deg;
};

bool initIMU();
void updateOrientation(float dt);
BalanceOffsets computeStabilizationTrim(float target_pitch, float target_roll, float dt);

extern float robot_pitch_deg;
extern float robot_roll_deg;
