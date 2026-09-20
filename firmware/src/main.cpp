#include <Arduino.h>
#include "config.h"
#include "hal.h"

enum class SystemState {
    STANDBY,
    ACTIVE,
    FAULT_ESTOP,
    FAULT_OVERCURRENT
};

HardwareAbstractionLayer hal;
SystemState currentState = SystemState::STANDBY;

uint32_t lastTelemetryTime = 0;
uint32_t lastCommandHeartbeat = 0;
int16_t currentTargetVelocity = 0;

void processSerialCommands();
void emitTelemetry(uint32_t now);
void runSafetyChecks();

void setup() {
    Serial.begin(Config::SERIAL_BAUD);
    hal.init();
    lastCommandHeartbeat = millis();
}

void loop() {
    uint32_t now = millis();

    processSerialCommands();
    runSafetyChecks();

    // Actuator Drive Output
    if (currentState == SystemState::ACTIVE) {
        hal.enableActuators();
        hal.setActuatorDrive(currentTargetVelocity);
    } else {
        hal.disableActuators();
        currentTargetVelocity = 0;
    }

    // Telemetry & Diagnostic Stream (10 Hz)
    if (now - lastTelemetryTime >= Config::TELEMETRY_MS) {
        lastTelemetryTime = now;
        hal.toggleHeartbeat();
        emitTelemetry(now);
    }
}

void runSafetyChecks() {
    uint32_t now = millis();

    // Hardware E-Stop verification
    if (hal.readEstopActive()) {
        currentState = SystemState::FAULT_ESTOP;
        return;
    }

    // Current draw limit enforcement
    if (hal.readCurrentAmps() > Config::MAX_CURRENT_AMPS) {
        currentState = SystemState::FAULT_OVERCURRENT;
        return;
    }

    // Command watchdog: drop to STANDBY if communication halts
    if (now - lastCommandHeartbeat > Config::WATCHDOG_MS && currentState == SystemState::ACTIVE) {
        currentState = SystemState::STANDBY;
    }
}

void processSerialCommands() {
    if (Serial.available() > 0) {
        char cmd = Serial.read();

        switch (cmd) {
            case 'E': // Enable command
                if (currentState == SystemState::STANDBY) {
                    currentState = SystemState::ACTIVE;
                }
                lastCommandHeartbeat = millis();
                break;

            case 'D': // Disable command
                currentState = SystemState::STANDBY;
                break;

            case 'S': // Set Speed: format "S <int>"
                currentTargetVelocity = constrain(Serial.parseInt(), -255, 255);
                lastCommandHeartbeat = millis();
                break;

            case 'R': // Reset Faults
                if (!hal.readEstopActive() && hal.readCurrentAmps() <= Config::MAX_CURRENT_AMPS) {
                    currentState = SystemState::STANDBY;
                }
                break;
        }
    }
}

void emitTelemetry(uint32_t now) {
    const char* stateStr = "UNKNOWN";
    switch (currentState) {
        case SystemState::STANDBY:           stateStr = "STANDBY"; break;
        case SystemState::ACTIVE:            stateStr = "ACTIVE"; break;
        case SystemState::FAULT_ESTOP:       stateStr = "FAULT_ESTOP"; break;
        case SystemState::FAULT_OVERCURRENT: stateStr = "FAULT_OVERCURRENT"; break;
    }

    // JSON formatted telemetry line
    Serial.print("{\"ts\":");
    Serial.print(now);
    Serial.print(",\"state\":\"");
    Serial.print(stateStr);
    Serial.print("\",\"amps\":");
    Serial.print(hal.readCurrentAmps(), 2);
    Serial.print(",\"cmd\":");
    Serial.print(currentTargetVelocity);
    Serial.println("}");
}
