/*-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=*/
/*                       Blue Crew Robotics #6153                             */
/*                            Charged Up 2023                                 */
/*-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=*/
// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#pragma once

// Controllers
constexpr int DRIVER_CONTROLLER = 0;
constexpr int AUX_CONTROLLER = 1;
/*
   Game controller button and joystick addressing.
   Access in code by including Constants.h and using BUTTON_A
   */
constexpr int BUTTON_A = 1;
constexpr int BUTTON_B = 2;
constexpr int BUTTON_X = 3;
constexpr int BUTTON_Y = 4;
constexpr int BUTTON_L_BUMP = 5;
constexpr int BUTTON_R_BUMP = 6; // Drive gear sifting
constexpr int BUTTON_SELECT = 7;
constexpr int BUTTON_START = 8;
constexpr int BUTTON_L3 = 9;
constexpr int BUTTON_R3 = 10;

constexpr int AXIS_LX = 0; // Steer left/right
constexpr int AXIS_LY = 1;
constexpr int AXIS_L_TRIG = 2; // Forward driving
constexpr int AXIS_R_TRIG = 3; // Reverse driving
constexpr int AXIS_RX = 4;
constexpr int AXIS_RY = 5;

constexpr double JOYSTICK_AXIS_BUFFER = 0.055;

/*
   CONTROLS --

      Primary

         R Trigger - drive forward (toward turret)
         L Trigger - drive backward (toward battery)
         L Joystick X axis - drive rotation left/right
         L Joystick Y axis - 

         A - Select cube/cone
         B - 
         X - move to cube
         Y - move to cone

         R Joystick X axis -
         R Joystick Y axis -

         L Bumper -
         R Bumber - ramp preper

         Start -
         Back -

         DPAD -

      Auxiliary

         R Trigger -
         L Trigger -

         L Joystick X axis - turret rotation
         L Joystick Y axis - move vertical elevator
      
         A - up a node pos (relative to selected piece type)
         B - down a node pos (relative to selected piece type)
         X - select cube piece type
         Y - select cone piece type

         R Joystick X axis -
         R Joystick Y axis - move horizontal elevator

         L Bumper - claw open/close
         R Bumper - wrist down (release = up)

         Start -
         Back -

         DPAD - Node Selection (defined below in DPAD_VALUE_XXX constants)

*/

// aux controller D-pad values
constexpr int DPAD_VALUE_MIDDLE_CENTER = -1;
constexpr int DPAD_VALUE_MIDDLE_UP = 0;
constexpr int DPAD_VALUE_RIGHT_UP = 45;
constexpr int DPAD_VALUE_RIGHT_CENTER = 90;
constexpr int DPAD_VALUE_RIGHT_DOWN = 135;
constexpr int DPAD_VALUE_MIDDLE_DOWN = 180;
constexpr int DPAD_VALUE_LEFT_DOWN = 225;
constexpr int DPAD_VALUE_LEFT_CENTER = 270;
constexpr int DPAD_VALUE_LEFT_UP = 315;
