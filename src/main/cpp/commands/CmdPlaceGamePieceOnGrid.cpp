// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#include "commands/CmdPlaceGamePieceOnGrid.h"

CmdPlaceGamePieceOnGrid::CmdPlaceGamePieceOnGrid(SubRobotGlobals* subRobotGlobals, SubLimeLightLower* subLimeLightLower, frc2::CommandXboxController* auxController, SubVerticalElevator* subVerticalElevator, SubTurret* subTurret, SubClawWrist* subClawWrist, SubHorizontalElevator* subHorizontalElevator)
  :m_subRobotGlobals{subRobotGlobals}, m_subLimeLightLower{subLimeLightLower}, m_auxController{auxController}, m_subVerticalElevator{subVerticalElevator}, m_subTurret{subTurret}, m_subClawWrist{subClawWrist}, m_subHorizontalElevator{subHorizontalElevator} {
  // Use addRequirements() here to declare subsystem dependencies.
  AddRequirements(subLimeLightLower);
  AddRequirements(subVerticalElevator);
  AddRequirements(subTurret);
  AddRequirements(subClawWrist);
  AddRequirements(subHorizontalElevator);
}

// Called when the command is initially scheduled.
void CmdPlaceGamePieceOnGrid::Initialize() {
  isVerticalElevatorUp = false;
  isTurretPerpendicular = false;
  isWristDown = false;
  isHorizontalElevatorOut = false;
  isTurretInPosition = false;
  m_finished = false;
  dPadPosition = m_auxController->GetPOV();
}

// Called repeatedly when this Command is scheduled to run
void CmdPlaceGamePieceOnGrid::Execute() {
  if(!m_auxController->GetXButton()) {
    m_finished = true;
  }
  else if(!isVerticalElevatorUp) {
    
  }
}

// Called once the command ends or is interrupted.
void CmdPlaceGamePieceOnGrid::End(bool interrupted) {}

// Returns true when the command should end.
bool CmdPlaceGamePieceOnGrid::IsFinished() {
  return false;
}
