// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#include "commands/CmdVerticalElevatorGridPiecePlacement.h"

CmdVerticalElevatorGridPiecePlacement::CmdVerticalElevatorGridPiecePlacement(SubRobotGlobals* subRobotGlobals, SubVerticalElevator* subVerticalElevator, frc2::CommandXboxController* auxController, SubLimeLightLower* subLimeLightLower, SubLimeLightUpper* subLimeLightUpper) 
: m_subRobotGlobals{subRobotGlobals}, m_subVerticalElevator{subVerticalElevator}, m_auxController{auxController}, m_subLimeLightLower{subLimeLightLower}, m_subLimeLightUpper{subLimeLightUpper} {
  // Use addRequirements() here to declare subsystem dependencies.
  AddRequirements(subVerticalElevator);
}

// Called when the command is initially scheduled.
void CmdVerticalElevatorGridPiecePlacement::Initialize() {}

// Called repeatedly when this Command is scheduled to run
void CmdVerticalElevatorGridPiecePlacement::Execute() {
  if((m_subRobotGlobals->g_gameState.selectedPieceType == ConePiece) && ((m_auxController->GetPOV() == DPAD_VALUE_MIDDLE_UP) || (m_auxController->GetPOV() == DPAD_VALUE_LEFT_UP) || (m_auxController->GetPOV() == DPAD_VALUE_RIGHT_UP))){
    m_subVerticalElevator->ServoToPosition(VERTICAL_ELEV_POS_CONE_NODE_UPPER);
    std::cout << "VE Cone Middle Up " << std::endl;
  }
  if((m_subRobotGlobals->g_gameState.selectedPieceType == ConePiece) && ((m_auxController->GetPOV() == DPAD_VALUE_MIDDLE_CENTER) || (m_auxController->GetPOV() == DPAD_VALUE_LEFT_CENTER) || (m_auxController->GetPOV() == DPAD_VALUE_RIGHT_CENTER))){
    m_subVerticalElevator->ServoToPosition(VERTICAL_ELEV_POS_CONE_NODE_LOWER);
    std::cout << "VE Cone Middle Center " << std::endl;
  }
  if(((m_subRobotGlobals->g_gameState.selectedPieceType == ConePiece || m_subRobotGlobals->g_gameState.selectedPieceType == CubePiece)) && ((m_auxController->GetPOV() == DPAD_VALUE_MIDDLE_DOWN) || (m_auxController->GetPOV() == DPAD_VALUE_LEFT_DOWN) || (m_auxController->GetPOV() == DPAD_VALUE_RIGHT_DOWN))){
    m_subVerticalElevator->ServoToPosition(VERTICAL_ELEV_POS_HYBRID_NODE);
    std::cout << "VE Cone or Cube Hybrid " << std::endl;
  }
  if((m_subRobotGlobals->g_gameState.selectedPieceType == CubePiece) && ((m_auxController->GetPOV() == DPAD_VALUE_MIDDLE_UP) || (m_auxController->GetPOV() == DPAD_VALUE_RIGHT_DOWN) || (m_auxController->GetPOV() == DPAD_VALUE_RIGHT_UP))){
    m_subVerticalElevator->ServoToPosition(VERTICAL_ELEV_POS_CUBE_NODE_UPPER);
    std::cout << "VE Cube Middle Up " << std::endl;
  }
  if((m_subRobotGlobals->g_gameState.selectedPieceType == CubePiece) && ((m_auxController->GetPOV() == DPAD_VALUE_MIDDLE_CENTER) || (m_auxController->GetPOV() == DPAD_VALUE_LEFT_CENTER) || (m_auxController->GetPOV() == DPAD_VALUE_RIGHT_CENTER))){
    m_subVerticalElevator->ServoToPosition(VERTICAL_ELEV_POS_CUBE_NODE_LOWER);
    std::cout << "VE Cube Middle Center " << std::endl;
  }
}

// Called once the command ends or is interrupted.
void CmdVerticalElevatorGridPiecePlacement::End(bool interrupted) {}

// Returns true when the command should end.
bool CmdVerticalElevatorGridPiecePlacement::IsFinished() {
  std::cout << "Auto VerticalElevator Grid Placement ended" << std::endl;
  return true;
}
