// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#include "commands/CmdClawWristGridPiecePlacement.h"

CmdClawWristGridPiecePlacement::CmdClawWristGridPiecePlacement(SubRobotGlobals* subRobotGlobals, SubClawWrist* subClawWrist, frc2::CommandXboxController* auxController, SubLimeLightLower* subLimeLightLower, SubLimeLightUpper* subLimeLightUpper) 
: m_subRobotGlobals{subRobotGlobals}, m_subClawWrist{subClawWrist}, m_auxController{auxController}, m_subLimeLightLower{subLimeLightLower}, m_subLimeLightUpper{subLimeLightUpper} {
  // Use addRequirements() here to declare subsystem dependencies.
  AddRequirements(subClawWrist);
}

// Called when the command is initially scheduled.
void CmdClawWristGridPiecePlacement::Initialize() {}

// Called repeatedly when this Command is scheduled to run
void CmdClawWristGridPiecePlacement::Execute() {
/*  
  if((m_subRobotGlobals->g_gameState.selectedPieceType == ConePiece) && (m_auxController->GetPOV() == DPAD_VALUE_MIDDLE_UP) || (m_auxController->GetPOV() == DPAD_VALUE_LEFT_UP) || (m_auxController->GetPOV() == DPAD_VALUE_RIGHT_UP) ){
    //m_subVerticalElevator->ServoToPosition(VERTICAL_ELEV_POS_CONE_NODE_UPPER);
  }
  if((m_subRobotGlobals->g_gameState.selectedPieceType == ConePiece) && (m_auxController->GetPOV() == DPAD_VALUE_MIDDLE_CENTER) || (m_auxController->GetPOV() == DPAD_VALUE_LEFT_CENTER) || (m_auxController->GetPOV() == DPAD_VALUE_RIGHT_CENTER) ){
    //m_subVerticalElevator->ServoToPosition(VERTICAL_ELEV_POS_CONE_NODE_LOWER);
  }
  if((m_subRobotGlobals->g_gameState.selectedPieceType == ConePiece || m_subRobotGlobals->g_gameState.selectedPieceType == CubePiece) && (m_auxController->GetPOV() == DPAD_VALUE_MIDDLE_DOWN) || (m_auxController->GetPOV() == DPAD_VALUE_LEFT_DOWN) || (m_auxController->GetPOV() == DPAD_VALUE_RIGHT_DOWN) ){
    //m_subVerticalElevator->ServoToPosition(VERTICAL_ELEV_POS_HYBRID_NODE);
  }
  if((m_subRobotGlobals->g_gameState.selectedPieceType == CubePiece) && (m_auxController->GetPOV() == DPAD_VALUE_MIDDLE_UP) || (m_auxController->GetPOV() == DPAD_VALUE_RIGHT_DOWN) || (m_auxController->GetPOV() == DPAD_VALUE_RIGHT_UP) ){
    //m_subVerticalElevator->ServoToPosition(VERTICAL_ELEV_POS_CUBE_NODE_UPPER);
  }
  if((m_subRobotGlobals->g_gameState.selectedPieceType == CubePiece) && (m_auxController->GetPOV() == DPAD_VALUE_MIDDLE_CENTER) || (m_auxController->GetPOV() == DPAD_VALUE_LEFT_CENTER) || (m_auxController->GetPOV() == DPAD_VALUE_RIGHT_CENTER) ){
    //m_subVerticalElevator->ServoToPosition(VERTICAL_ELEV_POS_CUBE_NODE_LOWER);
  }
  */
}

// Called once the command ends or is interrupted.
void CmdClawWristGridPiecePlacement::End(bool interrupted) {}

// Returns true when the command should end.
bool CmdClawWristGridPiecePlacement::IsFinished() {
  return true;
}
