# OPTIMUS_MAP.md — public Tesla numbers vs Unit-1 coupons

Design owned by Craig. Locked 2026-09-20.
Research map only. This file does **not** change `FRAME.md`, does **not**
mint a walk claim, and does **not** put 50 forearm actuators on a hobby servo.

Use it when you want the industrial skeleton to *aim at* published Optimus
geometry and actuator *classes*. Do not treat Tesla as a BOM.

DittoBot 25 mm / Phase 0 20 mm / coil numbers stay in
`Triforceninja420/DittoBot`. Do not paste them here.

---

## Split (do not mix)

| Stack | Mass / height | Walk? | This file’s job |
| :--- | :--- | :--- | :--- |
| Public Frame | 8–14 kg, 160–168 cm | Open-loop ten-step after card | **Leave alone.** Not a 3.3× scale-up |
| Industrial hang | 32–38 kg dressed, 160–168 cm preferred | **No.** Stand / pose. W0–W5 research | Touchable platinum body |
| Optimus-class walker (later SKU) | ~57 kg *bare metal + pack* class, 173 cm | Closed-loop, brakes, proven **bare** first | Target numbers only |
| Hands | Forearm tendon pack | Not a gait coupon | Copy the *architecture*, not 50 actuators on day one |

Three different machines. Frame is the shop droid. Industrial hang is the
sexdoll you can heat, clean, and talk to. Optimus-class is a third chassis
if you ever buy real linear/rotary units and a local balance loop.

Do not scale the Frame by “three point three” to hit 173 cm. The Frame
envelope is already adult-scale. Mid-stack in `FRAME.md` is already
~171 cm (foot + shank + thigh + torso + head).

---

## Public targets (treat as published / widely reported, not a Tesla license)

Gen 2 body is the copyable envelope. Gen 3 hands are the moving target.
Numbers disagree across blogs; prefer the cluster below.

| Item | Use this | Notes |
| :--- | :--- | :--- |
| Height | **173 cm** | Gen 2 locked public figure |
| Bare mass | **~57 kg** | Metal + actuators + pack. Early quotes 73 kg. Not your dressed silicone mass |
| Body DOF | **28** | Common split: 14 rotary + 14 linear |
| Body actuators | **28** | Hands are extra |
| Hands (Gen 2) | 11 DOF / hand | Older public hand |
| Hands (Gen 3 claim) | **22 DOF / hand**, **25 actuators / forearm**, tendons, actuators in the forearm | 50 hand/forearm actuators for the pair |
| Payload | **20 kg** carry | Deadlift / 68 kg figures are rumor. Do not put 20 kg pinch in a platinum fingertip |
| Shoulder width | **~44 cm** | Human-ish, not protocol-narrow |
| Arm length | **~62 cm** shoulder to wrist | |
| Inseam (clothes) | **~82 cm** | Pants measure. Hip-axis-to-floor is taller than inseam |
| Pack | ~2.3 kWh class, torso | Not the industrial 12 V heat brick |

Unit-1 industrial dressed **32–38 kg** is foam + platinum on a pose skeleton.
Optimus **57 kg** is a walking actuator farm. Adding skin on top of a 57 kg
bare walker is a fourth mass problem. Do not plan that until W5 exists.

---

## Geometry freeze if you aim at 173 cm

Protocol-droid *look* wants a narrow pelvis (`FRAME.md` hip–hip 180–220 mm).
Companion *look* wants human hips under silicone. Pick one skeleton.

| Segment | FRAME.md now | 173 cm companion-ish freeze | Notes |
| :--- | :--- | :--- | :--- |
| Height | 160–168 cm | **173 cm** | Industrial hang may stay 160–168; walker SKU can grow |
| Foot | 180–220 mm | 220–250 mm | Wide enough to stand. Rubber on the plate |
| Shank (knee–ankle) | 380–420 mm | **390–410 mm** | |
| Thigh (hip–knee) | 380–420 mm | **410–430 mm** | |
| Pelvis width hip–hip | 180–220 mm protocol | **260–300 mm** companion | Narrow = C-3PO. Wide = hips that fill platinum |
| Torso hip–shoulder | 450–500 mm | **480–520 mm** | Cage must hang breast mass + pads |
| Shoulder width | (narrow protocol) | **~440 mm** | |
| Upper arm | 250–280 mm | 280–310 mm | |
| Forearm + hand | 280–320 mm | to **~620 mm** arm total | Tendon pack lives here |
| Head + neck | 220–260 mm | 230–260 mm | Service module. Nape E-stop |

CoM for W0: write dressed mass, CoM height above floor, and foot polygon
on `MEASUREMENT_CARD.md`. Guessing “Optimus is 57 kg therefore hip torque
is X” without your CoM is fanfic.

---

## Joint-by-joint body map (28 DOF)

