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
  // mouth.move_voltage(12000)
outtake.move_voltage(12000);



    

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
