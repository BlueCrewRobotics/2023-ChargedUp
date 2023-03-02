/*-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=*/
/*                       Blue Crew Robotics #6153                             */
/*                            Charged Up 2023                                 */
/*-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=*/
// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#include "subsystems/SubLimeLightSwitcher.h"

SubLimeLightSwitcher::SubLimeLightSwitcher() = default;

// This method will be called once per scheduler run
void SubLimeLightSwitcher::Periodic() {
    if (m_subVerticalElevator->GetPosition() > VERTICAL_ELEV_POS_SWITCH_LIMELGIHT_THRESHOLD) {
        tblLimeLight = nt::NetworkTableInstance::GetDefault().GetTable("limelight-lower");
    }
    else {
        tblLimeLight = nt::NetworkTableInstance::GetDefault().GetTable("limelight-upper");
    }
}

double SubLimeLightSwitcher::GetDistanceToTarget(double h2_heightOfCenterTarget)  {  
  double d = 0.0;
  
  double h1_heightOfCamera = 0.0;
  double a1_angleOfCamera = 0.0;
  if(tblLimeLight == nt::NetworkTableInstance::GetDefault().GetTable("limelight-lower")) {
    h1_heightOfCamera = LL_LIMELIGHT_LOWER_HEIGHT;
    a1_angleOfCamera = LL_LIMELIGHT_LOWER_ANGLE;
  }
  else if(tblLimeLight == nt::NetworkTableInstance::GetDefault().GetTable("limelight-upper")) {
    h1_heightOfCamera = LL_LIMELIGHT_UPPER_HEIGHT;
    a1_angleOfCamera = LL_LIMELIGHT_UPPER_ANGLE;
  }
  else {
    return d;
  }
  double a2 = tblLimeLight->GetNumber("ty",0.0);
  
  d = (h2_heightOfCenterTarget-h1_heightOfCamera) / (tan((a1_angleOfCamera + a2)*3.1416/180));
  
  return d;
}
