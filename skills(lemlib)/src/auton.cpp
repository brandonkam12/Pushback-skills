#include "autons.hpp"

#include "pros/rtos.hpp"
#include "robot_config.hpp"
#include <sys/_intsup.h>

int leftwallx = 72;

int rightwallx = 0;

void skillsrightxreset() {
  chassis.setPose(
      ((rightwallx - 4.75 - distance_left.get_distance()) * 0.0393701),
      chassis.getPose().y, chassis.getPose().theta);
}

void skillsleftxreset() {
  chassis.setPose(
      ((leftwallx + 4.75 + distance_left.get_distance()) * 0.0393701),
      chassis.getPose().y, chassis.getPose().theta);
}

void left_auton() {
  intake_move(12000);
  stopper.set_value(false);

  // set position to x:0, y:0, heading:0
  chassis.setPose(0, 0, 0);

  chassis.moveToPoint(-10, 25, 1000, {.maxSpeed = 76});
  pros::delay(500);
  bar.set_value(true);
  pros::delay(300);
  bar.set_value(false);
  chassis.turnToPoint(-36, 54, 700);
  chassis.moveToPoint(-33, 38, 700);
  pros::delay(600);
  bar.set_value(true);
  pros::delay(600);
  bar.set_value(false);
  chassis.turnToPoint(-57, 80, 700);
  chassis.moveToPoint(-11, 33, 700, {.forwards = false});

  chassis.turnToPoint(-50, 0, 600);
  chassis.moveToPoint(4, 45, 600, {.forwards = false});
  intake_move(6000);
  pros::delay(750);
  midgoalswitch.set_value(false);
  pros::delay(800);
  midgoalswitch.set_value(true);
  intake_move(12000);

  chassis.moveToPoint(-32, 5, 1000);

	chassis.turnToPoint(-36, -10, 700);
	bar.set_value(true);
	chassis.moveToPoint(-32, -32, 1500, {.maxSpeed = 60});
	pros::delay(1000);
	chassis.moveToPoint(-38, 50, 1500, {.forwards = false, .maxSpeed = 60});//scoring
	pros::delay(1500);
	stopper.set_value(true);

	chassis.moveToPoint(-32, 10, 700);

  chassis.turnToPoint(-48, 10, 500);
  chassis.moveToPoint(-48, 10, 800);

  chassis.turnToPoint(-48, 31, 500, {.forwards = false});
  chassis.moveToPoint(-48, 31, 800, {.forwards = false});//wing
  
}


