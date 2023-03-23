// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#pragma once

#include <frc2/command/CommandBase.h>
#include <frc2/command/CommandHelper.h>

#include <frc/Timer.h>

#include "subsystems/SubClawWrist.h"

/**
 * An example command.
 *
 * <p>Note that this extends CommandHelper, rather extending CommandBase
 * directly; this is crucially important, or else the decorator functions in
 * Command will *not* work!
 */
class AutoCmdIntakeSpin
    : public frc2::CommandHelper<frc2::CommandBase, AutoCmdIntakeSpin> {
 public:
  AutoCmdIntakeSpin(SubClawWrist* subClawWrist, double speed, frc::Timer* timer, double spinTime /*Amount Of Time To Spin The Intake For In Seconds*/);

  void Initialize() override;

  void Execute() override;

  void End(bool interrupted) override;

  bool IsFinished() override;
 private:
  SubClawWrist* m_subClawWrist;
  double m_speed;
  frc::Timer* m_timer;
  double m_spinTime;
};
