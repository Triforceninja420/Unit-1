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
| Sense | FSR / piezoresistive pads. Log newtons. Software halt at 35 N if a clamp exists |
| Intimate parts | Removable platinum sleeves / cartridges. No permanent plumbing on the chassis |
| Brain | Local (Pico for heat/FSR; Jetson only after Phase 0 voice card). Cloud off by default |
| Contact | Nape E-stop. 35 N interrupt. Mute switch on mics |
| Appearance | Adult. Your face / your sculpt. No licensed likeness |

---

## Two legal build paths

### Path A — factory body, industrialize it

Buy a 160–168 cm **platinum silicone** doll with an EVO / yoga / standing-foot
skeleton. Do not buy TPE and pretend it is this file.

Then add, without cutting load tubes:

- nape E-stop tether
- 12 V zoned heat with NTC + hardware fuse
- one FSR coupon, then a small grid
- local voice box (umbilical first)
- removable sleeves if the factory tunnels are not already serviceable
- a real stand / hoist — 35 kg is dead weight

Factory foam + silicone sandwich is the mass plan. Do not pack the cavities
with extra gel until the card has a dressed-mass row.

### Path B — shop chassis, bought or cast skin

Build the skeleton yourself or have a fabricator weld / bolt it.

- 201 or 304 stainless tube, ~1.6–3 mm wall on load members (spine, thighs, shins)
- friction or gear joints at neck, shoulders (shrug + rotate), elbows, wrists,
  lumbar, hips, knees (double-gear or ratchet lock for stand), ankles
- manganese-steel or equivalent washers; lock the joint preload and write it on the card
- standing feet with **M10–M16** threaded inserts so the unit bolts to a floor plate
- foam wrap (closed-cell) bound to the skeleton so silicone never sees raw tube
- skin: bought hollow / zippered cover, or a cast you own the mold for
- service zipper or magnetic back plate at the nape / scapula so looms come out
  without destroying the pour

Path B is the one that looks like “industrial Unit-1.”
Path A is faster and usually better silicone than a first garage pour.

Do not mix Path B joints onto the public Frame coupon.

---

## Skeleton (the actual industrial robot)

The skin is cosmetics. The skeleton is the machine.

| Joint / member | Industrial requirement |
| :--- | :--- |
| Spine | Continuous load tube or segmented column. Cable loom **inside** or in a covered raceway. Not through raw silicone |
| Rib / torso cage | Enough structure to hang breast mass and heat pads without the skin tearing at the clavicle |
| Shoulder | Rotate + shrug. Rated for arm + skin + any gel insert |
| Hip | Rated for dressed torso. This is the joint that fails first on cheap dolls |
| Knee | Ratchet or high-friction. Must lock in stand. 180° fold is optional and limited by silicone thickness |
| Ankle / foot | Standing-foot class. Bolt pattern to a base plate. Rubber sole on the plate, not on raw silicone soles if you stand her often |
| Neck | Rotation + some tilt. Head is a service module. Nape E-stop lives here |
| Hands | Optional articulated. Dummy mitts legal on day one. Do not put 17 face servos on v1 |

Weld quality matters. Cheap doll welds crack at the hip. Prefer:

- documented weld procedure, or
- no-weld clamped / bolted joints with a published cycle test

Preload every friction joint after foam-wrap, because foam and silicone change
the feel. Log “joint still holds pose 10 min under dressed mass” on the card.

Rust rule: stainless is not a license to leave tunnels wet. Dry from the inside.

---

## Skin — platinum silicone, industrial not costume

| Item | Spec |
| :--- | :--- |
| Chemistry | Platinum-cure (addition-cure) silicone. Medical / body-safe pigment only |
| Not | Tin-cure, TPE, “silicone-feel” PVC, painted foam as the contact surface |
| Hardness | Zoned. Contact skin soft (roughly Shore 00-10 to Shore A 5–10). Load patches (soles, knees, scapula) firmer so the skeleton does not punch through |
| Thickness | Enough that a joint at end-stop does not print a square tube through the surface. Factories do this with foam + skin, not with 40 mm of solid gel everywhere |
| Surface | Non-porous. Powder when dry. No mineral-oil “wet care” (that is a TPE habit) |
| Color | Your call. Color-match the head if the head is a separate pour |
| Face | Separate head preferred so you can swap / repair without recasting a 35 kg body |
| Hands / feet | Optional separate pours. Easier to recast than a whole limb |

