// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#include "subsystems/SubVerticalElevator.h"

SubVerticalElevator::SubVerticalElevator() = default;

// This method will be called once per scheduler run
void SubVerticalElevator::Periodic() {}

// Configure the elevator motor and stuff
void SubVerticalElevator::ElevatorConfigure() {
    // Clear the sticky faults on the controllers (whatever that means)
    elevatorMotor->ClearStickyFault();
    // Invert the direction the motor spins if needed (idk why you would need this for the elevator but it's here because I put it here)
    elevatorMotor->SetInverted(false);
    // Select the feedback device (encoder) for the motor
    elevatorMotor->SetSelectedFeedbackSensor(FeedbackDevice::IntegratedSensor);
    // Set the current limit for the motor (you don't want to take up too much power and cause your robot to reset due to voltage drops)
    elevatorMotor->SetSupplyCurrentLimit(true,CONTINUOUS_CURRENT_LIMIT,PEAK_CURRENT_LIMIT,DURATION_CURRENT_LIMIT);
    // Set the ramp (The ramp makes it so the motor gradually accelerates, set it too high and it won't be fast enough, set it too low and the robot will jump in the air if you ram the elevator down at full speed, which you probably don't want but that would be funny, and at this point I'm just wondering if there's a limit to how long a line can be but it looks like there might not be a limit lol. If you're still reading this then wow your wasting time, get back to coding)
    elevatorMotor->SetRamp(0.15); // <-----PLACE HOLDER!!!!---------- this is just what the drive train motors are set to, may need to be changed
    // Set the maximum velocity of the elevator motor (you want it to be fast, but not so fast that yoou start breaking things or banging up the robot)
    elevatorMotor->SetMaxSpeed(ELEVATOR_VELOCITY_MAX); // <---PLACE HOLDER!!!--- Defined in the Constants.h file, currently set to 1000 encoder ticks per 100 miliseconds as a placeholder
}

// Move the elevator up and down based on speed (will not go to a specific location/position, just goes up or down until you stop telling it to)
void SubVerticalElevator::ElevateBySpeed(double elevatorSpeed) {
    // Set the motor speed
    elevatorMotor->Set(elevatorSpeed);
}
// Move the elevator to a specific location/position given encoder tics
void SubVerticalElevator::ElevateToPosition(double elevatorPosition) {
    // Get Current Position
    double currentElevatorPosition = elevatorMotor->GetEncoderValue();
    // Find the error from where we want to be
    double elevatorPositionError = elevatorPosition-currentElevatorPosition;
    // Set the elevator motor speed based on the error, the bigger the error the faster the speed
    double elevatorSpeed = elevatorPositionError/100; // <---PLACE HOLDER---- Deviding by 100 is an arbitrary number
    // Add offset if needed
    if (elevatorSpeed > 0 && elevatorSpeed < 0.16) {
        elevatorSpeed = elevatorSpeed + 0.06; // <---PLACE HOLDER----- Adding 0.06 is a place holder, we may want it higher or lower
    }
    else if (elevatorSpeed < 0 && elevatorSpeed > -0.16) {
        elevatorSpeed = elevatorSpeed - 0.06; // <---PLACE HOLDER----- Subtracting 0.06 is a place holder, we may want it higher or lower
    }
    if (elevatorPositionError > -10 && elevatorPositionError < 10) {
        elevatorSpeed = 0.0;
    }
    // Actually pass the speed to the motor
    elevatorMotor->Set(elevatorSpeed);
}

// Get the elevator motor encoder value
double SubVerticalElevator::GetElevatorEncoderValue() {
    return elevatorMotor->GetEncoderValue();
}

// Get the error from where we want to be
double SubVerticalElevator::GetElevatorErrorValue() {
    return elevatorMotor->GetError();
}

// Reset the encoder position to 0
void SubVerticalElevator::ResetEncoderValue() {
    elevatorMotor->ResetEncoder();
}

// Set the max speed of the elevator motor
void SubVerticalElevator::SetMaxSpeed(double maxSpeed) {
    elevatorMotor->SetMaxSpeed(maxSpeed);
}