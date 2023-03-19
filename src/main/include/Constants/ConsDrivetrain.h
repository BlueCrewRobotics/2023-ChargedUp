/*-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=*/
/*                       Blue Crew Robotics #6153                             */
/*                            Charged Up 2023                                 */
/*-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=*/
// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#pragma once

// Motor adressing
constexpr int MOTOR_RIGHT_MASTER = 1;
constexpr int MOTOR_LEFT_MASTER = 2;
constexpr int MOTOR_RIGHT_FOLLOWER = 3;
constexpr int MOTOR_LEFT_FOLLOWER = 4;

// Maximum velocity in units/100ms
constexpr int VELOCITY_MAX = 15000; // 20000
constexpr int VELOCITY_SP_MAX_HG = 15000;  // 20000/ Maximum velocity in actual high gear
constexpr int VELOCITY_SP_MAX_LG = 15000;  // 20000 Maximum velocity in actual low gear
constexpr int VELOCITY_SP_MAX_LL = 4500;   // Maximum velocity in low low virtual gear

// Continuous current limit for Talons in amps
constexpr int CONTINUOUS_CURRENT_LIMIT = 20;
// Peak current limit for the Talons in amps
constexpr int PEAK_CURRENT_LIMIT = 30;
// Peak current duration for Talons in ms
constexpr int DURATION_CURRENT_LIMIT = 500;

// PID constants PID[0] Used for low speed right side
// constexpr double RIGHT_KF_0 = 0.042; // 0.0465; //0.13; // Kf = ((percent of output used for control)*1023) / (max encoder units)/100ms
// constexpr double RIGHT_KP_0 = 0.048;// 0.123; // Kp = ((percent of output used for control)*1023) / Error
constexpr double RIGHT_KF_0 = 0.06138;//0.046035; // 0.0465; //0.13; // Kf = ((percent of output used for control)*1023) / (max encoder units)/100ms
constexpr double RIGHT_KP_0 = 0.137179;// 0.123; // Kp = ((percent of output used for control)*1023) / Error
constexpr double RIGHT_KI_0 = 0.000;
constexpr double RIGHT_KD_0 = 0.0;

// PID constants PID[0] Used for low speed right side
// constexpr double LEFT_KF_0 = 0.041; // 0.0465; //0.13; // Kf = ((percent of output used for control)*1023) / (max encoder units)/100ms
// constexpr double LEFT_KP_0 = 0.0455;// 0.123; // Kp = ((percent of output used for control)*1023) / Error
constexpr double LEFT_KF_0 = 0.06138; //0.046035; // 0.06138 0.0465; //0.13; // Kf = ((percent of output used for control)*1023) / (max encoder units)/100ms
constexpr double LEFT_KP_0 = 0.1292;// 0.123; // Kp = ((percent of output used for control)*1023) / Error
constexpr double LEFT_KI_0 = 0.000;
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

constexpr double DRIVE_TRAIN_TICKS_PER_INCH_RIGHT_SIDE = 1013.4;
constexpr double DRIVE_TRAIN_TICKS_PER_INCH_LEFT_SIDE = 1012.75;

constexpr double DRIVE_TRAIN_ROTATIONS_PER_INCH_LEFT_SIDE = DRIVE_TRAIN_TICKS_PER_INCH_LEFT_SIDE / 2048.0;
constexpr double DRIVE_TRAIN_ROTATIONS_PER_INCH_RIGHT_SIDE = DRIVE_TRAIN_TICKS_PER_INCH_RIGHT_SIDE / 2048.0;

constexpr int NAVX_CHARGED_UP_RAMP_PITCH = 11;

// 0.75 to 1.3 with on floor depending upon drive train tipped forward or back
constexpr double NAVX_CHARGED_UP_ON_FLOOR_PITCH = 0.12;


