/*-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=*/
/*                       Blue Crew Robotics #6153                             */
/*                            Charged Up 2023                                 */
/*-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=*/
// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#include "autocommands/AutoCmdAutonomousDriveOutOfCommunity.h"
#include "autocommands/AutoCmdTimer.h"


// NOTE:  Consider using this command inline, rather than writing a subclass.
// For more information, see:
// https://docs.wpilib.org/en/stable/docs/software/commandbased/convenience-features.html

// Add Pointer to Subsystems in Parenthesis (SubExampleThing* subExampleThing, SubOtherThing* subOtherThing)
AutoCmdAutonomousDriveOutOfCommunity::AutoCmdAutonomousDriveOutOfCommunity(SubDriveTrain* subDriveTrain,  frc::Timer* timer) {
  // Add your commands here, e.g.
  // AddCommands(FooCommand(), BarCommand());
  AddCommands(

    // Drive the robot by rotations
//    AutoCmdDrive(subDriveTrain)
//    AutoCmdDriveByRotations(subDriveTrain, 1, 1, timer)

    // Drive onto the charge Station
    //AutoCmdDriveOntoChargeStation(subDriveTrain),

    //AutoCmdTimer(timer, 1.5),

    // Self-Balance on the charge station
    //AutoCmdBalanceOnChargeStation(subDriveTrain)
    
    

  );
}
