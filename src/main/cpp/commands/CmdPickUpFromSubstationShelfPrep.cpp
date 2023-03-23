// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#include "commands/CmdPickUpFromSubstationShelfPrep.h"

// NOTE:  Consider using this command inline, rather than writing a subclass.
// For more information, see:
// https://docs.wpilib.org/en/stable/docs/software/commandbased/convenience-features.html
CmdPickUpFromSubstationShelfPrep::CmdPickUpFromSubstationShelfPrep(SubVerticalElevator* subVerticalElevator, SubClawWrist* subClawWrist, SubRobotGlobals* subRobotGlobals) {
  // Add your commands here, e.g.
  // AddCommands(FooCommand{}, BarCommand{});
  AddCommands(
    CmdVerticalElevatorServoToSubstationShelf(subVerticalElevator),
    CmdClawWristSubstationPrep(subClawWrist, subRobotGlobals)
  );
}
