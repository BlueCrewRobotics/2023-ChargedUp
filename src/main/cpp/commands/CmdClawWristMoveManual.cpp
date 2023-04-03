// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#include "commands/CmdClawWristMoveManual.h"

CmdClawWristMoveManual::CmdClawWristMoveManual(SubClawWrist* subClawWrist, frc2::CommandXboxController* auxController) 
  :m_subClawWrist{subClawWrist}, m_auxController{auxController} {
  // Use addRequirements() here to declare subsystem dependencies.
  AddRequirements(subClawWrist);
}

// Called when the command is initially scheduled.
void CmdClawWristMoveManual::Initialize() {}

// Called repeatedly when this Command is scheduled to run
void CmdClawWristMoveManual::Execute() {
  double speed = 0.0;
  if(m_auxController->GetLeftTriggerAxis() > JOYSTICK_AXIS_BUFFER) {
    speed = -0.5 * m_auxController->GetLeftTriggerAxis();
  }
  else if(m_auxController->GetRightTriggerAxis() > JOYSTICK_AXIS_BUFFER) {
    speed = 0.5 * m_auxController->GetRightTriggerAxis();
  }

  m_subClawWrist->ControlMotorManually(speed);
}

// Called once the command ends or is interrupted.
void CmdClawWristMoveManual::End(bool interrupted) {}

// Returns true when the command should end.
bool CmdClawWristMoveManual::IsFinished() {
  return false;
}
