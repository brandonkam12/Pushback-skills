#include "main.h"
#include "lemlib/chassis/trackingWheel.hpp"
#include "lemlib/chassis/chassis.hpp"
#include "liblvgl/llemu.hpp"
#include "pros/adi.hpp"
#include "pros/imu.hpp"
#include "pros/llemu.hpp"
#include "pros/misc.h"
#include "pros/motor_group.hpp"
#include "pros/rtos.hpp"
#include <string>
#include "lemlib/api.hpp" // IWYU pragma: keep

#define red_value 30.00
#define blue_value 100.00


#define MOUTH_PORT1 1
#define OUTTAKE_PORT1 -10

#define HORIZONTAL_PORT 15
#define VERTICAL_PORT 16
#define IMU_PORT 17

pros::Controller controller(pros::E_CONTROLLER_MASTER);

pros::MotorGroup left_legs({11, -12, -13}, pros::MotorGearset::blue);
pros::MotorGroup right_legs({18, 19, -20}, pros::MotorGearset::blue);

pros::Motor mouth(MOUTH_PORT1);
pros::Motor outtake(OUTTAKE_PORT1);

pros::adi::Pneumatics bar('A', false);
pros::adi::Pneumatics wing('B', false);
pros::adi::Pneumatics midgoalswitch('C', true);
pros::adi::Pneumatics stopper('D', false);

bool scoremode_bool = true;

// create an imu on port 10
pros::Imu imu(IMU_PORT);

pros::Rotation horizontal_sensor(HORIZONTAL_PORT);
pros::Rotation vertical_sensor(VERTICAL_PORT);

// horizontal tracking wheel
lemlib::TrackingWheel horizontal_tracking_wheel(&horizontal_sensor, lemlib::Omniwheel::NEW_2, -3.5);//offset in inches(back of robot is negative digit)=============================
// vertical tracking wheel
lemlib::TrackingWheel vertical_tracking_wheel(&vertical_sensor, lemlib::Omniwheel::NEW_2, 0);//offset in inches(front of robot is positive digit)=============================

void brake(double time){
	left_legs.brake();
	right_legs.brake();
	pros::delay(time);
}

void backwards(int voltage, double time) {
	left_legs.move_voltage(-voltage);
	right_legs.move_voltage(-voltage);
	pros::delay(time);
	left_legs.move_voltage(0);
	right_legs.move_voltage(0);
}

void forward(int voltage, double time) {
	left_legs.move_voltage(voltage);
	right_legs.move_voltage(voltage);
	pros::delay(time);
	left_legs.move_voltage(0);
	right_legs.move_voltage(0);
}

void left(int voltage, double time) {
	left_legs.move_voltage(-voltage);
	right_legs.move_voltage(voltage);
	pros::delay(time);
	left_legs.move_voltage(0);
	right_legs.move_voltage(0);
}

void right(int voltage, double time) {
	left_legs.move_voltage(voltage);
	right_legs.move_voltage(-voltage);
	pros::delay(time);
	left_legs.move_voltage(0);
	right_legs.move_voltage(0);
}



void intake_move(int voltage){

	int outtakevoltage = voltage;


	
	mouth.move_voltage(voltage);
	outtake.move_voltage(outtakevoltage);
}

void intake_brake(){
	mouth.brake();
	outtake.brake();
}

// drivetrain settings
lemlib::Drivetrain drivetrain(&left_legs, // left motor group
                              &right_legs, // right motor group
                              11.5, // track width
                              lemlib::Omniwheel::OLD_325, // using old 3.25" omnis
                              450, // drivetrain rpm
                              2 // horizontal drift is 2 (for now)
);

lemlib::OdomSensors sensors(&vertical_tracking_wheel, // vertical tracking wheel 1, set to null
                            nullptr, // vertical tracking wheel 2, set to nullptr as we are using IMEs
                            &horizontal_tracking_wheel, // horizontal tracking wheel 1
                            nullptr, // horizontal tracking wheel 2, set to nullptr as we don't have a second one
                            &imu // inertial sensor
);

// lateral PID controller 
lemlib::ControllerSettings lateral_controller(10, // proportional gain (kP)
                                              0, // integral gain (kI)
                                              40, // derivative gain (kD)
                                              3, // anti windup
                                              1, // small error range, in inches
                                              100, // small error range timeout, in milliseconds
                                              3, // large error range, in inches
                                              500, // large error range timeout, in milliseconds
                                              20 // maximum acceleration (slew)
);

