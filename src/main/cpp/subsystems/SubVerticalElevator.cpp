// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#include "subsystems/SubVerticalElevator.h"

SubVerticalElevator::SubVerticalElevator() = default;

// This method will be called once per scheduler run
void SubVerticalElevator::Periodic() {}

// Configure the elevator motor and stuff
void SubVerticalElevator::ConfigureMotor() {
    // Clear the sticky faults on the controllers (whatever that means)
    elevatorMotor->ClearStickyFaults(0);
    // Invert the direction the motor spins if needed (idk why you would need this for the elevator but it's here because I put it here)
    elevatorMotor->SetInverted(false);
    // Select the feedback device (encoder) for the motor
    elevatorMotor->ConfigSelectedFeedbackSensor(FeedbackDevice::IntegratedSensor);
    // Set the current limit for the motor (you don't want to take up too much power and cause your robot to reset due to voltage drops)
    elevatorMotor->ConfigSupplyCurrentLimit(SupplyCurrentLimitConfiguration(true,CONTINUOUS_CURRENT_LIMIT,PEAK_CURRENT_LIMIT,DURATION_CURRENT_LIMIT));
}

// Move the elevator up and down based on speed (will not go to a specific location/position, just goes up or down until you stop telling it to)
void SubVerticalElevator::ControlMotorManually(double speed) {
    elevatorMotor->Set(ControlMode::PercentOutput, speed);
}
// Move the elevator to a specific location/position given encoder tics
void SubVerticalElevator::ServoToPosition(double position) {

   if (position < m_bottomSoftLimit) {
    position = m_bottomSoftLimit;
   }
   else if (position > m_topSoftLimit) {
    position = m_topSoftLimit;
   }
   // Pass the encoder value to the elevator motor
   elevatorMotor->Set(ControlMode::Position, position);
}
   
// Get the elevator motor encoder value
double SubVerticalElevator::GetPosition() {
    return elevatorMotor->SetSelectedSensorPosition(0,0,0);
}

// Reset the encoder position to 0
void SubVerticalElevator::ResetPosition() {
    elevatorMotor->SetSelectedSensorPosition(0,0,0);
}
