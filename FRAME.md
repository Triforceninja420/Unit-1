# FRAME.md — public C-3PO coupon

Design owned by Craig. Locked 2026-09-15.

Anyone can build this. It is a protocol-droid armature, not a product claim about a dressed human.

Rigid biped. Hobby servos. Open-loop gait. Wobbly C-3PO demo.
The shell hangs on later. The shell is not this coupon.

---

## Why this cut

The metal skeleton is the only piece with real engineering:

- load paths
- joint axes
- servo torque vs limb mass
- a step script that does not fall over on tile

Paint, cape, voice, and any soft cover are costumes.

---

## Locked envelope

| Item | Locked value |
| :--- | :--- |
| Form | Rigid biped, adult proportions, 160–168 cm |
| Structure | Aluminum tube / plate, or printed joint blocks on metal spars |
| Actuation | Hobby digital servos. Position control. Open-loop gait |
| Quality bar | Ten consecutive steps on a flat floor. Wobble allowed. C-3PO |
| Balance | No force-torque ankles. No ZMP stack on this coupon |
| Bare mass | **8–14 kg** including servos + pack. Flag if >16 kg |
| Shell | Off for the walk claim |
| Dressed / 32 kg walk | Forbidden on this coupon |
| Human path | E-stop on servo enable. Boom optional; write it on the card |
| Bus | 6–8.4 V servo rail and/or 12 V. Fused |
| Brain | MCU gait player. Jetson not required to walk |

## Joint set (minimum demo)

| Joint | Side | Notes |
| :--- | :--- | :--- |
| Hip pitch | L/R | Primary step |
| Knee pitch | L/R | |
| Ankle pitch | L/R | Cheap first-order fall stop |
| Hip roll | L/R | Weight shift. May start locked |
| Shoulder pitch | L/R | Arm swing / counterweight. Dummy arms allowed |
| Elbow | L/R | Optional |
| Waist | 0–1 | Optional. Adds wobble if early |

Head can be a bucket. Fancy face motors are a different stack.

## Open-loop gait

Scripted sequence, no vision required:

1. Shift COM over the stance foot (hip roll or a lean stop).
2. Lift swing foot (hip + knee).
3. Plant.
4. Other side.

IMU may log. IMU does not have to stabilize the first ten steps.
Boom-assisted steps are allowed. They are not a walk claim. Write boom-on.

## Success tests

1. Bare frame stands 60 s on servo-hold or mechanical lock, no boom.
2. Ten steps, flat floor, no boom — or the card says boom-on.
3. E-stop drops servo enable in < 200 ms.
4. Mass, servo list, stall current, pack voltage on the Frame table.
5. No companion language on a blank card.

## What this file does not do

- Does not make hobby servos a closed-loop humanoid
- Does not set torque for a heavy soft shell
- Does not mix DittoBot latch numbers into hip joints
- Does not require a nightstand LLM to take a step
