// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#pragma once

#include <frc2/command/CommandHelper.h>
#include <frc2/command/SequentialCommandGroup.h>

#include "AutoCmdAutonomousPlaceCube.h"
#include "AutoCmdAutonomousDriveOverAndOntoChargeStation.h"

class AutoCmdAutonomousPlaceCubeAndDriveOverAndOntoRamp
    : public frc2::CommandHelper<frc2::SequentialCommandGroup,
                                 AutoCmdAutonomousPlaceCubeAndDriveOverAndOntoRamp> {
 public:
  AutoCmdAutonomousPlaceCubeAndDriveOverAndOntoRamp(SubVerticalElevator* subVerticalElevator, SubTurret* subTurret, SubHorizontalElevator* subHorizontalElevator, SubClawWrist* subClawWrist, SubDriveTrain* subDriveTrain, frc::Timer* timer);
};