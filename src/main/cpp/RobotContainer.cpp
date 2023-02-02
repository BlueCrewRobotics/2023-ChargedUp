/*-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=*/
/*                       Blue Crew Robotics #6153                             */
/*                            Charged Up 2023                                 */
/*-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=*/
// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#include "RobotContainer.h"

#include <frc2/command/button/Trigger.h>

#include "commands/Autos.h"
#include "commands/ExampleCommand.h"


RobotContainer::RobotContainer() {
  // Initialize all of your commands and subsystems here

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

  // Setup the command to shift gears when right bumper is pressed
  driverController_button_lbump->WhenPressed(CmdShiftGear(&m_subDriveTrain));

  driverController_button_x->WhenPressed(CmdFindAndGoToCube(&m_subDriveTrain, &m_subLimeLightUpper, driverController));
  driverController_button_y->WhenPressed(CmdFindAndGoToCone(&m_subDriveTrain, &m_subLimeLightUpper, driverController));

  // Set the default command for the Drive Train
  m_subDriveTrain.SetDefaultCommand(CmdDriveWithController(&m_subDriveTrain, driverController));

  // Settup the cone ramp prepper to extend when a is pressed
  driverController_button_a->WhenHeld(CmdConeRampPrepExtend(&m_subConeRampPrep));

  // Settup the Cone Ramp Prepper to retract when a is released
  driverController_button_a->WhenReleased(CmdConeRampPrepRetract(&m_subConeRampPrep));

  // Schedule `ExampleCommand` when `exampleCondition` changes to `true`
  // frc2::Trigger([this] {
  //   return m_subsystem.ExampleCondition();
  // }).OnTrue(ExampleCommand(&m_subsystem).ToPtr());

  // Schedule `ExampleMethodCommand` when the Xbox controller's B button is
  // pressed, cancelling on release.
  // m_driverController.B().WhileTrue(m_subsystem.ExampleMethodCommand());
}

frc2::CommandPtr RobotContainer::GetAutonomousCommand() {
  // An example command will be run in autonomous
  return autos::ExampleAuto(&m_subsystem);
}

void RobotContainer::ConfigureDrive() {
  m_subDriveTrain.DriveTrainConfigure();
  m_subDriveTrain.GetPidFromDashboard();
}
