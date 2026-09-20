# Unit-1 Frame — C-3PO-class biped

A rigid metal person you can actually build.

Hobby servos. Open-loop gait. Wobbly protocol-droid walk on a flat floor.
Design owned by Craig. Started 2026-09-15.

If you want a C-3PO, this is the repo. Cut tube, mount servos, play a step sequence, take ten ugly steps. That is the whole product on day one.

**This is not DittoBot.** DittoBot is a 25 mm voxel latch coupon (`Triforceninja420/DittoBot`). Do not paste those coil / EPM / 40 N numbers here.

**The gold shell is optional and later.** Paint, cape, and any soft cover hang on a frame that already stands. A dressed or companion body is a different stack. It does not walk on this lock.

---

## Status — 2026-09-15  Frame locked as the public build

| Item | Do not build as the first robot | Build this |
| :--- | :--- | :--- |
| Structure | Soft doll skeleton, no motors | **Aluminum tube / plate biped** |
| Actuators | Mystery “humanoid kit” with no torque math | **Named hobby digital servos, listed on the card** |
| Gait | Closed-loop AGI walk | **Open-loop script. C-3PO wobble is the bar** |
| Brain | Cloud girlfriend app | **MCU gait player.** Jetson is optional and later |
| Mass | 32 kg silicone on day one | **8–14 kg bare frame.** Flag >16 kg |
| Claim | “She walks” | **Ten steps, flat floor, or write boom-on** |

Nothing is a walking robot until the Frame table in `MEASUREMENT_CARD.md` is filled. Blank card = parts on a bench.

---

## What you are building

1. A 160–168 cm rigid biped armature.
2. Hip / knee / ankle pitch first. Hip roll when you need the weight shift.
3. A fused pack, an E-stop that kills servo enable, a gait script on an RP2040 / Pico / Mega.
4. Ten steps. Then a coat of paint if you want the protocol-droid look.

Optional tracks (not required for C-3PO):

- `PHASE0.md` — local voice box on a nightstand.
- Path 1 in `DESIGN.md` — bought soft shell hung on a finished frame. Adult-only. Poseable. **Does not walk.**

---

## Files

- `FRAME.md` — locked envelope and success tests
- `BUILD.md` — cut → wire → script → step
- `MIN_PARTS.md` — buy list for one bare droid
- `MEASUREMENT_CARD.md` — fill this or do not say it walks
- `DESIGN.md` — version ladder
- `LOCKS.md` — what must not get mixed
- `text` / `text.txt` — BOM + netlist
- `PHASE0.md` / `CONSTITUTION.md` — optional brain / later hang

## Technical Documentation

* [Master Design Document](MASTER_DESIGN.MD) — System architecture, mechanical mounting interface, dynamic load margins, and CAN bus topology.
* [Dimension Sheet](DIMENSION_SHEET.MD) — Dimensional envelope, joint torque ratings, mass breakdown, and ZMP reference specifications.

