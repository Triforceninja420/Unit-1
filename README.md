# Unit-1: Articulated Bipedal Doll Endoskeleton
Unit-1 is a modular, high-torque humanoid endoskeleton designed to sit inside flexible elastomer, silicone, or TPE doll skins without pinching, bunching, or causing actuator stall.
---
## System Overview

| Parameter | Specification | Notes |
| :--- | :--- | :--- |
| **Total Height Target** | 450 mm – 600 mm (1/3 to 1/4 scale) | Scalable via CAD variables |
| **Total Mass (Skeleton)** | ~1.2 kg – 1.8 kg | Without external elastomer skin |
| **Degrees of Freedom** | 12 DoF Lower Body (6 DoF per leg) | Expandable with spine/neck pivots |
| **Joint Architecture** | Direct-drive dual-shear bus servos | High continuous holding torque |
| **Skin Clearance** | Organic fillets, enclosed pivots | Prevents skin tearing & friction lock |
| **Power Rails** | 3.3V Logic / 7.4V–12V Servo Rail | Fused high-current rail with common ground |

---
## Kinematic Degree-of-Freedom Map
- **Hips (3 DoF per leg):** Yaw (Z), Roll (X), Pitch (Y)
- **Knee (1 DoF per leg):** Pitch (Y) with integrated mechanical hyperextension stop
- **Ankle (2 DoF per leg):** Pitch (Y) and Roll (X) for continuous ground compliance
- **Foot Interface:** Planar baseplate with mounting points for heel/toe elastomer dampeners
---
## Repository Structure
```text
Unit-1/
├── README.md                     # System specs, DoF map, and project overview
├── docs/
│   └── pinout.md                 # Pin assignments, power rails, and bus specs
├── cad/
│   └── femur_knee.scad           # Parametric OpenSCAD bone and knee clevis
└── firmware/
    ├── platformio.ini            # Build environment and dependencies
    ├── include/
    │   ├── config.h              # Kinematic lengths, servo IDs, and limits
    │   └── balance_controller.h  # IMU driver, filter, and balance PD interface
    └── src/
        ├── balance_controller.cpp# 6-Axis IMU fusion and stabilization math
        └── main.cpp              # 2D Inverse Kinematics and servo control loop