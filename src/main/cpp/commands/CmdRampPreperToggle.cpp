// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#include "commands/CmdRampPreperToggle.h"

CmdRampPreperToggle::CmdRampPreperToggle(SubRampPreper* subRampPreper) 
  :m_subRampPreper{subRampPreper} {
  // Use addRequirements() here to declare subsystem dependencies.
  AddRequirements(subRampPreper);
}

// Called when the command is initially scheduled.
void CmdRampPreperToggle::Initialize() {}

// Called repeatedly when this Command is scheduled to run
void CmdRampPreperToggle::Execute() {
  m_subRampPreper->ExtensionToggle();
}

// Called once the command ends or is interrupted.
void CmdRampPreperToggle::End(bool interrupted) {}

// Returns true when the command should end.
bool CmdRampPreperToggle::IsFinished() {
  return true;
}
