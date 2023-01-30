// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#pragma once

#include <frc2/command/SubsystemBase.h>
#include "BC_FalconFX.h"
#include "Constants.h"

class SubVerticleElevator : public frc2::SubsystemBase {
 public:
  SubVerticleElevator();

  /**
   * Will be called periodically whenever the CommandScheduler runs.
   */
  void Periodic() override;

  // Move the elevator up/down given a speed
  void ElevateBySpeed(double elevatorSpeed);
  // Move the elevator to a specific position given encoder tics
  void ElevateToPosition(double elevatorPosition);
  // Configure the Elevator
  void ElevatorConfigure();
  // Clear the sticky faults on the motor controller
  void ClearStickFaults();
  // Set the max speed
  void SetMaxSpeed(double maxSpeed);
  // Get the elevator encoder value
  double GetElevatorEncoderValue();
  // Get the error from where we want to be
  double GetElevatorErrorValue();
  // Reset encoder value
  void ResetEncoderValue();
 private:
  // Components (e.g. motor controllers and sensors) should generally be
  // declared private and exposed only through public methods.
  BC_FalconFX* elevatorMotor = new BC_FalconFX(MOTOR_VERTICLE_ELEVATOR);
};
