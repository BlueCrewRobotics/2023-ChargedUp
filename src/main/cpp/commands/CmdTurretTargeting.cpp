// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#include "commands/CmdTurretTargeting.h"

CmdTurretTargeting::CmdTurretTargeting(SubLimeLightUpper* subLimeLight, SubTurret* subTurret) 
 :m_subLimeLightUpper{subLimeLight}, m_subTurret{subTurret} {
  // Use addRequirements() here to declare subsystem dependencies.
  AddRequirements(subTurret);
}

// Called when the command is initially scheduled.
void CmdTurretTargeting::Initialize() {
  m_finished = false;
  
}

// Called repeatedly when this Command is scheduled to run
void CmdTurretTargeting::Execute() {
  if (m_subLimeLightUpper->GetTarget() == true) {
    double targetAngle = m_subLimeLightUpper->GetHorizontalOffset();
    if (targetAngle < -m_angleTolerance) {
      m_subTurret->RotateManual(0.2);
    }
    else if (targetAngle > m_angleTolerance) {
      m_subTurret->RotateManual(-0.2);
    }
    else {
      m_finished = true;
      m_subTurret->RotateManual(0.0);
    }
  }
  else {
    m_finished = true;
    m_subTurret->RotateManual(0.0);
  }
}

// Called once the command ends or is interrupted.
void CmdTurretTargeting::End(bool interrupted) {}

// Returns true when the command should end.
bool CmdTurretTargeting::IsFinished() {
  return m_finished;
}
