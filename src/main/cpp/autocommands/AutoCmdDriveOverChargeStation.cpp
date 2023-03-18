// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#include "autocommands/AutoCmdDriveOverChargeStation.h"

AutoCmdDriveOverChargeStation::AutoCmdDriveOverChargeStation(SubDriveTrain* subDriveTrain) 
  : m_driveTrain{subDriveTrain}{
  // Use addRequirements() here to declare subsystem dependencies.
  AddRequirements(subDriveTrain);
}

// Called when the command is initially scheduled.
void AutoCmdDriveOverChargeStation::Initialize() {
  // set the onChargeStation bool to false when we first start
  m_onChargeStation = false;
  m_finished = false;
  m_timer.Reset();
  m_overChargeStation = false;
  m_pitchedDown = false;
  // if the robot is level-ish, set the levelPitchValue variable to the current pitch, if not then set it to something we know is about level
  if (m_driveTrain->GetPitch() <= 0.2 && m_driveTrain->GetPitch() >= 2) {
    m_driveTrain->SetPitchLevelValue(m_driveTrain->GetPitch());
    m_levelPitchValue = m_driveTrain->GetPitchLevelValue();
  }
  else {
    m_driveTrain->SetPitchLevelValue(NAVX_CHARGED_UP_ON_FLOOR_PITCH);
    m_levelPitchValue = m_driveTrain->GetPitchLevelValue();
  }
  // Set the straight yaw heading
  m_driveTrain->SetYawStraightValue(m_driveTrain->GetYaw());
}

// Called repeatedly when this Command is scheduled to run
void AutoCmdDriveOverChargeStation::Execute() {
  double speed = 0.0;
  double currentPitch = m_driveTrain->GetPitch();
  if(!m_onChargeStation && currentPitch < m_levelPitchValue-5) {
    m_onChargeStation = true;
  }
  else if (m_onChargeStation && !m_pitchedDown && currentPitch > m_levelPitchValue+5) {
    m_pitchedDown = true;
  }
  else if(m_onChargeStation && m_pitchedDown && currentPitch > m_levelPitchValue-0.7 && currentPitch < m_levelPitchValue+0.7) {
    m_overChargeStation = true;
  }
  if(!m_overChargeStation && !m_onChargeStation) {
    speed = -0.5;
  }
  else if (!m_overChargeStation && m_onChargeStation) {
    speed = -0.4;
  }
  else {
    m_timer.Start();
    if(!m_timer.HasElapsed((units::time::second_t)1)) {
      speed = -0.3;
    }
    else {
      speed = 0.0;
      m_finished = true;
    }
  }
  m_driveTrain->DriveStraight(speed);
  
}

// Called once the command ends or is interrupted.
void AutoCmdDriveOverChargeStation::End(bool interrupted) {}

// Returns true when the command should end.
bool AutoCmdDriveOverChargeStation::IsFinished() {
  return m_finished;
}
