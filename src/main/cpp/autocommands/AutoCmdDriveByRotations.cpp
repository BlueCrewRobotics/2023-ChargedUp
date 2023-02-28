/*-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=*/
/*                       Blue Crew Robotics #6153                             */
/*                           Charged Up 2023                                  */
/*-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=*/
// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#include "autocommands/AutoCmdDriveByRotations.h"
#include <iostream>

AutoCmdDriveByRotations::AutoCmdDriveByRotations(SubDriveTrain* subDriveTrain, double leftrotations, double rightrotations, frc::Timer* timer) 
  : m_subDriveTrain(subDriveTrain), m_leftRotations(leftrotations), m_rightRotations(rightrotations), m_timer(timer) {
  // Use addRequirements() here to declare subsystem dependencies.
  AddRequirements({subDriveTrain});
}

// Called when the command is initially scheduled.
void AutoCmdDriveByRotations::Initialize() {
  m_timer->Reset();
  m_leftFinished = m_leftRotations*2048 + m_subDriveTrain->GetLeftEncoderValue();
  m_rightFinished = m_rightRotations*2048 + m_subDriveTrain->GetRightEncoderValue();
}

// Called repeatedly when this Command is scheduled to run
void AutoCmdDriveByRotations::Execute() {
  m_timer->Start();
  
  m_subDriveTrain->AutonomousDrivingToPosition(m_leftFinished,m_rightFinished);
 // std::cout << "L= " << m_leftFinished << " Err= " << m_subDriveTrain->GetLeftErrorValue() << std::endl;
 // std::cout << "R= " << m_rightFinished << " Err= " << m_subDriveTrain->GetRightErrorValue() << std::endl;
}

// Called once the command ends or is interrupted.
void AutoCmdDriveByRotations::End(bool interrupted) {
  // make sure we're stopped
  m_subDriveTrain->Drive(0, 0);  
}

// Returns true when the command should end.
bool AutoCmdDriveByRotations::IsFinished() {
   
  // have we stopped?  with an 8 second fail-safe
  if(m_subDriveTrain->GetLeftSideSpeed() < 100 ||  m_timer->HasElapsed((units::time::second_t)8)==true) {
    return true;
  }
  else {
     return false;
  }
}
