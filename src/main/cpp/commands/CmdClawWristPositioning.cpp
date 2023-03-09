// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#include <frc2/command/button/CommandXboxController.h>

#include "Constants/ConsControllers.h"
#include "commands/CmdClawWristPositioning.h"

CmdClawWristPositioning::CmdClawWristPositioning(SubClawWrist* subClawWrist, frc2::CommandXboxController* auxController) 
  : m_subClawWrist{subClawWrist}, m_auxController{auxController}{
  // Use addRequirements() here to declare subsystem dependencies.
  AddRequirements(subClawWrist);
}

// Called when the command is initially scheduled.
void CmdClawWristPositioning::Initialize() {}

// Called repeatedly when this Command is scheduled to run
void CmdClawWristPositioning::Execute() {

  if(m_auxController->GetPOV() == DPAD_VALUE_MIDDLE_UP ){
    m_subClawWrist->ServoToPosition(WRIST_CLAW_MIN_LIMIT);
  }
  else if(m_auxController->GetPOV() == DPAD_VALUE_MIDDLE_CENTER ){
    m_subClawWrist->ServoToPosition(WRIST_CLAW_UP_A_BIT_POSITION);
  }
  else if(m_auxController->GetPOV() == DPAD_VALUE_MIDDLE_DOWN ){
    m_subClawWrist->ServoToPosition(WRIST_CLAW_DOWN_FOR_PICKING_UP_POSITION);
  }
  else if(m_auxController->GetPOV() == DPAD_VALUE_RIGHT_CENTER ){
    m_subClawWrist->ServoToPosition(WRIST_CLAW_FORWARD_POSITION);
  }  
}

// Called once the command ends or is interrupted.
void CmdClawWristPositioning::End(bool interrupted) {}

// Returns true when the command should end.
bool CmdClawWristPositioning::IsFinished() {
  return true;
}
