# Unit‑1 Companion Module CAN Bus Specification
**Standard:** CAN 2.0B / CAN FD compatible  
**Baud Rate:** 1.0 Mbps  
**Endianness:** Little-Endian  
---
## 1. Arbitration ID Map

| CAN ID | Priority | Node Target | Function | Update Rate |
| :--- | :--- | :--- | :--- | :--- |
| `0x018` | Medium | Companion Actuator 1 | Shoulder Pitch Command / State | 500 Hz |
| `0x019` | Medium | Companion Actuator 2 | Shoulder Roll Command / State | 500 Hz |

---
## 2. Command Frame (Host Controller -> Actuator)
Payload Length: **8 Bytes**

| Byte Range | Field Name | Data Type | Units | Scaling / Formula | Valid Range |
| :--- | :--- | :--- | :--- | :--- | :--- |
| `Byte 0..1` | `Target Position` | `int16_t` | radians | $0.0001\text{ rad/LSB}$ | $\pm 3.1415\text{ rad}$ |
| `Byte 2..3` | `Target Velocity` | `int16_t` | rad/s | $0.01\text{ rad/s/LSB}$ | $\pm 30.0\text{ rad/s}$ |
| `Byte 4..5` | `Feedforward Torque` | `int16_t` | N·m | $0.01\text{ N}\cdot\text{m/LSB}$ | $\pm 45.0\text{ N}\cdot\text{m}$ |
| `Byte 6` | `Control Mode` | `uint8_t` | Enum | `0x01`: Pos, `0x02`: Vel, `0x03`: Torque, `0x00`: E-Stop | `0x00`–`0x03` |
| `Byte 7` | `Rolling Counter` | `uint8_t` | Counter | Increments per packet ($0\text{–}255$) | Loop |

---
## 3. Telemetry Feedback Frame (Actuator -> Host Controller)
Payload Length: **8 Bytes**

| Byte Range | Field Name | Data Type | Units | Scaling / Formula |
| :--- | :--- | :--- | :--- | :--- |
| `Byte 0..1` | `Actual Position` | `int16_t` | radians | $0.0001\text{ rad/LSB}$ |
| `Byte 2..3` | `Actual Velocity` | `int16_t` | rad/s | $0.01\text{ rad/s/LSB}$ |
| `Byte 4..5` | `Measured Torque` | `int16_t` | N·m | $0.01\text{ N}\cdot\text{m/LSB}$ |
| `Byte 6` | `Temperature` | `uint8_t` | °C | $1^\circ\text{C/LSB}$ (Range: $0\text{–}150^\circ\text{C}$) |
| `Byte 7` | `Fault Flags` | `uint8_t` | Bitfield | Bit 0: Over-temp, Bit 1: Over-current, Bit 2: Encoder error |