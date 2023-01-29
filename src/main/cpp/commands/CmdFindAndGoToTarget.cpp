/*-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=*/
/*                       Blue Crew Robotics #6153                             */
/*                           Charged Up 2023                                 */
/*-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=*/
// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.


/* Generic code for finding and driving towards a target
 * Commands that find and go to specific targets (purple cubes, yellow cones, etc.)
 * should inherit from this
*/

#include <stdio.h>
#include <iostream>

#include "commands/CmdFindAndGoToTarget.h"
#include "subsystems/SubLimeLight.h"
#include "Constants.h"

CmdFindAndGoToTarget::CmdFindAndGoToTarget(SubDriveTrain* driveTrain, SubLimeLight* limeLight,  frc::Joystick *driverController) 
  : m_driveTrain{driveTrain}, m_limeLight{limeLight}, m_driverController{driverController} {
  // Use addRequirements() here to declare subsystem dependencies.
  AddRequirements(driveTrain);
  AddRequirements(limeLight);  
}

// Called when the command is initially scheduled.
void CmdFindAndGoToTarget::Initialize() {
  
}

// Called repeatedly when this Command is scheduled to run
void CmdFindAndGoToTarget::Execute() {
  // Define speed and rotation for driving
  double speed = 0.0;
  double rotation = 0.0;

  std::cout << "Finding Target!" << std::endl;

  // If BUTTONT_SELLECT (back button on xbox controller) is pressed, exit the command
  if(m_driverController->GetRawButton(BUTTON_SELECT)==1) {
    m_isFinished = true;
  }
  else {
    // Check if limelight has found a target
    if (m_limeLight->GetTarget()) {
      std::cout << "see target!" << std::endl;

      // Select the tollerence (in degrees) of the angle toward the target based on distance (in feet)
      double dist = getDistanceToTarget();
      int angleTolerance = 2;
      if(dist < 10)
        angleTolerance = 2;
      if(dist < 6)
        angleTolerance = 1;

      // Turn towards target
      if (m_limeLight->GetHorizontalOffset() < -angleTolerance) {
        std::cout << "moving left to target!" << std::endl;
        rotation = -0.34;
        // Slow down the turning once we get close
        if(dist < 5.5)
          rotation = rotation * 0.8;
      }
      else if (m_limeLight->GetHorizontalOffset() > angleTolerance) {
        std::cout << "moving right to target!" << std::endl;
        rotation = 0.34;
        // Slow down the turning once we get close
        if(dist < 5.5)
          rotation = rotation * 0.8;
      }
      
      if (dist > 4.5) {
        std::cout << "moving forward to target!" << std::endl;
        //rotation = 0.0;
        speed = -0.65;
        if(dist < 5.5)
          speed = -0.4;
      }
      else {
        m_isFinished = true;
      }

    }
    else {
        std::cout << "scanning for target!" << std::endl;
        // Turn right on the spot slowly if no target is found to scan
        rotation = 0.3;
        speed = 0.0;
    }
  }

  // Pass speed and rotation to the drive train
  m_driveTrain->Drive(speed, rotation);

}

double CmdFindAndGoToTarget::getDistanceToTarget() {
  return m_limeLight->GetDistanceToTarget();
}

// Called once the command ends or is interrupted.
void CmdFindAndGoToTarget::End(bool interrupted) {}

// Returns true when the command should end.
bool CmdFindAndGoToTarget::IsFinished() {
  if(m_isFinished) {
    std::cout << "Find Target FINISHED!" << std::endl;
    m_isFinished = false;
    return true;
  }
  return false;
}

