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
#include "commands/CmdFindAndGoToCube.h"
#include "subsystems/SubLimeLightUpper.h"

CmdFindAndGoToCube::CmdFindAndGoToCube(SubDriveTrain* driveTrain, SubLimeLightUpper* LimeLightUpper, frc2::CommandXboxController* driverController) 
  : CmdFindAndGoToTarget(driveTrain, LimeLightUpper, driverController) {
}

// Called when the command is initially scheduled.
void CmdFindAndGoToCube::Initialize() {
  // Set the limelight pipeline to the purple cube pipeline
  m_LimeLightUpper->SelectPipeline(LL_PIPELINE_PURPLE_CUBE_NUMBER);  
  m_targetType = TID_PURPLE_CUBE_ID;
}
