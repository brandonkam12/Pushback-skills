#include "main.h"

#include <string>
#include <sys/_intsup.h>

#include "autons.hpp"
#include "liblvgl/llemu.hpp"
#include "pros/llemu.hpp"
#include "pros/misc.h"
#include "pros/rtos.hpp"
#include "robot_config.hpp"

int selector_stage = 1;

// 0 = Left, 1 = Right, 2 = Skills, 3 = sawp, 4 = 10sawp, 5 = elimleft, 6 = elimright +=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=-=+++++++
int selected_auton =1;
// 0 = left, 1 = right, 2 = skills, 3 = sawp, 4 = 10sawp, 5 = elimleft, 6 = elimright 

// void left_callback() {
//     if (selector_stage == 1) {
//         int selected_auto  = 0;
//     }
//     else if (selector_stage == 2) {
//         int selected_auto  = 2;
//     }
  
// };
void left_callback() {
    if (selector_stage == 1) {
        selected_auton = 0;
        selector_stage = 0;
    }
    else if (selector_stage == 2) {
        selected_auton = 2;
        selector_stage = 0;
    }
    else if (selector_stage == 3) {
        selected_auton = 4;
        selector_stage = 0;
    }
}
void middle_callback() {
    if (selector_stage == 1) {
        selected_auton = 1;
        selector_stage = 0;
    }
    else if (selector_stage == 2) {
        selected_auton = 3;
        selector_stage = 0;
    }
    else if (selector_stage == 3) {
        selected_auton = 5;
        selector_stage = 0;
    }
  
};
void right_callback() {
    if (selector_stage == 1) {
        selector_stage = 2;
    }
    else if (selector_stage == 2) {
        selector_stage = 3;
    }
    else if (selector_stage == 3) {
        selected_auton = 6;
        selector_stage = 0;
    }
  
};

bool bar_bool = true;


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

    bar.set_value(false);
    wing.set_value(false);
    midgoalswitch.set_value(true);
    stopper.set_value(true);
    intakelift.set_value(true);

    chassis.calibrate();
    pros::delay(1000);

while (imu.is_calibrating()) {
    pros::delay(10);
}
    static pros::Task screen_task([]() {
        while (true) {
            
            pros::lcd::register_btn0_cb(left_callback);
            pros::lcd::register_btn1_cb(middle_callback);
            pros::lcd::register_btn2_cb(right_callback);
            double ex =1.5;
            // pros::lcd::print(0, "X: %f", chassis.getPose().x);
            // pros::lcd::print(1, "Y: %f", chassis.getPose().y);
            // pros::lcd::print(2, "Theta: %f", chassis.getPose().theta);
            // pros::lcd::print(3, "IMU Heading: %f", imu.get_heading());
            // pros::lcd::print(4, "Rotation Sensor: %i", horizontal_sensor.get_position());
            printf("imu theta: %lf\n", imu.get_heading());
            pros::delay(20);
            if (selector_stage == 1) {
                pros::lcd::set_text(7, "left, right, next page");
            }
            else if (selector_stage == 2) {
                pros::lcd::set_text(7, "skills, sawp, next page");
            }
            else if (selector_stage == 3) {
                pros::lcd::set_text(7, "10sawp, elimleft, elimright");
            }
            else {
                pros::lcd::set_text(6, "// 0 = Left, 1 = Right, 2 = Skills, 3 = sawp, 4 = 10sawp, 5 = elimleft, 6 = elimright");
                pros::lcd::set_text(7, "auton selected: " + std::to_string(selected_auton));
            }
            pros::delay(100);
        }
    });

    printf("initialized");
}

void disabled() {}

void competition_initialize() {}

void autonomous() {
right_auton();
    // chassis.setPose(0, 0, 0);
    // // turn to face heading 90 with a very long timeout
    // chassis.moveToPoint(0, 48, 10000, {.maxSpeed = 70});
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
            if (scoremode_bool) {
                stopper.set_value(true);
                intakelift.set_value(true);
            } else {
                stopper.set_value(false);
            }
        } else if (controller.get_digital(pros::E_CONTROLLER_DIGITAL_R2)) {
            intake_move(-12000);
            stopper.set_value(true);
            intakelift.set_value(false);
            if (selected_auton == 2) {
                intakelift.set_value(false);
            }
        } else if (controller.get_digital(pros::E_CONTROLLER_DIGITAL_L1)) {
            intake_move(12000);
            stopper.set_value(false);
            intakelift.set_value(true);
        } else if (controller.get_digital(pros::E_CONTROLLER_DIGITAL_L2)) {
            intake_move(-12000);
            stopper.set_value(false);
            intakelift.set_value(true);
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
