# MIN_PARTS.md — one bare C-3PO

Public frame kit. Design owned by Craig.
Not DittoBot. Not a soft-body order.

Fill the Frame table in `MEASUREMENT_CARD.md`. No walk claim until that table has numbers.

## Buy or borrow

| # | Item | Spec | Why | Skip / substitute |
| :--- | :--- | :--- | :--- | :--- |
| 1 | Tube / plate | 20–25 mm aluminum tube or 2–3 mm plate for pelvis and feet | The robot | Steel is heavier; print-only legs will flex. Flag it |
| 2 | Joint hardware | M3/M4 bolts, locknuts, horn screws | Axes | Nyloc or thread locker |
| 3 | Servos (legs) | 6× hobby digital, metal gear. Start in the 20–40 kg-cm class and write the real model | Hip/knee/ankle pitch | Stronger for hip if the dummy is already 10 kg |
| 4 | Servos (optional) | 2× hip roll, 2× shoulder | Weight shift + arm swing | Add after the 6-servo shuffle exists |
| 5 | MCU | Pico / XIAO RP2040 / Mega | Gait table | Do not put a Jetson on this order unless you already own one |
| 6 | Pack | 2S–3S LiPo or 12 V LiFePO4 + UBEC to servo voltage | Walk rail | Bench PSU for first stand test |
| 7 | Fuse + E-stop | Rail fuse + mushroom or tether switch that kills enable | Human path | Software “stop” is not E-stop |
| 8 | Servo wire / extenders | 22–26 AWG, strain relief | Hips eat cables | |
| 9 | Feet | Wide plates. Rubber pad | C-3PO without feet is a coat rack | |
| 10 | Scale + tape | Luggage scale, 3 m tape | Mass and height on the card | |

## Already in the folder (do not repurchase as magic)

- Envelope and tests: `FRAME.md`
- Steps: `BUILD.md`
- Blank card: `MEASUREMENT_CARD.md`

## Borrow if cash is low

- Drill press or a square + hand drill
- Bench supply for the first stand
- A broom-handle boom and a friend for step one
- Makerspace night for tube cuts

## Do not put on this order

- DittoBot Phase 0: IRLZ44N cap-dump, Ø5 EPM, 1.8 mm pin
- 25 mm cell: Ø6 stack, AWG 36 latch coil, DRV8871 as a hip
- Full TPE/silicone body as the *first* structure
- Walking-hub motors rated for 35 kg “just in case”
- Cloud personality sub

## Bench order

1. Dummy armature stands with bolts tight, no servos.
2. Six pitch servos + fuse + E-stop.
3. Stand pose 60 s.
4. Script one step, then ten.
5. Write mass, servo models, stall A, boom yes/no on the card.
