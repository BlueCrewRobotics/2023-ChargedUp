// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#include "commands/CmdVerticalElevatorServoToSubstationShelf.h"

CmdVerticalElevatorServoToSubstationShelf::CmdVerticalElevatorServoToSubstationShelf(SubVerticalElevator* subVerticalElevator)
  :m_subVerticalElevator{subVerticalElevator} {
  // Use addRequirements() here to declare subsystem dependencies.
  AddRequirements(subVerticalElevator);
}

// Called when the command is initially scheduled.
void CmdVerticalElevatorServoToSubstationShelf::Initialize() {
  m_finished = false;
  m_isPositionSet = false;
}

// Called repeatedly when this Command is scheduled to run
void CmdVerticalElevatorServoToSubstationShelf::Execute() {
  if(!m_isPositionSet) {
    m_subVerticalElevator->ServoToPosition(VERTICAL_ELEV_POS_SUBSTATION_SHELF);
    m_isPositionSet = true;
  }
  if(m_subVerticalElevator->GetPosition() > 70000) {
    m_finished = true;
  }
}

// Called once the command ends or is interrupted.
void CmdVerticalElevatorServoToSubstationShelf::End(bool interrupted) {}

// Returns true when the command should end.
bool CmdVerticalElevatorServoToSubstationShelf::IsFinished() {
  return m_finished;
}
