#pragma once
#include <stdint.h>

namespace Config {
    constexpr uint32_t SERIAL_BAUD      = 115200;
    constexpr uint32_t TELEMETRY_MS     = 100;     // 10 Hz telemetry stream
    constexpr uint32_t WATCHDOG_MS      = 500;     // E-stop triggers if silent > 500ms
    constexpr float    MAX_CURRENT_AMPS = 8.5f;    // Software overcurrent limit

    // Pin Assignments
    constexpr uint8_t PIN_ACT_PWM_A = 18;
    constexpr uint8_t PIN_ACT_PWM_B = 19;
    constexpr uint8_t PIN_ACT_EN    = 23;
    constexpr uint8_t PIN_SENSE_AMP = 36;
    constexpr uint8_t PIN_ESTOP     = 4;
    constexpr uint8_t PIN_STATUS    = 2;
}
