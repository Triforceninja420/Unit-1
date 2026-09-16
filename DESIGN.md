# DESIGN.md
Project: Unit-1 / Protocol Frame
Inventor: Craig Edward Ralls
Status: Public Frame kit locked
Date: 2026-09-15

## 1. Core architecture

- Heterogeneous modules: Frame / Plates / Voice (optional)
- Servo rail 6–8.4 V. Logic 5 V / 3.3 V. Never mains in the pelvis
- 4-state machine: Idle → Stand → Shuffle → Halt (+ Fault)
- Safe-reserve: if pack voltage sags, gait freezes in a squat/lock, voice can stay
- E-stop cuts servo enable. Hardware, not an app button
- Protocol-droid *style*. Your plates. Not a licensed costume

This is the project anyone builds if they want a C-3PO-like droid in the shop.

## 2. Version ladder

**V0.8 Frame — the robot (now)**
Rigid biped. Hobby servos. Open-loop gait. See `FRAME.md`.

**V0.9 Voice (optional)**
Pico or small SBC + speaker + local TTS. Polite translator prompt in `CONSTITUTION.md`.
No heaters required. No cloud required.

**V1.0 Plates**
PETG / foam / vac-form covers, gold or whatever. Budget < 2 kg. Still the same gait.

**V1.1 Hands + head yaw**
Printed mitts. One head servo. Still open-loop.

**V2.0**
Not this repo. Not closed-loop parkour. Not DittoBot programmable matter.

## 3. Locked envelopes (public kit)

| Item | Locked value |
| :--- | :--- |
| Height | 160–168 cm |
| Bare mass | 8–14 kg; flag >16 kg |
| Walk | Open-loop hobby-servo gait on Frame / light plates only |
| Heavy soft shell walk | Forbidden |
| Human interrupt | 35 N on clamp/pinch; E-stop on enable |
| Bus | Fused servo rail + GFCI on wall chargers |
| Brain default | Local MCU. Cloud optional and off |
| Likeness | Style homage only. No official marks |

## 4. Optional stacks (not the kit)

Soft companion covers, heat pads, tactile / “feel-me” research, sleeves, and local
girlfriend brains live only in `OPTIONAL_SHELL.md`. They do not change Frame numbers.
They do not walk. UBHP-1 north star stays in `VISION.md` if present; do not paste it here.