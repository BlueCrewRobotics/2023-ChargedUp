// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#include "autocommands/AutoCmdTurretServoToDegree.h"

AutoCmdTurretServoToDegree::AutoCmdTurretServoToDegree(SubTurret* subTurret, double angleToGoTo, double angleToFinishAt)
  :m_subTurret{subTurret}, m_angleToGoTo{angleToGoTo}, m_angleToFinishAt{angleToFinishAt} {
  // Use addRequirements() here to declare subsystem dependencies.
  AddRequirements(subTurret);
}

// Called when the command is initially scheduled.
void AutoCmdTurretServoToDegree::Initialize() {
  m_finished = false;
  m_isPositionSet = false;
  startingAngle = m_subTurret->GetDegrees();
  if(startingAngle >= m_angleToGoTo && !(m_angleToFinishAt >= m_angleToGoTo)) {
    m_angleToFinishAt = m_angleToGoTo + 2;
  }
  else if(startingAngle <= m_angleToGoTo && !(m_angleToFinishAt <= m_angleToGoTo)) {
    m_angleToFinishAt = m_angleToGoTo - 2;
  }
  if(startingAngle > m_angleToGoTo) {
    goingClockwise = false;
  }
  else {
    goingClockwise = true;
  }
}

// Called repeatedly when this Command is scheduled to run
void AutoCmdTurretServoToDegree::Execute() {
  double currentAngle = m_subTurret->GetDegrees();
  if(!m_isPositionSet) {
    m_subTurret->RotateToDegree(m_angleToGoTo);
    m_isPositionSet = true;
  }
  if(!goingClockwise && currentAngle <= m_angleToFinishAt) {
    m_finished = true;
  }
  else if (goingClockwise && currentAngle >= m_angleToFinishAt) {
    m_finished = true;
  }
}

// Called once the command ends or is interrupted.
void AutoCmdTurretServoToDegree::End(bool interrupted) {}

// Returns true when the command should end.
bool AutoCmdTurretServoToDegree::IsFinished() {
  return m_finished;
}
