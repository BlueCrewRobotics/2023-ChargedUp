// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#include "subsystems/SubTurret.h"

SubTurret::SubTurret() = default;

// This method will be called once per scheduler run
void SubTurret::Periodic() {
        // Holding the position
    if(m_enableHoldPosition == true){
        //int curOffset =  m_holdPosition - motor->GetSelectedSensorPosition(0);
        //if(curOffset > TURRET_POSITION_HOLD_TOLERANCE || curOffset < -TURRET_POSITION_HOLD_TOLERANCE) {
          motor->Set(ControlMode::Position,m_holdPosition);
        //}
    }
    if(m_enableHoldPosition == false){
        m_holdPosition = motor->GetSelectedSensorPosition(0);
    }
}

void SubTurret::ConfigureTurret() {
    // Add the code here for configuring the turret motor
    // Look at the shooter subsystem on github for infinite recharge it has some turret configuration
    // Need the position limits set so the turret doesn't rotate too far an rip the wire off

    // Setup Turret Motor
    motor->Config_kF(0,TURRET_KF_0, 0);
    motor->Config_kP(0,TURRET_KP_0, 0);
    motor->Config_kI(0,TURRET_KI_0, 0);
    motor->Config_kD(0,TURRET_KD_0, 0);

    motor->ConfigMotionAcceleration(15 /*TURRET_ACCELERATION*/,0);
    motor->ConfigMotionCruiseVelocity(15 /*TURRET_CRUISE_VELOCITY*/,0);

    // Set the talon soft limits and enable limits
    motor->ConfigForwardSoftLimitThreshold(TURRET_MAX_ENCODER /*TURRET_LEFT_SOFT_LIMIT*/, 0);
    motor->ConfigReverseSoftLimitThreshold(TURRET_MIN_ENCODER /*TURRET_RIGHT_SOFT_LIMIT*/, 0);
    motor->ConfigForwardSoftLimitEnable(true /*TURRET_SOFT_LIMITS_ENABLE*/, 0);
    motor->ConfigReverseSoftLimitEnable(true /*TURRET_SOFT_LIMITS_ENABLE*/, 0);

    // Configure the hard limit switches of the talon
    //motor->ConfigReverseLimitSwitchSource(LimitSwitchSource_FeedbackConnector, LimitSwitchNormal_NormallyOpen, 0);
    //motor->ConfigForwardLimitSwitchSource(LimitSwitchSource_FeedbackConnector, LimitSwitchNormal_NormallyOpen, 0);

    motor->ConfigSelectedFeedbackSensor(FeedbackDevice::QuadEncoder, 0, 0);
  
    
    motor->SetSensorPhase(true);
    motor->SetInverted(false);

    motor->ConfigPeakCurrentDuration(20, 0);
    motor->ConfigPeakCurrentLimit(15, 0);
    motor->ConfigContinuousCurrentLimit(9, 0);
    motor->EnableCurrentLimit(true);

    motor->ConfigClosedloopRamp(0);
    motor->ConfigOpenloopRamp(0);

    //motor->SetSelectedSensorPosition(0,0,0);
    m_holdPosition = motor->GetSelectedSensorPosition(0);


}

double SubTurret::GetLocation() {
    // This should return the turret location
    return motor->GetSelectedSensorPosition();
}

double SubTurret::GetDegrees() {
    // This should return the turret location in degrees
    return motor->GetSelectedSensorPosition() / TURRET_ENCODER_TICS_PER_DEGREE;
}

// Give this the position you want in degrees, clockwise is positive, counter-clockwise is negative
void SubTurret::RotateToDegree(double position) {
    // This function will be used by the Cmd to rotate the turret
    // Use the position set function
    // Make sure you check that the position is within the range specified

    double xPosition = position*TURRET_ENCODER_TICS_PER_DEGREE;

    // Check that turret is within operating parameters
    if(xPosition < TURRET_MIN_ENCODER){
        xPosition = TURRET_MIN_ENCODER;
    }
    else if(xPosition > TURRET_MAX_ENCODER){
        xPosition = TURRET_MAX_ENCODER;
    }
    // Disable the periodic hold position
    EnableHoldPosition(false);
    // By setting the m_holdPosition the peridodic function will do the servoing to the position
    m_holdPosition = xPosition;
    EnableHoldPosition(true);

}

void SubTurret::RotateManual(double speed) {
    motor->Set(ControlMode::PercentOutput, speed);
}

void SubTurret::ServoToPosition(double position) {
    if (position < TURRET_MIN_ENCODER) {
        position = TURRET_MIN_ENCODER;
    }
    else if (position > TURRET_MAX_ENCODER) {
        position = TURRET_MAX_ENCODER;
    }
    // Pass the encoder value to the elevator motor
    motor->Set(ControlMode::Position, position);
}

void SubTurret::EnableHoldPosition(bool hold) {
    m_enableHoldPosition = hold;
}

void SubTurret::SetHoldPosition(double position) {
    if (position < TURRET_MIN_ENCODER) {
        position = TURRET_MIN_ENCODER;
    }
    else if (position > TURRET_MAX_ENCODER) {
        position = TURRET_MAX_ENCODER;
    }
    m_holdPosition = position;
}