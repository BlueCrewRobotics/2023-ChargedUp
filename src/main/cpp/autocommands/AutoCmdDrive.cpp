// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#include "autocommands/AutoCmdDrive.h"

AutoCmdDrive::AutoCmdDrive(BC_MotionProfile* motionProfile, SubDriveTrain* subDriveTrain)  : m_motionProfile{motionProfile} ,m_subDriveTrain{subDriveTrain} {
  // Use addRequirements() here to declare subsystem dependencies.
  AddRequirements(subDriveTrain);
  
  // Use addRequirements() here to declare subsystem dependencies.
}

// Called when the command is initially scheduled.
void AutoCmdDrive::Initialize() {

}

// Called repeatedly when this Command is scheduled to run
void AutoCmdDrive::Execute() {
  
}

// Called once the command ends or is interrupted.
void AutoCmdDrive::End(bool interrupted) {}

// Returns true when the command should end.
bool AutoCmdDrive::IsFinished() {
  // Return true if motion profile is finished
  return false;
}
