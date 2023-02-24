/*-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=*/
/*                       Blue Crew Robotics #6153                             */
/*                            Charged Up 2023                                 */
/*-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=*/
// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#include <iostream>
#include <stdio.h>

#include "commands/CmdSelectPieceType.h"
#include "Constants/ConsGlobal.h"

CmdSelectPieceType::CmdSelectPieceType(frc2::CommandXboxController* auxController) 
  : m_auxController{auxController} {
  // Use addRequirements() here to declare subsystem dependencies.
}

// Called when the command is initially scheduled.
void CmdSelectPieceType::Initialize() {
  m_isFinished = false;
}

// Called repeatedly when this Command is scheduled to run
void CmdSelectPieceType::Execute() {

  if(m_auxController->GetXButtonPressed()) {
    g_gameState.selectedPieceType = CubePiece;
  }
  if(m_auxController->GetYButtonPressed()) {
    g_gameState.selectedPieceType = ConePiece;
  }

    m_isFinished = true;
}

// Called once the command ends or is interrupted.
void CmdSelectPieceType::End(bool interrupted) {}

// Returns true when the command should end.
bool CmdSelectPieceType::IsFinished() {
  if(m_isFinished) {
    m_isFinished = false;
    return true;
  }
  return false;
}
