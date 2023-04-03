// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#include "autocommands/AutoCmdPickUpConeOffFloor.h"

AutoCmdPickUpConeOffFloor::AutoCmdPickUpConeOffFloor(SubClawWrist* subClawWrist)
  :m_subClawWrist{subClawWrist} {
  // Use addRequirements() here to declare subsystem dependencies.
  AddRequirements(subClawWrist);
}

// Called when the command is initially scheduled.
void AutoCmdPickUpConeOffFloor::Initialize() {
  m_finished = false;
}

// Called repeatedly when this Command is scheduled to run
void AutoCmdPickUpConeOffFloor::Execute() {
  if(m_subClawWrist->GetIntakeOutput() >= 9.5) {
    m_subClawWrist->SpinIntake(0.0);
    m_finished = true;
  }
  else {
    m_subClawWrist->SpinIntake(-0.3);
  }
}

// Called once the command ends or is interrupted.
void AutoCmdPickUpConeOffFloor::End(bool interrupted) {
  if(!m_finished) {
    m_subClawWrist->ServoToPosition(WRIST_CLAW_MIN_LIMIT);
    m_subClawWrist->SpinIntake(0.0);
  }
}

// Returns true when the command should end.
bool AutoCmdPickUpConeOffFloor::IsFinished() {
  return m_finished;
}
