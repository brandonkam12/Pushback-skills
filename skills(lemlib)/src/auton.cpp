#include "autons.hpp"

#include "robot_config.hpp"

void left_auton() {
    chassis.setPose({0, 0, 0});
}

void right_auton() {
    chassis.setPose({0, 0, 0});
}

void skills_auton() {
    chassis.setPose({0, 0, 0});

    outtake.move_voltage(-12000);
    mouth.move_voltage(12000);
    wing.set_value(true);

    chassis.setPose({0, 0, 0});
    backwards(6000, 250);
    bar.set_value(true);
    forward(7000, 1500);
    bar.set_value(false);
    backwards(7000, 600);
}
void sawp_auton() {
    chassis.setPose({0, 0, 0});
}

void forwards_auton() {
    forward(7000, 3000);
}

void run_auton_by_number(int auton_number) {
    switch (auton_number) {
        case 0:
            left_auton();
            break;
        case 1:
            right_auton();
            break;
        case 2:
            skills_auton();
            break;
        case 3:
            sawp_auton();
            break;
        case 4:
            forwards_auton();
            break;
        default:
            left_auton();
            break;
    }
}
