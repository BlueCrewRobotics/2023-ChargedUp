// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#include "autocommands/AutoCmdDrive.h"

//AutoCmdDrive::AutoCmdDrive(BC_MotionProfile* motionProfile, SubDriveTrain* subDriveTrain)  : m_motionProfile{motionProfile} ,m_subDriveTrain{subDriveTrain} {
AutoCmdDrive::AutoCmdDrive( SubDriveTrain* subDriveTrain)  : m_subDriveTrain{subDriveTrain} {

  // Use addRequirements() here to declare subsystem dependencies.
  AddRequirements(subDriveTrain);
  
  // Use addRequirements() here to declare subsystem dependencies.
}

// Called when the command is initially scheduled.
void AutoCmdDrive::Initialize() {
  m_timer.Reset();
  m_timer.Start();
  //m_leftFinished = m_leftRotations*2048 + m_subDriveTrain->GetLeftEncoderValue();
  //m_rightFinished = m_rightRotations*2048 + m_subDriveTrain->GetRightEncoderValue();

}

// Called repeatedly when this Command is scheduled to run
void AutoCmdDrive::Execute() {
  m_subDriveTrain->AutonomousDrivingByRotations(1, 1);
}

// Called once the command ends or is interrupted.
void AutoCmdDrive::End(bool interrupted) {}

// Returns true when the command should end.
bool AutoCmdDrive::IsFinished() {
  // Return true if motion profile is finished
  if(m_timer.HasElapsed((units::time::second_t)3)==true) {
    return true;
  }
  else {
    return false;
  }
}
