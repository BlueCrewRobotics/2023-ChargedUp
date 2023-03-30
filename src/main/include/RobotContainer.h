/*-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=*/
/*                       Blue Crew Robotics #6153                             */
/*                            Charged Up 2023                                 */
/*-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=*/
// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#pragma once

#include <frc/smartdashboard/SendableChooser.h>

#include <frc2/command/CommandPtr.h>
#include <frc2/command/button/CommandXboxController.h>
#include <frc/Joystick.h>
#include <frc2/command/button/JoystickButton.h>

// Command includes
#include "commands/CmdDriveWithController.h"
#include "commands/CmdFindAndGoToCube.h"
#include "commands/CmdFindAndGoToCone.h"
#include "commands/CmdPrinty.h"
#include "commands/CmdTurretRotate.h"
#include "commands/CmdMoveVerticalElevator.h"
#include "commands/CmdMoveHorizontalElevator.h"
#include "commands/CmdVerticalElevatorServoToPosition.h"
#include "commands/CmdVerticalElevatorServoUpNodePosition.h"
#include "commands/CmdVerticalElevatorServoDownNodePosition.h"
#include "commands/CmdPickUpFromSubstationShelfPrep.h"
#include "commands/CmdSelectPieceType.h"
#include "commands/CmdClawEngage.h"
#include "commands/CmdClawDisengage.h"
#include "commands/CmdIntakeSpin.h"
#include "commands/CmdClawWristPickUpOffFloor.h"

#include "commands/CmdClawWristPositioning.h"
#include "commands/CmdClawWristMoveManual.h"
#include "commands/SeqCmdPlaceGamePieceOnGrid.h"
#include "commands/SeqCmdTurretAndElevatorsServoToHome.h"
#include "commands/CmdTurretAndElevatorsServoToHome.h"
#include "commands/SeqCmdVerticalElevatorAndTurretPrepForPiecePlacement.h"

// Auto commands
#include "autocommands/AutoCmdAutonomousDriveOntoChargeStationAndBalance.h"
#include "autocommands/AutoCmdAutonomousDoNothing.h"
#include "autocommands/AutoCmdAutonomousDriveOutOfCommunity.h"
#include "autocommands/AutoCmdAutonomousDriveOverAndOntoChargeStation.h"
#include "autocommands/AutoCmdAutonomousPlaceCube.h"
#include "autocommands/AutoCmdAutonomousPlaceCubeAndDriveOntoChargeStation.h"
#include "autocommands/AutoCmdAutonomousPlaceCubeAndDriveOverAndOntoRamp.h"


#include "autocommands/AutoCmdDrive.h"

// Common classes
#include "common/BC_MotionProfile.h"

// Constants used throughout code
#include "Constants/ConsClawWrist.h"
#include "Constants/ConsControllers.h"
#include "Constants/ConsDrivetrain.h"
#include "Constants/ConsHorizontalElevator.h"
#include "Constants/ConsLimeLights.h"
#include "Constants/ConsPneumatics.h"
#include "Constants/ConsTurret.h"
#include "Constants/ConsVerticalElevator.h"
#include "Constants/ConsGlobal.h"

// Subsystems includes
#include "subsystems/ExampleSubsystem.h"
#include "subsystems/SubDriveTrain.h"
#include "subsystems/SubLimeLightLower.h"
#include "subsystems/SubLimeLightUpper.h"
#include "subsystems/SubLimeLightSwitcher.h"
#include "subsystems/SubTurret.h"
#include "subsystems/SubVerticalElevator.h"
#include "subsystems/SubHorizontalElevator.h"
#include "subsystems/SubPneumatics.h"
#include "subsystems/SubClawWrist.h"
#include "subsystems/SubRobotGlobals.h"

/**
 * This class is where the bulk of the robot should be declared.  Since
 * Command-based is a "declarative" paradigm, very little robot logic should
 * actually be handled in the {@link Robot} periodic methods (other than the
 * scheduler calls).  Instead, the structure of the robot (including subsystems,
 * commands, and trigger mappings) should be declared here.
 */
class RobotContainer {
 public:
  RobotContainer();

  frc2::Command* GetAutonomousCommand();

  void ZeroNavXYaw();

  // Configure the drive train run this function in RobotInit()
  void ConfigureDrive();

