// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#include "commands/CmdTargetCubePlacment.h"

CmdTargetCubePlacment::CmdTargetCubePlacment(SubDriveTrain* driveTrain, SubLimeLightLower* limeLightLower, SubLimeLightUpper* limeLightUpper, frc2::CommandXboxController* auxController) 
  : m_driveTrain{driveTrain}, m_limeLightLower{limeLightLower}, m_limeLightUpper{limeLightUpper}, m_auxController{auxController} {
  // Use addRequirements() here to declare subsystem dependencies.
  AddRequirements(limeLightUpper);
  AddRequirements(limeLightLower);
}

// Called when the command is initially scheduled.
void CmdTargetCubePlacment::Initialize() {
  // Get the aux controller D-pad position
  m_povPosition = m_auxController->GetPOV();
  // Get the ID of the targeted april tag
  m_aprilTagID = m_limeLightUpper->GetAprilTagId();
  // Set m_finished to false
  m_finished = false;
}

// Called repeatedly when this Command is scheduled to run
void CmdTargetCubePlacment::Execute() {
  if (m_povPosition == DPAD_VALUE_MIDDLE_CENTER) {
    
  }
  else if (m_povPosition == DPAD_VALUE_MIDDLE_UP) {
    
  }
  else if (m_povPosition == DPAD_VALUE_MIDDLE_DOWN) {
    
  }
  else if (m_povPosition == DPAD_VALUE_RIGHT_CENTER) {
    
  }
  else if (m_povPosition == DPAD_VALUE_RIGHT_UP) {
    
  }
  else if (m_povPosition == DPAD_VALUE_RIGHT_DOWN) {
    
  }
  else if (m_povPosition == DPAD_VALUE_LEFT_CENTER) {
    
  }
  else if (m_povPosition == DPAD_VALUE_LEFT_UP) {
    
  }
  else if (m_povPosition == DPAD_VALUE_LEFT_DOWN) {
    
  }
  else {
    m_finished = true;
  }

}
// Called once the command ends or is interrupted.
void CmdTargetCubePlacment::End(bool interrupted) {}

// Returns true when the command should end.
bool CmdTargetCubePlacment::IsFinished() {
  return m_finished;
}
