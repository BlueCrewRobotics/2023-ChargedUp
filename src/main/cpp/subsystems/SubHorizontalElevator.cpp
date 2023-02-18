// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#include "subsystems/SubHorizontalElevator.h"

SubHorizontalElevator::SubHorizontalElevator() = default;

// This method will be called once per scheduler run
void SubHorizontalElevator::Periodic() {}

void SubHorizontalElevator::ConfigureMotor() {
    // Add the code here for configuring the horizontal elevator motor
    // Need to set the position limits set so the elevator doesn't go too far and damage the it mechanically
    
    m_hElevatorMotor.SetSoftLimit(rev::CANSparkMax::SoftLimitDirection::kReverse,0);
    m_hElevatorMotor.SetSoftLimit(rev::CANSparkMax::SoftLimitDirection::kForward,30.0); // May have to be changed

    // set PID coefficients
    m_hElevatorController.SetP(0.02);
    m_hElevatorController.SetI(0.0);
    m_hElevatorController.SetD(0.0);
    m_hElevatorController.SetIZone(0.0);
    m_hElevatorController.SetFF(0.0);
    m_hElevatorController.SetOutputRange(-0.5, 0.5); // This can be sped up possibly
}

double SubHorizontalElevator::GetPosition() {
    // This should return the elevator position
    return 0.0; // TODO return correct value
}

void SubHorizontalElevator::ServoToPosition(double position) {
    // This function will be used by the Cmd to move the elevator to a position
    // Make sure you check that the position is within the range specified
    if(position > m_hElevatorMotor.GetSoftLimit(rev::CANSparkMax::SoftLimitDirection::kForward))
    {
        position = m_hElevatorMotor.GetSoftLimit(rev::CANSparkMax::SoftLimitDirection::kForward);
    }

    if(position < m_hElevatorMotor.GetSoftLimit(rev::CANSparkMax::SoftLimitDirection::kReverse))
    {
        position = m_hElevatorMotor.GetSoftLimit(rev::CANSparkMax::SoftLimitDirection::kReverse);
    }

    m_hElevatorController.SetReference(position, rev::ControlType::kPosition); 
}

void SubHorizontalElevator::ControlMotorManually(double speed) {
    m_hElevatorMotor.Set(speed);
}