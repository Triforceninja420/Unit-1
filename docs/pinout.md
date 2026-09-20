# Unit-1 Hardware Pin Mapping & Power Specs

Board default in `platformio.ini`: **ESP32-S3-DevKitC-1**.
Classic ESP32 DevKit pin numbers are the alt column only.

## Power

- **V_SERVO (+7.4 V to +12.0 V DC):** daisy-chained bus servos. Inline fuse + TVS.
- **V_LOGIC (+3.3 V DC):** MCU, IMU, transceiver logic. Separate buck, >= 1 A.
- **Common ground.** Star at the pack negative.
- **SERVO_ENABLE:** firmware-driven enable. Boot default is **disabled**.

## MCU pins (S3 DevKitC-1 lock)

| Function | S3 GPIO | Classic ESP32 alt | Dir | Notes |
| :--- | :--- | :--- | :--- | :--- |
| SERVO_BUS_TX | 17 | 17 | Out | 1 Mbps UART |
| SERVO_BUS_RX | 16 | 16 | In | Wired for later ack. V0.8 does not read |
| SERVO_BUS_DIR | 18 | 4 | Out | Optional half-duplex DIR. HIGH = TX |
| I2C_SDA | 8 | 21 | I/O | IMU. 4.7 k to 3.3 V |
| I2C_SCL | 9 | 22 | Out | IMU. 4.7 k to 3.3 V |
| SERVO_ENABLE | 5 | 5 | Out | Default LOW (rail off) |
| STATUS_LED | 2 | 2 | Out | Heartbeat when loop is alive |

V0.8 firmware is TX-only on the servo bus. DIR is driven TX before each packet.

## Bus servo IDs

| ID | Axis |
| :--- | :--- |
| 1 | Left hip yaw |
| 2 | Left hip roll |
| 3 | Left hip pitch |
| 4 | Left knee |
| 5 | Left ankle pitch |
| 6 | Left ankle roll |
| 7 | Right hip yaw |
| 8 | Right hip roll |
| 9 | Right hip pitch |
| 10 | Right knee |
| 11 | Right ankle pitch |
| 12 | Right ankle roll |

Protocol lock: Feetech / Waveshare STS-style write to goal position register 0x2A, 4096 counts / rev, center 2048.
