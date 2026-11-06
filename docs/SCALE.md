# SCALE.md — which machine this repo is

Locked 2026-09-20.

This tree builds **one** robot. Firmware, CAD numbers, and the README table must agree.

## Active product (firmware + `cad/`)

| Item | Value |
| :--- | :--- |
| Class | 1/3–1/4 scale articulated endoskeleton |
| Height | 450–600 mm |
| Bare mass | 1.2–1.8 kg skeleton, no skin |
| Leg links | L1 = L2 = 110 mm (`EndoskeletonConfig`) |
| Stance IK target | x = −15 mm, y = −200 mm |
| DoF this loop | 12 lower-body IDs mapped; stand loop drives pitch + roll |
| Walk claim | None. Open-loop stand + PD trim only |
| Skin | Later. Not a walk or stand claim |

If you change L1/L2, change the stance target and this table in the same commit.

## Archived envelope (docs only)

`FRAME.md` still describes a 160–168 cm, 8–14 kg protocol-droid coupon.
That is **not** what `firmware/` compiles.
Do not mix those mass/height numbers into `config.h`.

## Not this repo

DittoBot 25 mm voxel latch lives in `Triforceninja420/DittoBot`.
Do not paste EPM / 40 N coupon numbers here.
