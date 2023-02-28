// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#pragma once

#include <frc2/command/SubsystemBase.h>
#include <rev/CANSparkMax.h>
#include <ctre/Phoenix.h>
#include "Constants/ConsHorizontalElevator.h"

class SubHorizontalElevator : public frc2::SubsystemBase {
 public:
  SubHorizontalElevator();

  /**
   * Will be called periodically whenever the CommandScheduler runs.
   */
  void Periodic() override;
  /*
   * Configure the motor settings
  */
  void ConfigureMotor();
  /*
   * Get the elevator position
  */
  double GetPosition();
  /*
   * Servo the elevator to position
  */
  void ServoToPosition(double position);
  /*
   * Drive the elevator to manually
  */
  void ControlMotorManually(double position); 
  // Enable the hold position
  bool EnableHoldPosition(bool hold)
  //Set the hold position
  double SetHoldPosition(double position);


 private:
  // Components (e.g. motor controllers and sensors) should generally be

  // declared private and exposed only through public methods.
  rev::CANSparkMax m_hElevatorMotor{MOTOR_HORIZONTAL_ELEVATOR, rev::CANSparkMax::MotorType::kBrushless};
  rev::SparkMaxPIDController m_hElevatorController = m_hElevatorMotor.GetPIDController();
  rev::SparkMaxRelativeEncoder m_hElevatorEncoder = m_hElevatorMotor.GetEncoder();

  double m_topSoftLimit = HORIZONTAL_ELEV_MAX_LIMIT;
  double m_bottomSoftLimit = 0;  

  // Used for the hold position when the driver is not manually driving the elevator
  double m_holdPosition = motor->GetSelectedSensorPosition(0);
  // enable the hold position
  bool m_enableHoldPosition = true;
};
