/*-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=*/
/*                       Blue Crew Robotics #6153                             */
/*                            Charged Up 2023                                 */
/*-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=*/
// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#pragma once

// Vertical Elevator limits
constexpr double VERTICAL_ELEV_TOP_LIMIT = 95000;
constexpr double VERTICAL_ELEV_BOTTOM_LIMIT = 1000;
constexpr int VERTICAL_ELEV_VELOCITY_MAX = 1000; // <---PLACE HOLDER!!!------ Maximum velocity of the elevator motor

// Vertical Elevator motor address
constexpr int MOTOR_VERTICAL_ELEVATOR = 8;