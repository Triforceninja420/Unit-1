# Unit-1 Hardware Pin Mapping & Power Rails
## Power Architecture
- **V_MAIN (12V - 24V):** Primary power rail. Protected by a 10A mini blade fuse, SMAJ28A TVS diode, and P-channel reverse-polarity MOSFET.
- **V_LOGIC (3.3V):** Powered by an onboard high-efficiency synchronous buck converter (max 1.5A) feeding the MCU, logic-level shifters, and I2C sensors.
## Primary Pinout Definition

| Pin Function | MCU Pin | Direction | Description |
| :--- | :--- | :--- | :--- |
| `ACTUATOR_PWM_A` | GPIO 18 | Output | High-frequency PWM driver channel A |
| `ACTUATOR_PWM_B` | GPIO 19 | Output | High-frequency PWM driver channel B |
| `ACTUATOR_EN` | GPIO 23 | Output | Master driver enable (Active HIGH) |
| `CURRENT_SENSE` | GPIO 36 | Analog In | Current shunt amplifier feedback |
| `E_STOP_INPUT` | GPIO 4 | Input (P/U) | Active-LOW hardware interlock switch |
| `I2C_SDA` | GPIO 21 | Bidirectional | Sensor bus data (4.7kΩ pull-up to 3.3V) |
| `I2C_SCL` | GPIO 22 | Output | Sensor bus clock (4.7kΩ pull-up to 3.3V) |
| `STATUS_LED` | GPIO 2 | Output | Visual state indicator (Heartbeat) |