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
    skills_auton();
    break;
  case 1:
    skills75_auton();
    break;
  default:
    left_auton();
    break;
  }
}
