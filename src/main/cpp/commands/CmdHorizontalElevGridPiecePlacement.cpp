// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#include "commands/CmdHorizontalElevGridPiecePlacement.h"

CmdHorizontalElevGridPiecePlacement::CmdHorizontalElevGridPiecePlacement(SubRobotGlobals* subRobotGlobals, SubHorizontalElevator* subHorizontalElevator, frc2::CommandXboxController* auxController, SubLimeLightLower* subLimeLightLower, SubLimeLightUpper* subLimeLightUpper, SubTurret* subTurret) 
: m_subRobotGlobals{subRobotGlobals}, m_subHorizontalElevator{subHorizontalElevator}, m_auxController{auxController}, m_subLimeLightLower{subLimeLightLower}, m_subLimeLightUpper{subLimeLightUpper}, m_subTurret{subTurret} {
  // Use addRequirements() here to declare subsystem dependencies.
  AddRequirements(subHorizontalElevator);
}

// Called when the command is initially scheduled.
void CmdHorizontalElevGridPiecePlacement::Initialize() {}

// Called repeatedly when this Command is scheduled to run
void CmdHorizontalElevGridPiecePlacement::Execute() {
    double turretAngle = abs(m_subTurret->GetDegrees());
  if(turretAngle > 0 && turretAngle <= 120){
    m_maxExtension = -0.00019*turretAngle*turretAngle*turretAngle + 0.05838*turretAngle*turretAngle -5.8506*turretAngle + 233.99285;
    //m_subHorizontalElevator->SetMaxExtension(maxValue);
  }
  if(turretAngle > 120){
    m_maxExtension = -0.30*turretAngle +90.0;
    //m_subHorizontalElevator->SetMaxExtension(maxValue);
  }
  

}

// Called once the command ends or is interrupted.
void CmdHorizontalElevGridPiecePlacement::End(bool interrupted) {}

// Returns true when the command should end.
bool CmdHorizontalElevGridPiecePlacement::IsFinished() {
  return true;
}
