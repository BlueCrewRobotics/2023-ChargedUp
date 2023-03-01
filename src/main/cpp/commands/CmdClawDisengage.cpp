// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#include "commands/CmdClawDisengage.h"
#include <iostream>
#include "commands/CmdClawEngage.h"

CmdClawDisengage::CmdClawDisengage(SubClawWrist* subClawWrist) 
  :m_subClawWrist{subClawWrist} {
  // Use addRequirements() here to declare subsystem dependencies.
  AddRequirements(subClawWrist);
}

// Called when the command is initially scheduled.
void CmdClawDisengage::Initialize() {}

// Called repeatedly when this Command is scheduled to run
void CmdClawDisengage::Execute() {
  m_subClawWrist->EngageClaw(true);
  std::cout << "Engaged Claw" << std::endl;
}

// Called once the command ends or is interrupted.
void CmdClawDisengage::End(bool interrupted) {}

// Returns true when the command should end.
bool CmdClawDisengage::IsFinished() {
  return true;
}
