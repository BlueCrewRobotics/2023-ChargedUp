// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#include <stdio.h>
#include <iostream>
#include "commands/CmdClawEngage.h"

CmdClawEngage::CmdClawEngage(SubClawWrist* subClawWrist) 
  : m_subClawWrist{subClawWrist}{
  // Use addRequirements() here to declare subsystem dependencies.
  AddRequirements(subClawWrist);
}

// Called when the command is initially scheduled.
void CmdClawEngage::Initialize() {}

// Called repeatedly when this Command is scheduled to run
void CmdClawEngage::Execute() {
  
  m_subClawWrist->EngageClaw(false);
  std::cout << "Engaged Claw" << std::endl;
  
  /*
  bool engage = false;
  if(m_subClawWrist->GetEngagedClaw() == true) {
    engage = false;
  }
  else {
    engage = true;
  }
  m_subClawWrist->EngageClaw(engage);
  */
}

// Called once the command ends or is interrupted.
void CmdClawEngage::End(bool interrupted) {}

// Returns true when the command should end.
bool CmdClawEngage::IsFinished() {
  return true;
}
