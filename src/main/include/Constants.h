/*-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=*/
/*                       Blue Crew Robotics #6153                             */
/*                            Charged Up 2023                                 */
/*-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=*/
// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#pragma once

/**
 * The Constants header provides a convenient place for teams to hold robot-wide
 * numerical or boolean constants.  This should not be used for any other
 * purpose.
 *
 * It is generally a good idea to place constants into subsystem- or
 * command-specific namespaces within this header, which can then be used where
 * they are needed.
 */

// Controllers
constexpr int DRIVER_CONTROLLER = 0;
constexpr int AUX_CONTROLLER = 1;
/*
   Game controller button and joystick addressing.
   Access in code by including Constants.h and using BUTTON_A
   */
constexpr int BUTTON_A = 1;
constexpr int BUTTON_B = 2;
constexpr int BUTTON_X = 3;
constexpr int BUTTON_Y = 4;
constexpr int BUTTON_L_BUMP = 5;
constexpr int BUTTON_R_BUMP = 6; // Drive gear sifting
constexpr int BUTTON_SELECT = 7;
constexpr int BUTTON_START = 8;
constexpr int BUTTON_L3 = 9;
constexpr int BUTTON_R3 = 10;

constexpr int AXIS_LX = 0; // Steer left/right
constexpr int AXIS_LY = 1;
constexpr int AXIS_L_TRIG = 2; // Forward driving
constexpr int AXIS_R_TRIG = 3; // Reverse driving
constexpr int AXIS_RX = 4;
constexpr int AXIS_RY = 5;

// Falcon, Talon and Victor CAN Bus addressing
constexpr int MOTOR_RIGHT_MASTER = 1;
constexpr int MOTOR_LEFT_MASTER = 2;
constexpr int MOTOR_RIGHT_FOLLOWER = 3;
constexpr int MOTOR_LEFT_FOLLOWER = 4;
constexpr int MOTOR_Vertical_ELEVATOR = 999;// <---PLACE HOLDER!!!----------------------------

// Turret adressing
constexpr int MOTOR_TURRET = 7;

// Maximum velocity in units/100ms
constexpr int VELOCITY_MAX = 20000;
constexpr int VELOCITY_SP_MAX_HG = 20000;  // Maximum velocity in actual high gear
constexpr int VELOCITY_SP_MAX_LG = 20000;  // Maximum velocity in actual low gear
constexpr int VELOCITY_SP_MAX_LL = 5000;   // Maximum velocity in low low virtual gear
constexpr int ELEVATOR_VELOCITY_MAX = 1000; // <---PLACE HOLDER!!!------ Maximum velocity of the elevator motor

// Continuous current limit for Talons in amps
constexpr int CONTINUOUS_CURRENT_LIMIT = 20;
// Peak current limit for the Talons in amps
constexpr int PEAK_CURRENT_LIMIT = 30;
// Peak current duration for Talons in ms
constexpr int DURATION_CURRENT_LIMIT = 500;

// PID constants PID[0] Used for low speed right side
constexpr double RIGHT_KF_0 = 0.042; // 0.0465; //0.13; // Kf = ((percent of output used for control)*1023) / (max encoder units)/100ms
constexpr double RIGHT_KP_0 = 0.048;// 0.123; // Kp = ((percent of output used for control)*1023) / Error
constexpr double RIGHT_KI_0 = 0.0;
constexpr double RIGHT_KD_0 = 0.0;

// PID constants PID[0] Used for low speed right side
constexpr double LEFT_KF_0 = 0.041; // 0.0465; //0.13; // Kf = ((percent of output used for control)*1023) / (max encoder units)/100ms
constexpr double LEFT_KP_0 = 0.0455;// 0.123; // Kp = ((percent of output used for control)*1023) / Error
constexpr double LEFT_KI_0 = 0.0;
constexpr double LEFT_KD_0 = 0;

// PID constants PID[1] uesd for high speed left side
constexpr double RIGHT_KF_1 = 0.041; 
constexpr double RIGHT_KP_1 = 0.0;
constexpr double RIGHT_KI_1 = 0;
constexpr double RIGHT_KD_1 = 0;

// PID constants PID[1] uesd for high speed left side
constexpr double LEFT_KF_1 = 0.041;
constexpr double LEFT_KP_1 = 0.0;
constexpr double LEFT_KI_1 = 0;
constexpr double LEFT_KD_1 = 0;

// slabby encoder measurements...
//
// we measured moving a straight line for 80 feet
//  encoder 1 moved -197063 ticks
//  encoder 2 moved -197489 ticks
//
//  encoder 1 moved -2463.2875 ticks per foot
//  encoder 2 moved -2468.6125 ticks per foot
//
//  encoder 1 moved -205.2739583 ticks per inch
//  encoder 2 moved -205.7177083 ticks per inch
//  


// PCM Module CAN ID
constexpr int PCM_0 = 9;

// Solenoid Mappings for Shifter PCM
constexpr int PCM_0_GEARSHIFT = 0;  // Drive train gear shifter
constexpr int PCM_1_PREP_CONERAMP = 1; // piston used on Cone Ramp Extention

// NavX related constants and info
// 
// when slabby is sitting level, depending upon which 2 sets of wheels it is sitting on,
// pitch is: -1.18 to -0.50
// pitch decreases (more negative) when slabby is tipping backward
//
constexpr int NAVX_CHARGED_UP_RAMP_PITCH = 11;



// Limelight related Constants
constexpr int LL_PIPELINE_PURPLE_CUBE_NUMBER = 8;
constexpr int LL_PIPELINE_YELLOW_CONE_NUMBER = 9;
constexpr double LL_LIMELIGHT_UPPER_ANGLE = -24.8492;
constexpr double LL_LIMELIGHT_LOWER_ANGLE = -3.18;
constexpr double LL_LIMELIGHT_UPPER_HIGHT = 54.3;
constexpr double LL_LIMELIGHT_LOWER_HIGHT = 17.25;
constexpr double LL_YELLOW_CONE_CENTER_HIGHT = 6.5;
constexpr double LL_PURPLE_CUBE_CENTER_HIGHT = 4.5;
constexpr double LL_CONE_POLE_UPPER_HIGHT = 43.75;
constexpr double LL_CONE_POLE_LOWER_HIGHT = 99999; // <- PLACE HOLDER

// Target ID int values
constexpr int TID_YELLOW_CONE_ID = 1;
constexpr int TID_PURPLE_CUBE_ID = 2;
constexpr int TID_CONE_POLE_UPPER_ID = 3;
constexpr int TID_CONE_POLE_LOWER_ID = 4;

constexpr int kDriverControllerPort = 0;

namespace OperatorConstants {
}  // namespace OperatorConstants
