// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#include "subsystems/SubClawWrist.h"

SubClawWrist::SubClawWrist() = default;

// This method will be called once per scheduler run
void SubClawWrist::Periodic() {}

void SubClawWrist::ConfigureMotor() {
    // Add the code here for configuring the horizontal elevator motor
    // Need to set the position limits set so the elevator doesn't go too far and damage the it mechanically
    
    m_motorWristClaw.SetSoftLimit(rev::CANSparkMax::SoftLimitDirection::kReverse,0);
    m_motorWristClaw.SetSoftLimit(rev::CANSparkMax::SoftLimitDirection::kForward,30.0); // May have to be changed

    // set PID coefficients
    m_wristClawController .SetP(0.02);
    m_wristClawController .SetI(0.0);
    m_wristClawController .SetD(0.0);
    m_wristClawController .SetIZone(0.0);
    m_wristClawController .SetFF(0.0);
    m_wristClawController .SetOutputRange(-0.5, 0.5); // This can be sped up possibly
}

double SubClawWrist::GetPosition() {
    // This should return the elevator position
    return m_wristClawEncoder.GetPosition(); // TODO return correct value
}

void SubClawWrist::ServoToPosition(double position) {
    // This function will be used by the Cmd to move the elevator to a position
    // Make sure you check that the position is within the range specified
    if(position > m_motorWristClaw.GetSoftLimit(rev::CANSparkMax::SoftLimitDirection::kForward))
    {
        position = m_motorWristClaw.GetSoftLimit(rev::CANSparkMax::SoftLimitDirection::kForward);
    }

    if(position < m_motorWristClaw.GetSoftLimit(rev::CANSparkMax::SoftLimitDirection::kReverse))
    {
        position = m_motorWristClaw.GetSoftLimit(rev::CANSparkMax::SoftLimitDirection::kReverse);
    }

    m_wristClawController .SetReference(position, rev::ControlType::kPosition); 
}

void SubClawWrist::ControlMotorManually(double speed) {
    m_motorWristClaw.Set(speed);
}

void SubClawWrist::EngageClaw(bool engage) {
    m_wristClawSolenoid.Set(engage);
}

