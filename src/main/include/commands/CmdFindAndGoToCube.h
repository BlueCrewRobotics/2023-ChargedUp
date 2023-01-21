// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#pragma once

#include <frc2/command/CommandBase.h>
#include <frc2/command/CommandHelper.h>
#include <frc/Joystick.h>

#include "subsystems/SubLimeLight.h"
#include "subsystems/SubDriveTrain.h"
#include "Constants.h"

/**
 * Command to find a purple cube and drive to it.
 *
 * <p>Note that this extends CommandHelper, rather extending CommandBase
 * directly; this is crucially important, or else the decorator functions in
 * Command will *not* work!
 */
class CmdFindAndGoToCube
    : public frc2::CommandHelper<frc2::CommandBase, CmdFindAndGoToCube> {
 public:
  CmdFindAndGoToCube(SubDriveTrain* driveTrain, SubLimeLight* limeLight, frc::Joystick *driverController);

  void Initialize() override;

  void Execute() override;

  void End(bool interrupted) override;

  bool IsFinished() override;


 private:
  SubDriveTrain* m_driveTrain;
  SubLimeLight* m_limeLight;
  frc::Joystick* m_driverController;

  bool m_isFinished = false;
};