void right_auton() {

  intake_move(12000);
  stopper.set_value(false);

  // set position to x:0, y:0, heading:0
  chassis.setPose(0, 0,0);
  

  chassis.moveToPoint(10, 25, 700, {.minSpeed = 55});
  chassis.turnToPoint(36, 54, 1000);
  chassis.moveToPoint(31, 36, 1000, {.minSpeed = 55});
  pros::delay(600);
  bar.set_value(true);
  pros::delay(600);
  bar.set_value(false);
  chassis.turnToPoint(57, 80, 500);
  chassis.moveToPoint(11, 33, 1000, {.forwards = false, .minSpeed = 55});

  chassis.moveToPoint(-2, 40, 1000, {.minSpeed = 55});
  intake_move(-6000);
  intakelift.set_value(false);
  pros::delay(1750);

  intake_move(12000);
  intakelift.set_value(true);
  chassis.turnToPoint(-40, 48, 1000);
  chassis.moveToPoint(26, 10, 1000, {.forwards = false, .minSpeed = 45});

  chassis.turnToPoint(34, -15, 1000);
  bar.set_value(true);
  chassis.moveToPoint(34, -34, 1000, {.maxSpeed = 60});
  pros::delay(350);
  chassis.moveToPoint(32, 48, 1500, {.forwards = false, .maxSpeed = 60});//scoring
  pros::delay(1500);
  stopper.set_value(true);

  
  chassis.moveToPoint(32, 10, 700);

  chassis.turnToPoint(21, 10, 500);
  chassis.moveToPoint(22, 10, 700);

  chassis.turnToPoint(20, 31, 500, {.forwards = false});
  chassis.moveToPoint(20, 31, 700, {.forwards = false});//wing
  
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
  chassis.moveToPoint(-11.136, 41.429, 800, {.forwards = false}); // middle goal
  scoremode_bool = false; // false is middle goal
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
  chassis.moveToPoint(-46.18, -7.402, 800, {.maxSpeed = 50}); // match loader

  chassis.moveToPoint(-46.18, 9.833, 800, {.forwards = false});

  bar.set_value(false);

  chassis.turnToPoint(-61.865, 17.866, 500);
  chassis.moveToPoint(-61.865, 17.866, 800);

  chassis.turnToPoint(-62.531, 97.597, 500);
  chassis.moveToPoint(-62.531, 97.597, 1000); // long 1

  chassis.turnToPoint(-47.065, 97.064, 500);
  chassis.moveToPoint(-47.065, 97.064, 800);

  chassis.turnToPoint(-47.52, 83.175, 500, {.forwards = false});
  chassis.moveToPoint(-47.52, 83.175, 800, {.forwards = false}); // scoring 1

  skillsleftxreset();

  stopper.set_value(true);
  pros::delay(500);
  stopper.set_value(false);
  bar.set_value(true);

  chassis.moveToPoint(-46.946, 112.665, 800, {.maxSpeed = 50}); // match loader
                                                                // 2
  pros::delay(1000);

  chassis.moveToPoint(-47.065, 97.064, 700, {.forwards = false});
  bar.set_value(false);

  chassis.turnToPoint(0, 98.397, 500);
  chassis.moveToPoint(0, 98.397, 800);

  chassis.turnToPoint(0, 120.263, 500);
  chassis.moveToPoint(0, 120.263, 1000, {.minSpeed = 20}); // far park zone

  chassis.moveToPoint(0, 85.597, 800, {.forwards = false});

  chassis.turnToPoint(-25.199, 75.731, 500);
  chassis.moveToPoint(-25.199, 75.731, 800);
  chassis.waitUntil(20);
  bar.set_value(true);
  pros::delay(300);
  bar.set_value(false);

  chassis.turnToPoint(-10, 63.465, 500);
  chassis.moveToPoint(-10, 63.465, 800); // middle bottom goal
  intakelift.set_value(true);
  intake_move(-6000);
  pros::delay(700);

  chassis.moveToPoint(-25.199, 75.731, 750, {.forwards = false});
  intake_move(12000);

  chassis.turnToPoint(24.666, 77.331, 500);
  chassis.moveToPoint(24.666, 77.331, 800); // middle balls

  chassis.turnToPoint(48.665, 93.597, 500);
  chassis.moveToPoint(48.665, 93.597, 800);

  bar.set_value(true);
  chassis.turnToPoint(48.399, 118.396, 500);
  chassis.moveToPoint(48.399, 118.396, 800, {.maxSpeed = 50}); // match loader 3
  pros::delay(500);

  chassis.moveToPoint(48.665, 93.597, 800, {.forwards = false});
  bar.set_value(false);

  chassis.turnToPoint(62.265, 87.731, 500);
  chassis.moveToPoint(62.265, 87.731, 800);

  chassis.turnToPoint(62.265, 10.933, 500);
  chassis.moveToPoint(62.265, 10.933, 1200); // long 2

  chassis.turnToPoint(48.399, 10.933, 500);
  chassis.moveToPoint(48.399, 10.933, 800);

  chassis.turnToPoint(47.332, 26.399, 500, {.forwards = false});
  chassis.moveToPoint(47.332, 26.399, 800, {.forwards = false}); // scoring 2
  stopper.set_value(true);
  intake_move(12000);
  pros::delay(1000);
  stopper.set_value(false);
  bar.set_value(true);
  skillsrightxreset();


  chassis.moveToPoint(48.132, -6.933, 800); // match loader
  pros::delay(500);

  chassis.moveToPoint(48.399, 4.8, 800, {.forwards = false});

  chassis.turnToPoint(1.2, -10.666, 500);
  chassis.moveToPoint(1.2, -10.666, 1000, {.minSpeed = 30}); // park
};

