# MIN_PARTS.md — Phase 0 kit

Project started 2026-09-15. Design owned by Craig.
Human-proximate companion chassis. Not DittoBot.

**This list is only for the bench coupon.**
Not a body. Not a lattice. Not Phase 0 of the 20 mm face.

Fill `MEASUREMENT_CARD.md` with whatever this kit measures. No companion claim until that card is filled.

## Buy or borrow

| # | Item | Spec | Why | Skip / substitute |
| :--- | :--- | :--- | :--- | :--- |
| 1 | Jetson | Orin Nano Super 8 GB + official carrier / NVMe | Local STT+LLM+TTS | A LAN box with a used 3090/4090 is a legal substitute and better for V1.2 prose |
| 2 | 12 V brick | Mean Well-class, GFCI upstream, ≥150 W if heaters come later | Heat rail + tools | Laptop PD only runs the brain, not the pads |
| 3 | Heater coupon | 12 V graphene film or silicone pad + NTC 10k | 41 °C cap is a measured number | Hair-dryer is not a coupon |
| 4 | MOSFET + fuse | Logic-level N-FET, 5–10 A fuse on the pad | E-stop has something to cut | Relay is fine for Phase 0 |
| 5 | E-stop | NC momentary or latching mushroom on a tether | Human path | Software button is not E-stop |
| 6 | Mic mute | Physical switch on the mic V+ or line | Privacy | Mute in PulseAudio is not the lock |
| 7 | Mic + speaker | USB mic array + 5–10 W speaker | Voice loop | Headset is fine on the bench |
| 8 | FSR | Interlink 402 or 406 + 10 k divider | Newton log | Kitchen scale under the pad works for the first card |
| 9 | Storage | 256 GB+ NVMe | Models + encrypted memory | SD card is a prototype only |

## Do not put on this order

- DittoBot Phase 0 parts: IRLZ44N cap-dump, 220 µF / 30–36 V, Ø5 EPM, 1.8 mm pin, Pico netlist
- 25 mm cell parts: Ø6 stack, AWG 36 latch coil, DRV8871 as a body actuator
- TPE full body as the keeper chassis
- Childlike sculpt, voice, or clothing
- Any walk / balance platform
- Cloud personality subscription as the primary brain

## Bench order

1. Flash Jetson. Models on disk. Airplane mode.
2. VAD → STT → small LLM → TTS. Fill latency boxes.
3. Wire heater + NTC + FET + E-stop. 30 min soak.
4. Log FSR.
5. Paste numbers into `MEASUREMENT_CARD.md`.
6. Only then order a body.
