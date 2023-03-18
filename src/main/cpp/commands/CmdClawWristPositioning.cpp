// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#include <frc2/command/button/CommandXboxController.h>

#include "Constants/ConsControllers.h"
#include "commands/CmdClawWristPositioning.h"

CmdClawWristPositioning::CmdClawWristPositioning(SubClawWrist* subClawWrist, frc2::CommandXboxController* auxController, SubRobotGlobals* subRobotGlobals) 
  : m_subClawWrist{subClawWrist}, m_auxController{auxController}, m_subRobotGlobals{subRobotGlobals}{
  // Use addRequirements() here to declare subsystem dependencies.
  AddRequirements(subClawWrist);
}

// Called when the command is initially scheduled.
void CmdClawWristPositioning::Initialize() {}

// Called repeatedly when this Command is scheduled to run
void CmdClawWristPositioning::Execute() {
  // OLD POSITIONS FOR CLAW
/*
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
*/

  // NEW POSITIONS FOR INTAKE
  if(m_auxController->GetPOV() == DPAD_VALUE_MIDDLE_UP ){
    m_subClawWrist->ServoToPosition(WRIST_CLAW_MIN_LIMIT);
  }
  if(m_subRobotGlobals->g_gameState.selectedPieceType == ConePiece) {
    if(m_auxController->GetPOV() == DPAD_VALUE_MIDDLE_CENTER) {
      m_subClawWrist->ServoToPosition(WRIST_CLAW_PLACE_CONE);
    }
    else if(m_auxController->GetPOV() == DPAD_VALUE_MIDDLE_DOWN) {
      m_subClawWrist->ServoToPosition(WRIST_CLAW_MAX_LIMIT);
    }
    else if(m_auxController->GetPOV() == DPAD_VALUE_RIGHT_CENTER) {
      m_subClawWrist->ServoToPosition(WRIST_CLAW_PICKUP_UPRIGHT_CONE);
    }  
    else if(m_auxController->GetPOV() == DPAD_VALUE_LEFT_CENTER) {
      m_subClawWrist->ServoToPosition(WRIST_CLAW_PICKUP_TIPPED_OVER_CONE);
    }  
  }
  else if(m_subRobotGlobals->g_gameState.selectedPieceType == CubePiece) {
    if(m_auxController->GetPOV() == DPAD_VALUE_MIDDLE_CENTER) {
      m_subClawWrist->ServoToPosition(WRIST_CLAW_PLACE_CUBE);
    }
    else if(m_auxController->GetPOV() == DPAD_VALUE_RIGHT_CENTER) {
      m_subClawWrist->ServoToPosition(WRIST_CLAW_PICKUP_CUBE);
    }
    else if(m_auxController->GetPOV() == DPAD_VALUE_MIDDLE_DOWN) {
      m_subClawWrist->ServoToPosition(WRIST_CLAW_TILTED_DOWN);
    }
  }
}

// Called once the command ends or is interrupted.
void CmdClawWristPositioning::End(bool interrupted) {}

// Returns true when the command should end.
bool CmdClawWristPositioning::IsFinished() {
  return true;
}
