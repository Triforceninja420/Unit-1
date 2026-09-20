Unit‑1 Companion Module Master Design Doc
Created: 2026‑09‑20 08:49:56 UTC
Last Revised: 2026-09-20
Owner: Craig Ralls
Purpose: Master engineering design document for the Unit‑1 bipedal chassis and Companion Module interface, optimized for structural integrity, dynamic balance, and production readiness.
1. Executive Summary
The Unit‑1 Companion Module is a rigid, modular add-on designed to interface directly with the upper torso of the Unit‑1 bipedal chassis. It serves as a dual-robot attachment and supplemental actuation/compute package, housing secondary articulation (household manipulation/shoulder package) while maintaining rigid mechanical coupling and strict mass/inertia constraints.
Key Specifications
 * Module Dimensions (X \times Y \times Z): 20\text{–}25\text{ cm} \times 30\text{–}35\text{ cm} \times 70\text{–}80\text{ cm}
 * Chassis Stance / Armature Height: 160\text{–}168\text{ cm} total height (standing height 180\text{–}190\text{ cm} with leg extension)
 * Companion Module Mass: 2.0\text{–}4.0\text{ kg} (strict upper threshold < 5.0\text{ kg})
 * Total Combined System Mass: 32\text{–}49\text{ kg}
 * Actuators (Module): 2\times shoulder pitch/roll, 2\times supplemental articulation
 * Communication Interface: Dual CAN 2.0B / CAN FD bus lines (IDs 0x018, 0x019)
2. Design Philosophy & Interface Standards
 * Coordinate System Conformance: Fully aligned with ISO 8855 / robotics standards:
   * +X: Sagittal axis (Forward / travel direction)
   * +Y: Coronal axis (Lateral port / robot left)
   * +Z: Vertical axis (Upward, counter to gravity)
 * Deterministic Modular Coupling: Uses a standardized 25\text{ mm} grid mounting interface with shear-dowel locating pins, allowing rapid swap-out while preventing bolt shear failure during lateral acceleration.
 * Inertial Mass Budgeting: Keeps module CoM within an envelope that maintains a minimum 1.5\times thermal continuous torque margin across hip roll and ankle roll joints under single-support dynamic phase.
 * Separation of Compute & Power: Isolated control electronics and sensor IMUs connected via independent bus wiring to eliminate ground-loop interference from high-current BLDC drivers.
3. Mechanical Specifications & Fit-Check
3.1. Base Chassis & Module Dimensional Envelope
| Parameter | Longitudinal (X) | Lateral (Y) | Vertical (Z) | Structural Notes |
|---|---|---|---|---|
| Biped Base Chassis | 30\text{–}35\text{ cm} | 20\text{–}25\text{ cm} | 160\text{–}168\text{ cm} | Rigid armature (20\text{–}25\text{ mm} 6061-T6 aluminum tube, 3\text{ mm} gussets) |
| Companion Module | 20\text{–}25\text{ cm} | 30\text{–}35\text{ cm} | 70\text{–}80\text{ cm} | Upper torso mount; width aligns with shoulder width |
| Total Assembly | 30\text{–}35\text{ cm} | 30\text{–}35\text{ cm} | 180\text{–}190\text{ cm} | Stance height including baseline leg kinematics |
3.2. Standardized Mechanical Mounting Interface (The "25 mm" Standard)
 * Bulkhead Geometry: Dual mating plates CNC-milled from 6061-T6 aluminum, 6\text{ mm} plate thickness.
 * Fastener Pattern: Standardized 25\text{ mm} \times 25\text{ mm} rectangular hole grid.
 * Fasteners: 4\times M5 Socket Head Cap Screws (DIN 912, Class 12.9) torqued to 8.5\text{ N}\cdot\text{m} into helical steel inserts (Helicoil/Keensert) with medium-strength threadlocker (Loctite 243).
 * Shear Pin Locators: 2\times \varnothing 4\text{ mm} \times 12\text{ mm} hardened alloy steel dowel pins (ISO 8734) taking dynamic shear and torsional loads off the clamping screws.
 * Umbilical Cutout: Centered 30\text{ mm} circular chamfered pass-through for XT30 power and Molex Micro-Fit 3.0 control lines.
