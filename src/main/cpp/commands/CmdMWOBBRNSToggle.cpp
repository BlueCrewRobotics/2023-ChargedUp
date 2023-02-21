// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#include "commands/CmdMWOBBRNSToggle.h"

CmdMWOBBRNSToggle::CmdMWOBBRNSToggle(SubMWOBBRNS* subMWOBBRNS) 
  :m_subMWOBBRNS{subMWOBBRNS} {
  // Use addRequirements() here to declare subsystem dependencies.
  AddRequirements(subMWOBBRNS);
}

// Called when the command is initially scheduled.
void CmdMWOBBRNSToggle::Initialize() {}

// Called repeatedly when this Command is scheduled to run
void CmdMWOBBRNSToggle::Execute() {
  m_subMWOBBRNS->ExtensionToggle();
}

// Called once the command ends or is interrupted.
void CmdMWOBBRNSToggle::End(bool interrupted) {}

// Returns true when the command should end.
bool CmdMWOBBRNSToggle::IsFinished() {
  return true;
}
