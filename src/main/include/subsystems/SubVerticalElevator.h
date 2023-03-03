// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#pragma once

#include <frc2/command/SubsystemBase.h>
#include <ctre/Phoenix.h>
#include "BC_FalconFX.h"
#include "Constants/ConsVerticalElevator.h"

class SubVerticalElevator : public frc2::SubsystemBase {
 public:
  SubVerticalElevator();

  /**
   * Will be called periodically whenever the CommandScheduler runs.
   */
  void Periodic() override;

  // Configure the Elevator
  void ConfigureMotor();
  // Clear the sticky faults on the motor controller
  void ClearStickFaults();
  // Servo to postion
  void ServoToPosition(double position);
  // Move the elevator up/down given a speed
  void ControlMotorManually(double speed);
  // Move the elevator to a specific position given encoder tics
  void ElevateToPosition(double position);
  // Set or release the hold position
  void EnableHoldPosition(bool hold);
  // Set hold position
  void SetHoldPosition(double position);

  double GetHoldPositionDesired();

  // Get the elevator encoder value
  double GetPosition();
  // Reset encoder value
  void ResetPosition();


 private:
  // Components (e.g. motor controllers and sensors) should generally be
  // declared private and exposed only through public methods.
  TalonFX* motor = new TalonFX(MOTOR_VERTICAL_ELEVATOR);
  double m_topSoftLimit = VERTICAL_ELEV_MAX_LIMIT;
  double m_bottomSoftLimit = VERTICAL_ELEV_MIN_LIMIT;
  
  // Used for the hold position when the driver is not manually driving the elevator
  double m_holdPosition = motor->GetSelectedSensorPosition(0);
  // enable the hold position
  bool m_enableHoldPosition = true;

};
