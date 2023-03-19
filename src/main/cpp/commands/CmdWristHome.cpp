// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#include "commands/CmdWristHome.h"

CmdWristHome::CmdWristHome(SubClawWrist* subClawWrist) 
  :m_subClawWrist{subClawWrist} {
  // Use addRequirements() here to declare subsystem dependencies.
  AddRequirements(subClawWrist);
}

// Called when the command is initially scheduled.
void CmdWristHome::Initialize() {}

// Called repeatedly when this Command is scheduled to run
void CmdWristHome::Execute() {
  m_subClawWrist->ServoToPosition(WRIST_CLAW_MIN_LIMIT);
}

// Called once the command ends or is interrupted.
void CmdWristHome::End(bool interrupted) {}

// Returns true when the command should end.
bool CmdWristHome::IsFinished() {
  return true;
}
