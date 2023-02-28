// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#pragma once

#include <frc2/command/CommandBase.h>
#include <frc2/command/CommandHelper.h>
#include <frc2/command/button/CommandXboxController.h>
#include "subsystems/SubClawWrist.h"
#include "Constants/ConsControllers.h"
#include "subsystems/SubRobotGlobals.h"
#include "subsystems/SubLimeLightLower.h"
#include "subsystems/SubLimeLightUpper.h"


/**
 * An example command.
 *
 * <p>Note that this extends CommandHelper, rather extending CommandBase
 * directly; this is crucially important, or else the decorator functions in
 * Command will *not* work!
 */
class CmdClawWristGridPiecePlacement
    : public frc2::CommandHelper<frc2::CommandBase, CmdClawWristGridPiecePlacement> {
 public:
  CmdClawWristGridPiecePlacement(SubRobotGlobals* subRobotGlobals, SubClawWrist* subClawWrist, frc2::CommandXboxController* auxController, SubLimeLightLower* subLimeLightLower, SubLimeLightUpper* subLimeLightUpper);

  void Initialize() override;

  void Execute() override;

  void End(bool interrupted) override;

  bool IsFinished() override;

  protected: 
  SubRobotGlobals* m_subRobotGlobals;
  SubClawWrist* m_subClawWrist; 
  frc2::CommandXboxController* m_auxController;
  SubLimeLightLower* m_subLimeLightLower;
  SubLimeLightUpper* m_subLimeLightUpper;
  double m_position;

};
