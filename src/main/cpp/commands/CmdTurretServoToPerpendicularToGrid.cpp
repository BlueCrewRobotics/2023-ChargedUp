// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#include "commands/CmdTurretServoToPerpendicularToGrid.h"

#include <iostream>
#include <stdio.h>

CmdTurretServoToPerpendicularToGrid::CmdTurretServoToPerpendicularToGrid(SubTurret* subTurret, SubDriveTrain* SubDriveTrain, frc2::CommandXboxController* auxController)
  :m_subTurret{subTurret}, m_subDriveTrain{SubDriveTrain}, m_auxController{auxController} {
  // Use addRequirements() here to declare subsystem dependencies.
  AddRequirements(subTurret);
}

// Called when the command is initially scheduled.
void CmdTurretServoToPerpendicularToGrid::Initialize() {
  m_finished = false;
  m_robotYaw = -m_subDriveTrain->GetYaw();
  if(m_robotYaw <= 10 && m_robotYaw >= -10) {
    if(m_auxController->GetPOV() == DPAD_VALUE_LEFT_DOWN || m_auxController->GetPOV() == DPAD_VALUE_LEFT_CENTER || m_auxController->GetPOV() == DPAD_VALUE_LEFT_UP) {
      m_goingClockwise = false;
    }
    else if(m_auxController->GetPOV() == DPAD_VALUE_RIGHT_DOWN || m_auxController->GetPOV() == DPAD_VALUE_RIGHT_CENTER || m_auxController->GetPOV() == DPAD_VALUE_RIGHT_UP) {
      m_goingClockwise = true;
    }
    else if(m_subTurret->GetDegrees() <= 0.0) {
      m_goingClockwise = true;
    }
    else if(m_subTurret->GetDegrees() > 0.0) {
      m_goingClockwise = false;
    }
  }
  else if(m_robotYaw > 10) {
      m_goingClockwise = false;
  }
  else if(m_robotYaw < -10) {
      m_goingClockwise = true;
  }
  if(m_goingClockwise) {
    m_newTurretAngle = -180 - m_robotYaw;
  }
  else {
    m_newTurretAngle = 180 - m_robotYaw;
  }
  if(m_newTurretAngle > 190) {
    std::cout << "New Turret Angle Was Greater than 190: " << m_newTurretAngle << std::endl;
    m_newTurretAngle = 190;
  }
  else if(m_newTurretAngle < -190) {
    std::cout << "New Turret Angle Was Less Than -190: " << m_newTurretAngle << std::endl;
    m_newTurretAngle = -190;
  }
  std::cout << "New Turret Angle: " << m_newTurretAngle << std::endl;
  if(!(m_auxController->GetRawAxis(AXIS_LX) > JOYSTICK_AXIS_BUFFER || m_auxController->GetRawAxis(AXIS_LX) < -JOYSTICK_AXIS_BUFFER) && !(m_auxController->GetRawAxis(AXIS_RX) > JOYSTICK_AXIS_BUFFER || m_auxController->GetRawAxis(AXIS_RX) < -JOYSTICK_AXIS_BUFFER)) {
    m_subTurret->RotateToDegree(m_newTurretAngle);
  }
}

// Called repeatedly when this Command is scheduled to run
void CmdTurretServoToPerpendicularToGrid::Execute() {
  if((m_auxController->GetRawAxis(AXIS_LX) > JOYSTICK_AXIS_BUFFER || m_auxController->GetRawAxis(AXIS_LX) < -JOYSTICK_AXIS_BUFFER) || (m_auxController->GetRawAxis(AXIS_RX) > JOYSTICK_AXIS_BUFFER || m_auxController->GetRawAxis(AXIS_RX) < -JOYSTICK_AXIS_BUFFER)) {
    m_subTurret->RotateToDegree(m_newTurretAngle);
  }
  double currentTurretAngle = m_subTurret->GetDegrees();
  if(m_goingClockwise && currentTurretAngle < m_newTurretAngle+2) {
    m_finished = true;
  }
  else if(!m_goingClockwise && currentTurretAngle > m_newTurretAngle-2) {
    m_finished = true;
  }
}

// Called once the command ends or is interrupted.
void CmdTurretServoToPerpendicularToGrid::End(bool interrupted) {}

// Returns true when the command should end.
bool CmdTurretServoToPerpendicularToGrid::IsFinished() {
  return m_finished;
}
