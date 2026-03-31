#include "autons.hpp"

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
  pros::delay(300);
  bar.set_value(true);
  pros::delay(200);
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
  pros::delay(1000);
  midgoalswitch.set_value(true);
  intake_move(12000);

  chassis.moveToPoint(-32, 5, 1000);

	chassis.turnToPoint(-36, -10, 700);
	bar.set_value(true);
	chassis.moveToPoint(-30, -30, 700);
	pros::delay(750);
	chassis.moveToPoint(-34, 48, 1500, {.forwards = false, .maxSpeed = 60});
	pros::delay(1500);
	stopper.set_value(true);
}


void right_auton() {

  intake_move(12000);
  stopper.set_value(false);

  // set position to x:0, y:0, heading:0
  chassis.setPose(0, 0, 0);

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
  chassis.moveToPoint(32, 48, 1500, {.forwards = false, .maxSpeed = 60});
  pros::delay(1500);
  stopper.set_value(true);

  
  chassis.moveToPoint(30, -30, 700);

  chassis.turnToPoint(24.265, 13.599, 500);
  chassis.moveToPoint(24.265, 13.599, 700);

  chassis.turnToPoint(23.999, 31.465, 500);
  chassis.moveToPoint(23.999, 31.465, 700);
  
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

  chassis.setPose({0, 0, 0});

  intake_move(12000);
  stopper.set_value(false);

  chassis.moveToPoint(0, 34, 900, {.maxSpeed = 100});
  chassis.turnToPoint(18.5, 34, 600);
  bar.set_value(true);
  chassis.moveToPoint(17, 32, 700, {.maxSpeed = 70}); // match loader
  pros::delay(1050);
  chassis.moveToPoint(-9, 32, 950, {.forwards = false, .minSpeed = 90});
  chassis.moveToPoint(-29, 32, 1000,
                      {.forwards = false, .maxSpeed = 60}); // scoring
  stopper.set_value(true);
  intake_move(12000);
  pros::delay(120);

  chassis.setPose(
      -21, 34,
      chassis.getPose().theta); // reset pos after first long goal alignment

  bar.set_value(false);

  chassis.moveToPoint(-17, 34, 650, {.minSpeed = 90});
  stopper.set_value(false);

  chassis.turnToHeading(225, 800);
  intake_move(12000);
  chassis.moveToPoint(-29.5, 13, 1500, {.minSpeed = 34}); // middle balls 1

  chassis.turnToPoint(-38, -38, 400);

  chassis.moveToPoint(-39.3, -36, 600); // middle balls 2
  chassis.waitUntilDone();

  chassis.moveToPoint(-37, -36, 600, {.maxSpeed = 90}); // middle balls back

  chassis.turnToPoint(0, -120, 500);
  chassis.waitUntilDone();

  chassis.setPose({0, 0, 0});
  chassis.moveToPoint(-10, 21, 700);
  chassis.turnToPoint(-140, 0, 500);

  chassis.setPose({0, 0, 0});
  chassis.moveToPoint(
      100, -50, 1000,
      {.forwards = false, .maxSpeed = 90}); // scoring long goal 2
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

  chassis.setPose({0, 0, 0});
  chassis.turnToHeading(35, 300);

  chassis.moveToPoint(-67, -48, 1000, {.forwards = false, .maxSpeed = 90});
  intake_move(12000);
  pros::delay(1000);
  midgoalswitch.set_value(false);
}

void tensawp_auton() {
  chassis.setPose({0, 0, 0});
  intake_move(12000);

  chassis.moveToPoint(100.92, 1.355, 800);

  chassis.turnToPoint(102.274, -29.802, 500);
  bar.set_value(true);
  chassis.moveToPoint(102.274, -29.802, 800, {.maxSpeed = 70}); // match loader
  pros::delay(500);

  chassis.moveToPoint(104.306, 58.926, 800,
                      {.forwards = false, .maxSpeed = 60}); // scoring
  bar.set_value(false);
  stopper.set_value(true);
  pros::delay(1000);
  stopper.set_value(false);

  chassis.moveToPoint(102.274, 9.482, 800);

  chassis.turnToPoint(8.805, 103.629, 500);
  chassis.moveToPoint(8.805, 103.629, 800); // middle balls and middle goal
  intake_move(-12000);
  intakelift.set_value(true);
  pros::delay(500);

  chassis.moveToPoint(41.316, 68.409, 500);
  intake_move(12000);

  chassis.turnToPoint(-69.763, 69.086, 500);
  chassis.moveToPoint(-69.763, 69.086, 800); // middle balls 2

  midgoalswitch.set_value(false);
  chassis.turnToPoint(-41.316, 97.533, 500, {.forwards = false});
  chassis.moveToPoint(-41.316, 97.533, 800,
                      {.forwards = false}); // middle goal 2
  stopper.set_value(true);
}
void elimleft_auton() {}
void elimright_auton() {
  chassis.setPose({0, 0, 0});

  chassis.moveToPoint(37.93, 79.245, 900);

  chassis.turnToPoint(4.064, 112.434, 500);
  intakelift.set_value(true);
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
