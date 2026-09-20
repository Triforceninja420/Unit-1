#pragma once
#include <stdint.h>

namespace EndoskeletonConfig {
    // Kinematic link lengths (mm)
    constexpr float L1 = 110.0f; // Femur length
    constexpr float L2 = 110.0f; // Tibia length

    // Communication parameters
    constexpr uint32_t SERIAL_DEBUG_BAUD = 115200;
    constexpr uint32_t BUS_SERVO_BAUD    = 1000000; // 1 Mbps
    constexpr uint8_t PIN_BUS_RX         = 16;
    constexpr uint8_t PIN_BUS_TX         = 17;
    constexpr uint8_t PIN_STATUS_LED     = 2;

    // Servo resolution (4096 steps per 360 degrees)
    constexpr float STEPS_PER_DEGREE = 4096.0f / 360.0f;
    constexpr int16_t SERVO_CENTER_COUNT = 2048;
}

struct LegJoints {
    uint8_t hip_yaw;
    uint8_t hip_roll;
    uint8_t hip_pitch;
    uint8_t knee;
    uint8_t ankle_pitch;
    uint8_t ankle_roll;
};

const LegJoints LEFT_LEG  = {1, 2, 3, 4, 5, 6};
const LegJoints RIGHT_LEG = {7, 8, 9, 10, 11, 12};

struct LegAngles {
    float hip_pitch_deg;
    float knee_deg;
    float ankle_pitch_deg;
};
