/*-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=*/
/*                       Blue Crew Robotics #6153                             */
/*                            Charged Up 2023                                 */
/*-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=*/
// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#include "autocommands/AutoCmdAutonomous2.h"


// NOTE:  Consider using this command inline, rather than writing a subclass.
// For more information, see:
// https://docs.wpilib.org/en/stable/docs/software/commandbased/convenience-features.html

// Add Pointer to Subsystems in Parenthesis (SubExampleThing* subExampleThing, SubOtherThing* subOtherThing)
AutoCmdAutonomous2::AutoCmdAutonomous2(SubLimeLightLower* subLimelightLower, SubDriveTrain* subDriveTrain) {
  // Add your commands here, e.g.
  // AddCommands(FooCommand(), BarCommand());
  AddCommands(
    // Drive onto the charge Station
    AutoCmdDriveOntoChargeStation(subDriveTrain),
    // Drive off of the Charge Station
    AutoCmdDriveOffOfChargeStation(subDriveTrain),
    // Turn around
    AutoCmdTurnAround(subDriveTrain),
    // Drive onto the charge station
    AutoCmdDriveOntoChargeStation(subDriveTrain),
    // Self-Balance on the charge station
    AutoCmdBalanceOnChargeStation(subDriveTrain)
    

  );
}
