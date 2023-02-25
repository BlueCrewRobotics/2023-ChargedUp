/*-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=*/
/*                       Blue Crew Robotics #6153                             */
/*                            Charged Up 2023                                 */
/*-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=*/
// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#pragma once

// Vertical Elevator limits
constexpr double VERTICAL_ELEV_MAX_LIMIT = 95000;
constexpr double VERTICAL_ELEV_MIN_LIMIT = 1000;
constexpr int VERTICAL_ELEV_VELOCITY_MAX = 1000; // <---PLACE HOLDER!!!------ Maximum velocity of the elevator motor

constexpr int VERTICAL_ELEV_POSITION_HOLD_TOLERANCE = 600;

// Vertical Elevator motor address
constexpr int MOTOR_VERTICAL_ELEVATOR = 8;

constexpr double VERTICAL_ELEV_POS_CONE_NODE_LOWER = 76800;
constexpr double VERTICAL_ELEV_POS_CONE_NODE_UPPER = VERTICAL_ELEV_MAX_LIMIT;
constexpr double VERTICAL_ELEV_POS_CUBE_NODE_LOWER = 48000;
constexpr double VERTICAL_ELEV_POS_CUBE_NODE_UPPER = 85500;
constexpr double VERTICAL_ELEV_POS_HYBRID_NODE = VERTICAL_ELEV_MIN_LIMIT;

