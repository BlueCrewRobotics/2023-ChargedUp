// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#include "commands/SeqCmdTurretAndElevatorsServoToHome.h"

// NOTE:  Consider using this command inline, rather than writing a subclass.
// For more information, see:
// https://docs.wpilib.org/en/stable/docs/software/commandbased/convenience-features.html
SeqCmdTurretAndElevatorsServoToHome::SeqCmdTurretAndElevatorsServoToHome(SubClawWrist* subClawWrist, SubHorizontalElevator* subHorizontalElevator, SubTurret* subTurret, SubVerticalElevator* subVerticalElevator, frc2::CommandXboxController* auxController) {
  // Add your commands here, e.g.
  // AddCommands(FooCommand{}, BarCommand{});
  AddCommands(
    CmdWristHome{subClawWrist},
    CmdHorizontalElevatorHome{subHorizontalElevator, auxController},
    CmdTurretHome{subTurret, auxController},
    CmdVerticalElevatorHome{subVerticalElevator}
  );
}
