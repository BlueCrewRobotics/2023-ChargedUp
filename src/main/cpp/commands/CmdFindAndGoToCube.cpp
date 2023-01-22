// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#include <stdio.h>
#include <iostream>

#include "commands/CmdFindAndGoToCube.h"
#include "subsystems/SubLimeLight.h"
#include "Constants.h"

CmdFindAndGoToCube::CmdFindAndGoToCube(SubDriveTrain* driveTrain, SubLimeLight* limeLight,  frc::Joystick *driverController) 
  : m_driveTrain{driveTrain}, m_limeLight{limeLight}, m_driverController{driverController} {
  // Use addRequirements() here to declare subsystem dependencies.
  AddRequirements(driveTrain);
  AddRequirements(limeLight);  
}

// Called when the command is initially scheduled.
void CmdFindAndGoToCube::Initialize() {
  m_limeLight->SelectPipeline(LL_PIPELINE_PURPLE_CUBE_NUMBER);
}

// Called repeatedly when this Command is scheduled to run
void CmdFindAndGoToCube::Execute() {
  // Define speed and rotation for driving
  double speed = 0.0;
  double rotation = 0.0;

  std::cout << "Finding Cube!" << std::endl;

  if(m_driverController->GetRawButton(BUTTON_SELECT)==1) {
    m_isFinished = true;
  }
  else {
    // Check if limelight has found a target
    if (m_limeLight->GetTarget()) {
      std::cout << "see target!" << std::endl;
      double dist = m_limeLight->GetDistanceToPurpleCubeTarget();
      int angleTolerance = 3;
      if(dist < 10)
        angleTolerance = 4;
      if(dist < 6)
        angleTolerance = 5;

      // Turn towards target
      if (m_limeLight->GetHorizontalOffset() < -angleTolerance) {
        std::cout << "moving left to target!" << std::endl;
        rotation = -0.34;
        speed = 0.0;
      }
      else if (m_limeLight->GetHorizontalOffset() > angleTolerance) {
        std::cout << "moving right to target!" << std::endl;
        rotation = 0.34;
        speed = 0.0;
      }
      else if (dist > 4.5) {
         std::cout << "moving forward to target!" << std::endl;
        rotation = 0.0;
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
        rotation = 0.3;
        speed = 0.0;
    }
  }

  m_driveTrain->Drive(speed, rotation);

}

// Called once the command ends or is interrupted.
void CmdFindAndGoToCube::End(bool interrupted) {}

// Returns true when the command should end.
bool CmdFindAndGoToCube::IsFinished() {
  if(m_isFinished) {
    std::cout << "Find Cube FINISHED!" << std::endl;
    m_isFinished = false;
    return true;
  }
  return false;
}

