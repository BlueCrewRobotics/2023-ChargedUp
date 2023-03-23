// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#include "autocommands/AutoCmdPlaceCube.h"

AutoCmdPlaceCube::AutoCmdPlaceCube(SubVerticalElevator* subVerticalElevator, SubTurret* subTurret, SubHorizontalElevator* subHorizontalElevator, SubClawWrist* subClawWrist, frc::Timer* timer) 
  :m_subVerticalElevator{subVerticalElevator}, m_subTurret{subTurret}, m_subHorizontalElevator{subHorizontalElevator}, m_subClawWrist{subClawWrist}, m_timer{timer} {
  // Use addRequirements() here to declare subsystem dependencies.
  AddRequirements(subTurret);
  AddRequirements(subVerticalElevator);
  AddRequirements(subHorizontalElevator);
  AddRequirements(subClawWrist);
}

// Called when the command is initially scheduled.
void AutoCmdPlaceCube::Initialize() {
  m_verticalElevatorIsUp = false;
  m_turretIsTurned = false;
  m_horizontalElevatorIsOut = false;
  m_WristIsDown = false;
  m_cubeIsPlaced = false;
  m_finished = false;
  m_timer->Stop();
  m_timer->Reset();
}

// Called repeatedly when this Command is scheduled to run
void AutoCmdPlaceCube::Execute() {
  if(!m_verticalElevatorIsUp) {
    m_subVerticalElevator->ServoToPosition(VERTICAL_ELEV_POS_CUBE_NODE_UPPER);
    if(m_subVerticalElevator->GetPosition() > 60000) {
      m_verticalElevatorIsUp = true;
    }
  }
  else if(!m_turretIsTurned) {
    m_subTurret->RotateToDegree(183);
    if(m_subTurret->GetDegrees() > 140) {
      m_turretIsTurned = true;
    }
  }
  else if (!m_horizontalElevatorIsOut) {
    m_subHorizontalElevator->SetHoldPosition(34);
    if(m_subHorizontalElevator->GetPosition() > 26) {
      m_horizontalElevatorIsOut = true;
    }
  }
  else if(!m_WristIsDown) {
    m_subClawWrist->ServoToPosition(WRIST_CLAW_PLACE_CUBE);
    if(m_subClawWrist->GetPosition() > 7.8) {
      m_WristIsDown = true;
      m_timer->Start();
    }
  }
  else if(!m_cubeIsPlaced) {
    m_subClawWrist->SpinIntake(0.5);
    if(m_timer->HasElapsed((units::time::second_t)0.16)==true) {
      m_cubeIsPlaced = true;
      m_subClawWrist->SpinIntake(0.0);
    }
  }
}

// Called once the command ends or is interrupted.
void AutoCmdPlaceCube::End(bool interrupted) {
  m_timer->Stop();
  m_timer->Reset();
}

// Returns true when the command should end.
bool AutoCmdPlaceCube::IsFinished() {
  return m_cubeIsPlaced;
}
