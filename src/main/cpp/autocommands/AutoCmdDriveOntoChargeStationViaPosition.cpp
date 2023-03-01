// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#include "autocommands/AutoCmdDriveOntoChargeStationViaPosition.h"
#include "Constants/ConsDrivetrain.h"

#include <iostream>
#include <stdio.h>

AutoCmdDriveOntoChargeStationViaPosition::AutoCmdDriveOntoChargeStationViaPosition(SubDriveTrain* driveTrain) 
  : m_driveTrain{driveTrain} {
  // Use addRequirements() here to declare subsystem dependencies.
  AddRequirements(driveTrain);
}

// Called when the command is initially scheduled.
void AutoCmdDriveOntoChargeStationViaPosition::Initialize() {
  // set the onChargeStation bool to false when we first start
  m_onChargeStation = false;
  m_finished = false;
  m_startedDropping = false;
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
void AutoCmdDriveOntoChargeStationViaPosition::Execute() {
  // Define variables
  double currentPitch = m_driveTrain->GetPitch();
  double speed = 0.0;
  // Do we think we are already on the ChargeStation?
  // If not, go forward until we start tilting
  if(!m_onChargeStation && currentPitch > m_levelPitchValue-1 && currentPitch < m_levelPitchValue+5) {
    speed = 0.5;
    m_driveTrain->DriveStraight(speed);
  }
  // Drive forward until we are level again
  else {
    // if we're not yet fully on the charge station, start moving forward the distance to the upper end of the ramp
    if(m_onChargeStation == false) {
      m_timer.Start();
      m_onChargeStation = true;

      double leftRotationsNeeded = DRIVE_TRAIN_ROTATIONS_PER_INCH_LEFT_SIDE * (48 + 6);
      double rightRotationsNeeded = DRIVE_TRAIN_ROTATIONS_PER_INCH_RIGHT_SIDE * (48 + 6);

      m_driveTrain->AutonomousDrivingByRotations(leftRotationsNeeded, rightRotationsNeeded);
    }
    else {
      // keep the motor saftey aware that we're still alive and running, just waiting for the movement
      m_driveTrain->ResetSafetyTimer();
    }

    // wait until we "see" the ramp start dropping
    // but only consider a drop in pitch as the ramp dropping after some time has elapsed 
    // (so that the initial "bump" and "recoil" of hitting the ramp isn't caught)
    if (!m_startedDropping && currentPitch > m_wellOntoRampPitchValue - 3 && m_timer.HasElapsed((units::time::second_t)1.5)) {
      if(currentPitch > m_wellOntoRampPitchValue) {
        m_wellOntoRampPitchValue = currentPitch;
      }
    }
    // check for end conditions: the ramp and dropped and we've stopped, or lots of time has passed (fail-safe)
    else if(m_timer.HasElapsed((units::time::second_t)8.0)) {
        // too much time has gone by, something's gone wrong, so we need to stop!
        std::cout << "!Fail-Safe stop of AutoCmdDriveOntoChargeStationViaPosition!" << std::endl;
        m_finished = true;
    }
    else if(m_startedDropping) {
      // have the motors (backing up) stopped, or near stopped?
      if(m_driveTrain->GetLeftSideSpeed() < 100) {
        m_finished = true;
      }
    }
    else {
      m_startedDropping = true;
      // ramp started dropping, let's start backing up a few inches, since it will be needed
      double leftRotationsNeeded = DRIVE_TRAIN_ROTATIONS_PER_INCH_LEFT_SIDE * (-6);
      double rightRotationsNeeded = DRIVE_TRAIN_ROTATIONS_PER_INCH_RIGHT_SIDE * (-6);
      m_driveTrain->AutonomousDrivingByRotations(leftRotationsNeeded, rightRotationsNeeded);
    }
  }
}

// Called once the command ends or is interrupted.
void AutoCmdDriveOntoChargeStationViaPosition::End(bool interrupted) {
  // make sure we've stopped
  m_driveTrain->Drive(0, 0);  
}

// Returns true when the command should end.
bool AutoCmdDriveOntoChargeStationViaPosition::IsFinished() {
  return m_finished;
}
