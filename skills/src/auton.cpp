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
  mouth.move_voltage(12000);
  outtake.move_voltage(12000);
  pros::delay(2500);
  chassis.moveToPoint(0, 5, 1000);
  pros::delay(2500);
  midgoaldescore.set_value(true);
  chassis.moveToPoint(0, -12, 2000, {.forwards = false});
  midgoaldescore.set_value(false);
  chassis.turnToPoint(-3, 18,1000, {.maxSpeed = 40});
  chassis.moveToPoint(0, 18,1000, {.maxSpeed = 40});
  chassis.setPose({0, 0, 0});
  chassis.moveToPose(-4, -60,45,2000, {.forwards = false, .minSpeed = 10});
  chassis.turnToPoint(25, -10, 1000);
  chassis.moveToPoint(25, -10, 1000, {.maxSpeed = 40});

  chassis.turnToPoint(4, -38, 1000, {.forwards = false});
  chassis.moveToPoint(4, -38, 1000, {.forwards = false, .maxSpeed = 40});
  pros::delay(1000);
  outtake.move_voltage(4000);
  mouth.move_voltage(12000); 
  midgoalswitch.set_value(false);
  pros::delay(4000);
  midgoalswitch.set_value(true);
  chassis.turnToPoint(50, 0,1000);
  chassis.moveToPoint(50, 0, 2000);
  chassis.turnToPoint(50, 30, 1000);
  bar.set_value(true);
  chassis.moveToPoint(50, 30, 2000);  

  // intake_move(7000);
  // pros::delay(750)
  // midgoalswitch.set_value(false);
  // pros::delay(5000);
  // midgoalswitch.set_value(true);
  // mouth.move_voltage(12000)



    

};

void skills75_auton() {
  bar.set_value(false);
  intakelift.set_value(true);
  mouth.move_voltage(12000);
  outtake.move_voltage(12000);
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
  mouth.move_voltage(-8000);
  outtake.move_voltage(-8000);
  pros::delay(1000);
  mouth.move_voltage(12000);
  outtake.move_voltage(12000);
  intakelift.set_value(true);
  chassis.turnToPoint(32, 12, 500, {.forwards = false});
  chassis.moveToPoint(32, 12, 1500, {.forwards = false});
  intakelift.set_value(true);
  chassis.turnToPoint(32, -24, 500);
  bar.set_value(true);
  chassis.moveToPoint(34, -54, 700, {.maxSpeed = 60});// match loader
  chassis.moveToPoint(35, -55, 300, {.maxSpeed = 40});
  pros::delay(2000);
  chassis.moveToPoint(34, -24, 1000);

  chassis.turnToPoint(50, 0, 600, {.forwards = false});
  bar.set_value(false);
  chassis.moveToPoint(50, 0, 700, {.forwards = false});

  chassis.turnToPoint(50, 92, 600, {.forwards = false});
  chassis.moveToPoint(50, 92, 4000, {.forwards = false});//long 1
  chassis.turnToHeading(-90, 1000);
  chassis.moveToPoint(34, 92, 2000);
  chassis.turnToHeading(0, 1000);
  chassis.moveToPoint(34, 60, 1000, {.forwards = false});//scoring
  pros::delay(750);
  stopper.set_value(true);
  pros::delay(2000);
  stopper.set_value(false);
  bar.set_value(true);
  chassis.moveToPoint(32, 140, 1000, {.maxSpeed = 60});
  chassis.moveToPoint(32, 140, 1000, {.maxSpeed = 40});
  pros::delay(2000);
  chassis.moveToPoint(34, 65, 1000, {.forwards = false, .maxSpeed = 60});
  chassis.moveToPoint(34, 65, 1000, {.forwards = false, .maxSpeed = 60});//scoring 2
  bar.set_value(false);
   pros::delay(750);
  stopper.set_value(true);
  pros::delay(2000);
  chassis.setPose({0, 0, 0});
  chassis.moveToPoint(0, 10, 1000);
  stopper.set_value(false);
  chassis.turnToPoint(-100, 10, 500);
  chassis.moveToPoint(-100, 10, 3000);
  
  chassis.turnToPoint(-100, 48, 700);
  bar.set_value(true);
  chassis.moveToPoint(-100, 48, 1500, {.maxSpeed = 60});
  chassis.moveToPoint(-100, 45, 1000, {.maxSpeed = 60});
  pros::delay(2000);
  chassis.turnToPoint(-120, 0, 500, {.forwards = false});
  chassis.moveToPoint(-120, 0, 1000, {.forwards = false});
  bar.set_value(false);
  chassis.turnToPoint(-120, -70, 500, {.forwards = false});
  chassis.moveToPoint(-120, -70, 3000, {.forwards = false});
  chassis.turnToHeading(270, 1000);  
  chassis.turnToPoint(-105, -70, 100, {.forwards = false});
  chassis.moveToPoint(-105, -70, 2000, {.forwards = false}); 
  chassis.turnToPoint(-105, -50, 1000, {.forwards = false});
  chassis.moveToPoint(-105, -50, 1000, {.forwards = false});
  pros::delay(750);
  stopper.set_value(true);
  pros::delay(2000);
  stopper.set_value(false);
  bar.set_value(true);
  chassis.moveToPoint(-107, -124, 1500);
    chassis.moveToPoint(-107, -124, 300);
  pros::delay(2000);
  chassis.moveToPoint(-107, -60, 1000, {.forwards = false}); 
  pros::delay(750);
  stopper.set_value(true);
  pros::delay(2000); 
  chassis.setPose({0, 0, 0});
  bar.set_value(false);
  outtake.move_voltage(-12000);
  chassis.turnToPoint(-20, 55, 1000);
  chassis.moveToPoint(-20, 55, 1000);
  chassis.turnToPoint(-70, 55, 1000);
  chassis.moveToPoint(-70, 55, 1000); 



}

void run_auton_by_number(int auton_number) {
  switch (auton_number) {
  case 0:
    skills_auton();
    break;
  case 1:
    skills75_auton();
    break;
  // default:
  //   left_auton();
  //   break;
  }
}
