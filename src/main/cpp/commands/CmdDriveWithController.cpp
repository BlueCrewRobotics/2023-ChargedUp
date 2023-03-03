/*-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=*/
/*                       Blue Crew Robotics #6153                             */
/*                            Charged Up 2023                                 */
/*-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=*/
// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#include <iostream>
#include <stdio.h>
#include "commands/CmdDriveWithController.h"

CmdDriveWithController::CmdDriveWithController(SubDriveTrain* driveTrain, frc2::CommandXboxController* driverController) 
  : m_driveTrain{driveTrain}, m_driverController{driverController} {
  // Use addRequirements() here to declare subsystem dependencies.
  AddRequirements(driveTrain);

}

// Called when the command is initially scheduled.
void CmdDriveWithController::Initialize() {
  m_driveTrain->ZeroYaw();
}

// Called repeatedly when this Command is scheduled to run
void CmdDriveWithController::Execute() {

//  std::cout << "CmdDriveWithController>> ------------------------------" << std::endl;

  // speed as a percentage
  double speed = 0.0;
  // This sets up the virtual low gear
  if(m_driverController->GetRawButton(BUTTON_B)==1) {
    m_driveTrain->SetMaxSpeed(VELOCITY_SP_MAX_LL);
  }
  else {
    m_driveTrain->SetMaxSpeed(VELOCITY_SP_MAX_LG);

  }

  // This is controlling the speed of the drive train
  if(m_driverController->GetRawAxis(AXIS_R_TRIG) > 0) {
    // percentage controller axis is activated
    speed = -1*m_driverController->GetRawAxis(AXIS_R_TRIG);
  }
  else { // jhouse: is it safe to assume the L axis is really exactly 'zero' when not pressed by human?  robot could falsely move a bit otherwise
    // percentage controller axis is activated
    speed = m_driverController->GetRawAxis(AXIS_L_TRIG);
  }

  // This is the steering section of the drive train
  double rotation = 0.0;

  // Check if we want to auto-target using the limelight
/*  if(m_driverController->GetRawButton(BUTTON_X) == true || m_driverController->GetRawButton(BUTTON_Y) == true) {
    // Set the rotation to the rotation the limelight gives us
    rotation = m_driveTrain->GetDirectedRotation();
  }
  // Else use the navX to drive straight
  else */{
    // Booleans for detecting if we want the robot to move
    bool isMoveDesired = (speed > 0.02 || speed < -0.02);
    bool isTurnDesired = (m_driverController->GetRawAxis(AXIS_LX) > 0.02 || m_driverController->GetRawAxis(AXIS_LX) < -0.02);

    // is the controller telling us to turn?
    if(isTurnDesired) {
      // Store the yaw straight value while steering the robot.
      m_driveTrain->SetYawStraightValue(m_driveTrain->GetYaw());
  //    std::cout << "CmdDriveWithController>> Updated desired yaw to: " << m_driveTrain->GetYawStraightValue() << std::endl;

      rotation = m_driverController->GetRawAxis(AXIS_LX)*0.7;

  //    std::cout << "CmdDriveWithController>> Rotation set to: " << rotation << " Yaw is: " << m_driveTrain->GetYaw() << std::endl;
    }
    // Drive straight by comparing the stored yaw to the actual navx2 yaw reading
    else if(isMoveDesired) {    
    
  //    std::cout << "CmdDriveWithController>> headingError is: " << headingError  << std::endl;

      double headingError = m_driveTrain->GetYawStraightValue() - m_driveTrain->GetYaw();
      if (headingError > 180) {
        headingError = -(headingError - 360);
      }
      else if (headingError < -180) {
        headingError = -(headingError + 360);
      }

      if(headingError > 0.0) {
        // Normalize for quadrant I
        rotation = (1.0 - ((180.0-(headingError))/180.0));
        if(headingError > 5) {
         // std::cout << "CmdDriveWithController>> headingError is: " << headingError  << std::endl;
        }
      }
      if(headingError  < 0.0) {
        // Normailize for quadrant II
        rotation = (-1.0 + (180.0+(headingError))/180.0);
        if(headingError < -5) {
         // std::cout << "CmdDriveWithController>> headingError is: " << headingError  << std::endl;
        }
      }
      
      // Correct for quadrents III and IV
      if(rotation > 1.0) {
        rotation = (rotation - 1.0) * -1.0;
        if(rotation > 1.0) {
          //std::cout << "CmdDriveWithController>> ****** Wooooooo"  << std::endl;
        }
      }
      else if(rotation < -1.0) {
        rotation = (rotation + 1.0) * -1.0;
        if(rotation < -1.0) {
          //std::cout << "CmdDriveWithController>> ****** Wooooooo"  << std::endl;
        }
      }

      // catch and avoid erratic jumps
      if(headingError > 300)
        rotation = -0.2;
      else if(headingError < -300)
        rotation = 0.2;

      // Add offset if needed
      if(rotation > 0.0 && rotation < 0.2) {
        rotation = rotation + 0.07;
      }
      else if(rotation < 0.0 && rotation > -0.2) {
        rotation = rotation - 0.07;
      }
      //std::cout << "CmdDriveWithController>> Rotation set to: " << rotation << " Yaw is: " << m_driveTrain->GetYaw() << " Goal-Yaw is: " << m_driveTrain->GetYawStraightValue() << std::endl;
    }

  }

  //std::cout << "current pitch: " << m_driveTrain->GetPitch() << std::endl;
  //std::cout << "current roll: " << m_driveTrain->GetRoll() << std::endl;
  //std::cout << "current yaw: " << m_driveTrain->GetYaw() << std::endl;

  // This actually drives the drive train
  m_driveTrain->Drive(speed, rotation);
}

// Called once the command ends or is interrupted.
void CmdDriveWithController::End(bool interrupted) {}

// Returns true when the command should end.
bool CmdDriveWithController::IsFinished() {
  return false;
}
