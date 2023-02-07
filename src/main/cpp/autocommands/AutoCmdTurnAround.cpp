// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#include "autocommands/AutoCmdTurnAround.h"

AutoCmdTurnAround::AutoCmdTurnAround(SubDriveTrain* driveTrain) 
  : m_driveTrain{driveTrain} {
  // Use addRequirements() here to declare subsystem dependencies.
  AddRequirements(driveTrain);
}

// Called when the command is initially scheduled.
void AutoCmdTurnAround::Initialize() {
  m_finished = false;
  m_initialYaw = m_driveTrain->GetYawStraightValue();
  if(m_initialYaw < 0) {
    m_turnedAroundYaw = 180 + m_initialYaw;
  }
  else if(m_initialYaw > 0) {
    m_turnedAroundYaw = -180 + m_initialYaw;
  }
  else {
    m_turnedAroundYaw = 180;
  }
}

// Called repeatedly when this Command is scheduled to run
void AutoCmdTurnAround::Execute() {
  double rotation = 0.0;
  double currentYaw = m_driveTrain->GetYaw();
  double yawError = m_turnedAroundYaw - currentYaw;
  if (yawError < 0) {
    if(yawError < -30) {
      rotation = -0.35;
    }
    else if(yawError < -10) {
      rotation = -0.2;
    }
    else if(yawError < -0.5) {
      rotation = -0.1;
    }
  }
  else {
    if(yawError > 30) {
      rotation = 0.35;
    }
    else if(yawError > 10) {
      rotation = 0.2;
    }
    else if(yawError > 0.5) {
      rotation = 0.1;
    }
  }
  if (yawError > -0.5 && yawError < 0.5) {
    m_finished = true;
  }
  else {
    m_finished = false;
  }
  m_driveTrain->RotateDriveTrain(rotation);
}

// Called once the command ends or is interrupted.
void AutoCmdTurnAround::End(bool interrupted) {}

// Returns true when the command should end.
bool AutoCmdTurnAround::IsFinished() {
  return m_finished;
}
