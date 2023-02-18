// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#include "commands/CmdMoveHorizontalElevator.h"

CmdMoveHorizontalElevator::CmdMoveHorizontalElevator(SubHorizontalElevator* SubHorizontalElevator, frc2::CommandXboxController auxController) {
  // Use addRequirements() here to declare subsystem dependencies.
}

// Called when the command is initially scheduled.
void CmdMoveHorizontalElevator::Initialize() {}

// Called repeatedly when this Command is scheduled to run
void CmdMoveHorizontalElevator::Execute() {}

// Called once the command ends or is interrupted.
void CmdMoveHorizontalElevator::End(bool interrupted) {}

// Returns true when the command should end.
bool CmdMoveHorizontalElevator::IsFinished() {
  return false;
}
