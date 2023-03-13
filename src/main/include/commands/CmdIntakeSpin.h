// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#pragma once

#include <frc2/command/CommandBase.h>
#include <frc2/command/CommandHelper.h>

#include <frc2/command/button/CommandXboxController.h>
#include "subsystems/SubClawWrist.h"
#include "Constants/ConsControllers.h"
#include "Constants/ConsGlobal.h"
#include "subsystems/SubRobotGlobals.h"

/**
 * An example command.
 *
 * <p>Note that this extends CommandHelper, rather extending CommandBase
 * directly; this is crucially important, or else the decorator functions in
 * Command will *not* work!
 */
class CmdIntakeSpin
    : public frc2::CommandHelper<frc2::CommandBase, CmdIntakeSpin> {
 public:
  CmdIntakeSpin(SubClawWrist* subClawWrist, frc2::CommandXboxController* auxController, SubRobotGlobals* subRobotGlobals);

  void Initialize() override;

  void Execute() override;

  void End(bool interrupted) override;

  bool IsFinished() override;

 private:
  SubClawWrist* m_subIntakeWrist;
  frc2::CommandXboxController* m_auxController;
  SubRobotGlobals* m_subRobotGlobals;
  bool m_finished = false;
  bool m_pullIn = true;
  bool m_eject = false;
};
