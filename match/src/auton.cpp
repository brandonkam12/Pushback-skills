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
  pros::delay(600);
  bar.set_value(true);
  pros::delay(300);
  bar.set_value(false);
  // chassis.turnToPoint(-36, 54, 700, {.minSpeed = 40});
  // chassis.moveToPoint(-33, 41, 700, {.minSpeed = 40});
  // pros::delay(600);
  // bar.set_value(true);
  // pros::delay(600);
  // bar.set_value(false);
  // chassis.turnToPoint(-57, 80, 700, {.minSpeed = 40});
  // chassis.moveToPoint(-11, 33, 700, {.forwards = false, .minSpeed = 40});

  // chassis.turnToPoint(-55, 0, 600);
  // chassis.moveToPoint(0, 48, 600, {.forwards = false});
  // //  chassis.moveToPoint(4, 50, 400, {.forwards = false});
  // intake_move(6000);
  // pros::delay(750);
  // midgoalswitch.set_value(false);
  // pros::delay(800);
  // midgoalswitch.set_value(true);
  // intake_move(12000);
  chassis.turnToPoint(-32, 5, 800);
  chassis.moveToPoint(-32, 5, 1000, {.minSpeed = 55});

	chassis.turnToPoint(-32, -10, 700);
	bar.set_value(true);
	chassis.moveToPoint(-36, -38, 800, {.maxSpeed = 60});
	chassis.moveToPoint(-36, -40, 400, {.maxSpeed = 60});
  pros::delay(400);
	chassis.moveToPoint(-36, 50, 1500, {.forwards = false, .maxSpeed = 60});//scoring
	pros::delay(900);
	stopper.set_value(true);
  pros::delay(1000);
  bar.set_value(false);

	chassis.moveToPoint(-42, 6, 700);

  chassis.turnToPoint(-46, 6, 500, {.forwards = false, .minSpeed = 55});
  chassis.moveToPoint(-46, 6, 800, {.forwards = false, .minSpeed = 55});

  chassis.turnToPoint(-48, 24, 500, {.forwards = false, .minSpeed = 55});
  chassis.moveToPoint(-48, 24, 800, {.forwards = false, .minSpeed = 55});//wing
  
}


void right_auton() {

  intake_move(12000);
  stopper.set_value(false);

  // set position to x:0, y:0, heading:0
  chassis.setPose(0, 0,0);
  

  chassis.moveToPoint(10, 25, 700, {.minSpeed = 65});
  chassis.turnToPoint(36, 45, 1000, {.minSpeed = 65});
  chassis.moveToPoint(33, 45, 1000, {.minSpeed = 65});
  pros::delay(600);
  bar.set_value(true);
  pros::delay(600);
  bar.set_value(false);
  chassis.turnToPoint(57, 80, 500);
  chassis.moveToPoint(20, 20, 1300, {.forwards = false, .minSpeed = 65});
  // chassis.turnToPoint(-4, 43, 500);
  // chassis.moveToPoint(-10, 40, 1000, {.maxSpeed = 80});
  // pros::delay(500);
  // intake_move(-12000);
  // intakelift.set_value(false);
  // pros::delay(1500);

  intake_move(12000);
  intakelift.set_value(true);
  chassis.turnToPoint(32, 12, 1000, {.forwards = false,.minSpeed = 65});
  chassis.moveToPoint(32, 12, 1000, {.forwards = false, .minSpeed = 50});

  chassis.turnToPoint(32, -15, 600, {.minSpeed = 65});
  bar.set_value(true);
  chassis.moveToPoint(32, -40, 1000, {.maxSpeed = 60});
  chassis.moveToPoint(32, -48, 400, {.maxSpeed = 60});
  pros::delay(150);
  chassis.moveToPoint(32, 48, 1500, {.forwards = false, .maxSpeed = 60});//scoring
  pros::delay(1000);
  stopper.set_value(true);
  pros::delay(2500);
  bar.set_value(false);
  stopper.set_value(false);
  
  // chassis.moveToPoint(30, 10, 700);

  // chassis.turnToPoint(20, 10, 500, {.forwards = false, .minSpeed = 50});
  // chassis.moveToPoint(20, 10, 700, {.forwards = false, .minSpeed = 50});
  // chassis.turnToPoint(18, 31, 500, {.forwards = false, .minSpeed = 50});
  // chassis.moveToPoint(18, 31, 700, {.forwards = false, .minSpeed = 50});//wing
  
}


