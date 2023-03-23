// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#include "commands/CmdMoveHorizontalElevator.h"

CmdMoveHorizontalElevator::CmdMoveHorizontalElevator(SubHorizontalElevator* subHorizontalElevator, frc2::CommandXboxController* auxController,SubTurret* subTurret) 
 : m_subHorizontalElevator{subHorizontalElevator}, m_auxController{auxController}, m_subTurret{subTurret} {
  // Use addRequirements() here to declare subsystem dependencies.
  AddRequirements(subHorizontalElevator);
}

// Called when the command is initially scheduled.
void CmdMoveHorizontalElevator::Initialize() {}

// Called repeatedly when this Command is scheduled to run
void CmdMoveHorizontalElevator::Execute() {


  double turretAngle = abs(m_subTurret->GetDegrees());
  if(turretAngle > 0 && turretAngle <= 120){
    double maxValue = -0.00019*turretAngle*turretAngle*turretAngle + 0.05838*turretAngle*turretAngle -5.8506*turretAngle + 233.99285;
    m_subHorizontalElevator->SetMaxExtension(maxValue);
  }
  if(turretAngle > 120){
    double maxValue = -0.30*turretAngle +90.0;
    m_subHorizontalElevator->SetMaxExtension(maxValue);
  }
  

  double speed = 0.0;
  if(m_auxController->GetRawAxis(AXIS_RY) > 0.06 || m_auxController->GetRawAxis(AXIS_RY) < -0.06) {
    speed = -m_auxController->GetRawAxis(AXIS_RY)*0.3;
    m_subHorizontalElevator->EnableHoldPosition(false);
    m_subHorizontalElevator->ControlMotorManually(speed); 
  }
  else {
    m_subHorizontalElevator->EnableHoldPosition(true);
    //m_subHorizontalElevator->ControlMotorManually(0.0);
  }
}

// Called once the command ends or is interrupted.
void CmdMoveHorizontalElevator::End(bool interrupted) {}

// Returns true when the command should end.
bool CmdMoveHorizontalElevator::IsFinished() {
  return false;
}
