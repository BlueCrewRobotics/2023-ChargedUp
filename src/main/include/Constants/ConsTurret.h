/*-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=*/
/*                       Blue Crew Robotics #6153                             */
/*                            Charged Up 2023                                 */
/*-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=*/
// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#pragma once

//
//  TURRET:
//    180 degree rotation = 2768 encoder ticks
//    1 degree = 15.4 encoder ticks
//
// Turret setup and adressing
constexpr int MOTOR_TURRET = 7;
constexpr int TURRET_MIN_ENCODER = -3400; // clockwise (if looking down on robot)
constexpr int TURRET_MAX_ENCODER = 3400;
constexpr int TURRET_KF_0 = 0;
constexpr int TURRET_KP_0 = 1.1;
constexpr int TURRET_KI_0 = 0;
constexpr int TURRET_KD_0 = 0;
constexpr int TURRET_ENCODER_TICS_PER_DEGREE = 15.37778;
constexpr int TURRET_HOME_POSITION = 0;
constexpr int TURRET_POSITION_HOLD_TOLERANCE = 15;
