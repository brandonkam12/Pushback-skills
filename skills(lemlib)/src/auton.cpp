#include "autons.hpp"

#include "robot_config.hpp"
#include <sys/_intsup.h>

int leftwallx = 72;

int rightwallx = 0;

void skillsrightxreset() {
	chassis.setPose(((rightwallx - 4.75 - distance_left.get_distance()) * 0.0393701), chassis.getPose().y, chassis.getPose().theta);
}

void skillsleftxreset() {
	chassis.setPose(((leftwallx + 4.75 + distance_left.get_distance()) * 0.0393701), chassis.getPose().y, chassis.getPose().theta);
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
	bar.set_value(false);
	chassis.moveToPoint(-30.132, 16.266, 800);
	// leftxreset();

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
	
	chassis.moveToPoint(5, 45, 1000, {.maxSpeed = 76});
	chassis.waitUntil(36);

	chassis.turnToPoint(60, 90, 700);
	chassis.moveToPoint(60, 90, 700);
	bar.set_value(true);
	pros::delay(250);

	bar.set_value(false);
	pros::delay(250);

	chassis.turnToPoint(90, -50, 700);
	chassis.moveToPoint(0, 50, 700, {.forwards = false});

	chassis.turnToPoint(0, 80, 700);
	chassis.moveToPoint(1, 82, 700);
	intake_move(-12000);
	intakelift.set_value(false)


	bar.set_value(true);
	chassis.turnToPoint(30.132, 0.8, 700);
	chassis.moveToPoint(30.132, 0.8, 800, {.maxSpeed = 50});//match loader
	pros::delay(1000);

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

	intake_move(12000);
	stopper.set_value(false);

    // outtake.move_voltage(-12000);
    // mouth.move_voltage(12000);
    // wing.set_value(true);

    // chassis.setPose({0, 0, 0});
    // backwards(6000, 250);
    // bar.set_value(true);
    // forward(7000, 1500);
    // bar.set_value(false);
    // backwards(7000, 600);

	chassis.moveToPoint(-17.066, 35.733, 600);

	chassis.turnToPoint(-11.136, 41.429, 500, {.forwards = false});
	chassis.moveToPoint(-11.136, 41.429, 800, {.forwards = false});//middle goal
	scoremode_bool = false; //false is middle goal
	midgoalswitch.set_value(false);
	stopper.set_value(true);
	intake_move(12000);
	pros::delay(500);
	scoremode_bool = true;
	stopper.set_value(false);
	midgoalswitch.set_value(true);

	chassis.turnToPoint(-46.18, 9.833, 500);
	chassis.moveToPoint(-46.18, 9.833, 800);

	bar.set_value(true);
	chassis.turnToPoint(-46.18, -7.402, 500);
	chassis.moveToPoint(-46.18, -7.402, 800, {.maxSpeed = 50});//match loader

	chassis.moveToPoint(-46.18, 9.833, 800, {.forwards = false});

	bar.set_value(false);

	chassis.turnToPoint(-61.865, 17.866, 500);
	chassis.moveToPoint(-61.865, 17.866, 800);

	chassis.turnToPoint(-62.531, 97.597, 500);
	chassis.moveToPoint(-62.531, 97.597, 1000);//long 1

	chassis.turnToPoint(-47.065, 97.064, 500);
	chassis.moveToPoint(-47.065, 97.064, 800);

	chassis.turnToPoint(-47.52, 83.175, 500, {.forwards = false});
	chassis.moveToPoint(-47.52, 83.175, 800, {.forwards = false});//scoring 1

	skillsleftxreset();

	stopper.set_value(true);
	pros::delay(500);
	stopper.set_value(false);
	bar.set_value(true);

	chassis.moveToPoint(-46.946, 112.665, 800, {.maxSpeed = 50});//match loader 2
	pros::delay(1000);
	
	chassis.moveToPoint(-47.065, 97.064, 700, {.forwards = false});
	bar.set_value(false);

	chassis.turnToPoint(0, 98.397, 500);
	chassis.moveToPoint(0, 98.397, 800);

	chassis.turnToPoint(0, 120.263, 500);
	chassis.moveToPoint(0, 120.263, 1000, {.minSpeed = 20});//far park zone

	chassis.moveToPoint(0, 85.597, 800, {.forwards = false});

	chassis.turnToPoint(-25.199, 75.731, 500);
	chassis.moveToPoint(-25.199, 75.731, 800);
	chassis.waitUntil(20);
	bar.set_value(true);
	pros::delay(300);
	bar.set_value(false);

	chassis.turnToPoint(-10, 63.465, 500);
	chassis.moveToPoint(-10, 63.465, 800);//middle bottom goal
	intakelift.set_value(true);
	intake_move(-6000);
	pros::delay(700);

	chassis.moveToPoint(-25.199, 75.731, 750, {.forwards = false});
	intake_move(12000);

	chassis.turnToPoint(24.666, 77.331, 500);
	chassis.moveToPoint(24.666, 77.331, 800);//middle balls

	chassis.turnToPoint(48.665, 93.597, 500);
	chassis.moveToPoint(48.665, 93.597, 800);

	bar.set_value(true);
	chassis.turnToPoint(48.399, 118.396, 500);
	chassis.moveToPoint(48.399, 118.396, 800, {.maxSpeed = 50});//match loader 3
	pros::delay(500);

	chassis.moveToPoint(48.665, 93.597, 800, {.forwards = false});
	bar.set_value(false);

	chassis.turnToPoint(62.265, 87.731, 500);
	chassis.moveToPoint(62.265, 87.731, 800);

	chassis.turnToPoint(62.265, 10.933, 500);
	chassis.moveToPoint(62.265, 10.933, 1200);//long 2

	chassis.turnToPoint(48.399, 10.933, 500);
	chassis.moveToPoint(48.399, 10.933, 800);

	chassis.turnToPoint(47.332, 26.399, 500, {.forwards = false});
	chassis.moveToPoint(47.332, 26.399, 800, {.forwards = false});//scoring 2
	stopper.set_value(true);
	intake_move(12000);
	pros::delay(1000);
	stopper.set_value(false);
	bar.set_value(true);
	skillsrightxreset();

	chassis.moveToPoint(48.132, -6.933, 800);//match loader
	pros::delay(500);

	chassis.moveToPoint(48.399, 4.8, 800, {.forwards = false});

	chassis.turnToPoint(1.2, -10.666, 500);
	chassis.moveToPoint(1.2, -10.666, 1000, {.minSpeed = 30});//park

};

