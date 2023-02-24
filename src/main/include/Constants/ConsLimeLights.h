/*-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=*/
/*                       Blue Crew Robotics #6153                             */
/*                            Charged Up 2023                                 */
/*-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=*/
// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#pragma once

#include "ConsGlobal.h"

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
constexpr fieldpos FIELD_POS_OFFSET_FROM_TAG_SHELF_MIDDLE = { 0.0, 8.655, 5.25, CubeNode };
constexpr fieldpos FIELD_POS_OFFSET_FROM_TAG_SHELF_TOP = { 0.0, 23.035, 17.25, CubeNode };

constexpr fieldpos FIELD_POS_OFFSET_FROM_TAG_FLOOR_CENTER = { 0.0,  7.14, -18.24, HybridNode };
constexpr fieldpos FIELD_POS_OFFSET_FROM_TAG_FLOOR_RIGHT = { 16.75, 7.14, -18.24, HybridNode };
constexpr fieldpos FIELD_POS_OFFSET_FROM_TAG_FLOOR_LEFT = { -16.75, 7.14, -18.24, HybridNode };

constexpr fieldpos FIELD_POS_OFFSET_FROM_TAG_CONE_NODE_RIGHT_LOWER = { 21.875, 8.42, 16.75, ConeNode }; 
constexpr fieldpos FIELD_POS_OFFSET_FROM_TAG_CONE_NODE_RIGHT_UPPER = { 21.875, 25.45, 27.75, ConeNode };
constexpr fieldpos FIELD_POS_OFFSET_FROM_TAG_CONE_NODE_LEFT_LOWER = { -21.875, 8.42, 16.75, ConeNode };
constexpr fieldpos FIELD_POS_OFFSET_FROM_TAG_CONE_NODE_LEFT_UPPER = { -21.875, 25.45, 27.75, ConeNode };
