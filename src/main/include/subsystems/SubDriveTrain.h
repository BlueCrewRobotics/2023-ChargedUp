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
#include "Constants/ConsDrivetrain.h"
#include "Constants/ConsControllers.h"
#include "AHRS.h"
#include "common/BC_MotionProfile.h"


class SubDriveTrain : public frc2::SubsystemBase
{
public:
  SubDriveTrain();

  /**
   * Will be called periodically whenever the CommandScheduler runs.
   */
  void Periodic() override;

  // Drive the robot
  void Drive(double speed, double rotation);
  // Drive the robot straight using navx
  void DriveStraight(double speed);
  // Configure the drive controllers

  // Get current speed in ticks per 100/ms  
  double GetRightSideSpeed();
  double GetLeftSideSpeed();

  void DriveTrainConfigure();
  // Resets commonly changed things like max speed, motor safety, ramp, neutral band, etc. back to original configuration
  void ResetDriveTrainConfiguration();
  // Get the PID control parameters from the dashboard
  void GetPidFromDashboard();
  // calls feed() on the driveTrain to avoid safety timeout (for another interval)
  void ResetSafetyTimer();
  // Clear the sticky faults on the motor controllers
  void ClearStickFaults();
  // Set the follower
  void SetFollower(TalonFX *motor);
  // Set the gear solenoid position
  //void SetDriveTrainGear();
  // Get the gear shifter solenoid position
  //bool GetDriveTrainGear();
  // Set max speed on drive motors
  void SetMaxSpeed(double maxSpeed);
  // Set the ramp for the motors
  void SetRamp(double ramp);
  // Autonomous driving - move the given number of rotations, returns resulting position
  void AutonomousDrivingByRotations(double leftRotations, double rightRotations);
  // Autonomous driving - move to the given encoder positions, returns resulting position
  void AutonomousDrivingToPosition(double leftPosition, double rightPosition);

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
  // Reset Enocders Positons
  void ResetEncoderPositions();
  // Callibrate NavX
  void CalibrateNavX();
  // Get navx positional yaw
  float GetYaw();
  //zero yaw
  void ZeroYaw();
  // Get the Yaw straight value
  float GetYawStraightValue();
  // Set Yaw straight value
  void SetYawStraightValue(float yawValue);
  // Get navx pitch
  float GetPitch();
  // Get navx pitch
  float GetRoll();
  // Set the Pitch level value
  void SetPitchLevelValue(float pitchValue);
  // Get the Pitch level value
  float GetPitchLevelValue();
  // Set the Directed rotation
  void SetDirectedRotation(double rotation);
  // Get the Directed Rotation
  double GetDirectedRotation();

  // Write the motion profile to the buffered atream object
  void WriteMotionProfileToBuffer(BC_MotionProfile* motionProfile); 

  TalonSRXConfiguration leftDriveMotorConfigs;
  TalonSRXConfiguration rightDriveMotorConfigs;
  TalonSRXConfiguration leftFollowMotorConfigs;
  TalonSRXConfiguration rightFollowMotorConfigs;

private:
  // Components (e.g. motor controllers and sensors) should generally be
  // declared private and exposed only through public methods.

  
   // The below code is used for the falcon 500
   BC_FalconFX* leftDriveMotor = new BC_FalconFX(MOTOR_LEFT_MASTER);
   BC_FalconFX* rightDriveMotor = new BC_FalconFX(MOTOR_RIGHT_MASTER);

   BC_FalconFX* leftFollowMotor = new BC_FalconFX(MOTOR_LEFT_FOLLOWER);
   BC_FalconFX* rightFollowMotor = new BC_FalconFX(MOTOR_RIGHT_FOLLOWER);
 
/*
  // The below code is used for the Talon SRX controllers
  BC_TalonSRX *leftDriveMotor = new BC_TalonSRX(MOTOR_LEFT_MASTER);
  BC_TalonSRX *rightDriveMotor = new BC_TalonSRX(MOTOR_RIGHT_MASTER);
  BC_TalonSRX *leftFollowMotor = new BC_TalonSRX(MOTOR_LEFT_FOLLOWER);
  BC_TalonSRX *rightFollowMotor = new BC_TalonSRX(MOTOR_RIGHT_FOLLOWER);
 */ 
  frc::DifferentialDrive *driveTrain = new frc::DifferentialDrive(*leftDriveMotor, *rightDriveMotor);

  //frc::Solenoid *m_gearSolenoid = new frc::Solenoid(PCM_0, frc::PneumaticsModuleType::CTREPCM, PCM_0_GEARSHIFT);
  // frc::Solenoid* m_motorCooling = new frc::Solenoid(PCM_0,frc::PneumaticsModuleType::CTREPCM,PCM_0_MOTOR_COOLING);

  double m_maxSpeed = VELOCITY_SP_MAX_LG;

  // Navx setup and increasing the update rate default is 60 range is 4-200. Loading of the RobioRio should be monitored
  AHRS* m_ahrs = new AHRS(frc::SPI::kMXP, 100);
  
  // Used to drive straight
  float m_ahrsYawStraight = 0;
  float m_ahrsPitchLevel = 0;

  // Used to use rotation given from something automatically, like the limelight
  double m_directedRotation = 0.0;

  // Components (e.g. motor controllers and sensors) should generally be
  // declared private and exposed only through public methods.
 
};
