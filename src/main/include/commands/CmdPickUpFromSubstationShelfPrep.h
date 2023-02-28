// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#pragma once

#include <frc2/command/CommandHelper.h>
#include <frc2/command/ParallelCommandGroup.h>

#include "CmdTurretTargeting.h"
#include "CmdVerticalElevatorServoToSubstationShelf.h"

class CmdPickUpFromSubstationShelfPrep
    : public frc2::CommandHelper<frc2::ParallelCommandGroup,
                                 CmdPickUpFromSubstationShelfPrep> {
 public:
  CmdPickUpFromSubstationShelfPrep(SubTurret* subTurret, SubVerticalElevator* subVerticalElevator, SubLimeLightUpper* subLimeLightUpper);
};
