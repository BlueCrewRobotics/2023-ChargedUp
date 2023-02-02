// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#pragma once

#include <frc2/command/SubsystemBase.h>
#include <frc/Solenoid.h>
#include "Constants.h"

class SubConeRampPrep : public frc2::SubsystemBase {
 public:
  SubConeRampPrep();

  // Extend and retract the subsytem for cone and ramp prepping
  void SetPrepConeRampPosition(bool state);

  /**
   * Will be called periodically whenever the CommandScheduler runs.
   */
  void Periodic() override;

 private:
 frc::Solenoid *m_prepSolenoid = new frc::Solenoid(PCM_0, frc::PneumaticsModuleType::CTREPCM, PCM_1_PREP_CONERAMP);
  // Components (e.g. motor controllers and sensors) should generally be
  // declared private and exposed only through public methods.
};
