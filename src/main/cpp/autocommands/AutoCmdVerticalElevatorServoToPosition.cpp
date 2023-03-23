// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#include "autocommands/AutoCmdVerticalElevatorServoToPosition.h"

AutoCmdVerticalElevatorServoToPosition::AutoCmdVerticalElevatorServoToPosition(SubVerticalElevator* subVerticalElevator, double positionToGoTo, double positionToFinishAt) 
  :m_subVerticalElevator{subVerticalElevator}, m_positionToGoTo{positionToGoTo}, m_positionToFinishAt{positionToFinishAt} {
  // Use addRequirements() here to declare subsystem dependencies.
  AddRequirements(subVerticalElevator);
}

// Called when the command is initially scheduled.
void AutoCmdVerticalElevatorServoToPosition::Initialize() {
  m_finished = false;
  m_isPositionSet = false;
  startingPosition = m_subVerticalElevator->GetPosition();
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
void AutoCmdVerticalElevatorServoToPosition::Execute() {
  double currentPosition = m_subVerticalElevator->GetPosition();
  if(!m_isPositionSet) {
    m_subVerticalElevator->ServoToPosition(m_positionToGoTo);
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
void AutoCmdVerticalElevatorServoToPosition::End(bool interrupted) {}

// Returns true when the command should end.
bool AutoCmdVerticalElevatorServoToPosition::IsFinished() {
  return m_finished;
}
