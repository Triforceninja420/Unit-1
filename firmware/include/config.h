#pragma once
#include <stdint.h>

// Active scale: 450-600 mm class. See /SCALE.md.
// Do not paste 160 cm / 8-14 kg FRAME.md numbers here.

namespace EndoskeletonConfig {
    constexpr float L1 = 110.0f;
    constexpr float L2 = 110.0f;

    constexpr float STANCE_X_MM = -15.0f;
    constexpr float STANCE_Y_MM = -200.0f;

    constexpr uint32_t SERIAL_DEBUG_BAUD = 115200;
    constexpr uint32_t BUS_SERVO_BAUD    = 1000000;

    constexpr uint8_t PIN_BUS_RX         = 16;
    constexpr uint8_t PIN_BUS_TX         = 17;
    constexpr uint8_t PIN_BUS_DIR        = 18;
    constexpr bool    BUS_USE_DIR_PIN    = true;
    constexpr uint8_t PIN_I2C_SDA        = 8;
    constexpr uint8_t PIN_I2C_SCL        = 9;
    constexpr uint8_t PIN_STATUS_LED     = 2;
    constexpr uint8_t PIN_SERVO_ENABLE   = 5;
    constexpr bool    SERVO_ENABLE_ACTIVE_HIGH = true;

    constexpr float   STEPS_PER_DEGREE      = 4096.0f / 360.0f;
    constexpr int16_t SERVO_CENTER_COUNT    = 2048;
    constexpr uint8_t STS_REG_GOAL_POSITION = 0x2A;

    constexpr uint32_t LOOP_PERIOD_MS = 10;
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
