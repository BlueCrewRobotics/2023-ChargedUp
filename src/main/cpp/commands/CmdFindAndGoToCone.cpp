/*-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=*/
/*                       Blue Crew Robotics #6153                             */
/*                           Charged Up 2023                                 */
/*-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=*/
// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.


/****** This Command Inherits from CmdFindAndGoToTarget ******/

#include <stdio.h>
#include <iostream>

#include "commands/CmdFindAndGoToTarget.h"
#include "commands/CmdFindAndGoToCone.h"
#include "subsystems/SubLimeLightUpper.h"
#include "Constants.h"

CmdFindAndGoToCone::CmdFindAndGoToCone(SubDriveTrain* driveTrain, SubLimeLightUpper* LimeLightUpper,  frc::Joystick *driverController) 
  : CmdFindAndGoToTarget(driveTrain, LimeLightUpper, driverController) {
}

// Called when the command is initially scheduled.
void CmdFindAndGoToCone::Initialize() {
  // Set the limelight Piepline to the yellow cone pipeline
  m_LimeLightUpper->SelectPipeline(LL_PIPELINE_YELLOW_CONE_NUMBER);  
}
