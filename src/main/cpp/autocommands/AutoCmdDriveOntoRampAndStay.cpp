// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#include "autocommands/AutoCmdDriveOntoRampAndStay.h"

#include <iostream>
#include <stdio.h>

AutoCmdDriveOntoRampAndStay::AutoCmdDriveOntoRampAndStay(SubDriveTrain* driveTrain) 
  : m_driveTrain{driveTrain} {
  // Use addRequirements() here to declare subsystem dependencies.
  AddRequirements(driveTrain);
}

// Called when the command is initially scheduled.
void AutoCmdDriveOntoRampAndStay::Initialize() {
  // set the onRamp bool to false when we first start
  m_onRamp = false;
  m_leveling = false;
  m_timer.Reset();
  // if the robot is level-ish, set the levelPitchValue variable to the current pitch, if not then set it to something we know is about level
  if (m_driveTrain->GetPitch() <= 0.5 && m_driveTrain->GetPitch() >= -2) {
    m_levelPitchValue = m_driveTrain->GetPitch();
  }
  else {
    m_levelPitchValue = -1.15;
  }
}

// Called repeatedly when this Command is scheduled to run
void AutoCmdDriveOntoRampAndStay::Execute() {
  // Define variables
  double currentPitch = m_driveTrain->GetPitch();
  double pitchTolerance = 0.65;
  double speed = 0.0;

  // Do we think we are already on the ramp?
  if(m_leveling == false) {
    // Go forward until we start tilting
    if(!m_onRamp && currentPitch > m_levelPitchValue-5 && currentPitch < -m_levelPitchValue+5) {
      speed = -0.86;
    }

    // Drive forward until we are level again
    else {
      if(m_onRamp == false) {
        m_timer.Start();
        m_onRamp = true;
      }

      if (currentPitch < m_levelPitchValue-1) {
        if(!m_timer.HasElapsed((units::time::second_t)2.0)) {
          speed = -0.59;
        }
        else {
          speed = -0.30;
        }
      }
      // if we are level again, set onRamp to true
      else {
        m_leveling = true;
        speed = 0.0;
      }
    }
  }
  // once we are on the ramp, stay level
  else {
    std::cout << "on ramp, current pitch: " << currentPitch << " levelPitch: " << m_levelPitchValue << std::endl;
    speed = 0.0;
    
    m_driveTrain->SetRamp(1);
    if(currentPitch < m_levelPitchValue-pitchTolerance) {
      std::cout << "steadying forward current pitch: " << currentPitch << std::endl;
      speed = -0.28;
    }
    if(currentPitch > m_levelPitchValue+pitchTolerance) {
      std::cout << "steadying backward, current pitch: " << currentPitch << std::endl;
      speed = 0.28;
    }
  }
  // Pass speed to the drive train to make it go
  m_driveTrain->Drive(speed, 0.0);
}

// Called once the command ends or is interrupted.
void AutoCmdDriveOntoRampAndStay::End(bool interrupted) {}

// Returns true when the command should end.
bool AutoCmdDriveOntoRampAndStay::IsFinished() {
  return false;
}
