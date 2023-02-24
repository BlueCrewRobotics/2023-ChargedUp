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
#include <frc2/command/button/CommandXboxController.h>

#include "subsystems/SubLimeLightUpper.h"
#include "subsystems/SubDriveTrain.h"
#include "Constants/ConsControllers.h"

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
  CmdFindAndGoToTarget(SubDriveTrain* driveTrain, SubLimeLightUpper* LimeLightUpper, frc2::CommandXboxController* driverController);

  void Initialize() override;

  void Execute() override;

  void End(bool interrupted) override;

  bool IsFinished() override;

  double getDistanceToTarget();

 protected:
  SubDriveTrain* m_driveTrain;
  SubLimeLightUpper* m_LimeLightUpper;
  frc2::CommandXboxController* m_driverController;
  bool m_finished = false;
  int m_targetType = 0;
};
