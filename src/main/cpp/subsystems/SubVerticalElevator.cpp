// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#include "subsystems/SubVerticalElevator.h"

SubVerticalElevator::SubVerticalElevator() = default;

// This method will be called once per scheduler run
void SubVerticalElevator::Periodic() {
    
    // Holding the position
    if(m_enableHoldPosition == true){
        motor->Set(ControlMode::Position,m_holdPosition);
    }
    if(m_enableHoldPosition == false){
        m_holdPosition = motor->GetSelectedSensorPosition(0);
    }

}

// Configure the elevator motor and stuff
void SubVerticalElevator::ConfigureMotor() {
    // Clear the sticky faults on the controllers (whatever that means)
    motor->ClearStickyFaults(0);
    // Invert the direction the motor spins if needed (idk why you would need this for the elevator but it's here because I put it here)
    motor->SetInverted(false);
    // Select the feedback device (encoder) for the motor
    motor->ConfigSelectedFeedbackSensor(FeedbackDevice::IntegratedSensor);
    motor->SetInverted(TalonFXInvertType::CounterClockwise);
    
    // Set the current limit for the motor (you don't want to take up too much power and cause your robot to reset due to voltage drops)
    motor->ConfigSupplyCurrentLimit(SupplyCurrentLimitConfiguration(true,5,10,100));
    
    // Set the position limits
    motor->ConfigForwardSoftLimitThreshold(VERTICAL_ELEV_TOP_LIMIT,0);
    motor->ConfigReverseSoftLimitThreshold(1200,0);
    motor->ConfigForwardSoftLimitEnable(true,0);
    motor->ConfigReverseSoftLimitEnable(true,0);

        // Setup Turret Motor
    motor->Config_kF(0,0.0, 0);
    motor->Config_kP(0,0.01, 0);
    motor->Config_kI(0,0.00005, 0);
    motor->Config_kD(0,0.0, 0);

}

// Move the elevator up and down based on speed (will not go to a specific location/position, just goes up or down until you stop telling it to)
void SubVerticalElevator::ControlMotorManually(double speed) {
    motor->Set(ControlMode::PercentOutput, speed);
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
   motor->Set(ControlMode::Position, position);
}
   
// Get the elevator motor encoder value
double SubVerticalElevator::GetPosition() {
    return motor->SetSelectedSensorPosition(0,0,0);
}

// Reset the encoder position to 0
void SubVerticalElevator::ResetPosition() {
    motor->SetSelectedSensorPosition(0,0,0);
}

void SubVerticalElevator::EnableHoldPosition(bool hold) {
    m_enableHoldPosition = hold;
}

