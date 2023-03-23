// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#pragma once

#include <frc2/command/CommandHelper.h>
#include <frc2/command/SequentialCommandGroup.h>

#include <frc/Timer.h>

#include "AutoCmdPlaceCube.h"
#include "AutoCmdHorizontalElevatorServoToPosition.h"
#include "AutoCmdVerticalElevatorServoToPosition.h"
#include "AutoCmdTurretServoToDegree.h"
#include "AutoCmdWristServoToPosition.h"
#include "AutoCmdIntakeSpin.h"
#include "commands/SeqCmdTurretAndElevatorsServoToHome.h"

class AutoCmdAutonomousPlaceCube
    : public frc2::CommandHelper<frc2::SequentialCommandGroup,
                                 AutoCmdAutonomousPlaceCube> {
 public:
  AutoCmdAutonomousPlaceCube(SubVerticalElevator* subVerticalElevator, SubTurret* subTurret, SubHorizontalElevator* subHorizontalElevator, SubClawWrist* subClawWrist, frc::Timer* timer);
};
