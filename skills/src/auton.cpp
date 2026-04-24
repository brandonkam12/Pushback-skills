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
  intakelift.set_value(true);
  chassis.turnToHeading(-10, 500);
  chassis.turnToHeading(10, 500);
  chassis.turnToHeading(0, 500);
  pros::delay(500);
  chassis.moveToPoint(0, 10, 1000);
  chassis.turnToHeading(-10, 500);
  chassis.turnToHeading(10, 500);
  chassis.turnToHeading(0, 500);
  pros::delay(500);
  midgoaldescore.set_value(true);
  chassis.moveToPoint(0, -12, 1000, {.forwards = false});
  midgoaldescore.set_value(false);
  chassis.turnToPoint(0, 12,200, {.maxSpeed = 40});
  chassis.moveToPoint(0, 12,700, {.maxSpeed = 40});
  chassis.setPose({0, 0, 0});
  chassis.moveToPose(-4, -58,45,2000, {.forwards = false, .minSpeed = 10});
  chassis.turnToPoint(25, -18, 300);
  chassis.moveToPoint(25, -18, 1200, {.maxSpeed = 40});
  chassis.turnToPoint(4, -45, 200, {.forwards = false});
  chassis.moveToPoint(4, -45, 1000, {.forwards = false, .maxSpeed = 40});
  pros::delay(1000);
  outtake.move_voltage(4000);
  mouth.move_voltage(12000); 
  midgoalswitch.set_value(false);
  pros::delay(3500);
  midgoalswitch.set_value(true);
  outtake.move_voltage(12000); 
  chassis.turnToPoint(50, 0, 500);
  chassis.moveToPoint(50, 0, 1000);
  chassis.turnToPoint(50, 30, 500);  
  bar.set_value(true);
  chassis.moveToPoint(50, 30, 1000, {.maxSpeed = 90});
  chassis.moveToPoint(50, 34, 300);
  pros::delay(2000);
  chassis.turnToPoint(67, 5,300, {.forwards = false});
  chassis.moveToPoint(67, 5, 800, {.forwards = false});
  bar.set_value(false);
  wing.set_value(true);
  chassis.turnToPoint(80, -70,300, {.forwards = false});
  chassis.moveToPoint(80, -70, 2000, {.forwards = false});
  chassis.turnToPoint(60, -70,1000);
  chassis.moveToPoint(60, -70, 1000);
  chassis.turnToHeading(180, 1000);
  chassis.moveToPoint(60, -50, 1000, {.forwards = false});
  pros::delay(900);
  stopper.set_value(true);
  pros::delay(2000);
  stopper.set_value(false);
  bar.set_value(true);
  chassis.turnToPoint(60, -130, 400);
  chassis.moveToPoint(60, -130, 1000);
  chassis.moveToPoint(60, -130, 400);
  pros::delay(2000);
  chassis.moveToPoint(60, -50, 1000, {.forwards = false});
  pros::delay(1000);
  stopper.set_value(true);
  pros::delay(2000);
  bar.set_value(false);
  chassis.setPose(0,0,0);
  chassis.moveToPoint(0, 8, 800);
  stopper.set_value(false);
  chassis.turnToPoint(95, 12, 500);
  chassis.moveToPoint(95, 12, 2000);
  chassis.turnToHeading(0, 800);
  bar.set_value(true);//a
  chassis.moveToPoint(95, 50, 1100, {.maxSpeed = 60});
  chassis.moveToPoint(95, 54, 400, {.maxSpeed = 60});
  pros::delay(2000);
  chassis.turnToPoint(120, 4, 500, {.forwards = false});
  chassis.moveToPoint(120, 4, 800, {.forwards = false});
  bar.set_value(false);
  chassis.turnToPoint(120, -70, 500, {.forwards = false});
  chassis.moveToPoint(120, -65, 2000, {.forwards = false});
  chassis.turnToHeading(-90, 1000);  
  chassis.moveToPoint(105, -65, 1000); 
  chassis.turnToHeading(180, 1000);
  chassis.moveToPoint(105, -50, 1000, {.forwards = false});
  pros::delay(750);
  stopper.set_value(true);
  pros::delay(2000);
  stopper.set_value(false);
  bar.set_value(true);
  chassis.moveToPoint(105, -124, 1500);
  chassis.moveToPoint(105, -124, 500);
  pros::delay(2000);
  chassis.moveToPoint(105, -60, 1100, {.forwards = false}); 
  pros::delay(800);
  stopper.set_value(true);
  pros::delay(2000); 
  chassis.setPose({0, 0, 0});
  bar.set_value(false);
  outtake.move_voltage(-12000);
  chassis.turnToHeading(45, 600);
  chassis.turnToPoint(70, 55, 1000);
  chassis.moveToPoint(70, 55, 1000);




    

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
