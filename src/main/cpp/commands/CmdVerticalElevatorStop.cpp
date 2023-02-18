// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#include "commands/CmdMoveVerticalElevator.h"

CmdMoveVerticalElevator::CmdMoveVerticalElevator(SubVerticalElevator* SubVerticalElevator, frc2::CommandXboxController* auxController) {
  // Use addRequirements() here to declare subsystem dependencies.
}

// Called when the command is initially scheduled.
void CmdMoveVerticalElevator::Initialize() {}

// Called repeatedly when this Command is scheduled to run
void CmdMoveVerticalElevator::Execute() {}

// Called once the command ends or is interrupted.
void CmdMoveVerticalElevator::End(bool interrupted) {}

// Returns true when the command should end.
bool CmdMoveVerticalElevator::IsFinished() {
  return false;
}