**Casting notes (Path B only, if you insist on pouring):**

- Vacuum-degas. Bubbles become pits you will hate.
- Skeleton must hang in the mold and **not kiss the tool face**. Exposed steel
  is a scrap body.
- Reserve tunnel cores. Do not cast a dead-end pocket you cannot wash.
- Cure per the silicone data sheet. Do not accelerate with a heat gun on the tool.
- First article: tear test on a coupon, Shore reading, and a 24 h odor check
  before it touches skin.

TPE is allowed only as a cheap fit-check dummy. It is not the industrial skin.
TPE oils, stains, and goes tacky. Do not write TPE numbers into the silicone card.

---

## How the skin actually hangs

Three serviceable patterns. Pick one and write it on the card.

1. **Factory pour around the skeleton** (Path A). Fast. Repair means a factory
   or a local recast of a limb. Add electronics only through existing neck /
   back ports or a new service zipper you plan before you cut.
2. **Zippered / panel cover** over foam. Best for a shop brain. Heat pads and
   FSR live on the foam, under the panel. You can take the skin off.
3. **Sectional body** — torso + limbs + head as separate platinum pieces with
   hidden fasteners at wrist / ankle / neck. Heavier design work. Best long-term
   repair story.

Do not glue a 30 kg skin shut over live 12 V pads with no service hatch.
That is how heaters become landfill.

Gel breast / hip inserts are optional and go **outside** the skeleton,
inside the skin. Weigh them. They count toward 32–38 kg.

---

## Heat (industrial, not a heating-pad on the bedspread)

Target feel is human skin, not a heating blanket.

| Zone | First pass | Notes |
| :--- | :--- | :--- |
| Chest / sternum | 1 pad | Highest value per watt |
| Lower belly | 1 pad | Keep clear of sleeve plumbing |
| Inner thigh (each) | 1 pad | Watch pinch at the hip fold |
| Back / nape | optional | Do not cook the compute brick |
| Head | optional, tiny | Face silicone is thin. Easy to overshoot 41 °C |
| Sleeves | separate circuit | 42 °C hardware cap |

Electrical:

```
[wall, GFCI]──► 12 V brick ──┬── compute (official input only)
                             ├── zone MOSFET + per-zone fuse + NTC
                             ├── sleeve MOSFET + fuse + NTC
                             └── E-stop cuts every MOSFET gate + any motor PWM
```

- NTC on the **skin-facing** side of the pad, under the safety interlayer.
- Firmware set-point ~36–38 °C. Drop at **41 °C**.
- Independent hardware fuse / bimetal **≤ 45 °C** per zone. Not “the LLM will notice.”
- 30 min soak on the card. Peak NTC must stay ≤ 41 °C.
- Preheat is a state. Intimate is a state. Do not leave preheat running.
- No mains heaters. No 120 V pads in the torso. No “set the controller to 60 °C
  and hope the skin is only 37.” Measure the skin.

Commercial doll heating rods that live in a tunnel are allowed **as a removable
tool**, not as chassis wiring. Unplug and remove before use. Same 41 / 42 °C caps.

---

## Tactile + interrupt

Start smaller than a 64-channel fantasy grid.

1. One FSR coupon. Calibrate newtons vs ADC. Write the curve on the card.
2. Then a small grid on chest / hip / inner thigh — the places a human actually
   touches.
3. If you add a clamp, sleeve motor, or closing actuator, **software halt at 35 N**
   and a hardware path that drops PWM when that halt fires.
4. Optional chest “pulse” cue: low-force haptic or LED/audio metronome.
   Not a medical device. Not a heartbeat claim. Under the 35 N cap.

The silicone is the comfort layer. The FSR is the log. Do not use the skin tear
as your force sensor.

---

## Intimate cartridges

