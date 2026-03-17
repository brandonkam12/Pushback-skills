#include "autons.hpp"

#include "robot_config.hpp"

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
	
	chassis.turnToPoint(-30.132, 0.8, 700);
	bar.set_value(true);
	chassis.moveToPoint(-30.132, 0.8, 800);//match loader

	chassis.moveToPose(-29.332, 34.399, -175, 800, {.forwards = false, .maxSpeed = 50});
	intake_move(12000);
	stopper.set_value(true);
	pros::delay(1000);

	intake_move(12000);
	stopper.set_value(false);

	chassis.moveToPoint(-30.132, 16.266, 800);

	chassis.turnToPoint(2.933, 47.732, 700);
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
	chassis.moveToPoint(30.132, 16.266, 800);

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
