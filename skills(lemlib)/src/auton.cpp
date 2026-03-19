#include "autons.hpp"

#include "robot_config.hpp"
#include <sys/_intsup.h>

int leftwallx = 0;

int leftwally = 0;

void rightxreset() {
	chassis.setPose(((leftwallx - 4.75 - distance_left.get_distance()) * 0.0393701), chassis.getPose().y, chassis.getPose().theta);
}

void leftxreset() {
	chassis.setPose(((leftwallx + 4.75 + distance_right.get_distance()) * 0.0393701), chassis.getPose().y, chassis.getPose().theta);
}

void left_auton() {


	intake_move(12000);

     // left
    chassis.setPose(0, 0, 0);
	
	chassis.moveToPoint(-5.159, 38.056, 1200, {.maxSpeed = 63.5});
	chassis.waitUntil(36);
	//bar down
	bar.set_value(true);
	pros::delay(250);

	chassis.turnToPoint(-30.132, 16.266, 700);
	chassis.moveToPoint(-30.132, 16.266, 800);

	leftxreset();

	pros::delay(500);
	
	chassis.turnToPoint(-30.132, 0.8, 700);
	bar.set_value(true);
	chassis.moveToPoint(-30.132, 0.8, 800);//match loader

	chassis.moveToPose(-29.332, 34.399, -175, 800, {.forwards = false, .maxSpeed = 50}); //scoring
	intake_move(12000);
	stopper.set_value(true);
	pros::delay(1000);

	intake_move(12000);
	stopper.set_value(false);

	chassis.moveToPoint(-30.132, 16.266, 900);

	chassis.turnToPoint(2.933, 47.732, 800);
	chassis.moveToPose(2.933, 47.732, 50, 900);
	intake_move(-12000);
	pros::delay(500);
	intake_move(12000);

	chassis.moveToPoint(-19.551, 25.245, 800, {.forwards = false});
	
	chassis.turnToPoint(-19.147, 48.922, 700);
	chassis.moveToPoint(-19.147, 48.922, 800);

}

void right_auton() {

	intake_move(12000);

     // set position to x:0, y:0, heading:0
    chassis.setPose(0, 0, 0);
	
	chassis.moveToPoint(5.159, 38.056, 1000, {.maxSpeed = 76});
	chassis.waitUntil(36);
	bar.set_value(true);
	pros::delay(250);

	bar.set_value(false);
	pros::delay(250);

	chassis.turnToPoint(30.132, 16.266, 700);
	chassis.moveToPose(30.132, 16.266, -5, 800);

	rightxreset();

	pros::delay(500);

	bar.set_value(true);
	chassis.turnToPoint(30.132, 0.8, 700);
	chassis.moveToPoint(30.132, 0.8, 800, {.maxSpeed = 50});//match loader
	pros::delay(500);

	chassis.moveToPose(29.332, 34.399, 175, 800, {.forwards = false, .maxSpeed = 63.5});//scoring
	intake_move(12000);
	stopper.set_value(true);
	pros::delay(1000);
	
	intake_move(12000);
	stopper.set_value(false);

	chassis.moveToPoint(30.132, 16.266, 800);

	chassis.turnToPoint(-2.933, 47.732, 500);
	chassis.moveToPose(-2.933, 47.732, 50, 800); //middle goal
	intake_move(-12000);
	pros::delay(1000);

	chassis.moveToPoint(21.6, 26.933, 500, {.forwards = false});

	chassis.turnToPoint(20.799, 49.599, 550);
	chassis.moveToPoint(20.799, 49.599, 1000, {.maxSpeed = 70});


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

	intake_move(12000);
	stopper.set_value(false);

	chassis.moveToPoint(0, 32, 1500);
    chassis.turnToHeading(90, 800);
    chassis.waitUntilDone();
	bar.set_value(true);
	pros::delay(50);
    chassis.moveToPoint(18, 33, 1000, {.maxSpeed=70}); //match loader

	pros::delay(1100);
    chassis.moveToPoint(-9, 33, 2000, {.forwards=false, .minSpeed=55});
    chassis.moveToPoint(-29, 33, 2000, {.forwards=false, .maxSpeed=75}); //scoring
	pros::delay(500);
	stopper.set_value(true);
	intake_move(12000);
	pros::delay(1000);

	chassis.setPose(-21, 34, chassis.getPose().theta);

	intake_move(12000);
	bar.set_value(false);

	chassis.moveToPoint(-6, 34, 2000, {.minSpeed=20});
	stopper.set_value(false);

	chassis.turnToHeading(225, 1000);
    chassis.moveToPoint(-33, 14, 3000, {.minSpeed=20});//middle balls 1

	chassis.turnToHeading(180, 1000);
	bar.set_value(true);
	pros::delay(300);
	bar.set_value(false);

	chassis.moveToPoint(-33, -38, 5000, {.minSpeed=20}); //middle balls 2
	pros::delay(1000);
	bar.set_value(true);

	chassis.turnToHeading(135, 1000);
	pros::delay(500);
	bar.set_value(false);

	chassis.moveToPoint(-42, -28, 1500, {.forwards=false, .maxSpeed=70}); //middle goal
	pros::delay(300);
	intake_move(-12000);
	pros::delay(150);
	midgoalswitch.set_value(false);
	intake_move(12000);
	intake_move(12000);
	pros::delay(400);
	midgoalswitch.set_value(true);
	intake_move(0);
	chassis.moveToPoint(-15, -42, 2000, {.earlyExitRange=8});
	chassis.moveToPoint(3, -58, 2000);
	chassis.turnToHeading(90, 1000);
	pros::delay(200);
	bar.set_value(true);
	chassis.moveToPoint(10, -58, 1000);
	chassis.moveToPoint(30, -58, 1000);
	pros::delay(800);
    chassis.moveToPoint(-8, -58, 2000, {.forwards=false});
    chassis.moveToPoint(-28, -58.5, 2000, {.forwards=false});
	pros::delay(50);
	stopper.set_value(true);

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
