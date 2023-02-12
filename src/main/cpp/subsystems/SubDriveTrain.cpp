/*-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=*/
/*                       Blue Crew Robotics #6153                             */
/*                            Charged Up 2023                                 */
/*-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=*/
// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#include "subsystems/SubDriveTrain.h"

#include <iostream>
#include <stdio.h>

SubDriveTrain::SubDriveTrain() = default;

// This method will be called once per scheduler run
void SubDriveTrain::Periodic() {}

// Configure the TalonFX's on the Drive Train
void SubDriveTrain::DriveTrainConfigure() {

  // Clear the Sticky Faults on the controllers
  leftDriveMotor->ClearStickyFault();
  rightDriveMotor->ClearStickyFault();
  leftFollowMotor->ClearStickyFault();
  rightFollowMotor->ClearStickyFault();

  // Set the Drive motor inverted
  rightDriveMotor->SetInverted(true);
  leftDriveMotor->SetInverted(false);

  // Set the Drive motors neutral deadband
  rightDriveMotor->SetNeutralDeadband(0.001);
  leftDriveMotor->SetNeutralDeadband(0.001);

  // Set the right and left followers
  leftFollowMotor->SetFollower(leftDriveMotor->GetMotorController());
  rightFollowMotor->SetFollower(rightDriveMotor->GetMotorController());
  

  // Set the feedback sensor
  leftDriveMotor->SetSelectedFeedbackSensor(FeedbackDevice::IntegratedSensor);
  rightDriveMotor->SetSelectedFeedbackSensor(FeedbackDevice::IntegratedSensor);

  // Set the current limts on the motor
  //leftDriveMotor->SetStatorCurrentLimit(true,50,50,0.5);
  //rightDriveMotor->SetStatorCurrentLimit(true,50,50,0.5);

  leftDriveMotor->SetSupplyCurrentLimit(true,CONTINUOUS_CURRENT_LIMIT,PEAK_CURRENT_LIMIT,DURATION_CURRENT_LIMIT);
  rightDriveMotor->SetSupplyCurrentLimit(true,CONTINUOUS_CURRENT_LIMIT,PEAK_CURRENT_LIMIT,DURATION_CURRENT_LIMIT);

  // Set nominal and peak outputs for the motor for the different profile slots
  leftDriveMotor->SetNominalPeakOutput(0);
  rightDriveMotor->SetNominalPeakOutput(0);
  leftDriveMotor->SetNominalPeakOutput(1);
  rightDriveMotor->SetNominalPeakOutput(1);

  // Set the ramp
  leftDriveMotor->SetRamp(0.15);
  rightDriveMotor->SetRamp(0.15);

  // Setup Motion acceleration and velocity
  leftDriveMotor->ConfigureMotionMagic();
  rightDriveMotor->ConfigureMotionMagic();

  // Set max speed
  leftDriveMotor->SetMaxSpeed(VELOCITY_SP_MAX_LG);
  rightDriveMotor->SetMaxSpeed(VELOCITY_SP_MAX_LG);

  // PID constants for Profile 0 low gear Profile 1 high gear of Talon left
  frc::SmartDashboard::PutNumber("LEFT_KF_0",LEFT_KF_0);
  frc::SmartDashboard::PutNumber("LEFT_KP_0",LEFT_KP_0);
  frc::SmartDashboard::PutNumber("LEFT_KI_0",LEFT_KI_0);
  frc::SmartDashboard::PutNumber("LEFT_KD_0",LEFT_KD_0);

  leftDriveMotor->SetConfig_kF(0, LEFT_KF_0);
  leftDriveMotor->SetConfig_kP(0, LEFT_KP_0);
  leftDriveMotor->SetConfig_kI(0, LEFT_KI_0);
  leftDriveMotor->SetConfig_kD(0, LEFT_KD_0);

  frc::SmartDashboard::PutNumber("LEFT_KF_1",LEFT_KF_1);
  frc::SmartDashboard::PutNumber("LEFT_KP_1",LEFT_KP_1);
  frc::SmartDashboard::PutNumber("LEFT_KI_1",LEFT_KI_1);
  frc::SmartDashboard::PutNumber("LEFT_KD_1",LEFT_KD_1);

  leftDriveMotor->SetConfig_kF(1, LEFT_KF_1);
  leftDriveMotor->SetConfig_kP(1, LEFT_KP_1);
  leftDriveMotor->SetConfig_kI(1, LEFT_KI_1);
  leftDriveMotor->SetConfig_kD(1, LEFT_KD_1);

  // PID constants for Profile 0 low gear Profile 1 high gear of Talon Right

  frc::SmartDashboard::PutNumber("RIGHT_KF_0",RIGHT_KF_0);
  frc::SmartDashboard::PutNumber("RIGHT_KP_0",RIGHT_KP_0);
  frc::SmartDashboard::PutNumber("RIGHT_KI_0",RIGHT_KI_0);
  frc::SmartDashboard::PutNumber("RIGHT_KD_0",RIGHT_KD_0);

  rightDriveMotor->SetConfig_kF(0, RIGHT_KF_0);
  rightDriveMotor->SetConfig_kP(0, RIGHT_KP_0);
  rightDriveMotor->SetConfig_kI(0, RIGHT_KI_0);
  rightDriveMotor->SetConfig_kD(0, RIGHT_KD_0);

  frc::SmartDashboard::PutNumber("RIGHT_KF_1",RIGHT_KF_1);
  frc::SmartDashboard::PutNumber("RIGHT_KP_1",RIGHT_KP_1);
  frc::SmartDashboard::PutNumber("RIGHT_KI_1",RIGHT_KI_1);
  frc::SmartDashboard::PutNumber("RIGHT_KD_1",RIGHT_KD_1);

  rightDriveMotor->SetConfig_kF(1, RIGHT_KF_1);
  rightDriveMotor->SetConfig_kP(1, RIGHT_KP_1);
  rightDriveMotor->SetConfig_kI(1, RIGHT_KI_1);
  rightDriveMotor->SetConfig_kD(1, RIGHT_KD_1);



}

