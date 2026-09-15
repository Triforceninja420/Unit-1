# DESIGN.md
Project: Unit-1 / Companion Chassis
Inventor: Craig Edward Ralls
Status: Paper baseline, Path 1 locked
Date: 2026-09-15

## 1. Core architecture (all versions)

- Heterogeneous modules: Chassis / Intimate cartridge / Compute
- 12 V nominal power bus. Logic stays 5 V / 3.3 V. Never put mains in the pelvis
- 5-state session machine: Idle → Preheat → Attend → Intimate → Cleanup (+ Fault)
- Safe-reserve rule: if pack SOC or thermal headroom drops below threshold, heaters and sleeve motors drop, voice can stay
- Layered interlocks: nape E-stop, hardware mic mute, heater thermal fuse, 35 N interrupt
- Soft safety skin on any human-proximate surface that has a heater or a motor behind it
- Adult face, adult voice, adult constitution. Child / pet / public-demo use is not a version

Carry-forward from DittoBot companion gates (`DittoBot/LOCKS.md`, 2026-09-14):
35 N human-contact interrupt ≠ 40 N docked shear.
41 °C skin cap.
No companion claim on a blank measurement card.
Skills / LLM cannot override E-stop, brownout cutoff, or heater/motor fire interlock.

## 2. Version ladder

**V0.9 Phase 0 — Lab coupon (now)**
Nightstand brain + one heater pad + one FSR + local voice loop. No body required. Prove latency, 41 °C cap, E-stop, mute.

**V1.0 Phase 1 — Pelvic cartridge**
Removable sleeves + optional suction/heat dock on the bench. Prove wash/dry cycle, leak-down, 42 °C sleeve cutout.

**V1.1 Phase 2 — Bought chassis integrate**
Platinum silicone body, EVO skeleton, stand, spine loom, nape E-stop, zoned heat, 8–10 FSRs. Static or robotic head.

**V1.2 Phase 3 — Owned brain on-body**
Jetson in waist bay or umbilical. Local memory. Factory cloud is a disabled option, not the soul.

**V2.0**
Not this repo. Not a walk claim. Not a DittoBot swarm skin.

## 3. Locked envelopes (Path 1)

| Item | Locked value |
| :--- | :--- |
| Height | 160–168 cm preferred (4'10" Harmony-class accepted if lift matters) |
| Mass | 32–38 kg target; flag if >42 kg |
| Skin | Platinum-cure silicone. TPE is prototype-only |
| Skeleton | Stainless EVO / yoga class, neck lock for a robotic head |
| Soft tissue | Gel breasts + gel glutes |
| Orifices | Removable platinum sleeves, vaginal + anal separate |
| Heat rail | 5–12 V DC only |
| Skin contact cap | **41 °C** |
| Sleeve internal cap | **42 °C** hardware fuse, firmware 40 °C |
| Human interrupt | **35 N** on any closing / clamping actuator |
| Walk | **Forbidden on this stack** |
| Bus | 12 V chassis, fused per rail, GFCI on wall bricks |
| Brain default | Local. Cloud is opt-in lookup |
| Age class | 25+ appearance, 18+ operator |
