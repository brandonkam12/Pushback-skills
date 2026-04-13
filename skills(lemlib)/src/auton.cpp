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
  chassis.turnToPoint(-36, 54, 700, {.minSpeed = 40});
  chassis.moveToPoint(-33, 38, 700, {.minSpeed = 40});
  pros::delay(600);
  bar.set_value(true);
  pros::delay(600);
  bar.set_value(false);
  chassis.turnToPoint(-57, 80, 700, {.minSpeed = 40});
  chassis.moveToPoint(-11, 33, 700, {.forwards = false, .minSpeed = 40});

  chassis.turnToPoint(-50, 0, 600);
  chassis.moveToPoint(4, 45, 600, {.forwards = false});
  intake_move(6000);
  pros::delay(750);
  midgoalswitch.set_value(false);
  pros::delay(800);
  midgoalswitch.set_value(true);
  intake_move(12000);

  chassis.moveToPoint(-32, 5, 1000, {.minSpeed = 55});

	chassis.turnToPoint(-36, -10, 700);
	bar.set_value(true);
	chassis.moveToPoint(-32, -38, 800, {.maxSpeed = 60});
	chassis.moveToPoint(-32, -40, 400, {.maxSpeed = 60});
	chassis.moveToPoint(-38, 50, 1500, {.forwards = false, .maxSpeed = 60});//scoring
	pros::delay(900);
	stopper.set_value(true);
  pros::delay(1000);
  bar.set_value(false);

	chassis.moveToPoint(-45, 10, 700, {.minSpeed = 55});

  chassis.turnToPoint(-50, 10, 500, { .forwards = false, .minSpeed = 55});
  chassis.moveToPoint(-50, 10, 800, { .forwards = false, .minSpeed = 55});

  chassis.turnToPoint(-50, 31, 500, {.forwards = false, .minSpeed = 55});
  chassis.moveToPoint(-50, 31, 800, {.forwards = false, .minSpeed = 55});//wing
  
}


void right_auton() {

  intake_move(12000);
  stopper.set_value(false);

  // set position to x:0, y:0, heading:0
  chassis.setPose(0, 0,0);
  

  chassis.moveToPoint(10, 25, 700, {.minSpeed = 55});
  chassis.turnToPoint(36, 54, 1000, {.minSpeed = 55});
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
  pros::delay(1500);

  intake_move(12000);
  intakelift.set_value(true);
  chassis.turnToPoint(-40, 48, 1000, {.minSpeed = 55});
  chassis.moveToPoint(26, 10, 1000, {.forwards = false, .minSpeed = 55});

  chassis.turnToPoint(34, -15, 1000, {.minSpeed = 55});
  bar.set_value(true);
  chassis.moveToPoint(34, -34, 1000, {.maxSpeed = 60});
  chassis.moveToPoint(34, -38, 200, {.maxSpeed = 60});
  pros::delay(200);
  chassis.moveToPoint(32, 48, 1500, {.forwards = false, .maxSpeed = 60});//scoring
  pros::delay(900);
  stopper.set_value(true);
  pros::delay(750);
  
  chassis.moveToPoint(28, 10, 700, {.minSpeed = 55});

  chassis.turnToPoint(24, 10, 500, {.minSpeed = 55});
  chassis.moveToPoint(24, 10, 700, {.minSpeed = 55});

  chassis.turnToPoint(24, 31, 500, {.forwards = false});
  chassis.moveToPoint(24, 31, 700, {.forwards = false});//wing
  
}

void skills_auton() {
  chassis.setPose({0, 0, 0});
  intake_move(12000);
  pros::delay(2500);
  chassis.moveToPoint(0, 10, 1000);
  pros::delay(2500);
  midgoaldescore.set_value(true);
  chassis.moveToPoint(0, -20, 2000, {.forwards = false});
  midgoaldescore.set_value(false); 
  chassis.moveToPoint(0, 15,2000, {.maxSpeed = 60});
  chassis.setPose({0, 0, 0});
  chassis.turnToPoint(-24, 40, 500);  
  // chassis.moveToPoint(-24, 40, 1500, {.forwards = false});
  // chassis.turnToPoint(-26, 38, 500);
  // chassis.moveToPoint(-26, 38, 500);
  // chassis.moveToPoint(-24, 40, 1000, {.forwards = false});
  // intake_move(7000);
  // pros::delay(750)
  // midgoalswitch.set_value(false);
  // pros::delay(5000);
  // midgoalswitch.set_value(true);
  // intake_move(12000);



    

};

