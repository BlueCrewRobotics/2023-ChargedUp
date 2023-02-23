// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#include "commands/CmdVerticalElevatorServoToPosition.h"

CmdVerticalElevatorServoToPosition::CmdVerticalElevatorServoToPosition(SubVerticalElevator* subVerticalElevator, frc2::CommandXboxController* auxController, double position) 
: m_subVerticalElevator{subVerticalElevator}, m_auxController{auxController}, m_position{position} {
  // Use addRequirements() here to declare subsystem dependencies.
  AddRequirements(subVerticalElevator);
}

// Called when the command is initially scheduled.
void CmdVerticalElevatorServoToPosition::Initialize() {}

// Called repeatedly when this Command is scheduled to run
void CmdVerticalElevatorServoToPosition::Execute() {

    m_subVerticalElevator->ServoToPosition(m_position);
}

// Called once the command ends or is interrupted.
void CmdVerticalElevatorServoToPosition::End(bool interrupted) {}

// Returns true when the command should end.
bool CmdVerticalElevatorServoToPosition::IsFinished() {
  return false;
}
