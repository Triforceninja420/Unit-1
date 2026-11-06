Unit-1 Autonomous Bipedal Humanoid Platform (UBHP-1)
Master Engineering Specification & System Architecture
Document Revision 0.1.0 — Design Brief (Unvalidated)
System Class: Fully Autonomous Edge-AI Bipedal Platform
Kinematic Gait Model: Stiff-Legged Waddling / Shuffle Kinematics (ZMP Stabilized)
Status: design brief, not validated, not the public build

1. Master System Overview & Unit-1 Design Philosophy
The Unit-1 Autonomous Bipedal Humanoid Platform (UBHP-1) integrates dynamic, zero-cloud edge intelligence with a hardened, low-backlash humanoid chassis. Designed specifically to execute stable, characteristic waddling and shuffling bipedal gaits while retaining tactile compliance and realistic expressive animatronics, the platform resolves critical mechanical and electrical failure modes identified during stress testing.
Key architectural upgrades include zero-power electromagnetic holding brakes at high-stress joints, active dynamic bus clamping, a 200 Hz Zero Moment Point (ZMP) control loop backed by 8-zone ground reaction telemetry, double-shear linkage clevises, a zoned dual-durometer elastomer skin with integrated internal accordion pleats to eliminate tearing under extreme flexion, and a stereo ESP32-CAM eye pair giving gaze-coupled vision.

2. Hardened Full-Body Kinematic Chain
The Unit-1 lower body decouples sagittal stride from lateral waddle splay across 10 lower-body degrees of freedom (DOF), while retaining full upper-body expressivity:
| Joint Subsystem | Actuator Architecture | Torque Specs & Braking | Bearing / Load Isolation | CAN ID |
|---|---|---|---|---|
| Spine (Pitch/Roll) | Brushless Quasi-Direct Drive (QDD) | 18 N·m Cont. / 45 N·m Peak | Back-to-back angular contact pairs (5.5 kN) | 0x010, 0x011 |
| Hip Pitch (2x) | Integrated Planetary BLDC | 25 N·m Cont. / 60 N·m Peak | Dual deep-groove ball bearings (4.8 kN) | 0x012, 0x013 |
| Hip Roll / Splay (2x) | Harmonic Drive Component Set | 12 N·m Cont. / 35 N·m Peak | High-rigidity cross-roller bearing (7.2 kN) | 0x014, 0x015 |
| Knee Joint (2x) | 100:1 Harmonic Drive + BLDC | 35 N·m Cont. / 85 N·m Peak + 24V EM Brake | Integrated harmonic cross-roller output flange | 0x016, 0x017 |
| Ankle Gimbal (2x 2-DOF) | Shank Pushrod In-Line BLDC | Dual 600 N axial force (Push/Pull) | 7075-T6 double-shear clevises + M6 PTFE heim joints | 0x018, 0x019 |
| Neck & Animatronics | 3-DOF Neck + 12x Facial Servos | 0.8 to 6 N·m torque class | Sintered bronze pivot bushings | 0x020 (STM32 Node) |
| Eye Cameras (2x) | ESP32-CAM OV2640 stereo pair in eye sockets | Gaze-coupled stereo vision, ~1.5 m convergence | 3D-printed cradles on neck armature, passive heatsinks | 0x022 (Node -> Host) |

3. Hardened Power Network & Bus Clamping
Locomotion creates high regenerative back-EMF spikes that threaten digital compute rails. The Unit-1 PDN incorporates active transient suppression:
 * Battery Core: 6S2P Li-ion pack (22.2V nominal, 10,000 mAh, 50A continuous discharge) equipped with an SMBus hardware BMS monitoring cell differential, current, and thermal cutoffs.
 * Active Brake Chopper: Solid-state transient clamping circuit monitoring the 24V bus. If bus voltage exceeds 27.5V during rapid knee/hip deceleration, a fast comparator gates a power MOSFET to dump excess kinetic back-EMF into an aluminum chassis-mounted 1.5 Ω, 50W ceramic ballast resistor.
 * Isolated Compute Supply: 12.0V, 15A synchronous buck regulator feeding the Jetson AGX Orin with input TVS diode protection (30V clamping ceiling) and LC pi-filters to eliminate motor switching ripple.
 * Auxiliary Step-Down Rails: 5.0V (10A) rail for cameras and servo logic; 3.3V/1.8V ultra-low-noise LDOs for absolute magnetic encoders and sensor front-ends.

