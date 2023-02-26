// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#include "commands/CmdVerticalElevatorServoToPosition.h"

CmdVerticalElevatorServoToPosition::CmdVerticalElevatorServoToPosition(SubRobotGlobals* subRobotGlobals, SubVerticalElevator* subVerticalElevator, frc2::CommandXboxController* auxController, double position) 
: m_subRobotGlobals{subRobotGlobals}, m_subVerticalElevator{subVerticalElevator}, m_auxController{auxController}, m_position{position} {
  // Use addRequirements() here to declare subsystem dependencies.
  AddRequirements(subVerticalElevator);
}

// Called when the command is initially scheduled.
void CmdVerticalElevatorServoToPosition::Initialize() {}

// Called repeatedly when this Command is scheduled to run
void CmdVerticalElevatorServoToPosition::Execute() {
  if((m_subRobotGlobals->g_gameState.selectedPieceType == ConePiece) && (m_auxController->GetPOV() == 0) || (m_auxController->GetPOV() == 315) || (m_auxController->GetPOV() == 45) ){
    m_subVerticalElevator->ServoToPosition(VERTICAL_ELEV_POS_CONE_NODE_UPPER);
  }
  if((m_subRobotGlobals->g_gameState.selectedPieceType == ConePiece) && (m_auxController->GetPOV() == -1) || (m_auxController->GetPOV() == 270) || (m_auxController->GetPOV() == 90) ){
    m_subVerticalElevator->ServoToPosition(VERTICAL_ELEV_POS_CONE_NODE_LOWER);
  }
  if((m_subRobotGlobals->g_gameState.selectedPieceType == ConePiece || m_subRobotGlobals->g_gameState.selectedPieceType == CubePiece) && (m_auxController->GetPOV() == 180) || (m_auxController->GetPOV() == 225) || (m_auxController->GetPOV() == 135) ){
    m_subVerticalElevator->ServoToPosition(VERTICAL_ELEV_POS_HYBRID_NODE);
  }
  if((m_subRobotGlobals->g_gameState.selectedPieceType == CubePiece) && (m_auxController->GetPOV() == 0) || (m_auxController->GetPOV() == 315) || (m_auxController->GetPOV() == 45) ){
    m_subVerticalElevator->ServoToPosition(VERTICAL_ELEV_POS_CUBE_NODE_UPPER);
  }
  if((m_subRobotGlobals->g_gameState.selectedPieceType == CubePiece) && (m_auxController->GetPOV() == -1) || (m_auxController->GetPOV() == 270) || (m_auxController->GetPOV() == 90) ){
    m_subVerticalElevator->ServoToPosition(VERTICAL_ELEV_POS_CUBE_NODE_LOWER);
  }
}

// Called once the command ends or is interrupted.
void CmdVerticalElevatorServoToPosition::End(bool interrupted) {}

// Returns true when the command should end.
bool CmdVerticalElevatorServoToPosition::IsFinished() {
  return true;
}