void sawp_auton() {

  chassis.setPose({0, 0, 90});
  intake_move(12000);

  chassis.moveToPoint(32, 0, 1000);
  pros::delay(300);
  chassis.turnToPoint(32, -22, 500);
  bar.set_value(true);
  chassis.moveToPoint(32, -5, 800, {.minSpeed = 127}); // match loader
  chassis.moveToPoint(32, -22, 800, {.maxSpeed = 50}); // match loader
  pros::delay(1000);

  chassis.moveToPoint(30.5, 50, 900,{.forwards = false, .minSpeed = 70}); // scoring
  bar.set_value(false);
  pros::delay(950);
  stopper.set_value(true);
  pros::delay(1000);
  stopper.set_value(false);
  chassis.turnToPoint(17, 30, 500);
  chassis.moveToPoint(15.5, 28, 700, {.minSpeed = 115});
 // chassis.moveToPoint(12, -35, 500,  {.forwards = false, .minSpeed = 100});
  intake_move(12000);

  chassis.turnToPoint(-24, 30, 300);
  chassis.moveToPoint(-24, 30, 800, {.minSpeed = 115}); // middle balls 2
  chassis.turnToPoint(-54, 0, 500);
  chassis.moveToPoint(-54, 0, 1000, {.minSpeed = 127});
  chassis.turnToHeading(180, 500);
  chassis.moveToPoint(-54, 50, 800, {.forwards = false, .minSpeed = 90});
  pros::delay(1000);
  stopper.set_value(true);
  pros::delay(1000);
  stopper.set_value(false);
  bar.set_value(true);
  chassis.moveToPoint(-50, -10, 800, {.minSpeed = 127}); // match loader
  chassis.moveToPoint(-50, -35, 800, {.maxSpeed = 50});
  pros::delay(1100);
  intake_move(8000);
  chassis.turnToPoint(-10, 38, 300, {.forwards = false});
  chassis.moveToPoint(-10, 38, 1000, {.forwards = false, .maxSpeed = 110});
  pros::delay(1100);
  midgoalswitch.set_value(false);
  pros::delay(1250);
  midgoalswitch.set_value(true);


}

