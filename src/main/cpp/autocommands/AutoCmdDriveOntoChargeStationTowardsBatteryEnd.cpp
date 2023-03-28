// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#include "autocommands/AutoCmdDriveOntoChargeStationTowardsBatteryEnd.h"
#include "Constants/ConsDrivetrain.h"

#include <iostream>
#include <stdio.h>

AutoCmdDriveOntoChargeStationTowardsBatteryEnd::AutoCmdDriveOntoChargeStationTowardsBatteryEnd(SubDriveTrain* driveTrain) 
  : m_driveTrain{driveTrain} {
  // Use addRequirements() here to declare subsystem dependencies.
  AddRequirements(driveTrain);
}

// Called when the command is initially scheduled.
void AutoCmdDriveOntoChargeStationTowardsBatteryEnd::Initialize() {
  // set the onChargeStation bool to false when we first start
  m_onChargeStation = false;
  m_finished = false;
  m_timer.Reset();
  m_wellOntoRampPitchValue = -999;
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
void AutoCmdDriveOntoChargeStationTowardsBatteryEnd::Execute() {
  // Define variables
  double currentPitch = m_driveTrain->GetPitch();
  double speed = 0.0;
  // Do we think we are already on the ChargeStation?
  // Go forward until we start tilting
  if(!m_onChargeStation && (currentPitch < m_levelPitchValue+1) && (currentPitch > m_levelPitchValue-5)) {
    speed = -0.7;
  }
  // Drive forward until we are level again
  else {
    if(m_onChargeStation == false) {
      m_timer.Start();
      m_onChargeStation = true;
    }
    // wait until we "see" the ramp start dropping
    // but only consider a drop in pitch as the ramp dropping after some time has elapsed 
    // (so that the initial "bump" and "recoil" of hitting the ramp isn't caught)
    if (currentPitch > (m_wellOntoRampPitchValue + 3)) {
      if(!m_timer.HasElapsed((units::time::second_t)1.6)) {
        speed = -0.48;
      }
      else {
        if(currentPitch > m_wellOntoRampPitchValue) {
          m_wellOntoRampPitchValue = currentPitch;
        }
        speed = -0.28;
      }
    }
    // if we are level again, set onChargeStation to true
    else {
      m_finished = true;
      speed = 0.0;
    }
  }
  // Pass speed to the drive train to make it go
  m_driveTrain->DriveStraight(speed);
}

// Called once the command ends or is interrupted.
void AutoCmdDriveOntoChargeStationTowardsBatteryEnd::End(bool interrupted) {}

// Returns true when the command should end.
bool AutoCmdDriveOntoChargeStationTowardsBatteryEnd::IsFinished() {
  return m_finished;
}
