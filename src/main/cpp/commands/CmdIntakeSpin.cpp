// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#include "commands/CmdIntakeSpin.h"

CmdIntakeSpin::CmdIntakeSpin(SubClawWrist* subClawWrist, frc2::CommandXboxController* auxController, SubRobotGlobals* subRobotGlobals) 
  :m_subIntakeWrist{subClawWrist}, m_auxController{auxController}, m_subRobotGlobals{subRobotGlobals}{
  // Use addRequirements() here to declare subsystem dependencies.
  AddRequirements(subClawWrist);
}

// Called when the command is initially scheduled.
void CmdIntakeSpin::Initialize() {
  m_finished = false;
  m_pullIn = false;
  m_eject = false;
  if(m_auxController->GetPOV() == DPAD_VALUE_MIDDLE_UP) {
    m_pullIn = true;
  }
  else if(m_auxController->GetPOV() == DPAD_VALUE_MIDDLE_DOWN) {
    m_pullIn = false;
  }
  else if(m_auxController->GetPOV() == DPAD_VALUE_RIGHT_CENTER) {
    m_eject = true;
  }
  else {
    m_finished = true;
  }
}

// Called repeatedly when this Command is scheduled to run
void CmdIntakeSpin::Execute() {
  
  double speed = 0.0;
  if(!m_auxController->GetRawButton(BUTTON_L_BUMP)) {
    m_finished = true;
  }
  
/*  else if(m_subRobotGlobals->g_gameState.selectedPieceType == ConePiece && m_subIntakeWrist->GetIntakeOutput() > 3) {
    m_finished = true;
  }
  else if(m_subRobotGlobals->g_gameState.selectedPieceType == CubePiece && m_subIntakeWrist->GetIntakeOutput() > 1) {
    m_finished = true;
  }*/
  if (m_subRobotGlobals->g_gameState.selectedPieceType == ConePiece) {
    if(m_pullIn) {
      speed = -0.1;
    }
    else if (m_eject) {
      speed = 0.4;
    }
    else {
      speed = 0.1;
    }
  }
  else if (m_subRobotGlobals->g_gameState.selectedPieceType == CubePiece) {
    if(m_pullIn) {
      speed = -0.1;
    }
    else if (m_eject) {
      speed = 0.4;
    }
    else {
      speed = 0.1;
    }
  }
  
//  speed = 0.1;
  m_subIntakeWrist->SpinIntake(speed);
}

// Called once the command ends or is interrupted.
void CmdIntakeSpin::End(bool interrupted) {
  m_subIntakeWrist->SpinIntake(0.0);
}

// Returns true when the command should end.
bool CmdIntakeSpin::IsFinished() {
  return m_finished;
}
