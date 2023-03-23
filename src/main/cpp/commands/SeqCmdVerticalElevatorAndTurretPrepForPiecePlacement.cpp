// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#include "commands/SeqCmdVerticalElevatorAndTurretPrepForPiecePlacement.h"

// NOTE:  Consider using this command inline, rather than writing a subclass.
// For more information, see:
// https://docs.wpilib.org/en/stable/docs/software/commandbased/convenience-features.html
SeqCmdVerticalElevatorAndTurretPrepForPiecePlacement::SeqCmdVerticalElevatorAndTurretPrepForPiecePlacement(SubRobotGlobals* subRobotGlobals, SubVerticalElevator* subVerticalElevator, frc2::CommandXboxController* auxController, SubLimeLightLower* subLimeLightLower, SubLimeLightUpper* subLimeLightUpper, SubTurret* subTurret, SubDriveTrain* subDriveTrain, SubClawWrist* subClawWrist) {
  // Add your commands here, e.g.
  // AddCommands(FooCommand{}, BarCommand{});
  AddCommands(
    CmdVerticalElevatorGridPiecePlacement{subRobotGlobals, subVerticalElevator, auxController, subLimeLightLower, subLimeLightUpper},
    CmdClawWristGridPiecePlacement{subRobotGlobals, subClawWrist},
    CmdTurretServoToPerpendicularToGrid{subTurret, subDriveTrain, auxController}
  );
}
