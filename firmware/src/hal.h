#pragma once
#include <Arduino.h>
#include "config.h"

class HardwareAbstractionLayer {
public:
    void init() {
        pinMode(Config::PIN_ACT_PWM_A, OUTPUT);
        pinMode(Config::PIN_ACT_PWM_B, OUTPUT);
        pinMode(Config::PIN_ACT_EN, OUTPUT);
        pinMode(Config::PIN_STATUS, OUTPUT);
        pinMode(Config::PIN_ESTOP, INPUT_PULLUP);

        disableActuators();
    }

    void setActuatorDrive(int16_t command) {
        // Command range: -255 to +255
        if (command > 0) {
            analogWrite(Config::PIN_ACT_PWM_A, (uint8_t)command);
            analogWrite(Config::PIN_ACT_PWM_B, 0);
        } else if (command < 0) {
            analogWrite(Config::PIN_ACT_PWM_A, 0);
            analogWrite(Config::PIN_ACT_PWM_B, (uint8_t)(-command));
        } else {
            analogWrite(Config::PIN_ACT_PWM_A, 0);
            analogWrite(Config::PIN_ACT_PWM_B, 0);
        }
    }

    void enableActuators() {
        digitalWrite(Config::PIN_ACT_EN, HIGH);
    }

    void disableActuators() {
        digitalWrite(Config::PIN_ACT_EN, LOW);
        analogWrite(Config::PIN_ACT_PWM_A, 0);
        analogWrite(Config::PIN_ACT_PWM_B, 0);
    }

    bool readEstopActive() {
        // Active LOW switch
        return digitalRead(Config::PIN_ESTOP) == LOW;
    }

    float readCurrentAmps() {
        // Linear shunt scaling
        int raw = analogRead(Config::PIN_SENSE_AMP);
        return ((float)raw / 4095.0f) * 10.0f;
    }

    void toggleHeartbeat() {
        digitalWrite(Config::PIN_STATUS, !digitalRead(Config::PIN_STATUS));
    }
};
