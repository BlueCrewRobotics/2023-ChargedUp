// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#include "commands/CmdTurretRotate.h"

CmdTurretRotate::CmdTurretRotate(SubTurret* subTurret, frc2::CommandXboxController* auxController) 
  : m_subTurret{subTurret}, m_auxController{auxController} {
  // Use addRequirements() here to declare subsystem dependencies.
  AddRequirements(subTurret);
}

// Called when the command is initially scheduled.
void CmdTurretRotate::Initialize() {}

// Called repeatedly when this Command is scheduled to run
void CmdTurretRotate::Execute() {
  double rotationSpeed = 0.0;
  if(m_auxController->GetRawAxis(AXIS_LX) > 0.06 || m_auxController->GetRawAxis(AXIS_LX) < -0.06) {
    // This is controlling the speed of the turret
    rotationSpeed = m_auxController->GetRawAxis(AXIS_LX)*-0.84;
    if(rotationSpeed < 0) {
      rotationSpeed = rotationSpeed*-rotationSpeed;
    }
    else {
      rotationSpeed = rotationSpeed*rotationSpeed;
    }
    m_subTurret->EnableHoldPosition(false);
    m_subTurret->RotateManual(rotationSpeed);
  }
  else {
    m_subTurret->EnableHoldPosition(true);
    //m_subTurret->RotateManual(0.0);
  }
}



// Called once the command ends or is interrupted.
void CmdTurretRotate::End(bool interrupted) {}

// Returns true when the command should end.
bool CmdTurretRotate::IsFinished() {
  return false;
}