void sawp_auton() {

  chassis.setPose({0, 0, 90});
  intake_move(12000);

  chassis.moveToPoint(22, 0, 1000, {.maxSpeed = 100, .minSpeed = 40});
  chassis.turnToPoint(33, -22, 700);
  bar.set_value(true);
  chassis.moveToPoint(33, -9, 500, {.minSpeed = 40}); // match loader
  chassis.moveToPoint(33, -32, 700, {.maxSpeed = 20}); // match loader
  chassis.moveToPoint(33, 38, 1000,{.forwards = false, .minSpeed = 60}); // scoring
  bar.set_value(false);
  pros::delay(900);
  stopper.set_value(true);
  pros::delay(1000);
  stopper.set_value(false);
  chassis.turnToPoint(17, 25, 700);
//   chassis.moveToPoint(15.5, 28, 700, {.minSpeed = 115});
//   chassis.moveToPoint(12, -35, 500,  {.forwards = false, .minSpeed = 100});
//   intake_move(12000);
  // chassis.turnToPoint(-24, 30, 300);
  chassis.moveToPoint(-27, 25, 1200, {.minSpeed = 90}); // middle balls 2
  chassis.turnToPoint(-50, 2, 500);
  chassis.moveToPoint(-50, 2, 1100, {.minSpeed = 90});
  chassis.turnToHeading(180, 700);
  chassis.moveToPoint(-50, 30, 1100, {.forwards = false, .minSpeed = 50});
  pros::delay(700);
  stopper.set_value(true);
  pros::delay(1000);
  stopper.set_value(false);
  bar.set_value(true);
  // chassis.moveToPoint(-58, -10, 800, {.minSpeed = 127}); // match loader
  chassis.moveToPoint(-51, -54, 1200, {.maxSpeed = 70});
  pros::delay(1500);
  chassis.turnToPoint(-10, 30, 300, {.forwards = false});
  chassis.moveToPoint(-10, 30, 1000, {.forwards = false, .maxSpeed = 110});
  chassis.moveToPoint(-10, 30, 500, {.forwards = false, .maxSpeed = 110});
  intake_move(10000);
  pros::delay(300);
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

  chassis.setPose({0, 0, 90});
  intake_move(12000);

  chassis.moveToPoint(-22, 0, 1000, {.maxSpeed = 100, .minSpeed = 40});
  chassis.turnToPoint(-33, -22, 700);
  bar.set_value(true);
  chassis.moveToPoint(-33, -9, 500, {.minSpeed = 40}); // match loader
  chassis.moveToPoint(-33, -32, 700, {.maxSpeed = 20}); // match loader
  chassis.moveToPoint(-33, 38, 1000,{.forwards = false, .minSpeed = 60}); // scoring
  bar.set_value(false);
  pros::delay(900);
  stopper.set_value(true);
  pros::delay(1000);
  stopper.set_value(false);
  chassis.moveToPoint(-42, 6, 700);

  chassis.turnToPoint(-46, 6, 500, {.forwards = false, .minSpeed = 55});
  chassis.moveToPoint(-46, 6, 800, {.forwards = false, .minSpeed = 55});

  chassis.turnToPoint(-46, 24, 500, {.forwards = false, .minSpeed = 55});
  chassis.moveToPoint(-46, 24, 800, {.forwards = false, .minSpeed = 55});

	
  
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
  chassis.moveToPoint(34, -40, 1000, {.maxSpeed = 60});
  chassis.moveToPoint(34, -48, 1000, {.maxSpeed = 60});
  pros::delay(400);
  chassis.moveToPoint(32, 48, 1500, {.forwards = false, .maxSpeed = 60});//scoring
  pros::delay(900);
  stopper.set_value(true);
  pros::delay(1100);
  bar.set_value(false);
  stopper.set_value(false);

  
  chassis.moveToPoint(28, 10, 700);

  chassis.turnToPoint(20, 10, 500, {.forwards = false});
  chassis.moveToPoint(20, 10, 700, {.forwards = false});

  chassis.turnToPoint(20, 31, 500, {.forwards = false});
  chassis.moveToPoint(20, 31, 700, {.forwards = false});//wing
  
}

