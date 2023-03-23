// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#include "autocommands/AutoCmdIntakeSpin.h"

AutoCmdIntakeSpin::AutoCmdIntakeSpin(SubClawWrist* subClawWrist, double speed, frc::Timer* timer, double spinTime)
  :m_subClawWrist{subClawWrist}, m_speed{speed}, m_timer{timer}, m_spinTime{spinTime} {
  // Use addRequirements() here to declare subsystem dependencies.
}

// Called when the command is initially scheduled.
void AutoCmdIntakeSpin::Initialize() {
  m_timer->Reset();
  m_timer->Start();
}

// Called repeatedly when this Command is scheduled to run
void AutoCmdIntakeSpin::Execute() {
  m_subClawWrist->SpinIntake(m_speed);
}

// Called once the command ends or is interrupted.
void AutoCmdIntakeSpin::End(bool interrupted) {}

// Returns true when the command should end.
bool AutoCmdIntakeSpin::IsFinished() {
  if(m_timer->HasElapsed((units::time::second_t)m_spinTime)==true){
    m_subClawWrist->SpinIntake(0.0);
    return true;
  }
  else {
    return false;
  }
}

