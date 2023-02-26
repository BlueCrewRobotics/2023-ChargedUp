// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#include <stdio.h>
#include <iostream>
#include "commands/CmdClawToggleEngage.h"

CmdClawToggleEngage::CmdClawToggleEngage(SubClawWrist* subClawWrist) 
  : m_subClawWrist{subClawWrist}{
  // Use addRequirements() here to declare subsystem dependencies.
  AddRequirements(subClawWrist);
}

// Called when the command is initially scheduled.
void CmdClawToggleEngage::Initialize() {}

// Called repeatedly when this Command is scheduled to run
void CmdClawToggleEngage::Execute() {
  
  bool engage = m_subClawWrist->GetEngagedClaw();
  engage =! engage;
  m_subClawWrist->EngageClaw(engage);
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
void CmdClawToggleEngage::End(bool interrupted) {}

// Returns true when the command should end.
bool CmdClawToggleEngage::IsFinished() {
  return true;
}
