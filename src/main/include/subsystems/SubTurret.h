// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#pragma once

#include <frc2/command/SubsystemBase.h>
#include <rev/CANSparkMax.h>
#include <ctre/Phoenix.h>
#include "Constants/ConsTurret.h"

class SubTurret : public frc2::SubsystemBase {
 public:
  SubTurret();

  /**
   * Will be called periodically whenever the CommandScheduler runs.
   */
  void Periodic() override;
  void ConfigureTurret();
  double GetLocation();
  double GetDegrees();
  void RotateToDegree(double position);
  void RotateManual(double rotationSpeed);

 private:
  // Components (e.g. motor controllers and sensors) should generally be

  TalonSRX *motor = new TalonSRX(MOTOR_TURRET);

  // declared private and exposed only through public methods.
  //rev::CANSparkMax turretMotor{15, rev::CANSparkMax::MotorType::kBrushless}; // Change the zero to an address in robotmap
  //rev::CANPIDController pidController = turretEngageMotor.GetPIDController();
  //rev::CANEncoder turretEngageEncoder = turretEngageMotor.GetEncoder();
};
