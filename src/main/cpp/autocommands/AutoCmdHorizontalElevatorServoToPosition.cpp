// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#include "autocommands/AutoCmdHorizontalElevatorServoToPosition.h"

AutoCmdHorizontalElevatorServoToPosition::AutoCmdHorizontalElevatorServoToPosition(SubHorizontalElevator* subHorizontalElevator, double positionToGoTo, double positionToFinishAt)
  :m_subHorizontalElevator{subHorizontalElevator}, m_positionToGoTo{positionToGoTo}, m_positionToFinishAt{positionToFinishAt} {
  // Use addRequirements() here to declare subsystem dependencies.
  AddRequirements(subHorizontalElevator);
}

// Called when the command is initially scheduled.
void AutoCmdHorizontalElevatorServoToPosition::Initialize() {
  m_finished = false;
  m_isPositionSet = false;
  startingPosition = m_subHorizontalElevator->GetPosition();
  if(startingPosition >= m_positionToGoTo && !(m_positionToFinishAt >= m_positionToGoTo)) {
    m_positionToFinishAt = m_positionToGoTo + 2;
  }
  else if(startingPosition <= m_positionToGoTo && !(m_positionToFinishAt <= m_positionToGoTo)) {
    m_positionToFinishAt = m_positionToGoTo - 2;
  }
  if(startingPosition > m_positionToGoTo) {
    goingOut = false;
  }
  else {
    goingOut = true;
  }
}

// Called repeatedly when this Command is scheduled to run
void AutoCmdHorizontalElevatorServoToPosition::Execute() {
  double currentPosition = m_subHorizontalElevator->GetPosition();
  if(!m_isPositionSet) {
    m_subHorizontalElevator->SetHoldPosition(m_positionToGoTo);
    m_isPositionSet = true;
  }
  if(!goingOut && currentPosition <= m_positionToFinishAt) {
    m_finished = true;
  }
  else if (goingOut && currentPosition >= m_positionToFinishAt) {
    m_finished = true;
  }
}

// Called once the command ends or is interrupted.
void AutoCmdHorizontalElevatorServoToPosition::End(bool interrupted) {}

// Returns true when the command should end.
bool AutoCmdHorizontalElevatorServoToPosition::IsFinished() {
  return m_finished;
}
