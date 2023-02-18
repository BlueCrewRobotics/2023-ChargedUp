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

// Turret setup and adressing
constexpr int MOTOR_TURRET = 7;
constexpr int TURRET_MIN_ENCODER = -3500;
constexpr int TURRET_MAX_ENCODER = 3500;
constexpr int TURRET_KF_0 = 0;
constexpr int TURRET_KP_0 = 25;
constexpr int TURRET_KI_0 = 0;
constexpr int TURRET_KD_0 = 0;
constexpr int TURRET_ENCODER_TICS_PER_DEGREE = 15.37778;
constexpr int TURRET_MANUAL_ROTATION_OFF = 0;
constexpr int TURRET_MANUAL_ROTATION_CLOCKWISE = 1;
constexpr int TURRET_MANUAL_ROTATION_COUNTERCLOCKWISE = 2;
constexpr int TURRET_HOME_POSITION = 0;


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

// ellie encode measurements ....
//
// DRIVE TRAIN:
// we measured moving a straight line for 75 feet
//  right side : 12,161 ticks per foot
//  left side : 12,153 ticks per foot
//
//  right side: 1013.4 ticks per inch
//  left side: 1012.75 ticks per inch
//
//  pitch: is negative with the back (battery end) lifted up
//
//  TURRET:
//    180 degree rotation = 2768 encoder ticks
//    1 degree = 15.4 encoder ticks
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

// aux controller D-pad values
constexpr int AUX_DPAD_VALUE_MIDDLE_CENTER = -1;
constexpr int AUX_DPAD_VALUE_MIDDLE_UP = 0;
constexpr int AUX_DPAD_VALUE_RIGHT_UP = 45;
constexpr int AUX_DPAD_VALUE_RIGHT_CENTER = 90;
constexpr int AUX_DPAD_VALUE_RIGHT_DOWN = 135;
constexpr int AUX_DPAD_VALUE_MIDDLE_DOWN = 180;
constexpr int AUX_DPAD_VALUE_LEFT_DOWN = 225;
constexpr int AUX_DPAD_VALUE_LEFT_CENTER = 270;
constexpr int AUX_DPAD_VALUE_LEFT_UP = 315;



enum nodeTypes { Cone = 1, Cube = 2, Hybrid = 5, None = 0};

// Field Measurements (inches)
//    When facing/looking directly at center point of april tag ...
//      x = horizontal (left, right) distance from center point of april tag
//      y = depth (in, out) distance from center point of april tag
//      z = vertical (up, down) distance from center point of april tag
struct fieldpos { float x, y, z; nodeTypes nodeType; };

//  Grid has two cone nodes on left, two cone nodes on right, two shelves in center
//   _______________________________     ^
//  |          |        |           |    |
//  |     O    |        |     O     |    |
//  |          | ------ |           |   (y)
//  |     O    |        |     O     |    |
//  |          | ---t-- |           |    |    (z) is distance above ground
//  |          |        |           |    v
//  |_______________________________|     <------- (x) ------>
//
// Constants for offset distances from april tag center
constexpr fieldpos FIELD_POS_OFFSET_FROM_TAG_SHELF_MIDDLE = { 0.0, 8.655, 5.25, Cube };
constexpr fieldpos FIELD_POS_OFFSET_FROM_TAG_SHELF_TOP = { 0.0, 23.035, 17.25, Cube };

constexpr fieldpos FIELD_POS_OFFSET_FROM_TAG_FLOOR_CENTER = { 0.0,  7.14, -18.24, Hybrid };
constexpr fieldpos FIELD_POS_OFFSET_FROM_TAG_FLOOR_RIGHT = { 16.75, 7.14, -18.24, Hybrid };
constexpr fieldpos FIELD_POS_OFFSET_FROM_TAG_FLOOR_LEFT = { -16.75, 7.14, -18.24, Hybrid };

// TODO: only have 2 of the 3 coordinates for these calculated so far...
constexpr fieldpos FIELD_POS_OFFSET_FROM_TAG_CONE_NODE_RIGHT_LOWER = { 21.875, 8.42, 16.75, Cone }; 
constexpr fieldpos FIELD_POS_OFFSET_FROM_TAG_CONE_NODE_RIGHT_UPPER = { 21.875, 25.45, 27.75, Cone };
constexpr fieldpos FIELD_POS_OFFSET_FROM_TAG_CONE_NODE_LEFT_LOWER = { -21.875, 8.42, 16.75, Cone };
constexpr fieldpos FIELD_POS_OFFSET_FROM_TAG_CONE_NODE_LEFT_UPPER = { -21.875, 25.45, 27.75, Cone };


constexpr int kDriverControllerPort = 0;

namespace OperatorConstants {
}  // namespace OperatorConstants
