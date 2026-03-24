#include "main.h"

#include <string>

#include "autons.hpp"
#include "liblvgl/llemu.hpp"
#include "pros/llemu.hpp"
#include "pros/misc.h"
#include "pros/rtos.hpp"
#include "robot_config.hpp"


bool bar_bool = true;

// 0 = Left, 1 = Right, 2 = Skills, 3 = sawp, 4 = forwards +=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=-=+++++++
int selected_auton = 3;
// 0 = left, 1 = right, 2 = skills, 3 = sawp, 4 = forwards +=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=(=+=========+++++++

int get_color(double hue) {
    int c = 2;
    if (hue <= 35) {
        c = 1;
    } else if (hue >= 150) {
        c = 0;
    } else {
        c = 2;
    }
    return c;
}

void display_number(short int line, int nums) {
    pros::lcd::set_text(line, std::to_string(nums));
}

void on_center_button() {
    static bool pressed = false;
    pressed = !pressed;
    if (pressed) {
        pros::lcd::set_text(2, "I was pressed!");
    } else {
        pros::lcd::clear_line(2);
    }
}

void initialize() {
    pros::lcd::initialize();

    mouth.set_brake_mode(pros::E_MOTOR_BRAKE_HOLD);
    outtake.set_brake_mode(pros::E_MOTOR_BRAKE_HOLD);
    left_legs.set_brake_mode(pros::E_MOTOR_BRAKE_HOLD);
    right_legs.set_brake_mode(pros::E_MOTOR_BRAKE_HOLD);

    bar.set_value(false);
    wing.set_value(false);
    midgoalswitch.set_value(true);
    stopper.set_value(true);
    intakelift.set_value(true);

    imu.reset();
    chassis.calibrate();

    static pros::Task screen_task([]() {
        while (true) {
            pros::lcd::print(0, "X: %f", chassis.getPose().x);
            pros::lcd::print(1, "Y: %f", chassis.getPose().y);
            pros::lcd::print(2, "Theta: %f", chassis.getPose().theta);
            pros::lcd::print(3, "Rotation Sensor: %i", horizontal_sensor.get_position());
            pros::delay(20);
        }
    });

    imu.reset(true);
    printf("initialized");
}

void disabled() {}

void competition_initialize() {}

void autonomous() {
    run_auton_by_number(selected_auton);
}

void opcontrol() {
    while (true) {
        const double drive_temp = (left_legs.get_temperature() + right_legs.get_temperature()) / 2;
        controller.print(0, 0, "DT: %0.1f", drive_temp);

        int leftY = controller.get_analog(pros::E_CONTROLLER_ANALOG_LEFT_Y);
        int rightX = controller.get_analog(pros::E_CONTROLLER_ANALOG_RIGHT_X);

        left_legs.move(leftY + rightX);
        right_legs.move(leftY - rightX);

        if (controller.get_digital(pros::E_CONTROLLER_DIGITAL_Y)) {
            scoremode_bool = false;
        } else {
            scoremode_bool = true;
        }

        if (scoremode_bool) {
            midgoalswitch.set_value(true);
        } else {
            midgoalswitch.set_value(false);
        }

        if (controller.get_digital(pros::E_CONTROLLER_DIGITAL_R1)) {
            intake_move(12000);
            stopper.set_value(true);
        } else if (controller.get_digital(pros::E_CONTROLLER_DIGITAL_R2)) {
            intake_move(-12000);
            stopper.set_value(true);
            if (selected_auton == 2) {
                intakelift.set_value(false);
            }
        } else if (controller.get_digital(pros::E_CONTROLLER_DIGITAL_L1)) {
            intake_move(12000);
            stopper.set_value(false);
        } else if (controller.get_digital(pros::E_CONTROLLER_DIGITAL_L2)) {
            intake_move(-12000);
            stopper.set_value(false);
            if (selected_auton == 2) {
                intakelift.set_value(false);
            }
        } else {
            intake_brake();
        }

        if (controller.get_digital(pros::E_CONTROLLER_DIGITAL_B)) {
            wing.set_value(false);
        } else {
            wing.set_value(true);
        }

        if (controller.get_digital_new_press(pros::E_CONTROLLER_DIGITAL_DOWN)) {
            bar.set_value(bar_bool);
            bar_bool = !bar_bool;
        }
        
        if (controller.get_digital(pros::E_CONTROLLER_DIGITAL_RIGHT)) {
            midgoaldescore.set_value(true);
        }
        else {
            midgoaldescore.set_value(false);
        }


        pros::delay(25);
    }
}
