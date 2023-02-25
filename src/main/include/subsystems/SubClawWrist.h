// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#pragma once

#include <frc2/command/SubsystemBase.h>
#include <rev/CANSparkMax.h>
#include <ctre/Phoenix.h>
#include "Constants/ConsClawWrist.h"
#include "Constants/ConsPneumatics.h"
#include <frc/PneumaticHub.h>
#include <frc/Solenoid.h>


class SubClawWrist : public frc2::SubsystemBase {
 public:
  SubClawWrist();

  /**
   * Will be called periodically whenever the CommandScheduler runs.
   */
  void Periodic() override;
  /*
   * Configure the motor settings
  */
  void ConfigureMotor();
  /*
   * Get the wrist position
  */
  double GetPosition();
  /*
   * Servo the wrist to position
  */
  void ServoToPosition(double position);
  /*
   * Drive the wrist to manually
  */
  void ControlMotorManually(double position); 

  /*
   * Control the claw
  */
 void EngageClaw(bool engage);

 bool GetEngagedClaw();

 private:
  // Components (e.g. motor controllers and sensors) should generally be

  // declared private and exposed only through public methods.
  // Setup the Spark Max motor for the wrist
  rev::CANSparkMax m_motorWristClaw{MOTOR_WRIST_CLAW, rev::CANSparkMax::MotorType::kBrushless};
  rev::SparkMaxPIDController m_wristClawController = m_motorWristClaw.GetPIDController();
  rev::SparkMaxRelativeEncoder m_wristClawEncoder = m_motorWristClaw.GetEncoder();

  // Setup the solenoid for the claw to open and close
  frc::Solenoid m_wristClawSolenoid{PNEUMATIC_HUB_ADDR, frc::PneumaticsModuleType::REVPH,WRIST_CLAW_SOLENOID};

  double m_topSoftLimit = WRIST_CLAW_MAX_LIMIT;
  double m_bottomSoftLimit = WRIST_CLAW_MIN_LIMIT;  

};