// angular PID controller
lemlib::ControllerSettings angular_controller(3, // proportional gain (kP)
                                              0, // integral gain (kI)
                                              10, // derivative gain (kD)
                                              0, // anti windup
                                              0, // small error range, in inches
                                              0, // small error range timeout, in milliseconds
                                              0, // large error range, in inches
                                              0, // large error range timeout, in milliseconds
                                              20 // maximum acceleration (slew)
);

// create the chassis
lemlib::Chassis chassis(drivetrain, // drivetrain settings
                        lateral_controller, // lateral PID settings
                        angular_controller, // angular PID settings
                        sensors // odometry sensors
);

void toggle(pros::adi::Pneumatics pneumatic, bool pneumatic_bool){
	if (pneumatic_bool == true) pneumatic.retract();
	else if (pneumatic_bool == false) pneumatic.extend();
	
}
int get_color(double hue){
	int c = 2;
	if (hue <= 35){
		c = 1;
	}
	else if (hue >= 150){
		c = 0;
	}
	else c = 2;
	return c;
}

void display_number(short int line, int nums){
	pros::lcd::set_text(line, std::to_string(nums));			
}

/**
 * A callback function for LLEMU's center button.
 *
 * When this callback is fired, it will toggle line 2 of the LCD text between
 * "I was pressed!" and nothing.
 */
void on_center_button() {
	static bool pressed = false;
	pressed = !pressed;
	if (pressed) {
		pros::lcd::set_text(2, "I was pressed!");
	} else {
		pros::lcd::clear_line(2);
	}
}

void initialize() { //============================================================================================================================
	pros::lcd::initialize();
	//pros::lcd::set_text(0, "2088K/SHOCKWAVE");
	// left_legs.set_zero_position_all(0);
	// right_legs.set_zero_position_all(0);
	
	mouth.set_brake_mode(pros::E_MOTOR_BRAKE_HOLD);
	outtake.set_brake_mode(pros::E_MOTOR_BRAKE_HOLD);
	
	left_legs.set_brake_mode(pros::E_MOTOR_BRAKE_HOLD);
	right_legs.set_brake_mode(pros::E_MOTOR_BRAKE_HOLD);

	bar.set_value(false);
	wing.set_value(false);
	midgoalswitch.set_value(true);
	stopper.set_value(true);
	imu.reset();
    chassis.calibrate(); // calibrate sensors
    //print position to brain screen
    pros::Task screen_task([&]() {
        while (true) {
            // print robot location to the brain screen
            pros::lcd::print(0, "X: %f", chassis.getPose().x); // x
            pros::lcd::print(1, "Y: %f", chassis.getPose().y); // y
            pros::lcd::print(2, "Theta: %f", chassis.getPose().theta); // heading
			
        	// print measurements from the rotation sensor
        	pros::lcd::print(3, "Rotation Sensor: %i", horizontal_sensor.get_position());
            // delay to save resources
            pros::delay(20);
        }
	});

	imu.reset(true);
	printf("initalized");
}

/**
 * Runs while the robot is in the disabled state of Field Management System or
 * the VEX Competition Switch, following either autonomous or opcontrol. When
 * the robot is enabled, this task will exit.
 */
void disabled() {
	//select_auton();
}

/**
 * Runs after initialize(), and before autonomous when connected to the Field
 * Management System or the VEX Competition Switch. This is intended for
 * competition-specific initialization routines, such as an autonomous selector
 * on the LCD.
 *
 * This task will exit when the robot is enabled and autonomous or opcontrol
 * starts.
 */
void competition_initialize() {
	//select_auton();
}
//auton #######################################################################################################################################

void left_auton() {}

void right_auton() {}

void skills_auton() {}

