// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#include "subsystems/SubConeRampPrep.h"

SubConeRampPrep::SubConeRampPrep() = default;

// This method will be called once per scheduler run
void SubConeRampPrep::Periodic() {}

void SubConeRampPrep::SetPrepConeRampPosition(bool state){
    m_prepSolenoid->Set(state);
}