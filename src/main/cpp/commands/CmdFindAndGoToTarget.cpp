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
#include "subsystems/SubLimeLightUpper.h"
#include "Constants.h"

CmdFindAndGoToTarget::CmdFindAndGoToTarget(SubDriveTrain* driveTrain, SubLimeLightUpper* LimeLightUpper, frc2::CommandXboxController* driverController) 
  : m_driveTrain{driveTrain}, m_LimeLightUpper{LimeLightUpper}, m_driverController{driverController} {
  // Use addRequirements() here to declare subsystem dependencies.
  AddRequirements(LimeLightUpper);  
}

// Called when the command is initially scheduled.
void CmdFindAndGoToTarget::Initialize() {
  
}

// Called repeatedly when this Command is scheduled to run
void CmdFindAndGoToTarget::Execute() {
  // Define rotation for driving
  double rotation = 0.0;

  std::cout << "Finding Target!" << std::endl;

  // If BUTTONT_SELLECT (back button on xbox controller) is pressed, exit the command

  // Check if limelight has found a target
  if (m_LimeLightUpper->GetTarget()) {
    std::cout << "see target!" << std::endl;

    // Select the tollerence (in degrees) of the angle toward the target based on distance (in feet)
    double dist = getDistanceToTarget();
    int angleTolerance = 2;
    int angleOffset = 3;
    if(dist < 10) {
      angleTolerance = 2;
      angleOffset = 6;
    }
    if(dist < 6) {
      angleTolerance = 1;
      angleOffset = 8.5;
    }

    int desiredHeadingAngle = m_LimeLightUpper->GetHorizontalOffset() + angleOffset;

    // Turn towards target
    if (desiredHeadingAngle < -angleTolerance) {
      std::cout << "moving left to target!" << std::endl;
      rotation = -0.34;
      // Slow down the turning once we get close
      if(dist < 5.5)
        rotation = rotation * 0.8;
    }
    else if (desiredHeadingAngle > angleTolerance) {
      std::cout << "moving right to target!" << std::endl;
      rotation = 0.34;
      // Slow down the turning once we get close
      if(dist < 5.5)
        rotation = rotation * 0.8;
    
    }
  }


  // Pass speed and rotation to the drive train
  m_driveTrain->SetDirectedRotation(rotation);

  // set m_finished to true if x or y aren't pressed
  if(!m_driverController->GetXButton() && !m_driverController->GetYButton()) {
    m_finished = true;
  }
  else {
    m_finished = false;
  }

}

double CmdFindAndGoToTarget::getDistanceToTarget() {
  return m_LimeLightUpper->GetDistanceToTarget();
}

// Called once the command ends or is interrupted.
void CmdFindAndGoToTarget::End(bool interrupted) {
  m_driveTrain->SetDirectedRotation(0.0);
}

// Returns true when the command should end.
bool CmdFindAndGoToTarget::IsFinished() {
  return false;
}

