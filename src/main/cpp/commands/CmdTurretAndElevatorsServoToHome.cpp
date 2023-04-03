// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#include "commands/CmdTurretAndElevatorsServoToHome.h"

CmdTurretAndElevatorsServoToHome::CmdTurretAndElevatorsServoToHome(SubClawWrist* subClawWrist, SubHorizontalElevator* subHorizontalElevator, SubTurret* subTurret, SubVerticalElevator* subVerticalElevator, frc2::CommandXboxController* auxController)
  :m_subClawWrist{subClawWrist}, m_subHorizontalElevator{subHorizontalElevator}, m_subTurret{subTurret}, m_subVerticalElevator{subVerticalElevator}, m_auxController{auxController} {
  // Use addRequirements() here to declare subsystem dependencies.
  AddRequirements(subClawWrist);
  AddRequirements(subHorizontalElevator);
  AddRequirements(subTurret);
  AddRequirements(subVerticalElevator);
}

// Called when the command is initially scheduled.
void CmdTurretAndElevatorsServoToHome::Initialize() {
  m_wristIsHome = false;
  m_horizontalElevatorIsHome = false;
  m_turretIsHome = false;
  m_verticalElevatorIsHome = false;
  m_finished = false;
}

// Called repeatedly when this Command is scheduled to run
void CmdTurretAndElevatorsServoToHome::Execute() {
  if(m_auxController->GetBackButton() == false) {
    m_finished = true;
  }
  else if(!m_wristIsHome) {
    m_subClawWrist->ServoToPosition(0.0);
    m_wristIsHome = true;
  }
  else if(!m_horizontalElevatorIsHome) {
    m_subHorizontalElevator->SetHoldPosition(0.0);
    if(m_subHorizontalElevator->GetPosition() < 8) {
      m_horizontalElevatorIsHome = true;
    }
  }
  else if(!m_turretIsHome) {
    m_subTurret->RotateToDegree(TURRET_HOME_POSITION);
    if(m_subTurret->GetDegrees() < 9 && m_subTurret->GetDegrees() > -9) {
      m_turretIsHome = true;
    }
  }
  else if(!m_verticalElevatorIsHome) {
    m_subVerticalElevator->ServoToPosition(35000);
    if(m_subVerticalElevator->GetPosition() < 50000) {
      m_verticalElevatorIsHome = true;
      m_finished = true;
    }
  }
}

// Called once the command ends or is interrupted.
void CmdTurretAndElevatorsServoToHome::End(bool interrupted) {
  if(!m_horizontalElevatorIsHome) {
    m_subHorizontalElevator->SetHoldPosition(m_subHorizontalElevator->GetPosition());
  }
  if(!m_turretIsHome) {
    if(m_subTurret->GetDegrees() > 10) {
      m_subTurret->RotateToDegree(m_subTurret->GetDegrees() - 10);
    }
    else if(m_subTurret->GetDegrees() < -10) {
      m_subTurret->RotateToDegree(m_subTurret->GetDegrees() + 10);
    }
  }
  if(!m_verticalElevatorIsHome) {
    m_subVerticalElevator->ServoToPosition(m_subVerticalElevator->GetPosition());
  }
}

// Returns true when the command should end.
bool CmdTurretAndElevatorsServoToHome::IsFinished() {
  return m_finished;
}
