/*-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=*/
/*                       Blue Crew Robotics #6153                             */
/*                            Charged Up 2023                                 */
/*-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=*/
// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#pragma once

#include <frc2/command/CommandBase.h>
#include <frc2/command/CommandHelper.h>
#include <frc/Joystick.h>

#include "subsystems/SubLimeLightLower.h"
#include "subsystems/SubDriveTrain.h"
#include "Constants.h"

/**
 * Command to find a target and drive to it.
 *
 * <p>Note that this extends CommandHelper, rather extending CommandBase
 * directly; this is crucially important, or else the decorator functions in
 * Command will *not* work!
 */
class CmdFindAndGoToTarget
    : public frc2::CommandHelper<frc2::CommandBase, CmdFindAndGoToTarget> {
 public:
  CmdFindAndGoToTarget(SubDriveTrain* driveTrain, SubLimeLightLower* limeLightLower, frc::Joystick *driverController);

  void Initialize() override;

  void Execute() override;

  void End(bool interrupted) override;

  bool IsFinished() override;

  double getDistanceToTarget();

 protected:
  SubDriveTrain* m_driveTrain;
  SubLimeLightLower* m_limeLightLower;
  frc::Joystick* m_driverController;

  bool m_isFinished = false;
};
