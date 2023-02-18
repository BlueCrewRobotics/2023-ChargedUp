// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#include "commands/CmdVerticalElevatorStop.h"

CmdVerticalElevatorStop::CmdVerticalElevatorStop(SubVerticalElevator* SubVerticalElevator, frc2::CommandXboxController* auxController) 
: m_SubVerticalElevator{SubVerticalElevator}, m_auxController{auxController} {
  // Use addRequirements() here to declare subsystem dependencies.
  AddRequirements(SubVerticalElevator);
}

// Called when the command is initially scheduled.
void CmdVerticalElevatorStop::Initialize() {}

// Called repeatedly when this Command is scheduled to run
void CmdVerticalElevatorStop::Execute() {
 m_SubVerticalElevator->ControlMotorManually(0); 
}

// Called once the command ends or is interrupted.
void CmdVerticalElevatorStop::End(bool interrupted) {}

// Returns true when the command should end.
bool CmdVerticalElevatorStop::IsFinished() {
  return true;
}
