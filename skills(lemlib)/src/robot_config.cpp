#include "robot_config.hpp"
#include "pros/distance.hpp"

namespace {
constexpr int MOUTH_PORT = 1;
constexpr int OUTTAKE_PORT = -10;
constexpr int HORIZONTAL_PORT = 15;
constexpr int VERTICAL_PORT = -16;
constexpr int IMU_PORT = 17;
constexpr int DISTANCEBACK_PORT = 9;
constexpr int DISTANCELEFT_PORT = 2;
constexpr int DISTANCERIGHT_PORT = 8;
constexpr int DISTANCEFRONT_PORT = 3;
}  // namespace

//every time u add something here, add it to the robot_config.hpp file as well as an extern

pros::Controller controller(pros::E_CONTROLLER_MASTER);

pros::MotorGroup left_legs({11, -12, -13}, pros::MotorGearset::blue);
pros::MotorGroup right_legs({18, 19, -20}, pros::MotorGearset::blue);

pros::Motor mouth(MOUTH_PORT);
pros::Motor outtake(OUTTAKE_PORT);

pros::adi::Pneumatics bar('A', false);
pros::adi::Pneumatics wing('B', false);
pros::adi::Pneumatics midgoalswitch('C', true);
pros::adi::Pneumatics stopper('D', false);
pros::adi::Pneumatics midgoaldescore('E', false);
pros::adi::Pneumatics intakelift('F', true);

bool scoremode_bool = true;

pros::Distance distance_back(DISTANCEBACK_PORT);
pros::Distance distance_left(DISTANCELEFT_PORT);
pros::Distance distance_right(DISTANCERIGHT_PORT);
pros::Distance distance_front(DISTANCEFRONT_PORT);

pros::Imu imu(IMU_PORT);
pros::Rotation horizontal_sensor(HORIZONTAL_PORT);
pros::Rotation vertical_sensor(VERTICAL_PORT);

lemlib::TrackingWheel horizontal_tracking_wheel(&horizontal_sensor, lemlib::Omniwheel::NEW_2, -3.5);
lemlib::TrackingWheel vertical_tracking_wheel(&vertical_sensor, lemlib::Omniwheel::NEW_2, 0);

lemlib::Drivetrain drivetrain(&left_legs, 
                              &right_legs, 
                              11.5,
                              lemlib::Omniwheel::OLD_325, 
                              450, 
                              2);

lemlib::OdomSensors sensors(&vertical_tracking_wheel, 
                            nullptr, 
                            &horizontal_tracking_wheel, 
                            nullptr, 
                            &imu);

lemlib::ControllerSettings lateral_controller(9.25, 
                                              0, 
                                              75,
                                              3, 
                                              1, 
                                              100, 
                                              3, 
                                              500, 
                                              20
);

lemlib::ControllerSettings angular_controller(2, 
                                              0, 
                                              10, 
                                              0, 
                                              0, 
                                              0, 
                                              0, 
                                              0, 
                                              20
);

lemlib::Chassis chassis(drivetrain, 
                        lateral_controller, 
                        angular_controller,
                        sensors);

void brake(double time_ms) {
    left_legs.brake();
    right_legs.brake();
    pros::delay(time_ms);
}

void backwards(int voltage, double time_ms) {
    left_legs.move_voltage(-voltage);
    right_legs.move_voltage(-voltage);
    pros::delay(time_ms);
    left_legs.move_voltage(0);
    right_legs.move_voltage(0);
}

void forward(int voltage, double time_ms) {
    left_legs.move_voltage(voltage);
    right_legs.move_voltage(voltage);
    pros::delay(time_ms);
    left_legs.move_voltage(0);
    right_legs.move_voltage(0);
}

void left(int voltage, double time_ms) {
    left_legs.move_voltage(-voltage);
    right_legs.move_voltage(voltage);
    pros::delay(time_ms);
    left_legs.move_voltage(0);
    right_legs.move_voltage(0);
}

void right(int voltage, double time_ms) {
    left_legs.move_voltage(voltage);
    right_legs.move_voltage(-voltage);
    pros::delay(time_ms);
    left_legs.move_voltage(0);
    right_legs.move_voltage(0);
}

void intake_move(int voltage) {
    mouth.move_voltage(voltage);
    outtake.move_voltage(voltage);
}

void intake_brake() {
    mouth.brake();
    outtake.brake();
}
