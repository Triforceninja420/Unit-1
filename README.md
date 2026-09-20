# Unit-1: Articulated Bipedal Doll Endoskeleton

Modular high-torque humanoid endoskeleton meant to sit inside a flexible elastomer / TPE skin without pinching or stalling actuators.

**Scale lock:** 450–600 mm class. See `SCALE.md`.  
**Firmware lock:** open-loop stand + IMU PD trim. Not a walk.  
**Not DittoBot.** Voxel latch numbers stay in the other repo.

---

## System Overview

| Parameter | Specification | Notes |
| :--- | :--- | :--- |
| Height | 450–600 mm | 1/3 to 1/4 scale. CAD / firmware use 110 mm links |
| Bare skeleton mass | ~1.2–1.8 kg | No elastomer skin |
| Lower body | 12 DoF (6 per leg) | IDs 1–12 |
| Joints | Serial bus digital servos | STS/SCS-style 1 Mbps, register 0x2A writes |
| Skin clearance | Fillets, enclosed pivots | Prevents tear / friction lock |
| Power | 3.3 V logic / 7.4–12 V servo | Fused servo rail, common ground |
| Brain | ESP32-S3, 100 Hz loop | Enable pin defaults OFF |

Stand firmware solves sagittal IK, then adds pitch trim on ankle/hip and roll trim on ankle/hip roll (right side sign-flipped).

## Bench bar (V0.8)

1. Enable pin stays LOW until IMU init succeeds.
2. IMU fail leaves the rail off and prints `[ERROR]`.
3. Packet is TX-only. No current/temp/ack yet. That is intentional.
4. Nothing is a walking robot until a measurement card is filled.