Permanent holes you cannot wash are a hygiene failure, not realism.

- Removable platinum sleeves or factory tunnels with a documented wash path.
- Water-based lube only.
- Wash, rinse, **dry**. Leak-down **30 min** on the card.
- Sleeve heater is a separate fused circuit. 42 °C hardware cutout.
- No pumps, reservoirs, or warm-fluid loops on v1. That is how you grow mold
  in a pelvis.
- Clamp / suction peak force on the card. 35 N cap.

Sleeves are parts. They go in a wash bin. They do not live on the Frame rail.

---

## Stand, floor, and handling

35 kg of floppy silicone is a shop-injury problem.

- Dedicated stand that takes pelvis or foot bolts. Do not balance her on
  raw silicone soles for storage.
- Standing-foot M10–M16 bolts into a steel plate if she stands free.
- Two-person lift, or a hoist with wide padded straps under the torso cage —
  never lift by a wrist or by the silicone breast.
- Storage: neutral pose, joints not on end-stop, dry tunnels, sheet or bag
  that does not stain. Cool room. No car trunk, no attic.
- Flag dressed mass on the wall next to the stand so you do not “just pick her up.”

---

## Brain and voice

Industrial does not mean cloud girlfriend.

| Layer | What runs it |
| :--- | :--- |
| Heat + FSR + E-stop | MCU. Deterministic. No network |
| Voice | Local VAD + STT + ≥3B Q4 LLM + Piper/Kokoro after `PHASE0.md` card |
| Session machine | Idle → Preheat → Attend → Intimate → Cleanup (+ Fault) |
| Safe-reserve | Pack or thermal headroom dies → heaters and sleeve motors drop. Voice may stay |
| WAN | Off. A down row must exist on the card before an up row is allowed |

Do not block the safety MCU on a token stream.
Do not let a voice pack raise a heater set-point.
Load an adult register of `CONSTITUTION.md` only when this hang is the active body.
Do not mix the polite shop-droid register into an intimate session.

Phase 0 still has to pass before a Jetson lives in the waist.

---

## Hygiene and care (this is part of the machine)

| Task | Industrial rule |
| :--- | :--- |
| External wash | Mild soap, warm water. Silicone can take warmer water than TPE; still keep it sane. No solvents, no acetone, no household degreaser |
| Tunnels | Flush, rinse, dry until the entrance is dry. Then the 30 min leak-down |
| Dry | Air + absorbent sticks. Do not trap a wet heating rod in a tunnel overnight |
| Powder | On **dry** silicone only. Cornstarch or the powder the silicone vendor names |
| Lube | Water-based. Never silicone oil on silicone skin |
| Storage | Dry, cool, unposed-extreme, covered |
| Inspection | Monthly joint squeak / rust, seam tears, exposed tube, frayed loom, NTC that reads ambient when the pad is on |

A dirty tunnel is a failed build. Put wash+dry time on the card like it is a spec.

---

## Electrical + safety box (copy this)

```
[GFCI wall]──► 12 V brick (named, measured)
                 │
                 ├─ F_main (sized to brick)
                 ├─ ESTOP (nape + tether) ── cuts heater FET gates + motor PWM
                 ├─ MCU (heat, FSR, halt)
                 ├─ compute (official barrel / PD only, after Phase 0)
                 ├─ zone pads (FET + fuse + NTC each)
                 └─ sleeve circuit (FET + fuse + NTC)

Mics ── hardware MUTE ── compute
Speaker ◄── amp ◄── compute
FSR ── ADC ── MCU ── (optional serial to compute for log only)
```

Never share the public Frame 6–8.4 V servo rail with these heaters.
Never put 12 V across a 5 V pin.
Never put the Jetson on a random tap.

---

## Phase map (industrial)

