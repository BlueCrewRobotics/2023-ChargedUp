// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#pragma once

#include <frc2/command/CommandBase.h>
#include <frc2/command/CommandHelper.h>

#include "subsystems/SubDriveTrain.h"

/**
 * An example command.
 *
 * <p>Note that this extends CommandHelper, rather extending CommandBase
 * directly; this is crucially important, or else the decorator functions in
 * Command will *not* work!
 */
class AutoCmdDriveOverChargeStation
    : public frc2::CommandHelper<frc2::CommandBase, AutoCmdDriveOverChargeStation> {
 public:
  AutoCmdDriveOverChargeStation(SubDriveTrain* subDriveTrain);

  void Initialize() override;

  void Execute() override;

  void End(bool interrupted) override;

  bool IsFinished() override;

 private:

  SubDriveTrain* m_driveTrain;
  bool m_onChargeStation = false;
  bool m_overChargeStation = false;
  bool m_finished = false;
  double m_levelPitchValue = 0.0;
  frc::Timer m_timer;
};
