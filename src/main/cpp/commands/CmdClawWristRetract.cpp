// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#include "commands/CmdClawWristRetract.h"

CmdClawWristRetract::CmdClawWristRetract(SubClawWrist* subClawWrist) 
  : m_subClawWrist{subClawWrist}{
  // Use addRequirements() here to declare subsystem dependencies.
  AddRequirements(subClawWrist);
}

// Called when the command is initially scheduled.
void CmdClawWristRetract::Initialize() {}

// Called repeatedly when this Command is scheduled to run
void CmdClawWristRetract::Execute() {

  m_subClawWrist->ServoToPosition(0);
  
}

// Called once the command ends or is interrupted.
void CmdClawWristRetract::End(bool interrupted) {}

// Returns true when the command should end.
bool CmdClawWristRetract::IsFinished() {
  return true;
}
