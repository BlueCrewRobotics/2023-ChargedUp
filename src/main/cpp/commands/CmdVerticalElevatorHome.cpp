// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#include "commands/CmdVerticalElevatorHome.h"

CmdVerticalElevatorHome::CmdVerticalElevatorHome(SubVerticalElevator* subVerticalElevator, frc2::CommandXboxController* auxController) 
: m_subVerticalElevator{subVerticalElevator}, m_auxController{auxController}{
  // Use addRequirements() here to declare subsystem dependencies.
  AddRequirements(subVerticalElevator);
}

// Called when the command is initially scheduled.
void CmdVerticalElevatorHome::Initialize() {}

// Called repeatedly when this Command is scheduled to run
void CmdVerticalElevatorHome::Execute() {
  m_subVerticalElevator->SetHoldPosition(0);
}

// Called once the command ends or is interrupted.
void CmdVerticalElevatorHome::End(bool interrupted) {}

// Returns true when the command should end.
bool CmdVerticalElevatorHome::IsFinished() {
  return false;
}
