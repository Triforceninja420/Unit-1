# BUILD.md — build a C-3PO-class frame

Design owner: Craig. Public coupon. Status: Frame locked 2026-09-15.

You do not need a doll, a GPU, or a cloud account. You need tube, servos, a pack, and an afternoon of wiring.

## 0. Read first

- `FRAME.md` for numbers that are frozen
- `MIN_PARTS.md` for the cart
- `MEASUREMENT_CARD.md` so you know what you must write down

If you skip the card, you built a sculpture.

## 1. Cut the armature

1. Pick 160–168 cm. Mark hip, knee, ankle on the tube before you drill.
2. Hip width ~ the protocol-droid stance you can stand inside without the feet kicking each other. Start ~180–220 mm center to center.
3. Joint blocks: printed or plate. One bolt axis per joint. No slop you can see.
4. Dry-assemble legs + pelvis. Stand it on the bench with the joints locked (bolts tight, no servos yet). If it will not stand as a dummy, servos will not save it.
5. Weigh the dummy. Budget room for servos + pack so you finish at 8–14 kg.

## 2. Mount servos

1. Hip pitch L/R, knee L/R, ankle pitch L/R first. Six servos is a legal first walker.
2. Add hip roll L/R when the six-servo shuffle only tips sideways.
3. Arms can be dummy mass until the legs work.
4. Horn screws + thread locker. A loose horn is a fall.
5. Keep wiring off the floor path. Strain-relief at every joint.

## 3. Power and stop

1. Pack on the pelvis or backpack plate. Low COM helps.
2. Fuse the servo rail. BEC or a proper UBEC if you run 2S/3S.
3. E-stop in series with servo-enable / rail switch. Prove it with a meter.
4. Do not power a 32 kg cover from this rail. This rail is the bare frame.

## 4. Gait player

1. MCU: Pico, XIAO RP2040, or Mega. Servo library + a table of pulse widths vs time.
2. Find hold poses: stand, left-shift, right-shift, left-lift, left-plant.
3. Play them slow. Then shorten the delays until it steps instead of posing.
4. Open-loop only. If it needs a boom, use the boom and write boom-on.

Example pose table (fill with *your* microseconds):

```
stand        hipL hipR kneeL kneeR ankL ankR
shift_L
lift_R
plant_R
shift_R
lift_L
plant_L
```

Loop that. That is the droid.

## 5. Test order

1. Tether or boom for the first power-up.
2. Stand 60 s.
3. One step.
4. Ten steps.
5. E-stop mid-step once so you trust it.
6. Fill the Frame table.

## 6. Optional costume

Paint, printed chest, bucket head, cape. Hang them only after step 5.
Soft / companion covers are Path 1. They stay off the walk claim.

## Do not

- Do not start with a full silicone body and try to motorize the factory EVO joints.
- Do not call boom-on a walk.
- Do not skip the fuse or the E-stop.
- Do not paste DittoBot coil parts onto a hip.
