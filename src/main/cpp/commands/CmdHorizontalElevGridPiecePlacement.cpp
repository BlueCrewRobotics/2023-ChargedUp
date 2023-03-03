// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#include "commands/CmdHorizontalElevGridPiecePlacement.h"

CmdHorizontalElevGridPiecePlacement::CmdHorizontalElevGridPiecePlacement(SubRobotGlobals* subRobotGlobals, SubHorizontalElevator* subHorizontalElevator, frc2::CommandXboxController* auxController, SubLimeLightLower* subLimeLightLower, SubLimeLightUpper* subLimeLightUpper) 
: m_subRobotGlobals{subRobotGlobals}, m_subHorizontalElevator{subHorizontalElevator}, m_auxController{auxController}, m_subLimeLightLower{subLimeLightLower}, m_subLimeLightUpper{subLimeLightUpper} {
  // Use addRequirements() here to declare subsystem dependencies.
  AddRequirements(subHorizontalElevator);
}

// Called when the command is initially scheduled.
void CmdHorizontalElevGridPiecePlacement::Initialize() {}

// Called repeatedly when this Command is scheduled to run
void CmdHorizontalElevGridPiecePlacement::Execute() {

}

// Called once the command ends or is interrupted.
void CmdHorizontalElevGridPiecePlacement::End(bool interrupted) {}

// Returns true when the command should end.
bool CmdHorizontalElevGridPiecePlacement::IsFinished() {
  return true;
}
