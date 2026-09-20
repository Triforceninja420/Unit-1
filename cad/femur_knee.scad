// Unit-1 Bipedal Endoskeleton: Femur & Knee Clevis Segment
// Units: mm

$fn = 48;

// --- Parameters ---
bone_length     = 110.0;
bone_width      = 28.0;
bone_depth      = 22.0;
outer_radius    = 6.0;   // Radiused corners prevent cutting or pinching skin

servo_pocket_w  = 20.5;
servo_pocket_l  = 40.5;
servo_pocket_d  = 18.0;

wire_tunnel_dia = 7.0;   // Internal conduit down the neutral bending axis
pivot_pin_dia   = 4.0;   // Knee hinge bolt (M4)

module smooth_bar(l, w, d, r) {
    hull() {
        translate([r, r, 0]) cylinder(r=r, h=d);
        translate([w - r, r, 0]) cylinder(r=r, h=d);
        translate([r, l - r, 0]) cylinder(r=r, h=d);
        translate([w - r, l - r, 0]) cylinder(r=r, h=d);
    }
}

module femur_segment() {
    difference() {
        // Outer bone body with smooth continuous fillets
        smooth_bar(bone_length, bone_width, bone_depth, outer_radius);

        // Internal central wire tunnel along neutral bending axis
        translate([bone_width/2, bone_length/2, bone_depth/2])
            rotate([90, 0, 0])
            cylinder(r=wire_tunnel_dia/2, h=bone_length + 2, center=true);

        // Knee joint clevis cutout (Dual-shear pocket)
        translate([bone_width/2, bone_length - 10, bone_depth/2])
            cube([bone_width - 8, 22, bone_depth + 2], center=true);

        // Transverse pivot hole for knee hinge pin
        translate([-1, bone_length - 10, bone_depth/2])
            rotate([0, 90, 0])
            cylinder(r=pivot_pin_dia/2, h=bone_width + 2);

        // Recess for serial servo mounting
        translate([(bone_width - servo_pocket_w)/2, 15, bone_depth - servo_pocket_d])
            cube([servo_pocket_w, servo_pocket_l, servo_pocket_d + 1]);
    }
}

femur_segment();
