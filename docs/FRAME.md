# FRAME.md — 160 cm protocol coupon (docs only)

Design owned by Craig. Locked 2026-09-15 as a full-size armature note.

**Firmware and CAD in this repo do not build this envelope.**
Active scale is 450–600 mm in `SCALE.md` and `firmware/include/config.h`.
Keep this file as the adult-height coupon spec. Do not copy 8–14 kg or 160 cm into `config.h`.

Rigid biped. Hobby servos. Open-loop gait. Wobbly C-3PO demo.
The shell hangs on later. The shell is not this coupon.

## Locked envelope (coupon, not firmware)

| Item | Locked value |
| :--- | :--- |
| Form | Rigid biped, adult proportions, 160–168 cm |
| Structure | Aluminum tube / plate, or printed joint blocks on metal spars |
| Actuation | Hobby digital servos. Position control. Open-loop gait |
| Quality bar | Ten consecutive steps on a flat floor. Wobble allowed |
| Balance | No force-torque ankles. No ZMP stack on this coupon |
| Bare mass | 8–14 kg including servos + pack. Flag if >16 kg |
| Shell | Off for the walk claim |
| Dressed / 32 kg walk | Forbidden on this coupon |
| Human path | E-stop on servo enable |
| Bus | 6–8.4 V servo rail and/or 12 V. Fused |
| Brain | MCU gait player. Jetson not required to walk |

## What this file does not do

- Does not make hobby servos a closed-loop humanoid
- Does not set torque for a heavy soft shell
- Does not mix DittoBot latch numbers into hip joints
