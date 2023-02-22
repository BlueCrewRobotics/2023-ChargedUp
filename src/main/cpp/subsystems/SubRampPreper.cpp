// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.


// This is our code for the
// MWOBBRNS:
// Magic
// Wands
// Of
// Bippity
// Boppity
// Robot
// No
// Stoppity
#include "subsystems/SubRampPreper.h"

SubRampPreper::SubRampPreper() = default;

// This method will be called once per scheduler run
void SubRampPreper::Periodic() {}

void SubRampPreper::ExtensionToggle() {
    m_pistons->Toggle();
}
