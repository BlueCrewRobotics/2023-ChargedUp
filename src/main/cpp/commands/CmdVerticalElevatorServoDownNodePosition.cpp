// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#include "commands/CmdVerticalElevatorServoDownNodePosition.h"
#include "commands/CmdVerticalElevatorServoToPosition.h"
#include "Constants/ConsGlobal.h"

#include <iostream>

CmdVerticalElevatorServoDownNodePosition::CmdVerticalElevatorServoDownNodePosition(SubVerticalElevator* subVerticalElevator, frc2::CommandXboxController* auxController) 
: m_subVerticalElevator{subVerticalElevator}, m_auxController{auxController} {
  // Use addRequirements() here to declare subsystem dependencies.
  AddRequirements(subVerticalElevator);
}

// Called when the command is initially scheduled.
void CmdVerticalElevatorServoDownNodePosition::Initialize() {
  m_isFinished = false;
}

// Called repeatedly when this Command is scheduled to run
void CmdVerticalElevatorServoDownNodePosition::Execute() {


    double currentHeldPos = m_subVerticalElevator->GetHoldPositionDesired();
    double desiredHoldPos = -1;

    double upperPos = 50000; // VERTICAL_ELEV_POS_CONE_NODE_UPPER;
    double midPos = 40000; // VERTICAL_ELEV_POS_CONE_NODE_LOWER;
    double lowerPos = 30000; // VERTICAL_ELEV_POS_HYBRID_NODE;
    if(g_gameState.selectedPieceType == CubePiece) {
      upperPos = 75000; // VERTICAL_ELEV_POS_CONE_NODE_UPPER;
      midPos = 65000; // VERTICAL_ELEV_POS_CONE_NODE_LOWER;
      lowerPos = 55000; // VERTICAL_ELEV_POS_HYBRID_NODE;
    }

    if(currentHeldPos >= upperPos) {
      desiredHoldPos = midPos; 
    }
    else if(currentHeldPos >= midPos) {
      desiredHoldPos = lowerPos;
    }
    else { // just don't go any lower...
      desiredHoldPos = lowerPos;
    }
std::cout << "desiredPos: " << desiredHoldPos << std::endl;

    m_isFinished = true;

    m_subVerticalElevator->ServoToPosition(desiredHoldPos);
}

// Called once the command ends or is interrupted.
void CmdVerticalElevatorServoDownNodePosition::End(bool interrupted) {}

// Returns true when the command should end.
bool CmdVerticalElevatorServoDownNodePosition::IsFinished() {
  return m_isFinished;
}
