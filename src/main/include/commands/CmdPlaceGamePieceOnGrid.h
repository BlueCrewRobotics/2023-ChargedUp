// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#pragma once

#include <frc2/command/CommandBase.h>
#include <frc2/command/CommandHelper.h>

#include <frc2/command/button/CommandXboxController.h>
#include "Constants/ConsControllers.h"

#include "subsystems/SubRobotGlobals.h"
#include "subsystems/SubHorizontalElevator.h"
#include "subsystems/SubLimeLightLower.h"
#include "subsystems/SubTurret.h"
#include "subsystems/SubVerticalElevator.h"
#include "subsystems/SubClawWrist.h"

/**
 * An example command.
 *
 * <p>Note that this extends CommandHelper, rather extending CommandBase
 * directly; this is crucially important, or else the decorator functions in
 * Command will *not* work!
 */
class CmdPlaceGamePieceOnGrid
    : public frc2::CommandHelper<frc2::CommandBase, CmdPlaceGamePieceOnGrid> {
 public:
  CmdPlaceGamePieceOnGrid(SubRobotGlobals* subRobotGlobals, SubLimeLightLower* subLimeLightLower, frc2::CommandXboxController* auxController, SubVerticalElevator* subVerticalElevator, SubTurret* subTurret, SubClawWrist* subClawWrist, SubHorizontalElevator* subHorizontalElevator);

  void Initialize() override;

  void Execute() override;

  void End(bool interrupted) override;

  bool IsFinished() override;
 private:
  SubRobotGlobals* m_subRobotGlobals;
  SubLimeLightLower* m_subLimeLightLower;
  frc2::CommandXboxController* m_auxController;
  SubVerticalElevator* m_subVerticalElevator;
  SubTurret* m_subTurret;
  SubClawWrist* m_subClawWrist;
  SubHorizontalElevator* m_subHorizontalElevator;

  bool isVerticalElevatorUp = false;
  bool isTurretPerpendicular = false;
  bool isWristDown = false;
  bool isHorizontalElevatorOut = false;
  bool isTurretInPosition = false;
  bool m_finished = false;
  int dPadPosition = -1;
};