  BC_MotionProfile* m_firstRoutine;

 private:
   // Timers for automomous
  frc::Timer m_autoTimer;

  // The robot's commands
  AutoCmdAutonomousDriveOntoChargeStationAndBalance m_autoAutonomous{&m_subDriveTrain, &m_autoTimer};
  AutoCmdAutonomousDoNothing m_autoAutonomousDoNothing{};
  AutoCmdAutonomousDriveOutOfCommunity m_autoAutonomousDriveOutOfCommunity{&m_subDriveTrain, &m_autoTimer};
  AutoCmdAutonomousDriveOverAndOntoChargeStation m_autoAutonomousDriveOverAndOntoChargeStation{&m_subDriveTrain, &m_autoTimer};
  AutoCmdAutonomousPlaceCube m_autoAutonomousPlaceCube{&m_subVerticalElevator, &m_subTurret, &m_subHorizontalElevator, &m_subClawWrist, &m_autoTimer};
  AutoCmdAutonomousPlaceCubeAndDriveOntoChargeStation m_autoAutonomousPlaceCubeAndDriveOntoChargeStation{&m_subVerticalElevator, &m_subTurret, &m_subHorizontalElevator, &m_subClawWrist, &m_subDriveTrain, &m_autoTimer};
  AutoCmdAutonomousPlaceCubeAndDriveOverAndOntoRamp m_autoAutonomousPlaceCubeAndDriveOverAndOntoChargeStation{&m_subVerticalElevator, &m_subTurret, &m_subHorizontalElevator, &m_subClawWrist, &m_subDriveTrain, &m_autoTimer};

  frc::SendableChooser<frc2::Command*> m_autoChooser;
  frc::SendableChooser<frc2::Command*> m_pieceToAutoPlace;
  
  // Replace with CommandPS4Controller or CommandJoystick if needed
  //frc2::CommandXboxController m_driverController{
  //    OperatorConstants::kDriverControllerPort};

 
  // The robot's subsystems are defined here...
  SubRobotGlobals m_subRobotGlobals;
  ExampleSubsystem m_subsystem;
  SubDriveTrain m_subDriveTrain;
  SubLimeLightLower m_subLimeLightLower;
  SubLimeLightUpper m_subLimeLightUpper;
  SubLimeLightSwitcher m_subLimeLightSwitcher;
  SubTurret m_subTurret;
  SubVerticalElevator m_subVerticalElevator;
  SubHorizontalElevator m_subHorizontalElevator;
  SubPneumatics m_subPneumatics;
  SubClawWrist m_subClawWrist;

    // Setup driver controller
//  frc::Joystick *driverController = new frc::Joystick(DRIVER_CONTROLLER);
  frc2::CommandXboxController driverController{DRIVER_CONTROLLER};

  frc2::Trigger driverController_button_a = driverController.A();
  frc2::Trigger driverController_button_b = driverController.B();
  frc2::Trigger driverController_button_x = driverController.X();
  frc2::Trigger driverController_button_y = driverController.Y();
  frc2::Trigger driverController_button_lbump = driverController.LeftBumper();
  frc2::Trigger driverController_button_rbump = driverController.RightBumper();
  frc2::Trigger driverController_button_back = driverController.Back();
  frc2::Trigger driverController_button_start = driverController.Start();
  frc2::Trigger driverController_button_l3 = driverController.LeftStick();
  frc2::Trigger driverController_button_r3 = driverController.RightStick();

