// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#pragma once

#include <frc2/command/CommandHelper.h>
#include <frc2/command/SequentialCommandGroup.h>

#include <frc2/command/button/CommandXboxController.h>
#include "Constants/ConsControllers.h"

#include "CmdClawWristGridPiecePlacement.h"
#include "CmdVerticalElevatorGridPiecePlacement.h"
#include "CmdTurretServoToPerpendicularToGrid.h"

class SeqCmdVerticalElevatorAndTurretPrepForPiecePlacement
    : public frc2::CommandHelper<frc2::SequentialCommandGroup,
                                 SeqCmdVerticalElevatorAndTurretPrepForPiecePlacement> {
 public:
  SeqCmdVerticalElevatorAndTurretPrepForPiecePlacement(SubRobotGlobals* subRobotGlobals, SubVerticalElevator* subVerticalElevator, frc2::CommandXboxController* auxController, SubLimeLightLower* subLimeLightLower, SubLimeLightUpper* subLimeLightUpper, SubTurret* subTurret, SubDriveTrain* subDriveTrain, SubClawWrist* subClawWrist);
};
