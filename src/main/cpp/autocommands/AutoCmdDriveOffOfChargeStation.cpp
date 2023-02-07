// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#include "autocommands/AutoCmdDriveOffOfChargeStation.h"

#include <iostream>
#include <stdio.h>

AutoCmdDriveOffOfChargeStation::AutoCmdDriveOffOfChargeStation(SubDriveTrain* driveTrain) 
  : m_driveTrain{driveTrain} {
  // Use addRequirements() here to declare subsystem dependencies.
  AddRequirements(driveTrain);
}

// Called when the command is initially scheduled.
void AutoCmdDriveOffOfChargeStation::Initialize() {
  // set the onChargeStation bool to false when we first start
  m_onChargeStation = true;
  m_finished = false;
  m_timer.Reset();
  m_levelPitchValue = m_driveTrain->GetPitchLevelValue();
  
  // Set the straight yaw heading
  m_driveTrain->SetYawStraightValue(m_driveTrain->GetYaw());
}

// Called repeatedly when this Command is scheduled to run
void AutoCmdDriveOffOfChargeStation::Execute() {
  // Define variables
  double currentPitch = m_driveTrain->GetPitch();
  double pitchTolerance = 0.65;
  double speed = 0.0;
  // Do we think we are already on the ChargeStation?
  
  // Go forward until we start tilting
  if(m_onChargeStation && currentPitch > m_levelPitchValue-5 && currentPitch < -m_levelPitchValue+5) {
    speed = -0.86;
  }

  // Drive forward until we are level again
  else {
    if(m_onChargeStation == true) {
      m_timer.Start();
      m_onChargeStation = false;
    }

    if (currentPitch > m_levelPitchValue+1) {
      if(!m_timer.HasElapsed((units::time::second_t)3.0)) {
        speed = -0.59;
      }
      else {
        speed = -0.30;
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
void AutoCmdDriveOffOfChargeStation::End(bool interrupted) {}

// Returns true when the command should end.
bool AutoCmdDriveOffOfChargeStation::IsFinished() {
  return m_finished;
}
