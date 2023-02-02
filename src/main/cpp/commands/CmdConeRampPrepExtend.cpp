// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#include "commands/CmdConeRampPrepExtend.h"

CmdConeRampPrepExtend::CmdConeRampPrepExtend(SubConeRampPrep* subConeRampPrep) : m_subConeRampPrep(subConeRampPrep) {
  // Use addRequirements() here to declare subsystem dependencies.

}

// Called when the command is initially scheduled.
void CmdConeRampPrepExtend::Initialize() {}

// Called repeatedly when this Command is scheduled to run
void CmdConeRampPrepExtend::Execute() {
  m_subConeRampPrep->SetPrepConeRampPosition(true);
  
}

// Called once the command ends or is interrupted.
void CmdConeRampPrepExtend::End(bool interrupted) {}

// Returns true when the command should end.
bool CmdConeRampPrepExtend::IsFinished() {
  return false;
}
