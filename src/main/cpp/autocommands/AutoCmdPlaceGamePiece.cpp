// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#include "autocommands/AutoCmdPlaceGamePiece.h"

AutoCmdPlaceGamePiece::AutoCmdPlaceGamePiece(SubRobotGlobals* subRobotGlobals, SubLimeLightLower* subLimeLightLower, SubVerticalElevator* subVerticalElevator, SubTurret* subTurret, SubClawWrist* subClawWrist, SubHorizontalElevator* subHorizontalElevator)
  :m_subRobotGlobals{subRobotGlobals}, m_subLimeLightLower{subLimeLightLower}, m_subVerticalElevator{subVerticalElevator}, m_subTurret{subTurret}, m_subClawWrist{subClawWrist}, m_subHorizontalElevator{subHorizontalElevator} {
  // Use addRequirements() here to declare subsystem dependencies.
  AddRequirements(subLimeLightLower);
  AddRequirements(subVerticalElevator);
  AddRequirements(subTurret);
  AddRequirements(subClawWrist);
  AddRequirements(subHorizontalElevator);
}

// Called when the command is initially scheduled.
void AutoCmdPlaceGamePiece::Initialize() {
  verticalElevatorIsPositioned = false;
  turretIsPositioned = false;
  wristIsPositioned = false;
  horizontalElevatorIsPositioned = false;
  pieceIsPlaced = false;
  m_finished = false;
}

// Called repeatedly when this Command is scheduled to run
void AutoCmdPlaceGamePiece::Execute() {}

// Called once the command ends or is interrupted.
void AutoCmdPlaceGamePiece::End(bool interrupted) {}

// Returns true when the command should end.
bool AutoCmdPlaceGamePiece::IsFinished() {
  return false;
}
