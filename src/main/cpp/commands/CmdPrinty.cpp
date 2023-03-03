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

CmdPrinty::CmdPrinty(SubLimeLightLower* subLimeLightLower, SubLimeLightUpper* subLimeLightUpper, frc2::CommandXboxController* auxController) 
  : m_subLimeLightLower{subLimeLightLower}, m_subLimeLightUpper{subLimeLightUpper}, m_auxController{auxController} {
  // Use addRequirements() here to declare subsystem dependencies.

}

// Called when the command is initially scheduled.
void CmdPrinty::Initialize() {
  m_isFinished = false;
}

// Called repeatedly when this Command is scheduled to run
void CmdPrinty::Execute() {

  // If BUTTONT_SELLECT (back button on xbox controller) is pressed, exit the command
  if(m_auxController->GetBackButton() == true) {
    m_isFinished = true;
  }
  /*
  std::cout << "current pitch: " << m_driveTrain->GetPitch() << std::endl;
  std::cout << "current roll: " << m_driveTrain->GetRoll() << std::endl;
  std::cout << "current yaw: " << m_driveTrain->GetYaw() << std::endl;
  std::cout << "Current Turret Angle: " << m_subTurret->GetDegrees() << std::endl;
  std::cout << "Current Horizontal Elevator Position: " << m_subHorizontalElevator->GetPosition() << std::endl;
  */
  std::cout << "LL Upper Current Distance From Target: " << m_subLimeLightUpper->GetDistanceToTarget(LL_LIMELIGHT_UPPER_HEIGHT, TARGET_APRILTAG_SUBSTATION_HEIGHT, LL_LIMELIGHT_UPPER_ANGLE) << std::endl;
  std::cout << "LL Lower Current Distance From Target: " << m_subLimeLightLower->GetDistanceToTarget(LL_LIMELIGHT_LOWER_HEIGHT, TARGET_APRILTAG_SUBSTATION_HEIGHT, LL_LIMELIGHT_LOWER_ANGLE) << std::endl;
//  std::cout << "LL Switcher Current Distance From Target: " << m_subLimeLightSwitcher->GetDistanceToTargetS(TARGET_APRILTAG_SUBSTATION_HEIGHT) << std::endl;
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
