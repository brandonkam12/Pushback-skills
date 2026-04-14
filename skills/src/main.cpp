#include "main.h"

#include <string>
#include <sys/_intsup.h>

#include "autons.hpp"
#include "liblvgl/llemu.hpp"
#include "pros/llemu.hpp"
#include "pros/misc.h"
#include "pros/rtos.hpp"
#include "robot_config.hpp"

int selector_stage = 0;

// 0 = skills, 1 = skills75 +=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=-=+++++++
int selected_auton = 1;
// 0 = skills, 1 = skills75

void on_button_pressed() {
    if (selected_auton < 7) {
    selected_auton = selected_auton + 1;    
    } else {
    selected_auton = 0;
    }
    pros::lcd::set_text(7, "auton selected: " + std::to_string(selected_auton));
};

bool bar_bool = true;
bool slowscoremode_bool =false;

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

    pros::lcd::register_btn0_cb(on_button_pressed);
    pros::lcd::register_btn1_cb(on_button_pressed);
    pros::lcd::register_btn2_cb(on_button_pressed);
    
    pros::lcd::set_text(7, "auton selected: " + std::to_string(selected_auton));
    
    mouth.set_brake_mode(pros::E_MOTOR_BRAKE_HOLD);
    outtake.set_brake_mode(pros::E_MOTOR_BRAKE_HOLD);

    bar.set_value(false);
    wing.set_value(false);
    midgoalswitch.set_value(true);
    stopper.set_value(false);
    intakelift.set_value(false);

    pros::lcd::set_text(6, "0 = skills, 1 = skills75");

    chassis.calibrate();
    pros::delay(1000);

while (imu.is_calibrating()) {
    pros::delay(10);
}


    printf("initialized");
}

void disabled() {}

void competition_initialize() {}

void autonomous() {
    run_auton_by_number(selected_auton);
    // chassis.setPose(0, 0, 0);
    // // turn to face heading 90 with a very long timeout
    // chassis.moveToPoint(0, 48, 10000, {.maxSpeed = 70});
}

void opcontrol() {
    midgoaldescore.set_value(true);
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

        if (scoremode_bool == true) {//true is up false is down
            midgoalswitch.set_value(true);
        } else {
            midgoalswitch.set_value(false);
        }

        if (controller.get_digital(pros::E_CONTROLLER_DIGITAL_R1)) {
            //outtake scoring
            stopper.set_value(true);
            if (scoremode_bool == false){
                mouth.move_voltage(12000);
                outtake.move_voltage(3000);
            } else {
                if (slowscoremode_bool == true) {
                    mouth.move_voltage(3000);
                    outtake.move_voltage(3000);
                
                }
                else{
                    mouth.move_voltage(12000);
                    outtake.move_voltage(12000);
                }
            }
            
            
        } else if (controller.get_digital(pros::E_CONTROLLER_DIGITAL_R2)) {
            //reverse
            stopper.set_value(false);
            mouth.move_voltage(-3000);
            outtake.move_voltage(-12000);          
        }
        else if (controller.get_digital(pros::E_CONTROLLER_DIGITAL_L1)) {
            //outtake
            stopper.set_value(false);
            if (scoremode_bool == false){
                mouth.move_voltage(12000);
                outtake.move_voltage(3000);
            } else {
                if (slowscoremode_bool == true) {
                    mouth.move_voltage(3000);
                    outtake.move_voltage(3000);
                
                }
                else{
                    mouth.move_voltage(12000);
                    outtake.move_voltage(12000);
                }
            }
            
        } else if (controller.get_digital(pros::E_CONTROLLER_DIGITAL_L2)) {
            //reverse
            stopper.set_value(false);
            mouth.move_voltage(-3000);
            outtake.move_voltage(-12000);
        } else {
            intake_brake();
        }

        if (controller.get_digital(pros::E_CONTROLLER_DIGITAL_B)) {
            slowscoremode_bool = true;
        } else {
            slowscoremode_bool = false;
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
};