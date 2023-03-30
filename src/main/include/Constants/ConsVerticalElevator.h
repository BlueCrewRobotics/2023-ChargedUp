/*-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=*/
/*                       Blue Crew Robotics #6153                             */
/*                            Charged Up 2023                                 */
/*-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=*/
// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#pragma once

// Vertical Elevator limits
constexpr double VERTICAL_ELEV_MAX_LIMIT = 92000;
constexpr double VERTICAL_ELEV_MIN_LIMIT = 1200;
constexpr int VERTICAL_ELEV_VELOCITY_MAX = 1000; 

constexpr int VERTICAL_ELEV_POSITION_HOLD_TOLERANCE = 600;

// Vertical Elevator motor address
constexpr int MOTOR_VERTICAL_ELEVATOR = 8;

constexpr double VERTICAL_ELEV_POS_CONE_NODE_LOWER = 65000;
constexpr double VERTICAL_ELEV_POS_CONE_NODE_UPPER = 90000;
constexpr double VERTICAL_ELEV_POS_CUBE_NODE_LOWER = 53000;
constexpr double VERTICAL_ELEV_POS_CUBE_NODE_UPPER = 84000;
constexpr double VERTICAL_ELEV_POS_HYBRID_NODE = VERTICAL_ELEV_MIN_LIMIT;
constexpr double VERTICAL_ELEV_POS_SUBSTATION_SHELF = 85000; //90000; //83700;
constexpr double VERTICAL_ELEV_POS_SWITCH_LIMELGIHT_THRESHOLD = 20000;

