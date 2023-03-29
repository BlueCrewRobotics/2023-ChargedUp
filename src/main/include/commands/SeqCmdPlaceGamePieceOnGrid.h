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
#include "commands/CmdVerticalElevatorGridPiecePlacement.h"
#include "commands/CmdTurretGridPiecePlacement.h"
#include "commands/CmdHorizontalElevGridPiecePlacement.h"
#include "commands/CmdClawWristGridPiecePlacement.h"
#include "commands/SeqCmdVerticalElevatorAndTurretPrepForPiecePlacement.h"
#include "autocommands/AutoCmdTimer.h"

// Subsystem includes
#include "subsystems/SubRobotGlobals.h"
#include "subsystems/SubVerticalElevator.h"
#include "subsystems/SubTurret.h"
#include "subsystems/SubHorizontalElevator.h"
#include "subsystems/SubLimeLightLower.h"
#include "subsystems/SubLimeLightUpper.h"


class SeqCmdPlaceGamePieceOnGrid
    : public frc2::CommandHelper<frc2::SequentialCommandGroup, SeqCmdPlaceGamePieceOnGrid> {
 public:
  SeqCmdPlaceGamePieceOnGrid(SubRobotGlobals* subRobotGlobals, 
          SubVerticalElevator* subVerticalElevator, 
          SubTurret* subTurret, 
          SubHorizontalElevator* subHorizontalElevator, 
          frc2::CommandXboxController* auxController, 
          SubLimeLightLower* subLimeLightLower, 
          SubLimeLightUpper* subLimeLightUpper,
          SubDriveTrain* subDriveTrain,
          SubClawWrist* subClawWrist,
          frc::Timer* timer);
};
