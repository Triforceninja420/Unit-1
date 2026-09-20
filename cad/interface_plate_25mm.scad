// =============================================================================
// Unit-1 Companion Module 25mm Interface Plate
// Fastener spec: 4x M5 SHCS (DIN 912) on 25mm centers
// Shear pins: 2x 4mm ISO 8734 Dowel Pins
// =============================================================================

$fn = 80;

// Plate Parameters (mm)
plate_w        = 90.0;     // Overall plate width (Y)
plate_l        = 90.0;     // Overall plate length (X)
plate_t        = 6.0;      // Plate thickness (Z)
corner_radius  = 6.0;      // Corner filleting

// Standard 25mm Pattern Parameters
grid_pitch     = 25.0;     // 25mm square bolt pitch
m5_clearance_d = 5.5;      // M5 close-fit through hole
m5_csl_d       = 10.0;     // Counterbore diameter for DIN 912 head
m5_csl_depth   = 3.2;      // Counterbore depth

// Alignment & Cable Routing
dowel_d        = 4.0;      // 4mm press-fit dowel pin diameter
umbilical_d    = 30.0;     // Center wire harness pass-through

module rounded_plate(w, l, t, r) {
    hull() {
        translate([-w/2 + r, -l/2 + r, 0]) cylinder(r=r, h=t);
        translate([ w/2 - r, -l/2 + r, 0]) cylinder(r=r, h=t);
        translate([-w/2 + r,  l/2 - r, 0]) cylinder(r=r, h=t);
        translate([ w/2 - r,  l/2 - r, 0]) cylinder(r=r, h=t);
    }
}

module m5_mounting_hole() {
    // Thru-hole
    translate([0, 0, -1])
        cylinder(d=m5_clearance_d, h=plate_t + 2);
    // Counterbore
    translate([0, 0, plate_t - m5_csl_depth])
        cylinder(d=m5_csl_d, h=m5_csl_depth + 1);
}

module dowel_pin_hole() {
    translate([0, 0, -1])
        cylinder(d=dowel_d, h=plate_t + 2);
}

difference() {
    // 1. Base solid plate
    rounded_plate(plate_w, plate_l, plate_t, corner_radius);

    // 2. Central umbilical pass-through
    translate([0, 0, -1])
        cylinder(d=umbilical_d, h=plate_t + 2);

    // 3. 4x M5 Counterbored Grid (25mm square spacing)
    translate([ grid_pitch/2,  grid_pitch/2, 0]) m5_mounting_hole();
    translate([-grid_pitch/2,  grid_pitch/2, 0]) m5_mounting_hole();
    translate([-grid_pitch/2, -grid_pitch/2, 0]) m5_mounting_hole();
    translate([ grid_pitch/2, -grid_pitch/2, 0]) m5_mounting_hole();

    // 4. 2x Dowel alignment holes (transverse alignment across Y)
    translate([0,  32.5, 0]) dowel_pin_hole();
    translate([0, -32.5, 0]) dowel_pin_hole();
}
