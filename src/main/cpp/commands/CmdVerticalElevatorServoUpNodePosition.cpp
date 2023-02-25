// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#include "commands/CmdVerticalElevatorServoUpNodePosition.h"
#include "commands/CmdVerticalElevatorServoToPosition.h"
#include "Constants/ConsGlobal.h"

CmdVerticalElevatorServoUpNodePosition::CmdVerticalElevatorServoUpNodePosition(SubVerticalElevator* subVerticalElevator, frc2::CommandXboxController* auxController) 
: m_subVerticalElevator{subVerticalElevator}, m_auxController{auxController} {
  // Use addRequirements() here to declare subsystem dependencies.
  AddRequirements(subVerticalElevator);
}

// Called when the command is initially scheduled.
void CmdVerticalElevatorServoUpNodePosition::Initialize() {
  m_isFinished = false;
}

// Called repeatedly when this Command is scheduled to run
void CmdVerticalElevatorServoUpNodePosition::Execute() {


    double currentHeldPos = m_subVerticalElevator->GetHoldPositionDesired();
    double desiredHoldPos = -1;

    double upperPos = VERTICAL_ELEV_POS_CONE_NODE_UPPER;
    double midPos = VERTICAL_ELEV_POS_CONE_NODE_LOWER;
    double lowerPos = VERTICAL_ELEV_POS_HYBRID_NODE;
    if(g_gameState.selectedPieceType == CubePiece) {
      upperPos = VERTICAL_ELEV_POS_CONE_NODE_UPPER;
      midPos = VERTICAL_ELEV_POS_CONE_NODE_LOWER;
      lowerPos = VERTICAL_ELEV_POS_HYBRID_NODE;
    }

    if(currentHeldPos <= lowerPos) {
      desiredHoldPos = midPos; 
    }
    else if(currentHeldPos <= midPos) {
      desiredHoldPos = upperPos;
    }
    else { // just don't go any higher...
      desiredHoldPos = upperPos;
    }

    m_isFinished = true;

    m_subVerticalElevator->ServoToPosition(desiredHoldPos);
}

// Called once the command ends or is interrupted.
void CmdVerticalElevatorServoUpNodePosition::End(bool interrupted) {}

// Returns true when the command should end.
bool CmdVerticalElevatorServoUpNodePosition::IsFinished() {
  return m_isFinished;
}
