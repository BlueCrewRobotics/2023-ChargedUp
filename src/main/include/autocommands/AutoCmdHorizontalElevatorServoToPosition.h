// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#pragma once

#include <frc2/command/CommandBase.h>
#include <frc2/command/CommandHelper.h>

#include "subsystems/SubHorizontalElevator.h"

/**
 * An example command.
 *
 * <p>Note that this extends CommandHelper, rather extending CommandBase
 * directly; this is crucially important, or else the decorator functions in
 * Command will *not* work!
 */
class AutoCmdHorizontalElevatorServoToPosition
    : public frc2::CommandHelper<frc2::CommandBase, AutoCmdHorizontalElevatorServoToPosition> {
 public:
  AutoCmdHorizontalElevatorServoToPosition(SubHorizontalElevator* subHorizontalElevator, double positionToGoTo, double positionToFinishAt);

  void Initialize() override;

  void Execute() override;

  void End(bool interrupted) override;

  bool IsFinished() override;

 private:
  SubHorizontalElevator* m_subHorizontalElevator;
  double m_positionToGoTo = 0.0;
  double m_positionToFinishAt = 0.0;
  double startingPosition = 0.0;
  bool goingOut = false;
  bool m_isPositionSet;
  bool m_finished;
};