Linears for long-stroke pitch/roll where you want force and hold.
Rotary for yaw and compact swing. Holding **brake** on every load joint
that must not fold when PWM dies.

| # | Joint | Optimus-like type | Frame now | Industrial now | W-gate / buy class |
| :--- | :--- | :--- | :--- | :--- | :--- |
| 1–2 | Neck pitch / yaw | Rotary ×2 | Optional 1 yaw hobby | Friction neck | Small rotary + brake. E-stop lives at nape |
| 3–4 | Lumbar pitch + yaw | 1 linear + 1 rotary | Rigid torso | Segmented column, mostly locked | Optional. Skin tears at clavicle if the cage is weak |
| 5–8 | Shoulder pitch + roll ×2 | Pitch often linear; roll rotary | 2× hobby pitch | Friction shrug + rotate | First expensive pair. Hold arm + skin + gel |
| 9–10 | Humeral rotation ×2 | Rotary | Missing | Partial | Needed before a real hand |
| 11–12 | Elbow ×2 | Linear or high-ratio rotary | Optional hobby | Friction | Linear is the copy |
| 13–14 | Wrist flexion ×2 | Linear in forearm | Dummy | Dummy | With the tendon pack |
| 15–16 | Wrist deviate / rotate ×2 | Rotary | Dummy | Dummy | With the tendon pack |
| 17–18 | Hip pitch ×2 | **Linear** | 25–40 kg-cm hobby | Friction / ratchet | **W4.** Hobby dies under dressed moment |
| 19–20 | Hip roll ×2 | Linear or rotary | 20–35 kg-cm hobby | Weak / lock | **W4.** Balance, not cosmetics |
| 21–22 | Hip yaw ×2 | Rotary | Missing | Missing | Needed for anything but a shuffle |
| 23–24 | Knee ×2 | Linear | 25–40 kg-cm hobby | Ratchet lock | Hold + brake in extension. 180° fold fights silicone thickness |
| 25–26 | Ankle pitch ×2 | Linear | 20–35 kg-cm hobby | Standing foot, bolt-down | FSR / wrench before any free-walk language |
| 27–28 | Ankle roll ×2 | Rotary or small linear | Missing / lock | Bolt plate | Cheap to skip; expensive if you want no boom |

Hands are **on top of** these 28, not inside them.

---

## Hands (architecture only)

Public Gen 3 story: 22 DOF per hand, 25 actuators per forearm, mass in the
forearm, tendons to the fingers, tactile tips. Human hand ~27 DOF.

Buildable copy for this project:

1. Do **not** put 25 motors in a platinum palm.
2. First useful pack: **4–8** forearm units (thumb opposition + grouped
   finger flex + one wrist). That is a touch / later-chore hand.
3. 22 DOF is a second career after I5 + T4 + a dry tendon story.
4. Tendons in coated / bowden conduits. Raw steel in a wet tunnel seizes.
   Wash **and dry**. Water-based lube only on platinum.
5. Fingertip FSR before more DOF. **35 N** halt on any close that can pinch.
6. 20 kg payload is an arm + torso carry. Not a fingertip pinch spec.

Lane D chores stay parked until hands + W5 + 35 N exist
(`PIPELINE.md`). A pretty hand on a stand-locked hang is still a talking body.

---

## Order (does not weaken public locks)

1. Leave `FRAME.md` at 160–168 cm, hobby, ten ugly steps.
2. Industrial hang through **I5 + T4**: stand-lock, 41 °C skin, 42 °C sleeve
   hardware, local voice, hygiene. This is the body you can use.
3. **W0–W1** on that skeleton: dressed mass, CoM, sole FSR. No new motors.
4. **W2–W3**: hoist / boom, ≥50 % weight-share assisted plants. Motion, not walk.
5. **W4**: new hip / knee / ankle class sized from *your* card, with brakes,
   fused motion bus, stall-A row. Not DS-class. Not DittoBot EPM.
6. Forearm tendon pack on the stand-locked body in parallel with talk.
7. **W5**: local IMU + sole fusion. Cloud girlfriend is never the balance loop.
8. Attachable platinum goes back on only after a written **bare** step protocol.

Safety that does not move: adult-only, appearance 25+, 35 N interrupt,
41 °C skin cap, 42 °C sleeve hardware, 12 V fused heat/compute, GFCI on
wall, local brain, no unattended heat or clamp, no dressed free-walk on
open-loop hobby servos.

---

## What this file is not

- Not a Tesla BOM, patent license, or “build Optimus” kit
- Not a change to Frame torque or mass
- Not permission to hang 32–38 kg silicone on DS servos
- Not a walk claim, even if a joint table looks complete
- Not DittoBot

Next useful page after this map: hip / knee / ankle moment from a filled
W0 row (dressed kg × CoM height × single-support), then a shoppable W4
actuator class. Do not shop from the 57 kg column until that row exists.
