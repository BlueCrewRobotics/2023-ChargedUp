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

    // Setup Turret Motor
    turretMotor->Config_kF(0,TURRET_KF_0, 0);
    turretMotor->Config_kP(0,TURRET_KP_0, 0);
    turretMotor->Config_kI(0,TURRET_KI_0, 0);
    turretMotor->Config_kD(0,TURRET_KD_0, 0);

    turretMotor->ConfigMotionAcceleration(15 /*TURRET_ACCELERATION*/,0);
    turretMotor->ConfigMotionCruiseVelocity(15 /*TURRET_CRUISE_VELOCITY*/,0);

    // Set the talon soft limits and enable limits
    turretMotor->ConfigForwardSoftLimitThreshold(TURRET_MAX_ENCODER /*TURRET_LEFT_SOFT_LIMIT*/, 0);
    turretMotor->ConfigReverseSoftLimitThreshold(TURRET_MIN_ENCODER /*TURRET_RIGHT_SOFT_LIMIT*/, 0);
    turretMotor->ConfigForwardSoftLimitEnable(true /*TURRET_SOFT_LIMITS_ENABLE*/, 0);
    turretMotor->ConfigReverseSoftLimitEnable(true /*TURRET_SOFT_LIMITS_ENABLE*/, 0);

    // Configure the hard limit switches of the talon
    //turretMotor->ConfigReverseLimitSwitchSource(LimitSwitchSource_FeedbackConnector, LimitSwitchNormal_NormallyOpen, 0);
    //turretMotor->ConfigForwardLimitSwitchSource(LimitSwitchSource_FeedbackConnector, LimitSwitchNormal_NormallyOpen, 0);

    turretMotor->ConfigSelectedFeedbackSensor(FeedbackDevice::QuadEncoder, 0, 0);
  
    
    turretMotor->SetSensorPhase(false);
    turretMotor->SetInverted(false);

    turretMotor->ConfigPeakCurrentDuration(20, 0);
    turretMotor->ConfigPeakCurrentLimit(5, 0);
    turretMotor->ConfigContinuousCurrentLimit(1, 0);
    turretMotor->EnableCurrentLimit(true);

    turretMotor->SetSelectedSensorPosition(0,0,0);

}

double SubTurret::GetTurretLocation() {
    // This should return the turret location
    return turretMotor->GetSelectedSensorPosition();
}

void SubTurret::RotateTurret(double position) {
    // This function will be used by the Cmd to rotate the turret
    // Use the position set function
    // Make sure you check that the position is within the range specified

    double xPosition = position;

  // Check that turret is within operating parameters
  if(position < TURRET_MIN_ENCODER){
      xPosition = TURRET_MIN_ENCODER;
  }
  if(position > TURRET_MAX_ENCODER){
      xPosition = TURRET_MAX_ENCODER;
  }


      turretMotor->Set(ControlMode::Position, xPosition);
}
