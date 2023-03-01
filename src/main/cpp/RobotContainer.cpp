/*-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=*/
/*                       Blue Crew Robotics #6153                             */
/*                            Charged Up 2023                                 */
/*-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=*/
// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#include "RobotContainer.h"

#include <frc2/command/button/Trigger.h>

#include "commands/ExampleCommand.h"

RobotContainer::RobotContainer() {
  // Initialize all of your commands and subsystems here
  
  m_firstRoutine = new BC_MotionProfile(
    m_autoRoutinePoints1,m_autoRoutineLength1,m_autoRoutineTimeStep,
    m_autoRoutineVelocityMax,m_autoAccelerationMax,m_autoJerkMax,m_autoWheelbaseWidth);

  //Add commands to the autonomous drive station chooser
  m_autoChooser.SetDefaultOption("Auto 1", &m_autoAutonomous);
  m_autoChooser.AddOption("Auto 2", &m_autoAutonomous2);

  // Put the chooser on the dashboard
  frc::SmartDashboard::PutData("Autonomous", &m_autoChooser);

  // Configure the button bindings
  ConfigureBindings();

}

void RobotContainer::ConfigureBindings() {
  // Configure your trigger bindings here

  
  driverController_button_x.OnTrue(CmdFindAndGoToCube(&m_subDriveTrain, &m_subLimeLightUpper, &driverController).ToPtr());
  driverController_button_y.OnTrue(CmdFindAndGoToCone(&m_subDriveTrain, &m_subLimeLightUpper, &driverController).ToPtr());
  
  // select type of piece we're interested in
  driverController_button_a.OnTrue(CmdSelectPieceType(&m_subRobotGlobals).ToPtr());

  
  // Toggle whether or not the claw is engaged when the aux controller left bumper is pressed
  auxController_button_lbump.OnTrue(CmdClawDisengage(&m_subClawWrist).ToPtr());
  auxController_button_lbump.OnFalse(CmdClawEngage(&m_subClawWrist).ToPtr());
  auxController_button_rbump.OnTrue(CmdClawWristExtend(&m_subClawWrist).ToPtr());
  auxController_button_rbump.OnFalse(CmdClawWristRetract(&m_subClawWrist).ToPtr());
  //auxController_button_x.OnTrue(CmdSelectPieceType(& auxController).ToPtr());
  //auxController_button_y.OnTrue(CmdSelectPieceType(& auxController).ToPtr());

  // Press and hold the Dpad position down and press the x button to move the elevator to the right height based on the global variable
  auxController_button_x.OnTrue(CmdVerticalElevatorServoToPosition(&m_subRobotGlobals,&m_subVerticalElevator, &auxController,0/*This last variableis not used currently*/).ToPtr());
  auxController_button_start.OnTrue(CmdPickUpFromSubstationShelfPrep(&m_subTurret, &m_subVerticalElevator, &m_subLimeLightUpper).ToPtr());

//  auxController_button_b.OnTrue(CmdVerticalElevatorServoUpNodePosition(&m_subVerticalElevator, & auxController).ToPtr()).Debounce((units::time::second_t) 0.3, frc::Debouncer::kBoth);
//  auxController_button_a.OnTrue(CmdVerticalElevatorServoDownNodePosition(&m_subVerticalElevator, & auxController).ToPtr()).Debounce((units::time::second_t) 0.3, frc::Debouncer::kBoth);

  // used for testing via cout prints ... such as continuously printing pitch, roll, yaw 
  // driverController_button_a.OnTrue(CmdPrinty(&m_subDriveTrain, &driverController).ToPtr());

  // Set the default command for the Drive Train
  m_subDriveTrain.SetDefaultCommand(CmdDriveWithController(&m_subDriveTrain, &driverController));
  // Set the default command for the Turret
  m_subTurret.SetDefaultCommand(CmdRotateTurret(&m_subTurret, &auxController));
  // Set the default command for the vertical elevator
  m_subVerticalElevator.SetDefaultCommand(CmdMoveVerticalElevator(&m_subVerticalElevator, &auxController));
  // Set default command for the horizontal elevator
  m_subHorizontalElevator.SetDefaultCommand(CmdMoveHorizontalElevator(&m_subHorizontalElevator, &auxController));
  // Set the default command for the claw wrist
  m_subClawWrist.SetDefaultCommand(CmdClawWristMoveManual(&m_subClawWrist, &auxController));
  // Schedule `ExampleCommand` when `exampleCondition` changes to `true`
  // frc2::Trigger([this] {
  //   return m_subsystem.ExampleCondition();
  // }).OnTrue(ExampleCommand(&m_subsystem).ToPtr());

  // Schedule `ExampleMethodCommand` when the Xbox controller's B button is
  // pressed, cancelling on release.
  // m_driverController.B().WhileTrue(m_subsystem.ExampleMethodCommand());
}

frc2::Command* RobotContainer::GetAutonomousCommand() {
  
  return m_autoChooser.GetSelected();
}

void RobotContainer::ConfigureDrive() {
  m_subDriveTrain.DriveTrainConfigure();
  m_subDriveTrain.GetPidFromDashboard();
  // Move to propor location
  m_subTurret.ConfigureTurret();
  m_subVerticalElevator.ConfigureMotor();
  m_subHorizontalElevator.ConfigureMotor();
  m_subPneumatics.ConfigureCompressor();
  m_subClawWrist.ConfigureMotor();
}