  // LEFT TRIGGER // Drive Backwards use driverController->GetRawAxis(AXIS_L_TRIG)
  // RIGHT TRIGGER // Drive Forwards use driverController->GetRawAxis(AXIS_R_TRIG)
  // LEFT STICK LEFT // Turn Left driverController->GetRawAxis(AXIS_LX)
  // LEFT STICK RIGHT // Turn Right driverController->GetRawAxis(AXIS_LX)
  /*
  frc2::JoystickButton *driverController_button_a = new frc2::JoystickButton(driverController, BUTTON_A); // Acquire target to shoot
  frc2::JoystickButton *driverController_button_b = new frc2::JoystickButton(driverController, BUTTON_B); // Virtul low gear
  frc2::JoystickButton *driverController_button_x = new frc2::JoystickButton(driverController, BUTTON_X); // Index to shooter
  frc2::JoystickButton *driverController_button_y = new frc2::JoystickButton(driverController, BUTTON_Y); // Intake ball
  frc2::JoystickButton *driverController_button_lbump = new frc2::JoystickButton(driverController, BUTTON_L_BUMP); // Shift gears
  frc2::JoystickButton *driverController_button_rbump = new frc2::JoystickButton(driverController, BUTTON_R_BUMP); // Aim drive train towards ball for intake
  frc2::JoystickButton *driverController_button_back = new frc2::JoystickButton(driverController, BUTTON_SELECT); // Not Used 
  frc2::JoystickButton *driverController_button_start = new frc2::JoystickButton(driverController, BUTTON_START); // Not Used
  frc2::JoystickButton *driverController_button_l3 = new frc2::JoystickButton(driverController, BUTTON_L3); // Not Used
  frc2::JoystickButton *driverController_button_r3 = new frc2::JoystickButton(driverController, BUTTON_R3); // Not Used
*/
  // Setup auxilary controller   
//  frc::Joystick *auxController = new frc::Joystick(AUX_CONTROLLER);
  frc2::CommandXboxController auxController{AUX_CONTROLLER};

  frc2::Trigger auxController_button_a = auxController.A();
  frc2::Trigger auxController_button_b = auxController.B();
  frc2::Trigger auxController_button_x = auxController.X();
  frc2::Trigger auxController_button_y = auxController.Y();
  frc2::Trigger auxController_button_lbump = auxController.LeftBumper();
  frc2::Trigger auxController_button_rbump = auxController.RightBumper();
  frc2::Trigger auxController_button_back = auxController.Back();
  frc2::Trigger auxController_button_start = auxController.Start();
  frc2::Trigger auxController_button_l3 = auxController.LeftStick();
  frc2::Trigger auxController_button_r3 = auxController.RightStick();
  /*
  frc2::JoystickButton *auxController_button_a = new frc2::JoystickButton(auxController, BUTTON_A);  
  frc2::JoystickButton *auxController_button_b = new frc2::JoystickButton(auxController, BUTTON_B); 
  frc2::JoystickButton *auxController_button_x = new frc2::JoystickButton(auxController, BUTTON_X); 
  frc2::JoystickButton *auxController_button_y = new frc2::JoystickButton(auxController, BUTTON_Y); 
  frc2::JoystickButton *auxController_button_lbump = new frc2::JoystickButton(auxController, BUTTON_L_BUMP); 
  frc2::JoystickButton *auxController_button_rbump = new frc2::JoystickButton(auxController, BUTTON_R_BUMP); 
  frc2::JoystickButton *auxController_button_select = new frc2::JoystickButton(auxController, BUTTON_SELECT); 
  frc2::JoystickButton *auxController_button_start = new frc2::JoystickButton(auxController, BUTTON_START); 
  frc2::JoystickButton *auxController_button_l3 = new frc2::JoystickButton(auxController, BUTTON_L3); 
  frc2::JoystickButton *auxController_button_r3 = new frc2::JoystickButton(auxController, BUTTON_R3);   
  */

  void ConfigureBindings();

// Autonomous fixed vaaraiables for all routines
double m_autoTimeDuration = 10; // ms between calculated motion profile trajectories
// Step time between calculations
double m_autoRoutineTimeStep = 0.001;
// Use the VELOCITY_MAX above of the max velocity of the autonomous routines
double m_autoRoutineVelocityMax = VELOCITY_MAX;
// Max acceleration used in autonomous routines
double m_autoAccelerationMax = 1000;
// Max Jerk used in autonomous routines
double m_autoJerkMax = 12800;
// The counts per foot when in a particular gear
double m_autoEncoderCountsPerFt = 2048;  // This needs to be tested
// wheel base distance
double m_autoWheelbaseWidth = 2;
// int for choosing piece to place in auto true is cone false is cube
bool pieceToPlaceInAuto = false;

// Autonomous routine 1 declaration
int m_autoRoutineLength1 = 3;
// Number of field positions needs to match the above length for the routine
Waypoint m_autoRoutinePoints1[3] = {
   //x, y, angle  field positions in encoder counts 1ft = ???counts
   { 0, 0, 0 },
   { 2048, 0, 0 },
   { 4096, 0, 0 }};

};
