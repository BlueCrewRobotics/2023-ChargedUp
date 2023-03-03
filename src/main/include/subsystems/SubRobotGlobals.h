// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#pragma once

#include <frc2/command/SubsystemBase.h>
#include "Constants/ConsGlobal.h"
#include "common/BC_Blinkin.h"

class SubRobotGlobals : public frc2::SubsystemBase {
 public:
  SubRobotGlobals();

  // Global variable used throughout the code
  game_state g_gameState;

  // Set the color of the LED lights
  void SetColor(double color);

  //

  /**
   * Will be called periodically whenever the CommandScheduler runs.
   */
  void Periodic() override;

 private:
  // Components (e.g. motor controllers and sensors) should generally be
  // declared private and exposed only through public methods.

  BC_Blinkin* m_blinkin = new BC_Blinkin(0);
};
