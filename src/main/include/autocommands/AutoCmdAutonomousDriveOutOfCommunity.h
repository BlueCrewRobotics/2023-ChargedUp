/*-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=*/
/*                       Blue Crew Robotics #6153                             */
/*                            Charged Up 2023                                 */
/*-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=*/
// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#pragma once

#include <frc2/command/CommandHelper.h>
#include <frc2/command/SequentialCommandGroup.h>

// Command includes
#include "commands/ExampleCommand.h"

// Autonomous commands
#include "autocommands/AutoCmdDrive.h"

// Subsystem includes

#include "subsystems/SubDriveTrain.h"
#include "subsystems/SubPneumatics.h"
#include "subsystems/SubLimeLightLower.h"


class AutoCmdAutonomousDriveOutOfCommunity
    : public frc2::CommandHelper<frc2::SequentialCommandGroup, AutoCmdAutonomousDriveOutOfCommunity> {
 public:
  AutoCmdAutonomousDriveOutOfCommunity(SubLimeLightLower* subLimelightLower, SubDriveTrain* subDriveTrain,  frc::Timer* timer);
};