void tenleft_auton() {
  
  chassis.setPose({0, 0, 0});
  intake_move(12000);

  chassis.moveToPoint(0, -7, 1000);

//  chassis.turnToPoint(-34, -22, 700);
//   bar.set_value(true);
//   chassis.moveToPoint(-34, -25, 1000, {.maxSpeed = 50}); // match loader
//   pros::delay(1100);

//   chassis.moveToPoint(-34, 60, 900,{.forwards = false, .maxSpeed = 60}); // scoring
//   bar.set_value(false);
//   pros::delay(1050);
//   stopper.set_value(true);
//   pros::delay(1000);
//   stopper.set_value(false);

//   chassis.moveToPoint(-12, 28, 1000, {.minSpeed = 55});
//   pros::delay(800);
//   bar.set_value(true);
//   pros::delay(200);
//   bar.set_value(false);
//   pros::delay(500);

//  chassis.turnToPoint(3, 40, 500, {.forwards = false});
//   chassis.moveToPoint(3, 40, 1000, {.forwards = false, .maxSpeed = 60}); // middle balls and middle goal
//   intake_move(-6250);
//   intakelift.set_value(false);
//   pros::delay(1500);
//   intakelift.set_value(true);
//   chassis.moveToPoint(15, 35, 500,  {.forwards = false, .minSpeed = 55});
//   intake_move(12000);

//   chassis.turnToPoint(22, 30, 300);
//   chassis.moveToPoint(22, 30, 690, {.minSpeed = 55}); // middle balls 2
//   pros::delay(1000);
//   bar.set_value(true);
//   pros::delay(300);
//   bar.set_value(false);

//   intake_move(6000);
//   chassis.turnToPoint(70, 0, 300);
//   chassis.moveToPoint(16, 48, 800, {.forwards = false, .maxSpeed = 50});
//   pros::delay(750);
//   midgoalswitch.set_value(false);
//   pros::delay(1250);
//   midgoalswitch.set_value(true);

//   chassis.moveToPoint(29, 30, 690, {.minSpeed = 80});
//   pros::delay(500);
//   midgoaldescore.set_value(true);
//   chassis.moveToPoint(16, 48, 690, {.forwards = false, .maxSpeed = 60});
//   chassis.turnToPoint(-41.316, 97.533, 500);
//   chassis.moveToPoint(-41.316, 97.533, 800); // middle goal 2
//   stopper.set_value(true);
}

void lowgoallastsevenball() {
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
    chassis.moveToPoint(4, 45, 100, {.forwards = false});
  intake_move(6000);
  pros::delay(750);
  midgoalswitch.set_value(false);
  pros::delay(500);
  midgoalswitch.set_value(true);
  intake_move(12000);

  chassis.moveToPoint(-34, 5, 1000);

	chassis.turnToPoint(-34, -10, 700);
	bar.set_value(true);
	chassis.moveToPoint(-32, -38, 800, {.maxSpeed = 60});
	chassis.moveToPoint(-32, -40, 400, {.maxSpeed = 60});
  pros::delay(400);
	chassis.moveToPoint(-34, 52, 1500, {.forwards = false, .maxSpeed = 60});//scoring
		pros::delay(1000);
  stopper.set_value(true);
  pros::delay(1500);
	stopper.set_value(true);
  bar.set_value(false);

	chassis.moveToPoint(-42, 10, 700);

  chassis.turnToPoint(-44, 10, 500, {.forwards = false});
  chassis.moveToPoint(-44, 10, 800, {.forwards = false});

  chassis.turnToPoint(-44, 31, 500, {.forwards = false});
  chassis.moveToPoint(-44, 31, 800, {.forwards = false});//wing

}

void midgoallastsevenball() {
       intake_move(12000);
  stopper.set_value(false);

  // set position to x:0, y:0, heading:0
  chassis.setPose(0, 0, 0);

  chassis.moveToPoint(-10, 25, 1000, {.maxSpeed = 76});
  pros::delay(500);
  bar.set_value(true);
  pros::delay(300);

  chassis.turnToPoint(-50, 0, 600);
  // chassis.moveToPoint(4, 45, 600, {.forwards = false});
  //   chassis.moveToPoint(4, 45, 100, {.forwards = false});
  // intake_move(6000);
  // pros::delay(750);
  // midgoalswitch.set_value(false);
  // pros::delay(500);
  // midgoalswitch.set_value(true);
  // intake_move(12000);

  chassis.moveToPoint(-34, 5, 1000);

	chassis.turnToPoint(-34, -10, 700);
	bar.set_value(true);
	chassis.moveToPoint(-32, -38, 800, {.maxSpeed = 60});
	chassis.moveToPoint(-32, -40, 400, {.maxSpeed = 60});
  pros::delay(400);
	chassis.moveToPoint(-34, 52, 1500, {.forwards = false, .maxSpeed = 60});//scoring
		pros::delay(1000);
  stopper.set_value(true);
  pros::delay(1500);
	stopper.set_value(true);
  bar.set_value(false);

	chassis.moveToPoint(-42, 10, 700);

  chassis.turnToPoint(-44, 10, 500, {.forwards = false});
  chassis.moveToPoint(-44, 10, 800, {.forwards = false});

  chassis.turnToPoint(-44, 31, 500, {.forwards = false});
  chassis.moveToPoint(-44, 31, 800, {.forwards = false});//wing

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
    sawp_auton();
    break;
  case 3:
    tensawp_auton();
    break;
  case 4:
    elimleft_auton();
    break;
  case 5:
    elimright_auton();
    break;
  case 6:
    tenleft_auton();
    break;
  case 7:
    lowgoallastsevenball();
    break;
  case 8:
    midgoallastsevenball();
    break;
  default:
    left_auton();
    break;
  }
}
