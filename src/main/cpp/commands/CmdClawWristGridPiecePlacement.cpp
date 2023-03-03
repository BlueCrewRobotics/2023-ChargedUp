// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#include "commands/CmdClawWristGridPiecePlacement.h"

CmdClawWristGridPiecePlacement::CmdClawWristGridPiecePlacement(SubRobotGlobals* subRobotGlobals, SubClawWrist* subClawWrist, frc2::CommandXboxController* auxController, SubLimeLightLower* subLimeLightLower, SubLimeLightUpper* subLimeLightUpper) 
: m_subRobotGlobals{subRobotGlobals}, m_subClawWrist{subClawWrist}, m_auxController{auxController}, m_subLimeLightLower{subLimeLightLower}, m_subLimeLightUpper{subLimeLightUpper} {
  // Use addRequirements() here to declare subsystem dependencies.
  AddRequirements(subClawWrist);
}

// Called when the command is initially scheduled.
void CmdClawWristGridPiecePlacement::Initialize() {}

// Called repeatedly when this Command is scheduled to run
void CmdClawWristGridPiecePlacement::Execute() {

}

// Called once the command ends or is interrupted.
void CmdClawWristGridPiecePlacement::End(bool interrupted) {}

// Returns true when the command should end.
bool CmdClawWristGridPiecePlacement::IsFinished() {
  return true;
}
