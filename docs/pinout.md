
---

### File 2: `docs/pinout.md`
```markdown
# Unit-1 Hardware Pin Mapping & Power Specs

## Power Distribution Architecture

- **V_SERVO (+7.4V to +12.0V DC):** Primary high-current power rail for daisy-chained serial bus servos. Protected by an inline 10A blade fuse and an SMBJ15CA TVS diode.
- **V_LOGIC (+3.3V DC):** Dedicated low-noise logic rail derived from a high-efficiency synchronous buck converter (minimum 1.0A continuous). Powers the MCU, 6-axis IMU, and bus transceiver logic.
- **Common Ground:** Star-ground layout linking battery ground, buck ground, and servo signal ground to prevent ground bounce during rapid servo direction changes.

---

## Primary MCU Pinout (ESP32-S3 / Standard ESP32)

| Function | MCU Pin | Direction | Description |
| :--- | :--- | :--- | :--- |
| `SERVO_BUS_TX` | GPIO 17 | Output | Half-duplex / Daisy-chain Serial Bus TX (1 Mbps) |
| `SERVO_BUS_RX` | GPIO 16 | Input | Half-duplex / Daisy-chain Serial Bus RX (1 Mbps) |
| `I2C_SDA`       | GPIO 21 | Bidirectional | 6-Axis IMU data line (4.7 kΩ pull-up to 3.3V) |
| `I2C_SCL`       | GPIO 22 | Output | 6-Axis IMU clock line (4.7 kΩ pull-up to 3.3V) |
| `STATUS_LED`    | GPIO 2  | Output | 100 Hz balance loop heartbeat indicator |

---

## Default Serial Bus Servo ID Map

| Servo ID | Axis / Location | Motion Plane |
| :--- | :--- | :--- |
| **1** | Left Hip Yaw | Horizontal / Z |
| **2** | Left Hip Roll | Coronal / X |
| **3** | Left Hip Pitch | Sagittal / Y |
| **4** | Left Knee | Sagittal / Y |
| **5** | Left Ankle Pitch | Sagittal / Y |
| **6** | Left Ankle Roll | Coronal / X |
| **7** | Right Hip Yaw | Horizontal / Z |
| **8** | Right Hip Roll | Coronal / X |
| **9** | Right Hip Pitch | Sagittal / Y |
| **10** | Right Knee | Sagittal / Y |
| **11** | Right Ankle Pitch | Sagittal / Y |
| **12** | Right Ankle Roll | Coronal / X |