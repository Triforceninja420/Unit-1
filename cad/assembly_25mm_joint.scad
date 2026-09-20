// =============================================================================
// Unit-1 Companion Module Joint Assembly
// Displays the chassis frame spars, interface bulkhead, dowels, and module plate
// =============================================================================

$fn = 60;

// Mechanical Parameters (mm)
tube_size       = 25.0;     // 25mm structural frame square tubing
tube_wall       = 3.0;      // 3mm wall thickness
tube_spacing    = 60.0;     // Torso frame spar center-to-center

plate_size      = 90.0;
plate_t         = 6.0;
grid_pitch      = 25.0;
dowel_d         = 4.0;
dowel_len       = 14.0;
umbilical_d     = 30.0;

// Color Palette
c_chassis       = [0.35, 0.38, 0.42, 1.0]; // Anodized grey
c_companion     = [0.20, 0.50, 0.80, 0.9]; // Anodized blue
c_steel         = [0.85, 0.85, 0.88, 1.0]; // Hardened steel
c_fastener      = [0.15, 0.15, 0.15, 1.0]; // Black oxide Class 12.9

module chassis_spar() {
    color(c_chassis) {
        difference() {
            cube([tube_size, tube_size, 150], center=true);
            cube([tube_size - 2*tube_wall, tube_size - 2*tube_wall, 152], center=true);
        }
    }
}

module base_bulkhead() {
    color(c_chassis) {
        difference() {
            cube([plate_size, plate_size, plate_t], center=true);
            cylinder(d=umbilical_d, h=plate_t + 2, center=true);
            
            // 4x M5 Tap holes (4.2mm drill for M5 thread)
            for (dx = [-grid_pitch/2, grid_pitch/2]) {
                for (dy = [-grid_pitch/2, grid_pitch/2]) {
                    translate([dx, dy, 0]) cylinder(d=4.2, h=plate_t + 2, center=true);
                }
            }
            // 2x Dowel pin press-fit holes
            translate([0,  32.5, 0]) cylinder(d=dowel_d, h=plate_t + 2, center=true);
            translate([0, -32.5, 0]) cylinder(d=dowel_d, h=plate_t + 2, center=true);
        }
    }
}

module companion_plate() {
    color(c_companion) {
        difference() {
            cube([plate_size, plate_size, plate_t], center=true);
            cylinder(d=umbilical_d, h=plate_t + 2, center=true);
            
            // 4x M5 Counterbored through holes
            for (dx = [-grid_pitch/2, grid_pitch/2]) {
                for (dy = [-grid_pitch/2, grid_pitch/2]) {
                    translate([dx, dy, 0]) cylinder(d=5.5, h=plate_t + 2, center=true);
                    translate([dx, dy, plate_t/2 - 3.2]) cylinder(d=10.0, h=4, center=false);
                }
            }
            // 2x Dowel alignment holes
            translate([0,  32.5, 0]) cylinder(d=dowel_d, h=plate_t + 2, center=true);
            translate([0, -32.5, 0]) cylinder(d=dowel_d, h=plate_t + 2, center=true);
        }
    }
}

// 1. Chassis Structural Tubing
translate([-tube_spacing/2, 0, -80]) chassis_spar();
translate([ tube_spacing/2, 0, -80]) chassis_spar();

// 2. Chassis Torso Mounting Bulkhead
translate([0, 0, -plate_t/2]) base_bulkhead();

// 3. Hardened Shear Dowels
color(c_steel) {
    translate([0,  32.5, 0]) cylinder(d=dowel_d, h=dowel_len, center=true);
    translate([0, -32.5, 0]) cylinder(d=dowel_d, h=dowel_len, center=true);
}

// 4. Companion Receiver Plate (Exploded +15mm along Z for clarity)
translate([0, 0, plate_t/2 + 15]) {
    companion_plate();

    // 5. Fasteners (DIN 912 M5x20 SHCS)
    color(c_fastener) {
        for (dx = [-grid_pitch/2, grid_pitch/2]) {
            for (dy = [-grid_pitch/2, grid_pitch/2]) {
                translate([dx, dy, 5]) {
                    cylinder(d=8.5, h=5, center=true); // Bolt Head
                    translate([0, 0, -12.5]) cylinder(d=5.0, h=20, center=true); // Shank
                }
            }
        }
    }
}
