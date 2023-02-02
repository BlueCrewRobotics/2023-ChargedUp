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

#include "subsystems/SubLimeLightUpper.h"
#include "subsystems/SubDriveTrain.h"
#include "Constants.h"
#include "commands/CmdFindAndGoToTarget.h"

/**
 * Command to find a purple cube and drive to it.
 *
 * <p>Note that this extends CommandHelper, rather extending CommandBase
 * directly; this is crucially important, or else the decorator functions in
 * Command will *not* work!
 */
class CmdFindAndGoToCube
   : public CmdFindAndGoToTarget {
 public:
  CmdFindAndGoToCube(SubDriveTrain* driveTrain, SubLimeLightUpper* LimeLightUpper, frc::Joystick *driverController);

  void Initialize() override;

  double getDistanceToTarget();

};
