#!/usr/bin/env python3
"""
Unit-1 Lateral Gait & ZMP Margin Verification
Validates single-support roll overturn moment and actuator torque margins.
"""

import numpy as np

# System Mechanical Constants
M_CHASSIS = 35.0          # Base chassis dry mass (kg)
M_COMPANION = 4.0         # Companion module mass (kg)
M_TOTAL = M_CHASSIS + M_COMPANION

Z_COM_CHASSIS = 0.90      # Chassis CoM height (m)
Z_COM_COMPANION = 1.25    # Companion payload center height (m)
G = 9.80665               # Gravitational acceleration (m/s^2)

# Combined CoM Height
Z_C = (M_CHASSIS * Z_COM_CHASSIS + M_COMPANION * Z_COM_COMPANION) / M_TOTAL

# Actuator Limits (Harmonic Drive Hip Roll)
TORQUE_CONT_LIMIT = 12.0  # Continuous torque limit (N*m)
TORQUE_PEAK_LIMIT = 35.0  # Peak allowable torque (N*m)

# Simulation Parameters
T_STEP = 0.8              # Single-support step duration (s)
DT = 0.001                # Integration timestep (1 kHz)
T = np.arange(0, T_STEP, DT)

# Hip roll displacement profile: 8-degree lateral sway cycle
OMEGA = np.pi / T_STEP
THETA_MAX = np.radians(8.0)  # Max lateral excursion (rad)

theta = THETA_MAX * np.sin(OMEGA * T)
theta_dot = THETA_MAX * OMEGA * np.cos(OMEGA * T)
theta_ddot = -THETA_MAX * (OMEGA**2) * np.sin(OMEGA * T)

# Equivalent lateral CoM kinematic trajectory
y = Z_C * np.sin(theta)
y_ddot = Z_C * (theta_ddot * np.cos(theta) - (theta_dot**2) * np.sin(theta))

# Planar ZMP Calculation
p_y = y - (Z_C / G) * y_ddot

# Roll Moment at Hip Pivot
# Tau = m * g * y + I_roll * theta_ddot (Point mass approximation)
tau_roll = (M_TOTAL * G * np.sin(theta) * Z_C) + (M_TOTAL * (Z_C**2) * theta_ddot)
abs_tau_roll = np.abs(tau_roll)

max_tau = np.max(abs_tau_roll)
margin_cont = TORQUE_CONT_LIMIT / max_tau

print("=" * 55)
print("  UNIT-1 SINGLE-SUPPORT GAIT & ROLL MARGIN REPORT")
print("=" * 55)
print(f"Total System Mass       : {M_TOTAL:.2f} kg")
print(f"Effective CoM Height    : {Z_C:.3f} m")
print(f"Max Lateral Displacement: {np.max(np.abs(y))*100:.2f} cm")
print(f"Max ZMP Excursion       : {np.max(np.abs(p_y))*100:.2f} cm")
print(f"Peak Dynamic Hip Roll   : {max_tau:.2f} N*m")
print(f"Continuous Torque Limit : {TORQUE_CONT_LIMIT:.2f} N*m")
print(f"Peak Torque Limit       : {TORQUE_PEAK_LIMIT:.2f} N*m")
print(f"Continuous Safety Margin: {margin_cont:.2f}x")

if max_tau <= TORQUE_CONT_LIMIT:
    print("STATUS: PASS (Nominal walking within continuous thermal bounds)")
elif max_tau <= TORQUE_PEAK_LIMIT:
    print("STATUS: CAUTION (Requires intermittent duty cycle / peak bursts)")
else:
    print("STATUS: FAIL (Exceeds peak actuator torque capacity)")
print("=" * 55)
