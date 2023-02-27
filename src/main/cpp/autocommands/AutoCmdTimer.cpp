/*-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=*/
/*                       Blue Crew Robotics #6153                             */
/*                           Charged Up 2023                                  */
/*-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=*/
// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#include "autocommands/AutoCmdTimer.h"

AutoCmdTimer::AutoCmdTimer(frc::Timer* timer, double time) : m_timer(timer), m_time(time) {
  // Use addRequirements() here to declare subsystem dependencies.
}

// Called when the command is initially scheduled.
void AutoCmdTimer::Initialize() {
  m_timer->Reset();
}

// Called repeatedly when this Command is scheduled to run
void AutoCmdTimer::Execute() {
  m_timer->Start();
}

// Called once the command ends or is interrupted.
void AutoCmdTimer::End(bool interrupted) {}

// Returns true when the command should end.
bool AutoCmdTimer::IsFinished() {
  if(m_timer->HasElapsed((units::time::second_t)m_time)==true) {
    return true;
  }
  else {
    return false;
  }
  
}