void sawp_auton() {
	
    chassis.setPose({0, 0, 0});

	intake_move(12000);
	stopper.set_value(false);

	chassis.moveToPoint(0, 34, 900, {.maxSpeed = 100});
	chassis.turnToPoint(18.5,34,600);
	bar.set_value(true);
    chassis.moveToPoint(17, 32, 700, {.maxSpeed=70}); //match loader
	pros::delay(1050);
    chassis.moveToPoint(-9, 32, 950, {.forwards=false, .minSpeed=90});
    chassis.moveToPoint(-29, 32, 1000, {.forwards=false, .maxSpeed=60}); //scoring
	stopper.set_value(true);
	intake_move(12000);
	pros::delay(120);

	chassis.setPose(-21, 34, chassis.getPose().theta); //reset pos after first long goal alignment

	bar.set_value(false);

	chassis.moveToPoint(-17, 34, 650, {.minSpeed=90});
	stopper.set_value(false);

	chassis.turnToHeading(225, 800);
	intake_move(12000);
    chassis.moveToPoint(-29.5, 13, 1500, {.minSpeed=34});//middle balls 1

	chassis.turnToPoint(-38, -38,400);

	chassis.moveToPoint(-39.3, -36, 600); //middle balls 2
	chassis.waitUntilDone();

	chassis.moveToPoint(-37, -36, 600, {.maxSpeed=90}); //middle balls back


	chassis.turnToPoint(0, -120, 500);
	chassis.waitUntilDone();

	chassis.setPose({0,0,0});
	chassis.moveToPoint(-10, 21, 700);
	chassis.turnToPoint(-140, 0, 500);


	chassis.setPose({0, 0, 0});
    chassis.moveToPoint(85, -45, 1000, {.forwards=false, .maxSpeed=90}); //scoring long goal 2
	chassis.waitUntilDone();

	stopper.set_value(true);
	intake_move(12000);
	pros::delay(600);

	chassis.setPose({0, 0, 0});
	bar.set_value(true);
	chassis.moveToPoint(0, 48, 1000);
	stopper.set_value(false);
	intake_move(12000);
	pros::delay(300);

	chassis.setPose({0,0,0});
	chassis.turnToHeading(35, 300);

	chassis.moveToPoint(-67, -48, 1000, {.forwards=false, .maxSpeed=90});
	intake_move(12000);
	pros::delay(1000);
	midgoalswitch.set_value(false);
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
