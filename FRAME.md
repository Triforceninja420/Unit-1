# FRAME.md — Unit-1 metal armature coupon

Design owned by Craig. Locked 2026-09-15.

**This file is the buildable robot.**
Rigid biped. Hobby servos. Open-loop gait. Wobbly C-3PO demo.
The shell hangs on later. The shell is not this coupon.

Do not paste Path 1 silicone mass (32–38 kg) into this force box.
Do not paste DittoBot EPM / 40 N shear / Ø6 coil numbers here.
Do not claim a dressed companion walks until this card is filled *and* a separate dressed-mass card exists.

---

## Why this cut

The only piece with real engineering is the metal skeleton:
- load paths
- joint axes
- servo torque vs limb mass
- open-loop timing that doesn’t fall over on a flat floor

Everything else is a cover: platinum skin, gel, sleeves, Jetson voice, 41 °C pads.
Those hang on a frame that already stands, sits, and takes ten ugly steps.

---

## Locked envelope (frame only)

| Item | Locked value |
| :--- | :--- |
| Form | Rigid biped armature, adult proportions, 160–168 cm target height |
| Structure | Aluminum tube / plate or 3D-printed joints on metal spars. No silicone on this coupon |
| Actuation | Hobby digital servos (or robot-servo class). Position control. **Open-loop gait** |
| Gait claim | Ten consecutive steps on flat floor without a boom. Wobble allowed. C-3PO is the quality bar |
| Balance | No force-torque ankles. No ZMP stack required on this coupon |
| Mass (bare frame + servos + pack) | Target **8–14 kg**. Flag if >16 kg before any shell |
| Shell | **Off.** Soft cover, doll body, and sleeves are a later hang |
| Walk + 32 kg silicone | **Forbidden on this coupon.** That is a different card |
| Human contact | Tether or boom optional. 35 N interrupt still applies to any clamp/pinch joint |
| Bus | 6–8.4 V servo rail and/or 12 V walk rail. Fused. E-stop cuts servo enable |
| Brain on this coupon | MCU gait player (RP2040 / Pico / Arduino Mega class). Jetson is not required to walk |

## Joint set (minimum demo)

Hip yaw optional. You need enough to shuffle, not to dance.

| Joint | Side | Notes |
| :--- | :--- | :--- |
| Hip pitch | L/R | Primary step |
| Knee pitch | L/R | |
| Ankle pitch | L/R | First-order fall stop. Cheap is fine |
| Hip roll | L/R | Weight shift. Can start locked, then add |
| Shoulder pitch | L/R | Arm swing / counterweight. Can start dummy |
| Elbow | L/R | Optional Phase F1 |
| Torso / waist | 0–1 | Optional. Adds wobble if you do it early |

Head servos stay on the Path 1 / Harmony stack. Do not put a 17-motor face on a gait coupon.

## What “open-loop gait” means here

A recorded or scripted sequence:
1. Shift COM over stance foot (hip roll or a lean stop).
2. Lift swing foot (hip + knee).
3. Plant.
4. Repeat other side.

No vision. No IMU required for the first ten steps (IMU is allowed as a logger, not as the stabilizer, until the card says otherwise).
If it needs a fishing-line boom for the first week, say so on the card. Boom-assisted steps are not a walk claim.

## Success criteria

1. Bare frame stands 60 s unpowered-lock or servo-hold, no boom.
2. Ten steps, flat floor, no boom — or the card says boom-on and you do not use the word walk.
3. E-stop drops servo enable < 200 ms.
4. Measured mass, servo list, stall current, pack voltage written on `MEASUREMENT_CARD.md` (Frame table).
5. No silicone, no companion language.

## What this file does not do

- Does not unlock Path 1 “no walk” on a dressed body
- Does not turn hobby servos into a closed-loop humanoid
- Does not set dressed-mass torque (do that after you weigh the actual shell)
- Does not mix DittoBot latch numbers into hip joints
