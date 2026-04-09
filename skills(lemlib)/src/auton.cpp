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
  bar.set_value(false);

	chassis.moveToPoint(-42, 10, 700);

  chassis.turnToPoint(-44, 10, 500);
  chassis.moveToPoint(-44, 10, 800);

  chassis.turnToPoint(-44, 31, 500, {.forwards = false});
  chassis.moveToPoint(-44, 31, 800, {.forwards = false});//wing
  
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

  
  chassis.moveToPoint(28, 10, 700);

  chassis.turnToPoint(24, 10, 500);
  chassis.moveToPoint(24, 10, 700);

  chassis.turnToPoint(24, 31, 500, {.forwards = false});
  chassis.moveToPoint(24, 31, 700, {.forwards = false});//wing
  
}

void skills_auton() {
  chassis.setPose({0, 0, 90});
  intake_move(12000);
  chassis.moveToPoint(32, 0, 1000);
  pros::delay(300);
  chassis.turnToPoint(32, -22, 500);
  chassis.moveToPoint(32, -22, 1000);
  pros::delay(1500);
};

void sawp_auton() {

  chassis.setPose({0, 0, 90});
  intake_move(12000);

  chassis.moveToPoint(28, 0, 1000, {.minSpeed = 127});
  chassis.turnToPoint(28, -22, 500);
  bar.set_value(true);
  chassis.moveToPoint(28, -5, 500, {.minSpeed = 127}); // match loader
  chassis.moveToPoint(28, -22, 800, {.maxSpeed = 50}); // match loader
  pros::delay(1000);

  chassis.moveToPoint(28, 50, 900,{.forwards = false, .minSpeed = 70}); // scoring
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
  chassis.turnToPoint(-58, 10, 500);
  chassis.moveToPoint(-58, 10, 1000, {.minSpeed = 127});
  chassis.turnToHeading(180, 500);
  chassis.moveToPoint(-60, 38, 800, {.forwards = false, .minSpeed = 70});
  pros::delay(1000);
  stopper.set_value(true);
  pros::delay(1000);
  stopper.set_value(false);
  bar.set_value(true);
  // chassis.moveToPoint(-58, -10, 800, {.minSpeed = 127}); // match loader
  chassis.moveToPoint(-58, -54, 800, {.minSpeed = 70});
  pros::delay(1100);
  chassis.turnToPoint(-10, 47, 300, {.forwards = false});
  chassis.moveToPoint(-10, 47, 1000, {.forwards = false, .maxSpeed = 110});
  intake_move(8000);
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
  chassis.moveToPoint(34, -25, 1000, {.maxSpeed = 50}); // match loader
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

 chassis.turnToPoint(-3, 40, 500);
  chassis.moveToPoint(-3, 40, 1000, {.maxSpeed = 60}); // middle balls and middle goal
  intake_move(-6250);
  intakelift.set_value(false);
  pros::delay(1500);
  intakelift.set_value(true);
  chassis.moveToPoint(15, 35, 500,  {.forwards = false, .minSpeed = 55});
  intake_move(12000);

  chassis.turnToPoint(-22, 30, 300);
  chassis.moveToPoint(-22, 30, 690, {.minSpeed = 55}); // middle balls 2
  pros::delay(1000);
  bar.set_value(true);
  pros::delay(300);
  bar.set_value(false);

  intake_move(6000);
  chassis.turnToPoint(-70, 0, 300);
  chassis.moveToPoint(-16, 48, 800, {.forwards = false, .maxSpeed = 50});
  pros::delay(750);
  midgoalswitch.set_value(false);
  pros::delay(1250);
  midgoalswitch.set_value(true);

  chassis.moveToPoint(-29, 30, 690, {.minSpeed = 80});
  pros::delay(500);
  midgoaldescore.set_value(true);
  chassis.moveToPoint(-16, 48, 690, {.forwards = false, .maxSpeed = 60});
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

  chassis.moveToPoint(-34, 5, 1000);

	chassis.turnToPoint(-34, -10, 700);
	bar.set_value(true);
	chassis.moveToPoint(-34, -28, 1500, {.maxSpeed = 60});
	pros::delay(800);
	chassis.moveToPoint(-34, 52, 1500, {.forwards = false, .maxSpeed = 60});//scoring
		pros::delay(1000);
  stopper.set_value(true);
  pros::delay(1500);
	stopper.set_value(true);
  bar.set_value(false);

	chassis.moveToPoint(-42, 10, 700);

  chassis.turnToPoint(-44, 10, 500);
  chassis.moveToPoint(-44, 10, 800);

  chassis.turnToPoint(-44, 31, 500, {.forwards = false});
  chassis.moveToPoint(-44, 31, 800, {.forwards = false});//wing

	
  
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
  chassis.turnToPoint(-2, 40, 1000, {.minSpeed = 55});
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
  pros::delay(800);
  chassis.moveToPoint(32, 48, 1500, {.forwards = false, .maxSpeed = 60});//scoring
  pros::delay(1500);
  bar.set_value(false);
  stopper.set_value(true);

  
  chassis.moveToPoint(28, 10, 700);

  chassis.turnToPoint(24, 10, 500);
  chassis.moveToPoint(24, 10, 700);

  chassis.turnToPoint(24, 31, 500, {.forwards = false});
  chassis.moveToPoint(24, 31, 700, {.forwards = false});//wing
  
}

