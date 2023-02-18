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
  if(m_auxController->GetRawAxis(AXIS_LX) > 0.2 || m_auxController->GetRawAxis(AXIS_LX) < -0.2) {
    // This is controlling the speed of the drive train
    rotationSpeed = m_auxController->GetRawAxis(AXIS_LX) * 0.7;
    m_subTurret->RotateTurretManual(rotationSpeed);
  }
  else if (m_auxController->GetAButton() == true) { // PLACEHOLDER BUTTON not sure what button we want to reset to home position yet
    m_subTurret->RotateTurretToDegree(TURRET_HOME_POSITION);
  }

}

// Called once the command ends or is interrupted.
void CmdRotateTurret::End(bool interrupted) {}

// Returns true when the command should end.
bool CmdRotateTurret::IsFinished() {
  return false;
}
