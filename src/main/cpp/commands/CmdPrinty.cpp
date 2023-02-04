/*-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=*/
/*                       Blue Crew Robotics #6153                             */
/*                            Charged Up 2023                                 */
/*-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=*/
// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#include <iostream>
#include <stdio.h>
#include "commands/CmdPrinty.h"

CmdPrinty::CmdPrinty(SubDriveTrain* driveTrain, frc::Joystick *driverController) 
  : m_driveTrain{driveTrain}, m_driverController{driverController} {
  // Use addRequirements() here to declare subsystem dependencies.
  AddRequirements(driveTrain);
}

// Called when the command is initially scheduled.
void CmdPrinty::Initialize() {
  m_isFinished = false;
}

// Called repeatedly when this Command is scheduled to run
void CmdPrinty::Execute() {

  // If BUTTONT_SELLECT (back button on xbox controller) is pressed, exit the command
  if(m_driverController->GetRawButton(BUTTON_SELECT)==1) {
    m_isFinished = true;
  }

  std::cout << "current pitch: " << m_driveTrain->GetPitch() << std::endl;
}

// Called once the command ends or is interrupted.
void CmdPrinty::End(bool interrupted) {}

// Returns true when the command should end.
bool CmdPrinty::IsFinished() {
  if(m_isFinished) {
    m_isFinished = false;
    return true;
  }
  return false;
}
