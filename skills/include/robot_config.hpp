#pragma once

#include "lemlib/api.hpp"
#include "pros/adi.hpp"
#include "pros/imu.hpp"
#include "pros/misc.hpp"
#include "pros/motor_group.hpp"
#include "pros/rotation.hpp"
#include "pros/distance.hpp"


extern pros::Controller controller;

extern pros::MotorGroup left_legs;
extern pros::MotorGroup right_legs;

extern pros::Motor mouth;
extern pros::Motor outtake;

extern pros::adi::Pneumatics bar;
extern pros::adi::Pneumatics wing;
extern pros::adi::Pneumatics midgoalswitch;
extern pros::adi::Pneumatics stopper;
extern pros::adi::Pneumatics midgoaldescore;
extern pros::adi::Pneumatics intakelift;

extern bool scoremode_bool;


extern pros::Distance distance_back;
extern pros::Distance distance_left;
extern pros::Distance distance_right;
extern pros::Distance distance_front;


extern pros::Imu imu;
extern pros::Rotation horizontal_sensor;
extern pros::Rotation vertical_sensor;

extern lemlib::TrackingWheel horizontal_tracking_wheel;
extern lemlib::TrackingWheel vertical_tracking_wheel;

extern lemlib::Drivetrain drivetrain;
extern lemlib::OdomSensors sensors;
extern lemlib::ControllerSettings lateral_controller;
extern lemlib::ControllerSettings angular_controller;
extern lemlib::Chassis chassis;

void brake(double time_ms);
void backwards(int voltage, double time_ms);
void forward(int voltage, double time_ms);
void left(int voltage, double time_ms);
void right(int voltage, double time_ms);
void intake_brake();
