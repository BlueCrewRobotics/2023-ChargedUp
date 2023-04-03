// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#include "commands/CmdMoveVerticalElevator.h"

CmdMoveVerticalElevator::CmdMoveVerticalElevator(SubVerticalElevator* subVerticalElevator, frc2::CommandXboxController* auxController) 
: m_subVerticalElevator{subVerticalElevator}, m_auxController{auxController} {
  // Use addRequirements() here to declare subsystem dependencies.
  AddRequirements(subVerticalElevator);
}

// Called when the command is initially scheduled.
void CmdMoveVerticalElevator::Initialize() {}

// Called repeatedly when this Command is scheduled to run
void CmdMoveVerticalElevator::Execute() {
    
    double speed = 0.0;
    if(m_auxController->GetRawAxis(AXIS_LY) > JOYSTICK_AXIS_BUFFER || m_auxController->GetRawAxis(AXIS_LY) < -JOYSTICK_AXIS_BUFFER) {
      speed = -m_auxController->GetRawAxis(AXIS_LY)*0.7; // <- Actually only 0.49 because we square it
      if(speed < 0) {
        speed = speed*-speed;
      }
      else {
        speed = speed*speed;
      }
      m_subVerticalElevator->EnableHoldPosition(false);
      m_subVerticalElevator->ControlMotorManually(speed); 
    }
    else {
      m_subVerticalElevator->EnableHoldPosition(true);
    }

}

// Called once the command ends or is interrupted.
void CmdMoveVerticalElevator::End(bool interrupted) {}

// Returns true when the command should end.
bool CmdMoveVerticalElevator::IsFinished() {
  return false;
}
