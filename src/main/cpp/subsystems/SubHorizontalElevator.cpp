// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#include "subsystems/SubHorizontalElevator.h"

SubHorizontalElevator::SubHorizontalElevator() = default;

// This method will be called once per scheduler run
void SubHorizontalElevator::Periodic() {

    // Holding the position
    if(m_enableHoldPosition == true) {
        int curOffset = m_holdPosition - m_hElevatorEncoder.GetPosition();
        if(curOffset > HORIZONTAL_ELEV_MAX_LIMIT || curOffset < HORIZONTAL_ELEV_MIN_LIMIT) {
            m_hElevatorController.SetReference(m_holdPosition, rev::ControlType::kPosition); 
        }
    }
    if(m_enableHoldPosition == false) {
        m_holdPosition = m_hElevatorEncoder.GetPosition();
    }
}

void SubHorizontalElevator::ConfigureMotor() {
    // Add the code here for configuring the horizontal elevator motor
    // Need to set the position limits set so the elevator doesn't go too far and damage the it mechanically
    
    m_hElevatorMotor.SetSoftLimit(rev::CANSparkMax::SoftLimitDirection::kReverse,HORIZONTAL_ELEV_MIN_LIMIT);
    m_hElevatorMotor.SetSoftLimit(rev::CANSparkMax::SoftLimitDirection::kForward,HORIZONTAL_ELEV_MAX_LIMIT); // May have to be changed

    // set PID coefficients
    m_hElevatorController.SetP(0.02);
    m_hElevatorController.SetI(0.0);
    m_hElevatorController.SetD(0.0);
    m_hElevatorController.SetIZone(0.0);
    m_hElevatorController.SetFF(0.0);
    m_hElevatorController.SetOutputRange(-0.3, 0.3); // This can be sped up possibly
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
    m_hElevatorMotor.Set(speed*0.4);
}

void SubHorizontalElevator::EnableHoldPosition(bool hold) {
    m_enableHoldPosition = hold;
}

void SubHorizontalElevator::SetHoldPosition(double position) {
    if(position < m_bottomSoftLimit) {
        position = m_bottomSoftLimit;
    }
    else if(position > m_topSoftLimit) {
        position = m_topSoftLimit;
    }
    m_holdPosition = position; 
}
