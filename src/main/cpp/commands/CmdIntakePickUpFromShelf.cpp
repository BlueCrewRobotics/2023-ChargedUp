// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#include "commands/CmdIntakePickUpFromShelf.h"

CmdIntakePickUpFromShelf::CmdIntakePickUpFromShelf(SubRobotGlobals* subRobotGlobals, SubClawWrist* subClawWrist, frc2::CommandXboxController* auxController)
  :m_subRobotGlobals{subRobotGlobals}, m_subIntake{subClawWrist}, m_auxController{auxController} {
  // Use addRequirements() here to declare subsystem dependencies.
}

// Called when the command is initially scheduled.
void CmdIntakePickUpFromShelf::Initialize() {
  m_finished = false;
}

// Called repeatedly when this Command is scheduled to run
void CmdIntakePickUpFromShelf::Execute() {
  if(m_auxController->GetBackButton() == true) {
    m_finished = false;
  }
  if(m_subRobotGlobals->g_gameState.selectedPieceType == ConePiece) {
    m_subIntake->SpinIntake(-0.455);
    if(m_subIntake->GetIntakeOutput() > 45){
      m_finished = true;
    }
  }
  else if(m_subRobotGlobals->g_gameState.selectedPieceType == CubePiece) {
    m_subIntake->SpinIntake(-0.2);
    if(m_subIntake->GetIntakeOutput() > 9.5) {
      m_finished = true;
    }
  }
}

// Called once the command ends or is interrupted.
void CmdIntakePickUpFromShelf::End(bool interrupted) {
  m_subIntake->SpinIntake(0.0);
}

// Returns true when the command should end.
bool CmdIntakePickUpFromShelf::IsFinished() {
  return m_finished;
}
