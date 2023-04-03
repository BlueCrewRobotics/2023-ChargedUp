// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#pragma once

#include <frc2/command/CommandBase.h>
#include <frc2/command/CommandHelper.h>

#include <frc2/command/button/CommandXboxController.h>
#include "Constants/ConsControllers.h"

#include "subsystems/SubClawWrist.h"
#include "subsystems/SubRobotGlobals.h"

/**
 * An example command.
 *
 * <p>Note that this extends CommandHelper, rather extending CommandBase
 * directly; this is crucially important, or else the decorator functions in
 * Command will *not* work!
 */
class CmdClawWristPickUpOffFloor
    : public frc2::CommandHelper<frc2::CommandBase, CmdClawWristPickUpOffFloor> {
 public:
  CmdClawWristPickUpOffFloor(SubClawWrist* subClawWrist, frc2::CommandXboxController* driverController, SubRobotGlobals* subRobotGlobals);

  void Initialize() override;

  void Execute() override;

  void End(bool interrupted) override;

  bool IsFinished() override;
 private:
  SubClawWrist* m_subClawWrist;
  frc2::CommandXboxController* m_driverController;
  SubRobotGlobals* m_subRobotGlobals;
  bool m_finished = false;
};
