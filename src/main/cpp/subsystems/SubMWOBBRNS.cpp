// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.


// This is our code for the
// Magic
// Wands
// Of
// Bippity
// Boppity
// Robot
// No
// Stoppity
#include "subsystems/SubMWOBBRNS.h"

SubMWOBBRNS::SubMWOBBRNS() = default;

// This method will be called once per scheduler run
void SubMWOBBRNS::Periodic() {}

void SubMWOBBRNS::ExtensionToggle() {
    m_pistons->Toggle();
}
