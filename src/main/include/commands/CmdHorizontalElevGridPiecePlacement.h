// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#pragma once

#include <frc2/command/CommandBase.h>
#include <frc2/command/CommandHelper.h>
#include <frc2/command/button/CommandXboxController.h>
#include "subsystems/SubHorizontalElevator.h"
#include "Constants/ConsControllers.h"
#include "subsystems/SubRobotGlobals.h"
#include "subsystems/SubLimeLightLower.h"
#include "subsystems/SubLimeLightUpper.h"
#include "subsystems/SubTurret.h"


/**
 * An example command.
 *
 * <p>Note that this extends CommandHelper, rather extending CommandBase
 * directly; this is crucially important, or else the decorator functions in
 * Command will *not* work!
 */
class CmdHorizontalElevGridPiecePlacement
    : public frc2::CommandHelper<frc2::CommandBase, CmdHorizontalElevGridPiecePlacement> {
 public:
  CmdHorizontalElevGridPiecePlacement(SubRobotGlobals* subRobotGlobals, SubHorizontalElevator* subHorizontal, frc2::CommandXboxController* auxController, SubLimeLightLower* subLimeLightLower, SubLimeLightUpper* subLimeLightUpper, SubTurret* subTurret);

  void Initialize() override;

  void Execute() override;

  void End(bool interrupted) override;

  bool IsFinished() override;

  protected: 
  SubRobotGlobals* m_subRobotGlobals;
  SubHorizontalElevator* m_subHorizontalElevator; 
  frc2::CommandXboxController* m_auxController;
  SubLimeLightLower* m_subLimeLightLower;
  SubLimeLightUpper* m_subLimeLightUpper;
  SubTurret* m_subTurret;
  double m_position;
  double m_maxExtension;

};
