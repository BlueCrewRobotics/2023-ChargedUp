/*-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=*/
/*                       Blue Crew Robotics #6153                             */
/*                            Charged Up 2023                                 */
/*-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=*/
// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#pragma once

#include "ConsGlobal.h"

  // angle up upper LimeLightUpper: -28.2209
  // angle of LimeLightLower: 23.8122
  // Height of middle of cube: 4.5 inches
  // Height of middle of cone: 6.5 inches
  // Height of Upper Pole: 43.75 inches
  // Height of Upper LimeLight: 51.875 inches
  // Height of Lower LimeLight: 8.25 inches



// Limelight related Constants
constexpr int LL_PIPELINE_APRILTAG_1n8 = 1;  // This pipline will have 1 and 8 aprilTages selected
constexpr int LL_PIPELINE_APRILTAG_2n7 = 2;  // This pipline will have 2 and 7 aprilTages selected
constexpr int LL_PIPELINE_APRILTAG_3n6 = 3;  // This pipline will have 3 and 6 aprilTages selected
constexpr int LL_PIPELINE_APRILTAG_4n5 = 4;  // This pipline will have 4 and 5 aprilTages selected

constexpr int LL_PIPLINE_TARGET_UPPER_CONE = 5;
constexpr int LL_PIPLINE_TARGET_LOWER_CONE = 6;

constexpr int LL_PIPELINE_PURPLE_CUBE_NUMBER = 8;
constexpr int LL_PIPELINE_YELLOW_CONE_NUMBER = 9;
// Limelight camera specifics
constexpr double LL_LIMELIGHT_UPPER_ANGLE = -29.0762;
constexpr double LL_LIMELIGHT_LOWER_ANGLE =  20.59; //21.4527;
constexpr double LL_LIMELIGHT_UPPER_HEIGHT = 51.5;
constexpr double LL_LIMELIGHT_LOWER_HEIGHT = 8.5;  // Quick calculations says it should be 8.0 inches
// Game piece specifics
constexpr double LL_YELLOW_CONE_CENTER_HEIGHT = 6.5;
constexpr double LL_PURPLE_CUBE_CENTER_HEIGHT = 4.5;
// Game grid placement specifics
constexpr double TARGET_CONE_POLE_UPPER_HEIGHT = 43.875;
constexpr double TARGET_CONE_POLE_LOWER_HEIGHT = 24;

// Substation shelf height
constexpr double LL_SUBSTATION_SHELF_HEIGHT = 37.375;


// Target ID int values
constexpr int TID_YELLOW_CONE_ID = 1;
constexpr int TID_PURPLE_CUBE_ID = 2;
constexpr int TID_CONE_POLE_UPPER_ID = 3;
constexpr int TID_CONE_POLE_LOWER_ID = 4;

// Target heights
constexpr double TARGET_APRILTAG_GRID_HEIGHT = 18.125;
constexpr double TARGET_APRILTAG_SUBSTATION_HEIGHT = 27.375;

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

// Cone node from AprilTag 22, 8.5, 18.875
//                                  27.875 
