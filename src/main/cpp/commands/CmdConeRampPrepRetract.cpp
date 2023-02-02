// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#include "commands/CmdConeRampPrepRetract.h"

CmdConeRampPrepRetract::CmdConeRampPrepRetract(SubConeRampPrep* subConeRampPrep) : m_subConeRampPrep(subConeRampPrep){
  // Use addRequirements() here to declare subsystem dependencies.
}

// Called when the command is initially scheduled.
void CmdConeRampPrepRetract::Initialize() {}

// Called repeatedly when this Command is scheduled to run
void CmdConeRampPrepRetract::Execute() {
  m_subConeRampPrep->SetPrepConeRampPosition(false);

}

// Called once the command ends or is interrupted.
void CmdConeRampPrepRetract::End(bool interrupted) {}

// Returns true when the command should end.
bool CmdConeRampPrepRetract::IsFinished() {
  return false;
}
