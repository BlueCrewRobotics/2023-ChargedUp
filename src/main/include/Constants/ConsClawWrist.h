/*-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=*/
/*                       Blue Crew Robotics #6153                             */
/*                            Charged Up 2023                                 */
/*-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=*/
// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#pragma once
/*
// OLD POSITIONS FOR CLAW
// Claw Wrist motor limits
constexpr double WRIST_CLAW_MAX_LIMIT = 24; // this is down hitting the floor when elevator is down, not pointing all the way down
constexpr double WRIST_CLAW_MIN_LIMIT = 0;

// Claw Wrist positions
constexpr double WRIST_CLAW_FORWARD_POSITION = 16.5;
constexpr double WRIST_CLAW_DROP_FOR_PLACEMENT_POSITION = 16.5;
constexpr double WRIST_CLAW_UP_A_BIT_POSITION = 7;
constexpr double WRIST_CLAW_DOWN_FOR_PICKING_UP_POSITION = 22.5;
*/

// NEW WRIST POSITIONS FOR INTAKE
/*
CUBE PICKUP: 22
CONE UP-RIGHT PICKUP: 19
CONE TIPPED-OVER PICKUP: 22.5
TILTED DOWN: 27
STRAIGHT DOWN: 34.5
CONE PLACEMENT: 9
CUBE PLACEMENT: 10
*/
constexpr double WRIST_CLAW_MAX_LIMIT = 34.5; // this is pointing all the way down
constexpr double WRIST_CLAW_MIN_LIMIT = 0;
constexpr double WRIST_CLAW_TILTED_DOWN = 27; // this is down hitting the floor when elevator is down, not pointing all the way down

constexpr double WRIST_CLAW_PICKUP_UPRIGHT_CONE = 12;
constexpr double WRIST_CLAW_PICKUP_TIPPED_OVER_CONE = 22.5;
constexpr double WRIST_CLAW_PLACE_CONE = 9;

constexpr double WRIST_CLAW_PICKUP_CUBE = 15;
constexpr double WRIST_CLAW_PLACE_CUBE = 10;


// Intake motor max speed
constexpr double INTAKE_MOTOR_MAX_SPEED = 2048;

// Claw Wrist motor address
constexpr int MOTOR_WRIST_CLAW = 12;
constexpr int MOTOR_INTAKE = 16;
