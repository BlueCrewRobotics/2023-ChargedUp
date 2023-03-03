/*-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=*/
/*                       Blue Crew Robotics #6153                             */
/*                            Charged Up 2023                                 */
/*-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=*/
// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#pragma once

#include <frc2/command/SubsystemBase.h>
#include <frc/smartdashboard/SmartDashboard.h>
#include <networktables/NetworkTable.h>
#include <networktables/NetworkTableInstance.h>
#include "Constants/ConsLimeLights.h"

//#include "SubVerticalElevator.h"
#include "SubLimeLightBase.h"


class SubLimeLightSwitcher : public SubLimeLightBase {
 public:
  SubLimeLightSwitcher();

  /**
   * Will be called periodically whenever the CommandScheduler runs.
   */
//  void Periodic() override;

//  double GetDistanceToTargetS(double h2_heightOfTarget);
// private:
  // Components (e.g. motor controllers and sensors) should generally be
  // declared private and exposed only through public methods.

//  SubVerticalElevator* m_subVerticalElevator;

//  bool m_usingUpperLimeLight = true;
};