4. Real-Time ZMP Gait & Locomotion Control Engine
The waddling gait is achieved by maintaining a constant forward-knee flexion while swaying the pelvis over alternating support polygons:
 * ZMP Preview Controller (200 Hz): The Orin compute module calculates Zero Moment Point trajectories in real time based on a Linear Inverted Pendulum Model (LIPM), keeping the ground reaction vector inside the active foot envelope.
 * Foot Telemetry: Each foot plate houses a 4-zone force-sensitive resistor (FSR) matrix (heel, medial metatarsal, lateral metatarsal, toe) sampling at 1 kHz via the lower leg STM32 node, detecting foot strikes, liftoff, and lateral tipping moments.
 * Zero-Power Posture Hold: When the platform halts in a standing position, 24V spring-applied electromagnetic brakes on the knee shafts engage within 250 ms, allowing the drive current to cut to zero while maintaining a rigid stance with zero heat buildup.

5. Biomimetic Composite Armor & Skin Casing
The outer aesthetic shell and compliant flesh survive repeated dynamic flexing without surface tearing, wrinkling, or delamination:
 * Skeletal Enclosure: 6061-T6 aluminum structural spars closed off with 2.5 mm 3K quasi-isotropic carbon-fiber covers providing torsional rigidity and EMI shielding.
 * Sub-Dermal Matrix: 45 kg/m³ low-density compliant polyurethane foam layer to deaden internal acoustic motor noise and provide human compliance.
 * Dual-Durometer Epidermal Skin:
   * Joint Flexure Zones (Groin, Knee Creases, Ankles): Cast Shore 00-30 platinum silicone with molded internal accordion bellows, supporting over 900% elongation without surface necking.
   * Structural / Tactile Contact Surfaces: Cast Shore 10A platinum silicone reinforced with an embedded flexible nylon mesh scrim to prevent puncture and tearing.
 * Tactile Feedback Layer: 64-channel piezoresistive grid embedded between the foam and outer skin, multiplexed to CAN ID 0x030.

6. Master CAN Bus Topology & Frame Map
========================================================================================
CAN ID    Node Assignment         Direction     Payload Format           Frequency
========================================================================================
0x001     System E-Stop           Host -> ALL   [0xFF, 0x00, 0x00, 0x00] Async (Critical)
0x010     Spine Pitch BLDC        Host -> Node  float32 pos, float32 tor 100 Hz
0x011     Spine Roll BLDC         Host -> Node  float32 pos, float32 tor 100 Hz
0x012     Left Hip Pitch          Host -> Node  float32 pos, float32 tor 200 Hz
0x013     Right Hip Pitch         Host -> Node  float32 pos, float32 tor 200 Hz
0x014     Left Hip Roll           Host -> Node  float32 pos, float32 tor 200 Hz
0x015     Right Hip Roll          Host -> Node  float32 pos, float32 tor 200 Hz
0x016     Left Knee BLDC + Brake  Host -> Node  float32 pos, uint8 brake 200 Hz
0x017     Right Knee BLDC + Brake Host -> Node  float32 pos, uint8 brake 200 Hz
0x018     Left Ankle Pushrods     Host -> Node  float32 pitch, float32 roll 200 Hz
0x019     Right Ankle Pushrods    Host -> Node  float32 pitch, float32 roll 200 Hz
0x020     Head / Facial MCU       Host -> Node  uint8 jaw, eye_l, eye_r  50 Hz
0x021     Diaphragm Stepper       Host -> Node  float32 breathing_bpm    20 Hz
0x022     Stereo Eye Cameras      Node -> Host  MJPEG frame chunks (L/R) 5-15 Hz
0x030     Torso Tactile Hub       Node -> Host  uint32 mask, uint16 peak 50 Hz
0x032     Left Foot 4-FSR Matrix  Node -> Host  uint16 F0, F1, F2, F3    200 Hz
0x033     Right Foot 4-FSR Matrix Node -> Host  uint16 F0, F1, F2, F3    200 Hz
========================================================================================

---

## 7. Consolidated Bill of Materials (BOM)

