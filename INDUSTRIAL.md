# INDUSTRIAL.md — silicone-capable Unit-1 chassis (not the public kit)

Design owned by Craig. Started 2026-09-17.
This file is the **industrial hang**: a stand-locked, adult, platinum-silicone body
that a human can touch, heat, clean, and talk to.

It is **not** `FRAME.md`.
It is **not** a walking protocol droid.
It does **not** inherit the hobby-servo gait.

Public kit stays: rigid aluminum biped, 8–14 kg, DS-class servos, open-loop shuffle.
This file is what you build when the goal is a real silicone sexdoll skin and
everything that skin needs to stay safe, serviceable, and warm.

UBHP-1 closed-loop / dressed-walk numbers stay in `VISION.md` if present.
DittoBot 25 mm / Phase 0 20 mm / coil / cap-dump numbers stay in
`Triforceninja420/DittoBot`. Do not paste them here.

---

## Split (do not mix)

| Stack | What it is | Walks? |
| :--- | :--- | :--- |
| Public Frame | `FRAME.md` — C-3PO-style shop droid | Only after Frame card |
| Light plates | PETG / foam / vac-form < 2 kg | Yes, if ten-step retest passes |
| Optional shell notes | `OPTIONAL_SHELL.md` — research hang | **No** |
| **Industrial (this file)** | Stainless / yoga-class skeleton + platinum silicone + 12 V heat + local brain | **No** |

No companion language until the Industrial tables on `MEASUREMENT_CARD.md`
(and the rows at the bottom of this file) are filled.
Childlike sculpt or voice is not a variant.

---

## Why a separate chassis

A 160–168 cm platinum-silicone body is **32–38 kg dressed** if you do it
the factory way (foam core + silicone skin). Full-pour silicone with no foam
can blow past **50 kg**. Hobby 25–40 kg-cm servos are not a load path for that.

Industrial Unit-1 therefore:

1. Uses a **poseable metal skeleton rated for the dressed mass**, not the Frame tube.
2. Hangs **skin as a cover / cast**, not as structure.
3. Stands on a **locked stand or foot-bolted base**. Knees may ratchet-lock in
   extension. They do not shuffle.
4. Puts heat, tactile, sleeves, and the local brain on a **12 V fused bus**
   with hardware cutouts the LLM cannot override.

If you already built the public Frame, leave it as the droid.
Do not bolt 30 kg of silicone onto it and call that industrial.

---

## Rules that do not move

- Adult-only. Operator **18+**. Appearance **25+**. No childlike face, body, or voice.
- Skin-contact cap **41 °C**. Firmware drop at 41 °C. Hardware fuse **≤ 45 °C**.
- Sleeve / tunnel internal cap **42 °C** hardware, firmware ~40 °C.
- Human-contact interrupt **35 N** on any clamp, pinch, close, or suction actuator.
- Soft safety skin (or the silicone itself with a documented interlayer) on every
  human-proximate surface that has a heater or motor behind it.
- Bus for this hang: **12 V** heaters / compute brick, fused. **GFCI** on every
  wall supply. Never mains in the pelvis, torso, or head.
- Skills / LLM cannot override E-stop, brownout, heater fuse, or the 35 N interrupt.
- Cloud girlfriend is not the chassis brain. Local-first. WAN opt-in and off.
- Water-based lube only on platinum silicone. Silicone lube swells silicone.
- Cavities get washed **and fully dried**. Trapped water rusts joints from the inside.
- Unattended heat is off. Unattended clamp / sleeve motors are off.
- This stack does not walk. Pose and stand-lock only.

---

## Locked envelope (industrial)

| Item | Locked value |
| :--- | :--- |
| Height | 160–168 cm preferred (shares the Unit-1 envelope) |
| Dressed mass | **32–38 kg** target. Flag **>42 kg**. Hard stop planning at 50 kg |
| Structure | Stainless articulated skeleton (201 / 304 class) **or** no-weld alloy of equal rating. Yoga / EVO / standing-foot class |
| Skin | Platinum-cure silicone. TPE is prototype-only and off the industrial SKU |
| Core | Closed-cell foam wrap on the skeleton + silicone skin. Full-pour solid silicone is a mass flag |
| Walk | **Forbidden** |
| Stand | Foot-bolted base and/or dedicated stand. Ankle and knee must take dressed weight without folding |
| Heat | Zoned 12 V graphene or silicone pads. NTC on the **skin-facing** side of each zone |
| Sense 
... 