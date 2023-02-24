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

/*


Elevator Positions:

        Lower Cone Node: 76800
        Upper Cone Node: VERTICAL_ELEVATOR_MAX_LIMIT


        Lower Cube Node:  48000
        Upper Cube Node:  85500

        Hybrid Node: VERTICAL_ELEVATOR_MIN_LIMIT


*/