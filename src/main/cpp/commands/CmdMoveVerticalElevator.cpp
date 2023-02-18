// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#include "commands/CmdMoveVerticalElevator.h"

CmdMoveVerticalElevator::CmdMoveVerticalElevator(SubVerticalElevator* SubVerticalElevator, frc2::CommandXboxController* auxController) 
: m_SubVerticalElevator{SubVerticalElevator}, m_auxController{auxController} {
  // Use addRequirements() here to declare subsystem dependencies.
}

// Called when the command is initially scheduled.
void CmdMoveVerticalElevator::Initialize() {}

// Called repeatedly when this Command is scheduled to run
void CmdMoveVerticalElevator::Execute() {
    double rotationSpeed = 0.0;
  if(m_auxController->GetRawAxis(AXIS_LY) > 0.2 || m_auxController->GetRawAxis(AXIS_LY) < -0.2) {
    rotationSpeed = m_auxController->GetRawAxis(AXIS_LY) * 0.7;
    m_SubVerticalElevator->ControlMotorManually(rotationSpeed); 
  }
  else if(m_auxController->GetAButton() == true) {
    m_SubVerticalElevator->ResetPosition();
  }
}

// Called once the command ends or is interrupted.
void CmdMoveVerticalElevator::End(bool interrupted) {}

// Returns true when the command should end.
bool CmdMoveVerticalElevator::IsFinished() {
  return true;
}
