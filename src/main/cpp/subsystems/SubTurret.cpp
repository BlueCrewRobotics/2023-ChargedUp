// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#include "subsystems/SubTurret.h"

SubTurret::SubTurret() = default;

// This method will be called once per scheduler run
void SubTurret::Periodic() {}

void SubTurret::ConfigureTurret() {
    // Add the code here for configuring the turret motor
    // Look at the shooter subsystem on github for infinite recharge it has some turret configuration
    // Need the position limits set so the turret doesn't rotate too far an rip the wire off

}

double SubTurret::GetTurretLocation() {
    // This should return the turret location
}

void SubTurret::RotateTurret(double position) {
    // This function will be used by the Cmd to rotate the turret
    // Use the position set function
    // Make sure you check that the position is within the range specified
}
