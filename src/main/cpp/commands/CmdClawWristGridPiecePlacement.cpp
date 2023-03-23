// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#include "commands/CmdClawWristGridPiecePlacement.h"

CmdClawWristGridPiecePlacement::CmdClawWristGridPiecePlacement(SubRobotGlobals* subRobotGlobals, SubClawWrist* subClawWrist) 
: m_subRobotGlobals{subRobotGlobals}, m_subClawWrist{subClawWrist} {
  // Use addRequirements() here to declare subsystem dependencies.
  AddRequirements(subClawWrist);
}

// Called when the command is initially scheduled.
void CmdClawWristGridPiecePlacement::Initialize() {
  if(m_subRobotGlobals->g_gameState.selectedPieceType == ConePiece) {
    m_subClawWrist->ServoToPosition(WRIST_CLAW_PLACE_CONE);
  }
  else if(m_subRobotGlobals->g_gameState.selectedPieceType == CubePiece) {
    m_subClawWrist->ServoToPosition(WRIST_CLAW_PLACE_CUBE);
  }
}

// Called repeatedly when this Command is scheduled to run
void CmdClawWristGridPiecePlacement::Execute() {}

// Called once the command ends or is interrupted.
void CmdClawWristGridPiecePlacement::End(bool interrupted) {}

// Returns true when the command should end.
bool CmdClawWristGridPiecePlacement::IsFinished() {
  return true;
}
