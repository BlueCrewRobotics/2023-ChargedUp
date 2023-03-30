// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#include "commands/CmdClawWristPickUpOffFloor.h"

CmdClawWristPickUpOffFloor::CmdClawWristPickUpOffFloor(SubClawWrist* subClawWrist, frc2::CommandXboxController* driverController, SubRobotGlobals* subRobotGlobals)
  :m_subClawWrist{subClawWrist}, m_driverController{driverController}, m_subRobotGlobals{subRobotGlobals} {
  // Use addRequirements() here to declare subsystem dependencies.
  AddRequirements(subClawWrist);
}

// Called when the command is initially scheduled.
void CmdClawWristPickUpOffFloor::Initialize() {
  m_finished = false;
}

// Called repeatedly when this Command is scheduled to run
void CmdClawWristPickUpOffFloor::Execute() {
  if(m_driverController->GetYButton() == true) {
    if(m_subRobotGlobals->g_gameState.selectedPieceType == ConePiece) {
      m_subClawWrist->ServoToPosition(WRIST_CLAW_PICKUP_UPRIGHT_CONE_OFF_FLOOR);
      m_subClawWrist->SpinIntake(-0.43);
    }
    else if(m_subRobotGlobals->g_gameState.selectedPieceType == CubePiece) {
      m_subClawWrist->ServoToPosition(WRIST_CLAW_PICKUP_CUBE_OFF_FLOOR);
      m_subClawWrist->SpinIntake(-0.2);
    }
  }
  else {
    m_subClawWrist->ServoToPosition(WRIST_CLAW_MIN_LIMIT);
    m_subClawWrist->SpinIntake(0.0);
    m_finished = true;
  }
}

// Called once the command ends or is interrupted.
void CmdClawWristPickUpOffFloor::End(bool interrupted) {}

// Returns true when the command should end.
bool CmdClawWristPickUpOffFloor::IsFinished() {
  return m_finished;
}
