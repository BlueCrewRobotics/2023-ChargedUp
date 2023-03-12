/*-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=*/
/*                       Blue Crew Robotics #6153                             */
/*                            Charged Up 2023                                 */
/*-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=*/
// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#pragma once

// Claw Wrist motor limits
constexpr double WRIST_CLAW_MAX_LIMIT = 24; // this is down hitting the floor when elevator is down, not pointing all the way down
constexpr double WRIST_CLAW_MIN_LIMIT = 0;

constexpr double WRIST_CLAW_FORWARD_POSITION = 16.5;
constexpr double WRIST_CLAW_DROP_FOR_PLACEMENT_POSITION = 16.5;
constexpr double WRIST_CLAW_UP_A_BIT_POSITION = 7;
constexpr double WRIST_CLAW_DOWN_FOR_PICKING_UP_POSITION = 22.5;


// Claw Wrist motor address
constexpr int MOTOR_WRIST_CLAW = 12;
constexpr int MOTOR_INTAKE = 16;
