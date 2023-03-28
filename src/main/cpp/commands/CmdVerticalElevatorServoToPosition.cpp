// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#include "commands/CmdVerticalElevatorServoToPosition.h"

#include <iostream>
#include <stdio.h>

CmdVerticalElevatorServoToPosition::CmdVerticalElevatorServoToPosition(SubRobotGlobals* subRobotGlobals, SubVerticalElevator* subVerticalElevator, frc2::CommandXboxController* auxController) 
: m_subRobotGlobals{subRobotGlobals}, m_subVerticalElevator{subVerticalElevator}, m_auxController{auxController} {
  // Use addRequirements() here to declare subsystem dependencies.
  AddRequirements(subVerticalElevator);
}

// Called when the command is initially scheduled.
void CmdVerticalElevatorServoToPosition::Initialize() {
  m_position = 0.0;
  m_finished = false;
  if((m_subRobotGlobals->g_gameState.selectedPieceType == ConePiece) && ((m_auxController->GetPOV() == DPAD_VALUE_MIDDLE_UP) || (m_auxController->GetPOV() == DPAD_VALUE_LEFT_UP) || (m_auxController->GetPOV() == DPAD_VALUE_RIGHT_UP))){
    m_position=VERTICAL_ELEV_POS_CONE_NODE_UPPER;
  }
  if((m_subRobotGlobals->g_gameState.selectedPieceType == ConePiece) && ((m_auxController->GetPOV() == DPAD_VALUE_MIDDLE_CENTER) || (m_auxController->GetPOV() == DPAD_VALUE_LEFT_CENTER) || (m_auxController->GetPOV() == DPAD_VALUE_RIGHT_CENTER))){
    m_position=VERTICAL_ELEV_POS_CONE_NODE_LOWER;
  }
  if(((m_subRobotGlobals->g_gameState.selectedPieceType == ConePiece || m_subRobotGlobals->g_gameState.selectedPieceType == CubePiece)) && ((m_auxController->GetPOV() == DPAD_VALUE_MIDDLE_DOWN) || (m_auxController->GetPOV() == DPAD_VALUE_LEFT_DOWN) || (m_auxController->GetPOV() == DPAD_VALUE_RIGHT_DOWN))){
    m_position=VERTICAL_ELEV_POS_HYBRID_NODE;
  }
  if((m_subRobotGlobals->g_gameState.selectedPieceType == CubePiece) && ((m_auxController->GetPOV() == DPAD_VALUE_MIDDLE_UP) || (m_auxController->GetPOV() == DPAD_VALUE_RIGHT_DOWN) || (m_auxController->GetPOV() == DPAD_VALUE_RIGHT_UP))){
    m_position=VERTICAL_ELEV_POS_CUBE_NODE_UPPER;
  }
  if((m_subRobotGlobals->g_gameState.selectedPieceType == CubePiece) && ((m_auxController->GetPOV() == DPAD_VALUE_MIDDLE_CENTER) || (m_auxController->GetPOV() == DPAD_VALUE_LEFT_CENTER) || (m_auxController->GetPOV() == DPAD_VALUE_RIGHT_CENTER))){
    m_position=VERTICAL_ELEV_POS_CUBE_NODE_LOWER;
  }
  if(m_position != 0.0) {
    m_subVerticalElevator->ServoToPosition(m_position);
    std::cout << "Position Not Set" << std::endl;
  }
}

// Called repeatedly when this Command is scheduled to run
void CmdVerticalElevatorServoToPosition::Execute() {
  if(m_position != 0.0) {
    if(m_subVerticalElevator->GetPosition() > (m_position-10000) &&m_subVerticalElevator->GetPosition() < (m_position+10000)) {
      m_finished = true;
      std::cout << "Finished Going Up: " << m_subVerticalElevator->GetPosition() << std::endl;
    }
  }
  else {
    m_finished = true;
    std::cout << "Position Not Set Finished" << std::endl;
  }
}

// Called once the command ends or is interrupted.
void CmdVerticalElevatorServoToPosition::End(bool interrupted) {}

// Returns true when the command should end.
bool CmdVerticalElevatorServoToPosition::IsFinished() {
  return m_finished;
}
