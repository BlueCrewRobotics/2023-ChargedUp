// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#include "subsystems/SubRobotGlobals.h"

SubRobotGlobals::SubRobotGlobals() = default;

// This method will be called once per scheduler run
void SubRobotGlobals::Periodic() {}

void SubRobotGlobals::SetColor(double color){
    m_blinkin->Set(color);
}
