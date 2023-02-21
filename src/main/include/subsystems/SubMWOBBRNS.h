// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#pragma once

#include <frc2/command/SubsystemBase.h>
#include <frc/Solenoid.h>

#include "Constants.h"

class SubMWOBBRNS : public frc2::SubsystemBase {
 public:
  SubMWOBBRNS();

  /**
   * Will be called periodically whenever the CommandScheduler runs.
   */
  void Periodic() override;
  void ExtensionToggle();

 private:
  // Components (e.g. motor controllers and sensors) should generally be
  // declared private and exposed only through public methods.
  frc::Solenoid* m_pistons = new frc::Solenoid(PCM_0,frc::PneumaticsModuleType::CTREPCM,PCM_1_MWOBBRNS);
};