void SubDriveTrain::GetPidFromDashboard() {
  // PID constants for Profile 0 low gear Profile 1 high gear of Talon left
  leftDriveMotor->SetConfig_kF(0, frc::SmartDashboard::GetNumber("LEFT_KF_0",LEFT_KF_0));
  leftDriveMotor->SetConfig_kP(0, frc::SmartDashboard::GetNumber("LEFT_KP_0",LEFT_KP_0));
  leftDriveMotor->SetConfig_kI(0, frc::SmartDashboard::GetNumber("LEFT_KI_0",LEFT_KI_0));
  leftDriveMotor->SetConfig_kD(0, frc::SmartDashboard::GetNumber("LEFT_KD_0",LEFT_KD_0));

  leftDriveMotor->SetConfig_kF(1, frc::SmartDashboard::GetNumber("LEFT_KF_1",LEFT_KF_1));
  leftDriveMotor->SetConfig_kP(1, frc::SmartDashboard::GetNumber("LEFT_KP_1",LEFT_KP_1));
  leftDriveMotor->SetConfig_kI(1, frc::SmartDashboard::GetNumber("LEFT_KI_1",LEFT_KI_1));
  leftDriveMotor->SetConfig_kD(1, frc::SmartDashboard::GetNumber("LEFT_KD_1",LEFT_KD_1));

  // PID constants for Profile 0 low gear Profile 1 high gear of Talon Right
  rightDriveMotor->SetConfig_kF(0, frc::SmartDashboard::GetNumber("RIGHT_KF_0",RIGHT_KF_0));
  rightDriveMotor->SetConfig_kP(0, frc::SmartDashboard::GetNumber("RIGHT_KP_0",RIGHT_KP_0));
  rightDriveMotor->SetConfig_kI(0, frc::SmartDashboard::GetNumber("RIGHT_KI_0",RIGHT_KI_0));
  rightDriveMotor->SetConfig_kD(0, frc::SmartDashboard::GetNumber("RIGHT_KD_0",RIGHT_KD_0));

  rightDriveMotor->SetConfig_kF(1, frc::SmartDashboard::GetNumber("RIGHT_KF_1",RIGHT_KF_1));
  rightDriveMotor->SetConfig_kP(1, frc::SmartDashboard::GetNumber("RIGHT_KP_1",RIGHT_KP_1));
  rightDriveMotor->SetConfig_kI(1, frc::SmartDashboard::GetNumber("RIGHT_KI_1",RIGHT_KI_1));
  rightDriveMotor->SetConfig_kD(1, frc::SmartDashboard::GetNumber("RIGHT_KD_1",RIGHT_KD_1));
}

// Drives the Drive Train with ArcadeDrive given speed and rotation
void SubDriveTrain::Drive(double speed, double rotation) {
    driveTrain->SetDeadband(0.02);
    driveTrain->ArcadeDrive(speed, rotation, true);
}

/*  Drives the Drive train straight given speed                       */
/*  use m_driveTrain->SetYawStraightValue(m_driveTrain->GetYaw());    */
/*  to set the direction you want to go in                            */

