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
