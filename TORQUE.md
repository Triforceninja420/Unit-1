TORQUE.md — Unit-1 hip and knee torque budget
Design owned by Craig. Public kit. 2026-09-15.
This file shows the math for hip load at 160 cm. It does not change locked numbers in FRAME.md or DESIGN.md. It does not mix DittoBot latch or coil numbers into the hips.
Assumptions
Frame height: 160 cm
Bare mass: 8–14 kg
Center of mass: roughly 55% of height, so about 88 cm from the ground
Hip joint at ground level (worst case for torque)
Gravity: 9.81 m/s²
Servo arm: 3 cm (typical hobby servo horn)
Static hip torque at full extension
Standing straight, one leg supporting the full weight:
Load at hip: 14 kg × 9.81 = 137 N
Lever arm: 88 cm = 0.88 m
Static torque: 137 × 0.88 = 121 N·m
Torque at the servo horn
With a 3 cm horn:
121 N·m ÷ 0.03 m = 4,033 N of force at the horn
Or: 121 × 0.03 = 3.6 N·m at the servo output shaft
What this means for servo choice
Hobby servos are usually rated in kg·cm, not N·m.
3.6 N·m ≈ 37 kg·cm at the shaft
Real-world duty needs margin for acceleration, not just static hold
Target: metal-gear servo rated 20+ kg·cm continuous, 30+ kg·cm stall, for hip and knee
Knee note
Knee load is lower than hip in this stance but spikes during the swing phase. Use the same servo class for both.
What this file does not cover
Dynamic walking torque (needs gait data)
Ankle or shoulder loads
DittoBot latch or coil numbers
Exact servo brand (not locked)