3.3. Actuator Sizing & Bus Topology
| Joint Axis | Kinematic Role | Actuator Type | Cont. Torque | Peak Torque | CAN Arbitration ID |
|---|---|---|---|---|---|
| Spine Pitch/Roll | Torso lean / stabilization | Brushless QDD | 18\text{ N}\cdot\text{m} | 45\text{ N}\cdot\text{m} | 0x010, 0x011 |
| Hip Pitch (2\times) | Sagittal forward propulsion | Planetary BLDC | 25\text{ N}\cdot\text{m} | 60\text{ N}\cdot\text{m} | 0x012, 0x013 |
| Hip Roll/Splay (2\times) | Coronal balance / weight shift | Harmonic Drive | 12\text{ N}\cdot\text{m} | 35\text{ N}\cdot\text{m} | 0x014, 0x015 |
| Ankle Roll/Pitch (2\times) | Ground contact / push-off | Brushless QDD | 10\text{ N}\cdot\text{m} | 30\text{ N}\cdot\text{m} | 0x016, 0x017 |
| Companion Joint 1 | Shoulder pitch / manipulation | Brushless QDD | 15\text{ N}\cdot\text{m} | 40\text{ N}\cdot\text{m} | 0x018 |
| Companion Joint 2 | Shoulder roll / articulation | Harmonic Drive | 12\text{ N}\cdot\text{m} | 35\text{ N}\cdot\text{m} | 0x019 |
4. Dynamics, Balance & Control Formulations
4.1. Multi-Body Zero Moment Point (ZMP) Formulation
To ensure dynamic stability during single-support walking phases with the added module mass, the contact foot must maintain non-zero pressure across its entire surface without tipping. The generalized planar ZMP ground projections (p_x, p_y) at ground elevation (z = 0) are defined by:
Where:
 * m_i, x_i, y_i, z_i: Mass and spatial coordinates of link i (including base chassis links and companion payload).
 * I_{x,i}, I_{y,i}: Principal moments of inertia of link i.
 * \ddot{x}_i, \ddot{y}_i, \ddot{z}_i: Linear accelerations relative to the global world frame.
Linear Inverted Pendulum Model (LIPM) fast real-time estimation:

4.2. Roll Moment Overturning Budget
 * Payload Mass: m_{\text{comp}} \le 4.0\text{ kg} mounted at center height z \approx 1.0\text{ m}.
 * Static Gravity Moment at Max Permissible Lean (10^\circ):
   
 * Dynamic Roll Compensation Margin:
   The Harmonic Drive hip roll actuator (12\text{ N}\cdot\text{m} continuous / 35\text{ N}\cdot\text{m} peak) operates with a 1.76\times continuous safety factor during nominal walking gait cycles, maintaining sufficient reserve torque to reject sudden external lateral disturbances.
4.3. Sensor Architecture & Bus Arbitration
 * Inertial Measurement Units (IMUs): 2\times 6-DOF industrial IMUs (accelerometer + gyroscope) located on the companion frame, sampled at \ge 1\text{ kHz} to feed torso orientation directly into the LIPM ZMP state estimator.
 * CAN Arbitration Priority:
   * Emergency/Fault broadcasts: 0x000–0x00F
   * Primary chassis locomotion joints: 0x010–0x017
   * Companion module actuators: 0x018–0x019
   * Sensor telemetry frames: 0x020+
5. Production & Build Traceability
 * Bill of Materials (BOM): Reference MIN_PARTS.md for stock material specs, fastener part numbers, and Keensert thread specifications.
 * Firmware Protocol: Reference PHASE0.md for low-level CAN message byte encodings, heartbeat rates, and thermal shutdown thresholds.
 * Assembly Protocol: Reference BUILD.md for torque check patterns, loctite application guidelines, and wiring harness routing.
6. Verification Milestones
 * Step 1 — Mechanical Fit & Coordinate Clearance: Complete (Envelope verified against 20\text{–}25\text{ mm} armature).
 * Step 2 — Dimension & Tolerancing Sheet: Complete (Updated with 25\text{ mm} grid and M5/dowel specifications).
 * Step 3 — Gait Simulation & Torque Envelope: In Progress (Verifying peak Harmonic Drive thermal margins under single-support stance).
 * Step 4 — Prototype Hardware Validation: In Progress (Interface plate machining and dowel slip-fit tolerance verification).
 * Step 5 — Master Design Doc Final Approval: Complete.
End of Master Design Doc