void skills75_auton() {
  intake_move(12000);
  chassis.setPose({0, 0, 0});

  chassis.moveToPoint(10, 25, 700, {.minSpeed = 55});

  chassis.turnToPoint(34, 0, 500);
  chassis.moveToPoint(34, 0, 700);

  chassis.turnToPoint(34, -24, 700);
  bar.set_value(true);
  chassis.moveToPoint(34, -24, 700);// match loader
  pros::delay(500);

  chassis.moveToPoint(34, 0, 700, {.forwards = false});
  bar.set_value(false);

  chassis.turnToPoint(46, 0, 600);
  chassis.moveToPoint(46, 0, 700);

  chassis.turnToPoint(46, 84, 600);
  chassis.moveToPoint(46, 84, 900);//long 1

  chassis.turnToPoint(34, 84, 600);
  chassis.moveToPoint(34, 84, 700);

  chassis.turnToPoint(34, 72, 600, {.forwards = false});
  chassis.moveToPoint(34, 72, 700, {.forwards = false});//scoring
  stopper.set_value(true);
  pros::delay(1000);
  stopper.set_value(false);

  chassis.setPose(34, 72, 0);

  bar.set_value(true);
  chassis.moveToPoint(34, 108, 700);//match loader
  pros::delay(500);

  chassis.moveToPoint(34, 72, 700, {.forwards = false});//scoring
  stopper.set_value(true);
  pros::delay(1000);
  stopper.set_value(false);

  chassis.setPose(34, 72, 0);

  chassis.moveToPoint(34, 84, 700);

  chassis.turnToPoint(-62, 84, 600);
  chassis.moveToPoint(-62, 84, 700);

  chassis.turnToPoint(-62, 108, 600);
  bar.set_value(true);
  chassis.moveToPoint(-62, 108, 700);//match loader
  pros::delay(500);

  chassis.moveToPoint(-62, 84, 700, {.forwards = false});

  chassis.turnToPoint(-74, 84, 600);
  chassis.moveToPoint(-74, 84, 700);

  chassis.turnToPoint(-74, 0, 600);
  chassis.moveToPoint(-74, 0, 900);//long 2

  chassis.turnToPoint(-62, 0, 600);
  chassis.moveToPoint(-62, 0, 700);

  chassis.turnToPoint(-62, 24, 600, {.forwards = false});
  chassis.moveToPoint(-62, 24, 700, {.forwards = false});//scoring
  stopper.set_value(true);
  pros::delay(1000);
  stopper.set_value(false);

  bar.set_value(true);
  chassis.moveToPoint(-62, -12, 700);//match loader
  pros::delay(500);

  chassis.moveToPoint(-62, 0, 700, {.forwards = false});

  chassis.turnToPoint(-38, 24, 700);
  chassis.moveToPoint(-38, 24, 700);//middle balls

  midgoalswitch.set_value(false);

  chassis.turnToPoint(-26, 36, 600, {.forwards = false});
  chassis.moveToPoint(-26, 36, 700, {.forwards = false}); //middle goal
  stopper.set_value(true);
  pros::delay(1000);
  stopper.set_value(false);

  chassis.turnToPoint(-36, -24, 600);
  chassis.moveToPoint(-36, -24, 700);

  chassis.turnToPoint(-12, -24, 600);
  chassis.moveToPoint(-12, -24, 700);//park 

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
  case 7:
    skills75_auton();
    break;
  default:
    left_auton();
    break;
  }
}
