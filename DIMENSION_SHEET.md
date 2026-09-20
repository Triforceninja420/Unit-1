Unit‑1 Companion Module Dimension Sheet
Created: 2026‑09‑20 08:42:50 UTC
Last Revised: 2026‑09‑20 09:05:00 UTC
Owner: Craig Ralls
Purpose: Engineering dimension, coordinate alignment, and mechanical interface specification sheet for Unit‑1 chassis + companion module fit-check.
1. Coordinate Reference Frame & Assembly Envelope
All physical coordinates conform to standard ISO 8855 / robotics conventions:
 * +X (Longitudinal / Sagittal): Anterior direction (forward travel).
 * +Y (Lateral / Coronal): Port direction (robot left).
 * +Z (Vertical / Transverse): Superior direction (upward, opposing gravity).
| Parameter | Axis / Vector | Dimension / Spec | Unit | Engineering Notes |
|---|---|---|---|---|
| Chassis Armature Height | Z | 160–168 | cm | Rigid structural spine/pelvis armature length |
| Total Stance Height | Z | 180–190 | cm | Ground-to-head clearance with nominal leg extension |
| Torso Stance Width | Y | 30–35 | cm | Shoulder-to-shoulder hardpoint span |
| Torso Stance Depth | X | 20–25 | cm | Sagittal depth of main structural tube frame |
| Structural Stock | Cross-section | 20–25 | mm | 6061-T6 aluminum square/round tubing (3\text{ mm} wall) |
| Base Chassis Dry Mass | Total | 30–45 | kg | Bare chassis excluding supplemental payloads |
| Nominal CoM Height (z_{\text{CoM}}) | Z | 0.90–1.05 | m | Baseline height without companion payload |
2. Companion Module Clearance & Mounting Envelope
| Item | Axis | Value | Unit | Fit-Check Requirement |
|---|---|---|---|---|
| Module Depth | X | 20–25 | cm | Mounts flush to upper torso hardpoints along sagittal axis |
| Module Width | Y | 30–35 | cm | Interfaces symmetrically across upper torso shoulder line |
| Module Height | Z | 70–80 | cm | Upper body housing envelope above pelvis mounting plate |
| Module Payload Mass | Mass | 2.0–4.0 | kg | Design limit: strictly \le 5.0\text{ kg} |
| Combined System Mass | Mass | 32–49 | kg | Full biped stack in operational walking trim |
3. Mechanical Interface & Mounting Pattern (The "25 mm" Standard)
 * Bulkhead Spec: Dual CNC 6061-T6 aluminum mounting plates (6\text{ mm} nominal thickness).
 * Grid Hole Pattern: Standard 25\text{ mm} \times 25\text{ mm} square pitch.
 * Primary Fasteners: 4\times M5 Socket Head Cap Screws (DIN 912, Class 12.9) torqued to 8.5\text{ N}\cdot\text{m} into Keenserts/steel inserts with Loctite 243.
 * Shear Locators: 2\times \varnothing 4\text{ mm} \times 12\text{ mm} hardened alloy steel dowel pins (ISO 8734) taking dynamic shear and torque loads off the bolts.
 * Service Pass-Through: Centered \varnothing 30\text{ mm} chamfered circular bore for power (XT30) and CAN communication lines.
4. Joint, Actuator & CAN Bus Allocations
| Subsystem | Joint Axis | Actuator Architecture | Cont. Torque | Peak Torque | CAN Arbitration ID |
|---|---|---|---|---|---|
| Chassis | Spine (Pitch/Roll) | Brushless QDD | 18\text{ N}\cdot\text{m} | 45\text{ N}\cdot\text{m} | 0x010, 0x011 |
| Chassis | Hip Pitch (2\times) | Planetary BLDC | 25\text{ N}\cdot\text{m} | 60\text{ N}\cdot\text{m} | 0x012, 0x013 |
| Chassis | Hip Roll/Splay (2\times) | Harmonic Drive | 12\text{ N}\cdot\text{m} | 35\text{ N}\cdot\text{m} | 0x014, 0x015 |
| Chassis | Ankle Pitch/Roll (2\times) | Brushless QDD | 10\text{ N}\cdot\text{m} | 30\text{ N}\cdot\text{m} | 0x016, 0x017 |
| Companion | Shoulder Pitch | Brushless QDD | 15\text{ N}\cdot\text{m} | 40\text{ N}\cdot\text{m} | 0x018 |
| Companion | Shoulder Roll / Artic. | Harmonic Drive | 12\text{ N}\cdot\text{m} | 35\text{ N}\cdot\text{m} | 0x019 |
5. Balance & Dynamic Equilibrium Reference
 * Planar ZMP Coordinates (LIPM Approximation):
   
 * Multi-Body Projection:
   
 * Torque Load Safety Factor: Under peak dynamic sway (10^\circ lateral excursion), companion overturning moment is \approx 6.81\text{ N}\cdot\text{m}, maintaining a >1.75\times continuous safety factor on the 12\text{ N}\cdot\text{m} Harmonic Drive hip roll actuators.
6. Execution Schedule
 * Step‑3 (Simulation): 2026‑09‑20 09:45:00 UTC (Single-support balance envelopes & thermal load tracking)
 * Step‑4 (Iteration): 2026‑09‑20 10:30:00 UTC (Tolerancing tweaks and bracket mass reduction)
 * Step‑5 (Documentation): 2026‑09‑20 11:00:00 UTC (Export full CAD interface packages and drawings)
End of Dimension Sheet
