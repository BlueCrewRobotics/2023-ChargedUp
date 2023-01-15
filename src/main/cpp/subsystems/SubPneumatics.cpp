/*-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=*/
/*                       Blue Crew Robotics #6153                             */
/*                           Charged Up 2023                                 */
/*-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=*/
// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#include "subsystems/SubPneumatics.h"

SubPneumatics::SubPneumatics() = default;

// This method will be called once per scheduler run
void SubPneumatics::Periodic() {}

// Configures the robot air compressor.  The default is closed loop control
// So just enabling is all that is needed
void SubPneumatics::ConfigureCompressor(){
    m_compressor->EnableDigital();
}

