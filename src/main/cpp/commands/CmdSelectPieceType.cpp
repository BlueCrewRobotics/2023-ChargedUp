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

#include <iostream>

CmdSelectPieceType::CmdSelectPieceType(SubRobotGlobals* subRobotGlobals) 
  : m_subRobotGlobals{subRobotGlobals} {
  // Use addRequirements() here to declare subsystem dependencies.
}

// Called when the command is initially scheduled.
void CmdSelectPieceType::Initialize() {
  //m_isFinished = false;
}

// Called repeatedly when this Command is scheduled to run
void CmdSelectPieceType::Execute() {

  if(m_subRobotGlobals->g_gameState.selectedPieceType == ConePiece)
  {
    m_subRobotGlobals->g_gameState.selectedPieceType = CubePiece;
    m_subRobotGlobals->SetColor(BLINKIN_SOLID_VIOLET);
    std::cout << "Cube Selected" << std::endl;
  }

  else
  {
    m_subRobotGlobals->g_gameState.selectedPieceType = ConePiece;
    m_subRobotGlobals->SetColor(BLINKIN_SOLID_YELLOW);
    std::cout << "Cone Selected" << std::endl;
  }

/*  if(m_auxController->GetXButtonPressed()) {
    g_gameState.selectedPieceType = CubePiece;

    std::cout << "Selected Cube type" << std::endl;
  }
  if(m_auxController->GetYButtonPressed()) {
    g_gameState.selectedPieceType = ConePiece;

    std::cout << "Selected Cone type" << std::endl;
  }

    m_isFinished = true;
    */
}

// Called once the command ends or is interrupted.
void CmdSelectPieceType::End(bool interrupted) {}

// Returns true when the command should end.
bool CmdSelectPieceType::IsFinished() {
  /*if(m_isFinished) {
    m_isFinished = false;
    return true;
  }*/
  return true;
}
