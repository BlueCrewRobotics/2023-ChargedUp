/*-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=*/
/*                       Blue Crew Robotics #6153                             */
/*                            Charged Up 2023                                 */
/*-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=*/
// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#include "commands/SeqCmdPlaceGamePieceOnGrid.h"


// NOTE:  Consider using this command inline, rather than writing a subclass.
// For more information, see:
// https://docs.wpilib.org/en/stable/docs/software/commandbased/convenience-features.html

// Add Pointer to Subsystems in Parenthesis (SubExampleThing* subExampleThing, SubOtherThing* subOtherThing)
SeqCmdPlaceGamePieceOnGrid::SeqCmdPlaceGamePieceOnGrid(SubRobotGlobals* subRobotGlobals, 
        SubVerticalElevator* subVerticalElevator, 
        SubTurret* subTurret, 
        SubHorizontalElevator* subHorizontalElevator, 
        frc2::CommandXboxController* auxController, 
        SubLimeLightLower* subLimeLightLower, 
        SubLimeLightUpper* subLimeLightUpper) {
  // Add your commands here, e.g.
  // AddCommands(FooCommand(), BarCommand());
  AddCommands(
    // Move vertical elevator to the right height based on game piece selected
    CmdVerticalElevatorGridPiecePlacement(subRobotGlobals, subVerticalElevator, auxController, subLimeLightLower, subLimeLightUpper),
    // Rotate the turret to the proper locations based on the DPad selected placement
    CmdTurretGridPiecePlacement(subRobotGlobals, subTurret, auxController, subLimeLightLower, subLimeLightUpper)

    

  );
}