void sawp_auton() {

  chassis.setPose({0, 0, 90});
  intake_move(12000);

  chassis.moveToPoint(27, 0, 1000, {.maxSpeed = 100, .minSpeed = 40});
  chassis.turnToPoint(28, -22, 700);
  bar.set_value(true);
  chassis.moveToPoint(38, -9, 500, {.minSpeed = 90}); // match loader
  chassis.moveToPoint(38, -23, 800, {.maxSpeed = 20}); // match loader
  pros::delay(900);

  chassis.moveToPoint(27, 50, 900,{.forwards = false, .minSpeed = 70}); // scoring
  bar.set_value(false);
  pros::delay(950);
  stopper.set_value(true);
  pros::delay(1000);
  stopper.set_value(false);
  chassis.turnToPoint(17, 35, 700);
//   chassis.moveToPoint(15.5, 28, 700, {.minSpeed = 115});
//  // chassis.moveToPoint(12, -35, 500,  {.forwards = false, .minSpeed = 100});
//   intake_move(12000);
  // chassis.turnToPoint(-24, 30, 300);
  chassis.moveToPoint(-24, 30, 1200, {.minSpeed = 115}); // middle balls 2
  chassis.turnToPoint(-50, 10, 500);
  chassis.moveToPoint(-50, 10, 1000, {.minSpeed = 127});
  chassis.turnToHeading(180, 500);
  chassis.moveToPoint(-50, 38, 800, {.forwards = false, .minSpeed = 70});
  pros::delay(900);
  stopper.set_value(true);
  pros::delay(1000);
  stopper.set_value(false);
  bar.set_value(true);
  // chassis.moveToPoint(-58, -10, 800, {.minSpeed = 127}); // match loader
  chassis.moveToPoint(-50, -54, 800, {.minSpeed = 70});
  pros::delay(1100);
  chassis.turnToPoint(-5, 40, 300, {.forwards = false});
  chassis.moveToPoint(-5, 40, 1000, {.forwards = false, .maxSpeed = 110});
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
	chassis.moveToPoint(-34, -30, 500, {.maxSpeed = 60});
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
  chassis.moveToPoint(34, -36, 1000, {.maxSpeed = 60});
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
  bar.set_value(false);
  intakelift.set_value(true);
  intake_move(12000);
  chassis.setPose({0, 0, 0});
  chassis.moveToPoint(13, 25, 700, {.minSpeed = 55});
  pros::delay(500);
  bar.set_value(true);
  pros::delay(300);
  chassis.turnToPoint(-2, 38, 1000, {.minSpeed = 55});
  bar.set_value(false);
  chassis.moveToPoint(-2, 38, 1000, {.minSpeed = 55});
  pros::delay(400);
  intakelift.set_value(false);
  intake_move(-8000);
  pros::delay(1000);
  intake_move(12000);
  intakelift.set_value(true);
  chassis.turnToPoint(32, 12, 500, {.forwards = false});
  chassis.moveToPoint(32, 12, 1500, {.forwards = false});
  intakelift.set_value(true);
  chassis.turnToPoint(32, -24, 500);
  bar.set_value(true);
  chassis.moveToPoint(34, -50, 400, {.maxSpeed = 60});// match loader
  chassis.moveToPoint(35, -50, 100, {.maxSpeed = 40});
  pros::delay(2000);
  chassis.moveToPoint(34, -24, 1000);

  chassis.turnToPoint(50, 0, 600, {.forwards = false});
  bar.set_value(false);
  chassis.moveToPoint(50, 0, 700, {.forwards = false});

  chassis.turnToPoint(50, 92, 600, {.forwards = false});
  chassis.moveToPoint(50, 92, 3000, {.forwards = false});//long 1
  chassis.turnToPoint(40, 92, 600, {.forwards = false});
  chassis.moveToPoint(40, 92, 700, {.forwards = false});
  chassis.turnToHeading(0, 1000);
  chassis.moveToPoint(40, 60, 700, {.forwards = false});//scoring
  pros::delay(750);
  stopper.set_value(true);
  pros::delay(2000);
  stopper.set_value(false);
  bar.set_value(true);
  chassis.moveToPoint(38, 140, 1000, {.maxSpeed = 60});
  chassis.moveToPoint(38, 140, 1000, {.maxSpeed = 40});
  pros::delay(2000);
  chassis.moveToPoint(40, 65, 1000, {.forwards = false, .maxSpeed = 60});
  chassis.moveToPoint(40, 65, 1000, {.forwards = false, .maxSpeed = 60});
  bar.set_value(false);
   pros::delay(750);
  stopper.set_value(true);
  pros::delay(2000);
  chassis.setPose({0, 0, 0});
  chassis.moveToPoint(0, 13, 1000);
  stopper.set_value(false);
  chassis.turnToPoint(-95, 13, 500);
  chassis.moveToPoint(-95, 13, 3000);
  
  chassis.turnToPoint(-100, 40, 700);
  bar.set_value(true);
  chassis.moveToPoint(-100, 40, 1000);
  chassis.moveToPoint(-100, 42, 1000);
  pros::delay(2000);
  chassis.turnToPoint(-130, 0, 500, {.forwards = false});
  chassis.moveToPoint(-130, 0, 1000, {.forwards = false});
  bar.set_value(false);
  chassis.turnToPoint(-150, -70, 500, {.forwards = false});
  chassis.moveToPoint(-150, -70, 2000, {.forwards = false});  
  chassis.turnToPoint(-120, -70, 500, {.forwards = false});
  chassis.moveToPoint(-120, -70, 1000, {.forwards = false}); 
  chassis.turnToPoint(-115, -50, 500, {.forwards = false});
  chassis.moveToPoint(-115, -50, 1000, {.forwards = false});
  // pros::delay(750);
  // stopper.set_value(true);
  // pros::delay(2000);
  // stopper.set_value(false);
  // bar.set_value(true);
  // chassis.moveToPoint(-107, -124, 1000);
  // pros::delay(2000);
  // chassis.moveToPoint(-107, -60, 1000, {.forwards = false}); 
  // pros::delay(750);
  // stopper.set_value(true);
  // pros::delay(2000); 
  // chassis.setPose({0, 0, 0});


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
