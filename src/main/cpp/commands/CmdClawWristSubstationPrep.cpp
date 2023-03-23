// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#include "commands/CmdClawWristSubstationPrep.h"

CmdClawWristSubstationPrep::CmdClawWristSubstationPrep(SubClawWrist* subClawWrist, SubRobotGlobals* subRobotGlobals)
  :m_subClawWrist{subClawWrist}, m_subRobotGlobals{subRobotGlobals} {
  // Use addRequirements() here to declare subsystem dependencies.
  AddRequirements(subClawWrist);
}

// Called when the command is initially scheduled.
void CmdClawWristSubstationPrep::Initialize() {}

// Called repeatedly when this Command is scheduled to run
void CmdClawWristSubstationPrep::Execute() {
  if(m_subRobotGlobals->g_gameState.selectedPieceType == ConePiece) {
    m_subClawWrist->ServoToPosition(WRIST_CLAW_PICKUP_UPRIGHT_CONE_OFF_SHELF);
  }
  else {
    m_subClawWrist->ServoToPosition(WRIST_CLAW_PICKUP_CUBE_OFF_SHELF);
  }
}

// Called once the command ends or is interrupted.
void CmdClawWristSubstationPrep::End(bool interrupted) {}

// Returns true when the command should end.
bool CmdClawWristSubstationPrep::IsFinished() {
  return true;
}
