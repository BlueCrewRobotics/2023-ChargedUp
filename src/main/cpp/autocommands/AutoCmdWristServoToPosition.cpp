// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#include "autocommands/AutoCmdWristServoToPosition.h"

AutoCmdWristServoToPosition::AutoCmdWristServoToPosition(SubClawWrist* subClawWrist, double positionToGoTo, double positionToFinishAt) 
  :m_subClawWrist{subClawWrist}, m_positionToGoTo{positionToGoTo}, m_positionToFinishAt{positionToFinishAt} {
  // Use addRequirements() here to declare subsystem dependencies.
  AddRequirements(subClawWrist);
}

// Called when the command is initially scheduled.
void AutoCmdWristServoToPosition::Initialize() {
  m_finished = false;
  m_isPositionSet = false;
  startingPosition = m_subClawWrist->GetPosition();
  if(startingPosition >= m_positionToGoTo && !(m_positionToFinishAt >= m_positionToGoTo)) {
    m_positionToFinishAt = m_positionToGoTo + 2;
  }
  else if(startingPosition <= m_positionToGoTo && !(m_positionToFinishAt <= m_positionToGoTo)) {
    m_positionToFinishAt = m_positionToGoTo - 2;
  }
  if(startingPosition < m_positionToGoTo) {
    goingUp = false;
  }
  else {
    goingUp = true;
  }
}

// Called repeatedly when this Command is scheduled to run
void AutoCmdWristServoToPosition::Execute() {
  double currentPosition = m_subClawWrist->GetPosition();
  if(!m_isPositionSet) {
    m_subClawWrist->ServoToPosition(m_positionToGoTo);
    m_isPositionSet = true;
  }
  if(!goingUp && currentPosition >= m_positionToFinishAt) {
    m_finished = true;
  }
  else if (goingUp && currentPosition <= m_positionToFinishAt) {
    m_finished = true;
  }
}

// Called once the command ends or is interrupted.
void AutoCmdWristServoToPosition::End(bool interrupted) {}

// Returns true when the command should end.
bool AutoCmdWristServoToPosition::IsFinished() {
  return m_finished;
}