/* THIS FUNCTION SHOULD BE A COMMAND. THIS NEEDS TO BE REMOVED FROM HERE.
   SUBSYSTEMS ARE FOR LOW LEVEL FUNCTIONALITY, WHERE COMMANDS ARE USED FOR 
   MORE COMPLICTATED MOVEMENTS AND CHECKING. */

void SubDriveTrain::DriveStraight(double speed) {
  double rotation = 0.0;
  double headingError = m_ahrsYawStraight - m_ahrs->GetYaw();
  if(headingError > 0.0) {
    // Normalize for quadrant I
    rotation = (1.0 - ((180.0-(headingError))/180.0));
//    if(headingError > 5)
//    std::cout << "CmdDriveWithController>> headingError is: " << headingError  << std::endl;
  }
  if(headingError  < 0.0) {
    // Normailize for quadrant II
    rotation = (-1.0 + (180.0+(headingError))/180.0);
//    if(headingError < -5)
//      std::cout << "CmdDriveWithController>> headingError is: " << headingError  << std::endl;
  }
    
    // Correct for quadrents III and IV
  if(rotation > 1.0) {
    rotation = (rotation - 1.0) * -1.0;
    if(rotation > 1.0) {
//      std::cout << "CmdDriveWithController>> ****** Wooooooo"  << std::endl;
    }
  }
  else if(rotation < -1.0) {
    rotation = (rotation + 1.0) * -1.0;
    if(rotation < -1.0) {
//      std::cout << "CmdDriveWithController>> ****** Wooooooo"  << std::endl;
    }
  }

  // catch and avoid erratic jumps
  if(headingError > 300)
    rotation = -0.2;
  else if(headingError < -300)
    rotation = 0.2;

  // Add offset if needed
  if(rotation > 0.0 && rotation < 0.2) {
    rotation = rotation + 0.07;
  }
  else if(rotation < 0.0 && rotation > -0.2) {
    rotation = rotation - 0.07;
  }

  driveTrain->SetDeadband(0.02);
  driveTrain->ArcadeDrive(speed, rotation, true);
}
/*
void SubDriveTrain::SetDriveTrainGear() {
    bool gear = m_gearSolenoid->Get();
    gear = !gear;
    m_gearSolenoid->Set(gear);
}

// Get the drive train gear, false is low gear, true is high gear
bool SubDriveTrain::GetDriveTrainGear() {
    return m_gearSolenoid->Get();
}
*/
void SubDriveTrain::SetMaxSpeed(double maxSpeed) {
    leftDriveMotor->SetMaxSpeed(maxSpeed);
    rightDriveMotor->SetMaxSpeed(maxSpeed);
}

// Set the ramp for the motors
void SubDriveTrain::SetRamp(double ramp) {
  leftDriveMotor->SetRamp(ramp);
  rightDriveMotor->SetRamp(ramp);
}

void SubDriveTrain::AutonomousDriving(double leftrotations, double rightrotations) {
  leftrotations = leftrotations * 2048;
  rightrotations = rightrotations * 2048;

  leftDriveMotor->DriveWithMotionMagic(leftrotations);
  rightDriveMotor->DriveWithMotionMagic(rightrotations);
}

void SubDriveTrain::RotateDriveTrain(double rotation) {
  driveTrain->ArcadeDrive(0,rotation);
}

double SubDriveTrain::GetLeftEncoderValue() {
  return leftDriveMotor->GetEncoderValue();
}

double SubDriveTrain::GetRightEncoderValue() {
  return rightDriveMotor->GetEncoderValue();
}

double SubDriveTrain::GetLeftErrorValue() {
  return leftDriveMotor->GetError();
}

double SubDriveTrain::GetRightErrorValue() {
  return rightDriveMotor->GetError();
}

void SubDriveTrain::ResetEncoderPositions() {
  rightDriveMotor->ResetEncoder();
  leftDriveMotor->ResetEncoder();
}

float SubDriveTrain::GetYaw() {
  return m_ahrs->GetYaw();
}

void SubDriveTrain::ZeroYaw() {
  m_ahrs->ZeroYaw();
}



float SubDriveTrain::GetYawStraightValue() {
  return m_ahrsYawStraight;
}

void SubDriveTrain::SetYawStraightValue(float yawValue) {
  m_ahrsYawStraight = yawValue;
}

void SubDriveTrain::SetPitchLevelValue(float pitchValue) {
  m_ahrsPitchLevel = pitchValue;
}

float SubDriveTrain::GetPitchLevelValue() {
  return m_ahrsPitchLevel;
}
float SubDriveTrain::GetPitch() {
  return m_ahrs->GetRoll();
}

void SubDriveTrain::SetDirectedRotation(double rotation) {
  m_directedRotation = rotation;
}

double SubDriveTrain::GetDirectedRotation() {
  return m_directedRotation;
}
