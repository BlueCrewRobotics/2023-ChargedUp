// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#include "commands/CmdClawWristExtend.h"

CmdClawWristExtend::CmdClawWristExtend(SubClawWrist* subClawWrist) 
  : m_subClawWrist{subClawWrist}{
  // Use addRequirements() here to declare subsystem dependencies.
  AddRequirements(subClawWrist);
}

// Called when the command is initially scheduled.
void CmdClawWristExtend::Initialize() {}

// Called repeatedly when this Command is scheduled to run
void CmdClawWristExtend::Execute() {

  m_subClawWrist->ServoToPosition(22.5);
  
}

// Called once the command ends or is interrupted.
void CmdClawWristExtend::End(bool interrupted) {}

// Returns true when the command should end.
bool CmdClawWristExtend::IsFinished() {
  return true;
}
