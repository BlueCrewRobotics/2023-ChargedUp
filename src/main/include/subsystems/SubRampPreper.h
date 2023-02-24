// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#pragma once

#include <frc2/command/SubsystemBase.h>
#include <frc/Solenoid.h>

#include "Constants/ConsRampPreper.h"
#include "Constants/ConsPneumatics.h"
class SubRampPreper : public frc2::SubsystemBase {
 public:
  SubRampPreper();

  /**
   * Will be called periodically whenever the CommandScheduler runs.
   */
  void Periodic() override;
  void ExtensionToggle();

 private:
  // Components (e.g. motor controllers and sensors) should generally be
  // declared private and exposed only through public methods.
  frc::Solenoid* m_pistons = new frc::Solenoid(PNEUMATIC_HUB_ADDR,frc::PneumaticsModuleType::REVPH,PH_1_RAMP_PREPER_SOLENOID);
};
