// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#include "commands/CmdRotateTurret.h"

CmdRotateTurret::CmdRotateTurret(SubTurret* subTurret, frc2::CommandXboxController* auxController) 
  : m_subTurret{subTurret}, m_auxController{auxController} {
  // Use addRequirements() here to declare subsystem dependencies.
  AddRequirements(subTurret);
}

// Called when the command is initially scheduled.
void CmdRotateTurret::Initialize() {}

// Called repeatedly when this Command is scheduled to run
void CmdRotateTurret::Execute() {
  double rotationSpeed = 0.0;
  if(m_auxController->GetRawAxis(AXIS_R_TRIG) > 0 || m_auxController->GetRawAxis(AXIS_L_TRIG) > 0) {
    manualRotate = true;
    // This is controlling the speed of the drive train
    if(m_auxController->GetRawAxis(AXIS_R_TRIG) > 0) {
      // percentage controller axis is activated
      rotationDirection = TURRET_MANUAL_ROTATION_CLOCKWISE;
    }
    else { // jhouse: is it safe to assume the L axis is really exactly 'zero' when not pressed by human?  robot could falsely move a bit otherwise
      // percentage controller axis is activated
      rotationDirection = TURRET_MANUAL_ROTATION_COUNTERCLOCKWISE;
    }
  }

}

// Called once the command ends or is interrupted.
void CmdRotateTurret::End(bool interrupted) {}

// Returns true when the command should end.
bool CmdRotateTurret::IsFinished() {
  return false;
}
