# FAILURES.md — Unit-1 known failure modes

Design owned by Craig. Public kit. 2026-09-15.

This file lists the ways the frame fails so builders can plan around them.
It does **not** change locked numbers in `FRAME.md` or `DESIGN.md`.
It does **not** mix DittoBot latch or coil numbers into the hips.

---

## 1. Pack sag mid-step

**What happens**
Battery voltage drops under load. Servos lose torque. The swing foot plants late or short. The frame tips forward or sideways.

**Why**
Hobby digital servos draw peak current at stall. A sagging LiPo or weak BEC cannot hold the rail.

**Mitigation**
- Use a pack rated for the stall current of all active servos at once.
- Add a low-voltage cutoff that freezes the gait in the squat/lock position.
- Keep the servo rail fused and separate from logic.
- Log pack voltage during the first ten steps. Write the number on the card.

**Locked behavior**
If voltage sags, the gait freezes in squat/lock. Voice may stay on. This is the safe-reserve state from `DESIGN.md`.

---

## 2. Servo strip or gear failure

**What happens**
A servo gear strips under repeated load. The joint goes soft. The frame collapses on that side.

**Why**
Hobby servos are not rated for continuous humanoid duty. Plastic gears fatigue. Metal gears are better but still finite.

**Mitigation**
- Prefer metal-gear servos for hip and knee.
- Do not run servos at stall for more than a few seconds.
- Add a mechanical stop or hard limit so the joint cannot over-travel.
- Replace stripped servos immediately. Do not "limp" on a failed joint.

**Locked behavior**
A stripped servo is a hard stop. No walk claim until it is replaced.

---

## 3. Open-loop gait drift

**What happens**
The scripted step sequence drifts over time. Steps get shorter or longer. The frame walks in a curve or tips.

**Why**
Open-loop means no feedback. Small timing errors accumulate. Floor friction varies.

**Mitigation**
- Keep the first ten steps short and deliberate.
- Use a boom for early testing. Write "boom-on" on the card.
- Add an IMU log so you can see the drift after the fact.
- Do not claim a walk until ten consecutive steps are clean on a flat floor.

**Locked behavior**
Boom-assisted steps are allowed for testing. They are not a walk claim.

---

## 4. E-stop failure

**What happens**
The E-stop does not cut servo enable. The frame keeps moving after you hit the button.

**Why**
Software E-stop is not enough. A hung MCU or bad wiring leaves servos powered.

**Mitigation**
- E-stop must be hardware. It cuts the servo enable line directly.
- Test it before every session. Time it. It must drop enable in under 200 ms.
- Never rely on an app button or software halt as the primary E-stop.

**Locked behavior**
Hardware E-stop on servo enable is mandatory. Software halt is extra.

---

## 5. Mass creep

**What happens**
The bare frame ends up over 14 kg. Servos cannot hold it. The walk claim fails.

**Why**
Extra brackets, longer tubes, or a heavier pack push the mass past the envelope.

**Mitigation**
- Weigh every part before assembly.
- Flag anything over 16 kg on the card.
- Do not add a soft shell until the bare frame walks clean.

**Locked behavior**
Bare mass 8–14 kg. Flag >16 kg. Heavy soft shell does not walk on this coupon.

---

## What this file does not cover

- Closed-loop balance failures (not this coupon)
- DittoBot voxel latch failures (different repo)
- Soft-shell or companion failures (see `OPTIONAL_SHELL.md`)
- Exact servo brand or tube size (not locked)