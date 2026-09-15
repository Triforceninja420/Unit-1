# PHASE0.md — Unit-1 first hardware target

**This file is the locked bench coupon.**
It is **not** the full body. It is **not** DittoBot Phase 0.

Design owned by Craig. Started 2026-09-15.

Status: frozen until voice-loop / heat / E-stop / mute numbers are published on `MEASUREMENT_CARD.md`.

## What Phase 0 is

One brain box. One heater coupon. One force pad. Prove the loop that later lives in the waist.

| Item | Locked value |
| :--- | :--- |
| Compute | NVIDIA Jetson Orin Nano Super 8 GB (budget) or Orin NX Super 16 GB (preferred) |
| Voice | Local VAD + Faster-Whisper + ≥3B Q4 LLM + Piper/Kokoro |
| Greeting latency | **< 0.7 s** cached |
| Normal reply | **< 3.0 s** local, no WAN |
| Heater coupon | 12 V graphene or silicone pad, ≥80 × 80 mm, NTC on the skin-facing side |
| Skin cap | **41 °C** at the coupon face, 30 min soak |
| Cutout | Firmware drop at 41 °C, hardware fuse ≤ 45 °C |
| Sense | One FSR or load cell, log newtons |
| Interrupt | Software halt at **35 N** on that pad if a clamp is later attached; Phase 0 only has to log N |
| E-stop | Momentary on a tether. Kills heater enable + any motor PWM. Mics optional |
| Mic mute | Hardware switch, scoped or LED-verified |
| Network | Default down. Measurement card says WAN up/down |
| Body | Not required |

## Electrical (Phase 0)

```
[wall, GFCI]──► 12 V brick ──┬── Jetson carrier (official barrel / PD only)
                             ├── heater MOSFET + fuse + NTC
                             └── E-stop cuts MOSFET gate + motor PWM

[mics]──► USB or I2S ──► Jetson
[speaker]◄── amp ◄── Jetson
[FSR]──► ADS1115 / MCU ADC ──► USB serial ──► Jetson
```

Do not feed the Jetson from a random 12 V tap without the carrier’s specified input.
Do not put the 12 V heater across a 5 V pin.
DittoBot XIAO + DRV8871 + Ø6 disc is a different coupon. Do not reuse that netlist here.

## Success criteria (Phase 0)

1. Local greeting < 0.7 s, WAN unplugged.
2. 10-turn conversation, memory of turn 2 still present at turn 10.
3. Coupon face holds 36–38 °C, never >41 °C on the logged NTC.
4. E-stop drops heater within 200 ms.
5. Hardware mute stops STT.
6. Card filled. Then and only then may Phase 1 start.
