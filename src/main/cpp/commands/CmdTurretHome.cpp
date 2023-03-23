// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#include "commands/CmdTurretHome.h"

CmdTurretHome::CmdTurretHome(SubTurret* subTurret) 
  : m_subTurret{subTurret} {
  // Use addRequirements() here to declare subsystem dependencies.
  AddRequirements(subTurret);
}

// Called when the command is initially scheduled.
void CmdTurretHome::Initialize() {
  m_finished = false;
}

// Called repeatedly when this Command is scheduled to run
void CmdTurretHome::Execute() {
  m_subTurret->SetHoldPosition(TURRET_HOME_POSITION);
  if(m_subTurret->GetDegrees() < 9 && m_subTurret->GetDegrees() > -9) {
    m_finished = true;
  }
}



// Called once the command ends or is interrupted.
void CmdTurretHome::End(bool interrupted) {}

// Returns true when the command should end.
bool CmdTurretHome::IsFinished() {
  return m_finished;
}