void autonomous() {

	outtake.move_voltage(-12000);
	mouth.move_voltage(12000);
	wing.set_value(true);

	chassis.setPose({0, 0, 0});
	
	// chassis.moveToPoint(6.724, 40.346, 1800, {.maxSpeed = 63.5});
	// // chassis.waitUntil(25);
	// // bar.set_value(true);

	// chassis.turnToPoint(28.422, 10.176, 1700);
	// chassis.moveToPoint(28.422, 10.176, 1700);

	// chassis.turnToPoint(29.543, 32.367, 1000, {.forwards = false});
	// chassis.moveToPoint(29.543, 32.367, 1700, {.forwards = false, .maxSpeed = 95.25}); //scoring 1

	// chassis.waitUntil(1);
	// pros::delay(500);
	// intake_move(12000);
	// pros::delay(3000);
	// bar.set_value(false);
	// outtake.move_voltage(-12000);

	// chassis.moveToPoint(25, 11, 1400); 
	// chassis.turnToPoint(62, 5, 1300);
	// chassis.moveToPoint(62, 5, 1400, {.maxSpeed = 53.5});//boink
	// chassis.moveToPoint(33.5, 12, 1400, {.forwards = false, .maxSpeed = 53.5}); //boink

	// bar.set_value(true);

	// chassis.turnToPoint(23, -26.5, 700);
	// chassis.moveToPoint(23, -26.5, 1600, {.maxSpeed = 43.5}); //match loader 1
	// pros::delay(5000);

	// chassis.moveToPoint(25.922, 10.176, 800, {.forwards = false});

	// chassis.turnToPoint(40, 26.707, 700, {.forwards = false});
	// chassis.moveToPoint(40, 26.707, 900, {.forwards = false});

	// chassis.turnToPoint(30, 97.306, 900, {.forwards = false});
	// chassis.moveToPoint(30, 97.306, 3000, {.forwards = false});//long 1

	// bar.set_value(false);


	// chassis.turnToPoint(31.562, 97.222, 900, {.forwards = false});
	// chassis.moveToPoint(31.562, 97.222, 1000, {.forwards = false});

	// chassis.turnToPoint(29.043, 87.581, 900, {.forwards = false});
	// chassis.moveToPoint(29.043, 87.581, 1000, {.forwards = false}); //scoring 2

	// chassis.waitUntil(1);
	// pros::delay(500);
	// intake_move(12000);
	// pros::delay(3000);
	// bar.set_value(true);
	// outtake.move_voltage(-12000);

	// chassis.moveToPoint(30.893, 127.603, 1000, {.maxSpeed = 42.33}); // match loader 2
	// pros::delay(5000);
	
	// chassis.moveToPoint(33.043, 88.581, 900, {.forwards = false}); //scoring 3
	// pros::delay (900);
	// intake_move(12000);
	// pros::delay(3000);

	// chassis.moveToPoint(31.562, 109.222, 900);

	// chassis.turnToPoint(15.099, 108.849, 1000);
	// chassis.moveToPoint(15.099, 108.849, 900);

	// chassis.turnToPoint(14.785, -2, 1000);
	// chassis.moveToPoint(14.785, -2, 3000); //long 2

	// bar.set_value(false);

	// chassis.turnToPoint(-16.058, 4, 700);
	// chassis.moveToPoint(-16.058, 4, 900); //park

	// forward(12000, 500);

	backwards(6000, 250);
	bar.set_value(true);
	forward(7000, 1500);
	bar.set_value(false);
	backwards(7000, 600);
	
}

//opcontrol ####################################################################################################################################################################

void opcontrol() {
	double drive_temp = (left_legs.get_temperature() + right_legs.get_temperature())/2;
	controller.print(0,0,"DT: %0.1f",drive_temp);
    while (true) {
		
        // get joystick positions
        int leftY = controller.get_analog(pros::E_CONTROLLER_ANALOG_LEFT_Y);
        int leftX = controller.get_analog(pros::E_CONTROLLER_ANALOG_LEFT_X);
        int rightY = controller.get_analog(pros::E_CONTROLLER_ANALOG_RIGHT_Y);
        int rightX = controller.get_analog(pros::E_CONTROLLER_ANALOG_RIGHT_X);

        // move the robot

	
        
		// chassis.arcade(leftY, rightX);
		left_legs.move(leftY + rightX);
		right_legs.move(leftY - rightX);


		if (controller.get_digital(pros::E_CONTROLLER_DIGITAL_Y)){
			scoremode_bool = false; //false is down
		}
		else {
			scoremode_bool = true; //true is up
		}

		if (scoremode_bool == true) {
			midgoalswitch.set_value(true);
		}
		else {
			midgoalswitch.set_value(false);
		}

		if (controller.get_digital(pros::E_CONTROLLER_DIGITAL_R1)){
			intake_move(12000);
			stopper.set_value(true);

		}
		else if (controller.get_digital(pros::E_CONTROLLER_DIGITAL_R2)){
			intake_move(-12000);
			stopper.set_value(true);
		}
		else if (controller.get_digital(pros::E_CONTROLLER_DIGITAL_L1)){
			intake_move(6000);
			stopper.set_value(false);
		}
		else if (controller.get_digital(pros::E_CONTROLLER_DIGITAL_L2)){
			intake_move(-6000);
			stopper.set_value(false);
		}
		else{
			intake_brake();
		}

		//pneumatic
		if (controller.get_digital(pros::E_CONTROLLER_DIGITAL_B)) {
			wing.set_value(false);
		}
		else {
			wing.set_value(true);
		}
		
        // delay to save resources
        pros::delay(25);

    }
}