| Step | Prove | Where |
| :--- | :--- | :--- |
| I0 | Path chosen. Skeleton on a stand. Dressed-mass estimate. E-stop exists | this file |
| I1 | Bare industrial chassis holds pose 10 min. Foot bolts or stand rated | this file + card |
| I2 | Skin on. Dressed mass written. No exposed tube. Service hatch works | this file + card |
| I3 | Phase 0 voice/heat/FSR coupon numbers, then zoned heat 30 min ≤ 41 °C | `PHASE0.md` + this file |
| I4 | Sleeve wash/dry + leak-down + 42 °C sleeve cutout | this file + card |
| I5 | Owned local brain on-body or umbilical. WAN still optional and off | this file |

V2.0 walking dressed shell is **not this repo**.

---

## What you may not do on this coupon

- Hang the industrial skin on the public hobby-servo Frame and press Shuffle
- Call boom-on ten steps a companion walk
- Mains heat in the pelvis
- Cloud LLM as the heater / clamp brain
- DittoBot EPM / cap-dump / 25 mm cell as hips
- Childlike sculpt, voice, or “petite minor” sizing
- Silicone lube on platinum skin
- TPE listed as the industrial material
- Unattended preheat
- Permanent wet plumbing
- A licensed film face

---

## Measurement rows (copy onto `MEASUREMENT_CARD.md`)

One row per build. Add rows. Do not overwrite.

### Industrial chassis

| Field | Value | Unit / notes |
| :--- | :--- | :--- |
| Builder | | name / handle |
| Date | | YYYY-MM-DD |
| Path | | A factory / B shop |
| Height | | cm (target 160–168) |
| Skeleton | | alloy / 201 / 304 / other + joint class |
| Bare chassis mass | | kg |
| Dressed mass | | kg (target 32–38; flag >42) |
| Stand method | | foot bolts / external stand / both |
| Holds pose 10 min | | yes/no, which joints |
| Service hatch | | nape / back zip / sectional |
| E-stop drop | | ms (heaters + motors) |
| Photo | | |

### Industrial skin

| Field | Value | Unit / notes |
| :--- | :--- | :--- |
| Chemistry | | platinum-cure / (TPE prototype only) |
| Shore (contact) | | scale + number |
| Foam core | | yes/no + type |
| Exposed metal | | none / where |
| Powder used | | |

### Industrial heat + sense

| Field | Value | Unit / notes |
| :--- | :--- | :--- |
| Rail V | | V at the pad |
| Zones | | list |
| Skin NTC 30 min | | °C |
| Peak skin NTC | | °C (must be ≤41) |
| Hardware fuse rating | | °C |
| FSR calibration | | N vs ADC |
| 35 N halt test | | pass/fail / N/A if no clamp |

### Industrial intimate

| Field | Value | Unit / notes |
| :--- | :--- | :--- |
| Sleeve type | | removable platinum / factory tunnel |
| Wash + dry time | | min |
| Leak-down 30 min | | pass/fail |
| Sleeve heater peak | | °C (≤42 hardware) |
| Clamp / suction peak | | N (35 N cap) |
| Lube used | | water-based only |

No companion claim on a blank industrial card.

---

## Cash (2026 street, order-of-magnitude, USD)

| Item | Ballpark |
| :--- | :--- |
| Path A factory platinum 160–168 cm with standing / yoga skeleton | mid four figures and up |
| Path B stainless skeleton + joints + stand | roughly 400–2 000 depending on who welds it |
| Platinum skin (bought cover or first cast + mold) | wide. Mold is the real cost |
| 12 V zoned heat + NTC + fuses + E-stop | 80–250 |
| FSR coupon → small grid | 20–150 |
| Local voice after Phase 0 | Pico cheap; Jetson is the spend |
| Hoist / proper stand | cheaper than a torn rotator cuff |

Do not price this as “Frame + a skin from Amazon.”
The industrial unit is a different machine.

---

## File pointers

- Public walking droid: `FRAME.md`, `BUILD.md`, `MIN_PARTS.md`
- Architecture / version ladder: `DESIGN.md`
- Soft-hang research that must not rewrite the Frame: `OPTIONAL_SHELL.md`
- Voice coupon: `PHASE0.md`, `CONSTITUTION.md`
- Paper locks: `LOCKS.md`
- Blank numbers: `MEASUREMENT_CARD.md`

This file is the silicone sexdoll chassis.
Keep the gold protocol droid in its own pile.