| System Domain | Hardened Specification Components | Cost (USD) |
| :--- | :--- | :--- |
| **Primary Edge AI** | NVIDIA Jetson AGX Orin 64GB Developer Kit | $1,999 |
| **Distributed MCUs** | 3x STM32H723 Core Modules (Head, Torso/Tactile, Lower Limbs) | $320 |
| **Lower-Body Drive Train** | 4x Planetary Hips (25 N·m) + 2x Hip Roll Harmonics (12 N·m) + 2x Knee Harmonics w/ 24V Brakes (35 N·m) + 4x Ankle Pushrod Drives | $3,000 |
| **Upper-Body Actuation** | 2x QDD Spine Motors + 3-DOF Neck + 12x Facial Coreless Micro-Servos | $1,200 |
| **Eye Vision** | 2x ESP32-CAM OV2640 stereo pair + 850 nm IR LED rings + heatsinks + 3D-printed cradles | $60 |
| **PDN & Transient Clamping** | 6S2P Li-ion 10Ah + Active 27.5V Brake Chopper + Buck Converters | $520 |
| **Structural Endoskeleton** | CNC 7075/6061 Billet Pelvis/Spars, Carbon Boxes, Double-Shear Clevises | $2,100 |
| **Dual-Durometer Skin** | SLA Tooling Negatives, Shore 00-30 Pleated Joints, Shore 10A Skin, Scrim | $1,550 |
| **Sensors & Ground Reaction**| Intel RealSense D435i, 64-Ch Tactile Grid, 8x Foot FSR Sensors, MEMS Mics | $720 |
| **Thermal & Cabling** | Graphite PGS Spreaders, Dual Blowers, Braided Shielded Bus Harnessing | $300 |
| **Total Engineered Cost** | **Fully Autonomous, Bipedal Unit-1 Architecture** | **$11,869** |

The structural mass budget and baseline link lengths can be locked to freeze the kinematic tree for the preview controller.
These values assume a nominal 165 cm overall stature with the lower-body proportions tuned to support the bent-knee, wide-stance Linear Inverted Pendulum Model (LIPM).

## 8. Frozen Link Lengths & Kinematic Offsets
All dimensions define joint axis-to-axis centerlines:
 * Pelvic Width (Hip Pitch-to-Pitch Centerline): 240 mm (Wide stance base to facilitate the lateral pendulum sway).
 * Hip Pitch-to-Roll Offset (d_hip): 48 mm (Orthogonal intersecting offset).
 * Femur Length (L_thigh): 360 mm (Hip roll pivot to knee harmonic axis).
 * Shank Length (L_shank): 380 mm (Knee harmonic axis to ankle gimbal pivot center).
 * Ankle Gimbal-to-Sole Offset (h_sole): 65 mm (Vertical distance from ankle pitch/roll cross-pin to bottom of compliant foot tread).
 * Foot Sole Envelope: 220 mm total length (75 mm posterior to ankle center, 145 mm anterior) × 110 mm width.

## 9. Bare-Frame Mass & Center of Gravity (CoG) Budget
The masses represent the fully populated sub-assemblies (skeleton, internal drives, wiring, and structural covers, excluding cast outer silicone):
| Segment / Assembly | Bare-Frame Mass | Local Center of Gravity (from proximal joint) | Segment Inertia Estimate (I_xx, I_yy, I_zz) |
|---|---|---|---|
| Pelvis Core Assembly | 4.20 kg | Centered 35 mm below spine pitch base | [0.024, 0.018, 0.028] kg·m² |
| Femur Assembly (x2) | 3.15 kg ea. | 145 mm distally along tube centerline | [0.038, 0.036, 0.007] kg·m² |
| Shank Assembly (x2) | 2.85 kg ea. | 130 mm distally (biased proximal by Bay 2/3 motors) | [0.031, 0.029, 0.005] kg·m² |
| Foot Plate Assembly (x2) | 0.95 kg ea. | 18 mm forward of pitch pin, 25 mm below pivot | [0.003, 0.006, 0.004] kg·m² |
| Upper Body Lumped Mass | 17.50 kg | Torso center (Orin, battery, spine, animatronics) | [0.320, 0.280, 0.190] kg·m² |
| Total Platform Mass (M) | 35.60 kg | Nominal standing CoG height: z_c ≈ 540 mm | — |

## 10. Frozen LIPM Constants for 10-Step Gait Execution
With the link parameters set, the fundamental parameters for the 200 Hz preview loop normalize to:
 * Nominal CoM Operating Height (z_c): 0.54 m (calculated at constant 22° static knee flexion).
 * Pendulum Time Constant: TBD — compute from z_c / g once the mass model is locked.
 * Step Cycle Timing:
   * Step Duration (T_step): 0.65 s per step (0.45 s single support, 0.20 s double support).
   * Stride Length (S_x): 120 mm (short, stable shuffle).
   * Step Width (S_y): 240 mm constant lateral stance.
   * Lateral CoM Sway Amplitude: ±38 mm across the pelvic roll axis to keep the ZMP safely within the 110 mm foot width during single-leg support.
