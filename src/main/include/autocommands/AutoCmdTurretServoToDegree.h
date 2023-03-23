// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#pragma once

#include <frc2/command/CommandBase.h>
#include <frc2/command/CommandHelper.h>

#include "subsystems/SubTurret.h"

/**
 * An example command.
 *
 * <p>Note that this extends CommandHelper, rather extending CommandBase
 * directly; this is crucially important, or else the decorator functions in
 * Command will *not* work!
 */
class AutoCmdTurretServoToDegree
    : public frc2::CommandHelper<frc2::CommandBase, AutoCmdTurretServoToDegree> {
 public:
  AutoCmdTurretServoToDegree(SubTurret* subTurret, double angleToGoTo, double angleToFinishAt);

  void Initialize() override;

  void Execute() override;

  void End(bool interrupted) override;

  bool IsFinished() override;
 private:
  SubTurret* m_subTurret;
  double m_angleToGoTo = 0.0;
  double m_angleToFinishAt = 0.0;
  double startingAngle = 0.0;
  bool goingClockwise = false;
  bool m_isPositionSet;
  bool m_finished;
};
