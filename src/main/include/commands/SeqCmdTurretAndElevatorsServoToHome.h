// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#pragma once

#include <frc2/command/CommandHelper.h>
#include <frc2/command/SequentialCommandGroup.h>

#include "commands/CmdHorizontalElevatorHome.h"
#include "commands/CmdTurretHome.h"
#include "commands/CmdVerticalElevatorHome.h"
#include "commands/CmdWristHome.h"


class SeqCmdTurretAndElevatorsServoToHome
    : public frc2::CommandHelper<frc2::SequentialCommandGroup,
                                 SeqCmdTurretAndElevatorsServoToHome> {
 public:
  SeqCmdTurretAndElevatorsServoToHome(SubClawWrist* subClawWrist, SubHorizontalElevator* subHorizontalElevator, SubTurret* subTurret, SubVerticalElevator* subVerticalElevator, frc2::CommandXboxController* auxController);
};
