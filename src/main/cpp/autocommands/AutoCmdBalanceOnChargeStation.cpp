// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#include "autocommands/AutoCmdBalanceOnChargeStation.h"

#include <iostream>
#include <stdio.h>

AutoCmdBalanceOnChargeStation::AutoCmdBalanceOnChargeStation(SubDriveTrain* driveTrain) 
  : m_driveTrain{driveTrain} {
  // Use addRequirements() here to declare subsystem dependencies.
  AddRequirements(driveTrain);
}

// Called when the command is initially scheduled.
void AutoCmdBalanceOnChargeStation::Initialize() {
  // Make sure the timer is reset
  m_timer.Reset();
  // Set m_levelPitchValue to the drive train's level pitch
  m_levelPitchValue = m_driveTrain->GetPitchLevelValue();
  // Make sure the finished boolean is false
  m_finished = false;
}

// Called repeatedly when this Command is scheduled to run
void AutoCmdBalanceOnChargeStation::Execute() {
  // Define variables
  double currentPitch = m_driveTrain->GetPitch();
  double pitchTolerance = 0.65;
  double speed = 0.0;


  std::cout << "on ramp, current pitch: " << currentPitch << " levelPitch: " << m_levelPitchValue << std::endl;
  speed = 0.0;
  
  m_driveTrain->SetRamp(1);
  if(currentPitch < m_levelPitchValue-pitchTolerance) {
    std::cout << "steadying forward current pitch: " << currentPitch << std::endl;
    speed = -0.28;
  }
  else if(currentPitch > m_levelPitchValue+pitchTolerance) {
    std::cout << "steadying backward, current pitch: " << currentPitch << std::endl;
    speed = 0.28;
  }
  else {
    m_timer.Start();
  }
  if (m_timer.HasElapsed((units::time::second_t) 2)) {
    m_finished = true;
  }
  // Pass speed to the drive train to make it go
  m_driveTrain->DriveStraight(speed);
}

// Called once the command ends or is interrupted.
void AutoCmdBalanceOnChargeStation::End(bool interrupted) {}

// Returns true when the command should end.
bool AutoCmdBalanceOnChargeStation::IsFinished() {
  return m_finished;
}
