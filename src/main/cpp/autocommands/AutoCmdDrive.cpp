// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#include "autocommands/AutoCmdDrive.h"

#include <iostream>
#include <stdio.h>

//AutoCmdDrive::AutoCmdDrive(BC_MotionProfile* motionProfile, SubDriveTrain* subDriveTrain)  : m_motionProfile{motionProfile} ,m_subDriveTrain{subDriveTrain} {
AutoCmdDrive::AutoCmdDrive(SubDriveTrain* subDriveTrain, double speed, double distance /*This Needs To Have The Same Sign As Speed*/)
  : m_subDriveTrain{subDriveTrain}, m_speed{speed}, m_distance{distance} {

  // Use addRequirements() here to declare subsystem dependencies.
  AddRequirements(subDriveTrain);
  
  // Use addRequirements() here to declare subsystem dependencies.
}

// Called when the command is initially scheduled.
void AutoCmdDrive::Initialize() {
  //m_timer.Reset();
  //m_timer.Start();
  m_finished = false;
  m_leftFinished = m_distance*DRIVE_TRAIN_TICKS_PER_INCH_LEFT_SIDE + m_subDriveTrain->GetLeftEncoderValue();
  m_rightFinished = m_distance*DRIVE_TRAIN_TICKS_PER_INCH_RIGHT_SIDE + m_subDriveTrain->GetRightEncoderValue();
  m_subDriveTrain->SetYawStraightValue(m_subDriveTrain->GetYaw());
}

// Called repeatedly when this Command is scheduled to run
void AutoCmdDrive::Execute() {
  double rightPosition = m_subDriveTrain->GetRightEncoderValue();
  double leftPosition = m_subDriveTrain->GetLeftEncoderValue();
  if(m_speed < 0 && ((rightPosition < m_rightFinished) || (leftPosition < m_leftFinished))) {
    m_finished = true;
    m_subDriveTrain->Drive(0.0, 0.0);
    std::cout << " Done Going Negative" << std::endl;
  }
  else if(m_speed > 0 && ((rightPosition > m_rightFinished) || (leftPosition > m_leftFinished))) {
    m_finished = true;
    m_subDriveTrain->Drive(0.0, 0.0);
    std::cout << " Done Going Positive" << std::endl;
  } 
  else {
    std::cout << "Moving, Currently At: " << rightPosition << " To: " << m_rightFinished << std::endl;
    m_subDriveTrain->DriveStraight(m_speed);
  }
}

// Called once the command ends or is interrupted.
void AutoCmdDrive::End(bool interrupted) {}

// Returns true when the command should end.
bool AutoCmdDrive::IsFinished() {
  return m_finished;
}
