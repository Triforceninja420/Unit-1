# VISION.md — UBHP-1 (north star, not the public build)

> Banner: This is a design brief and long-term architecture sketch. It is not the public Unit-1 build. It is not Path 1. It is not a walk claim. No measurement card is filled. No validation has been performed. Status on X and in-repo: not validated. Parked here so the better-leg ideas survive without overwriting `FRAME.md` or breaking the no-walk lock.

## What to keep from the old UBHP-1
- Hip pitch / hip roll split (sagittal stride vs lateral splay).
- Knee with a zero-power electromagnetic holding brake + active bus chopper (regenerative spike protection).
- Ankle as 2-DOF pushrod gimbal with double-shear clevises.
- Foot 4-zone FSR matrix at 1 kHz for ground reaction (correct sensor for a waddle).
- Dual-durometer skin with accordion pleats in flexure zones (later, after the frame walks).

## What stays out of day-one Unit-1
- ZMP preview controller at 200 Hz.
- Jetson AGX Orin 64 GB.
- Harmonic drives at 35/85 N·m.
- 6S 10 Ah pack + full PDN.
- Any validated or hardened language.

Those belong to a funded, measured build — not the coupon.

## Leg v2 coupon (single joint class, one at a time)
1. Knee pitch + brake on a stick. Match the 8–14 kg bare-frame target with a hanging weight.
2. Log stall current, hold-with-brake-at-zero-drive, back-EMF dump into the 1.5 Ω ballast.
3. Then a single hip-roll weight-shift coupon.
4. Fill the Frame table before any walk language.

This is the same discipline as DittoBot Phase 0: one joint class, one card, then the next.

## Frozen numbers carried forward (paper only, unmeasured)
Mass budget (paper): \~35.6 kg total, CoG \~540 mm. These are targets, not measurements.

Replaces the old `UBHP-1` file. The old file is retired; do not reintroduce Validated System Specification anywhere in this repo.