// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#pragma once

#include <frc2/command/CommandHelper.h>
#include <frc2/command/SequentialCommandGroup.h>

#include <frc/Timer.h>

#include "autocommands/AutoCmdPlaceCube.h"
#include "AutoCmdAutonomousPlaceCube.h"
#include "autocommands/AutoCmdDriveOntoChargeStationTowardsBatteryEnd.h"
#include "autocommands/AutoCmdBalanceOnChargeStation.h"


class AutoCmdAutonomousPlaceCubeAndDriveOntoChargeStation
    : public frc2::CommandHelper<frc2::SequentialCommandGroup,
                                 AutoCmdAutonomousPlaceCubeAndDriveOntoChargeStation> {
 public:
  AutoCmdAutonomousPlaceCubeAndDriveOntoChargeStation(SubVerticalElevator* subVerticalElevator, SubTurret* subTurret, SubHorizontalElevator* subHorizontalElevator, SubClawWrist* subClawWrist, SubDriveTrain* subDriveTrain, frc::Timer* timer);
};
