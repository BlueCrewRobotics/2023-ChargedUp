// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#pragma once

#include <frc2/command/CommandBase.h>
#include <frc2/command/CommandHelper.h>

#include "subsystems/SubClawWrist.h"

/**
 * An example command.
 *
 * <p>Note that this extends CommandHelper, rather extending CommandBase
 * directly; this is crucially important, or else the decorator functions in
 * Command will *not* work!
 */
class AutoCmdWristServoToPosition
    : public frc2::CommandHelper<frc2::CommandBase, AutoCmdWristServoToPosition> {
 public:
  AutoCmdWristServoToPosition(SubClawWrist* subClawWrist, double positionToGoTo, double positionToFinishAt);

  void Initialize() override;

  void Execute() override;

  void End(bool interrupted) override;

  bool IsFinished() override;
 private:
  SubClawWrist* m_subClawWrist;
  double m_positionToGoTo = 0.0;
  double m_positionToFinishAt = 0.0;
  double startingPosition = 0.0;
  bool goingUp = false;
  bool m_isPositionSet;
  bool m_finished;
};
