/*-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=*/
/*                       Blue Crew Robotics #6153                             */
/*                           Charged Up 2023                                  */
/*-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=*/

// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#pragma once

#include <frc2/command/SubsystemBase.h>
#include "BC_FalconFX.h"
#include "BC_TalonSRX.h"
#include <frc/drive/DifferentialDrive.h>
#include <frc/smartdashboard/SmartDashboard.h>
#include <frc/Solenoid.h>
#include "Constants.h"

class SubDriveTrain : public frc2::SubsystemBase {
 public:
  SubDriveTrain();

  /**
   * Will be called periodically whenever the CommandScheduler runs.
   */
  void Periodic() override;

   // Drive the robot
  void Drive(double speed, double rotation);
  // Configure the drive controllers
  void DriveTrainConfigure();
  // Get the PID control parameters from the dashboard
  void GetPidFromDashboard();
  // Clear the sticky faults on the motor controllers
  void ClearStickFaults();
  // Set the follower
  void SetFollower(TalonFX* motor);
  // Set the gear solenoid position
  void SetDriveTrainGear();
  // Get the gear shifter solenoid position
  bool GetDriveTrainGear();
  // Set max speed on drive motors
  void SetMaxSpeed(double maxSpeed);
  // Autonomous driving
  void AutonomousDriving(double leftrotations, double rightrotations);
  // Rotate the robot
  void RotateDriveTrain(double rotation);
  // Get left encoder value
  double GetLeftEncoderValue();
  // Get right encoder value
  double GetRightEncoderValue();
  // Get the error
  double GetLeftErrorValue();
  // Get right encoder value
  double GetRightErrorValue();
  //Reset Enocders Positons
  void ResetEncoderPositions();

 private:
  // Components (e.g. motor controllers and sensors) should generally be
  // declared private and exposed only through public methods.

 /*
  // The below code is used for the falcon 500
  BC_FalconFX* leftDriveMotor = new BC_FalconFX(MOTOR_LEFT_MASTER);
  BC_FalconFX* rightDriveMotor = new BC_FalconFX(MOTOR_RIGHT_MASTER);

  BC_FalconFX* leftFollowMotor = new BC_FalconFX(MOTOR_LEFT_FOLLOWER);
  BC_FalconFX* rightFollowMotor = new BC_FalconFX(MOTOR_RIGHT_FOLLOWER);
*/

  // The below code is used for the Talon SRX controllers
  BC_TalonSRX* leftDriveMotor = new BC_TalonSRX(MOTOR_LEFT_MASTER);
  BC_TalonSRX* rightDriveMotor = new BC_TalonSRX(MOTOR_RIGHT_MASTER);

  BC_TalonSRX* leftFollowMotor = new BC_TalonSRX(MOTOR_LEFT_FOLLOWER);
  BC_TalonSRX* rightFollowMotor = new BC_TalonSRX(MOTOR_RIGHT_FOLLOWER);

  frc::DifferentialDrive* driveTrain = new frc::DifferentialDrive(*leftDriveMotor, *rightDriveMotor);

  frc::Solenoid* m_gearSolenoid = new frc::Solenoid(PCM_0,frc::PneumaticsModuleType::CTREPCM,PCM_0_GEARSHIFT);
  //frc::Solenoid* m_motorCooling = new frc::Solenoid(PCM_0,frc::PneumaticsModuleType::CTREPCM,PCM_0_MOTOR_COOLING);

  double m_maxSpeed = VELOCITY_SP_MAX_LG;
  // Components (e.g. motor controllers and sensors) should generally be
  // declared private and exposed only through public methods.
};