void tensawp_auton() {
  chassis.setPose({0, 0, 90});
  intake_move(12000);

  chassis.moveToPoint(34, 0, 1000);

 chassis.turnToPoint(34, -22, 700);
  bar.set_value(true);
  chassis.moveToPoint(34, -22, 1000, {.maxSpeed = 50}); // match loader
  pros::delay(1100);

  chassis.moveToPoint(34, 60, 900,{.forwards = false, .maxSpeed = 60}); // scoring
  bar.set_value(false);
  pros::delay(1050);
  stopper.set_value(true);
  pros::delay(1000);
  stopper.set_value(false);

  chassis.moveToPoint(12, 28, 1000, {.minSpeed = 55});
  pros::delay(800);
  bar.set_value(true);
  pros::delay(200);
  bar.set_value(false);
  pros::delay(500);

 chassis.turnToPoint(-3, 42, 500);
  chassis.moveToPoint(-3, 42, 1000, {.maxSpeed = 60}); // middle balls and middle goal
  intake_move(-6250);
  intakelift.set_value(false);
  pros::delay(1500);
  intakelift.set_value(true);
  chassis.moveToPoint(15, 35, 500,  {.forwards = false, .minSpeed = 55});
  intake_move(12000);

  chassis.turnToPoint(-10, 30, 300);
  chassis.moveToPoint(-10, 30, 690, {.minSpeed = 55}); // middle balls 2
  pros::delay(1000);
  bar.set_value(true);
  pros::delay(300);
  bar.set_value(false);

  intake_move(6000);
  chassis.turnToPoint(-70, 0, 300);
  chassis.moveToPoint(-16, 45, 800, {.forwards = false, .maxSpeed = 50});
  pros::delay(750);
  midgoalswitch.set_value(false);
  pros::delay(1250);
  midgoalswitch.set_value(true);

  chassis.moveToPoint(-31, 30, 690, {.minSpeed = 80});
  pros::delay(500);
  midgoaldescore.set_value(true);
  chassis.moveToPoint(-16, 45, 690, {.forwards = false, .maxSpeed = 60});
//   chassis.turnToPoint(-41.316, 97.533, 500, {.forwards = false});
//   chassis.moveToPoint(-41.316, 97.533, 800,
//                       {.forwards = false}); // middle goal 2
//   stopper.set_value(true);
}
void elimleft_auton() {
   intake_move(12000);
  stopper.set_value(false);

  // set position to x:0, y:0, heading:0
  chassis.setPose(0, 0, 0);

  chassis.moveToPoint(-10, 25, 1000, {.maxSpeed = 76});
  pros::delay(500);
  bar.set_value(true);
  pros::delay(300);

  chassis.turnToPoint(-50, 0, 600);
  chassis.moveToPoint(4, 45, 600, {.forwards = false});
  intake_move(6000);
  pros::delay(750);
  midgoalswitch.set_value(false);
  pros::delay(500);
  midgoalswitch.set_value(true);
  intake_move(12000);

  chassis.moveToPoint(-32, 5, 1000);

	chassis.turnToPoint(-32, -10, 700);
	bar.set_value(true);
	chassis.moveToPoint(-32, -22, 1500, {.maxSpeed = 60});
	pros::delay(800);
	chassis.moveToPoint(-36, 52, 1500, {.forwards = false, .maxSpeed = 60});//scoring
		pros::delay(1000);
  stopper.set_value(true);
  pros::delay(1500);
	stopper.set_value(true);
  bar.set_value(false);

	chassis.moveToPoint(-32, 10, 700);

  chassis.turnToPoint(-48, 10, 500);
  chassis.moveToPoint(-48, 10, 800);

  chassis.turnToPoint(-48, 31, 500, {.forwards = false});
  chassis.moveToPoint(-48, 31, 800, {.forwards = false});//wing

	
  
}
void elimright_auton() {
  intake_move(12000);
  stopper.set_value(false);

  // set position to x:0, y:0, heading:0
  chassis.setPose(0, 0,0);
  

  chassis.moveToPoint(10, 25, 700, {.minSpeed = 55});
  pros::delay(500);
  bar.set_value(true);
  pros::delay(300);
  bar.set_value(false);
  chassis.turnToPoint(0, 37, 1000, {.minSpeed = 55});
  chassis.moveToPoint(0, 37, 1000, {.minSpeed = 55});
  intake_move(-6000);
  intakelift.set_value(false);
  pros::delay(1750);

  intake_move(12000);
  intakelift.set_value(true);
  chassis.turnToPoint(-40, 48, 1000);
  chassis.moveToPoint(26, 10, 1000, {.forwards = false, .minSpeed = 45});

  chassis.turnToPoint(34, -15, 1000);
  bar.set_value(true);
  chassis.moveToPoint(34, -34, 1000, {.maxSpeed = 60});
  pros::delay(800);
  chassis.moveToPoint(32, 48, 1500, {.forwards = false, .maxSpeed = 60});//scoring
  pros::delay(1500);
  bar.set_value(false);
  stopper.set_value(true);

  
  chassis.moveToPoint(32, 10, 700);

  chassis.turnToPoint(21, 10, 500);
  chassis.moveToPoint(22, 10, 700);

  chassis.turnToPoint(20, 31, 500, {.forwards = false});
  chassis.moveToPoint(20, 31, 700, {.forwards = false});//wing
  
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
    tensawp_auton();
    break;
  case 5:
    elimleft_auton();
    break;
  case 6:
    elimright_auton();
    break;
  default:
    left_auton();
    break;
  }
}
