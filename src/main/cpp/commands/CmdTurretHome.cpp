// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#include "commands/CmdTurretHome.h"

CmdTurretHome::CmdTurretHome(SubTurret* subTurret, frc2::CommandXboxController* auxController) 
  : m_subTurret{subTurret}, m_auxController{auxController} {
  // Use addRequirements() here to declare subsystem dependencies.
  AddRequirements(subTurret);
}

// Called when the command is initially scheduled.
void CmdTurretHome::Initialize() {}

// Called repeatedly when this Command is scheduled to run
void CmdTurretHome::Execute() {
  m_subTurret->SetHoldPosition(0);
}



// Called once the command ends or is interrupted.
void CmdTurretHome::End(bool interrupted) {}

// Returns true when the command should end.
bool CmdTurretHome::IsFinished() {
  return false;
}
