// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#include "commands/CmdHorizontalElevatorHome.h"

CmdHorizontalElevatorHome::CmdHorizontalElevatorHome(SubHorizontalElevator* subHorizontalElevator) {
  // Use addRequirements() here to declare subsystem dependencies.
}

// Called when the command is initially scheduled.
void CmdHorizontalElevatorHome::Initialize() {}

// Called repeatedly when this Command is scheduled to run
void CmdHorizontalElevatorHome::Execute() {
  m_subHorizontalElevator->SetHoldPosition(0);
}

// Called once the command ends or is interrupted.
void CmdHorizontalElevatorHome::End(bool interrupted) {}

// Returns true when the command should end.
bool CmdHorizontalElevatorHome::IsFinished() {
  return false;
}
