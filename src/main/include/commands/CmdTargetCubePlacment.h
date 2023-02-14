// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#pragma once

#include <frc2/command/CommandBase.h>
#include <frc2/command/CommandHelper.h>
#include <frc/Joystick.h>
#include <frc2/command/button/CommandXboxController.h>
#include <frc/DriverStation.h>
#include <frc/util/Color.h>

#include "subsystems/SubLimeLightUpper.h"
#include "subsystems/SubLimeLightLower.h"
#include "subsystems/SubDriveTrain.h"
#include "Constants.h"


/**
 * An example command.
 *
 * <p>Note that this extends CommandHelper, rather extending CommandBase
 * directly; this is crucially important, or else the decorator functions in
 * Command will *not* work!
 */
class CmdTargetCubePlacment
    : public frc2::CommandHelper<frc2::CommandBase, CmdTargetCubePlacment> {
 public:
  CmdTargetCubePlacment(SubDriveTrain* driveTrain, SubLimeLightLower* LimeLightLower, SubLimeLightUpper* LimeLightUpper, frc2::CommandXboxController* auxController);

  void Initialize() override;

  void Execute() override;
  

  void End(bool interrupted) override;

  bool IsFinished() override;

 protected:
  SubDriveTrain* m_driveTrain;
  SubLimeLightUpper* m_limeLightUpper;
  SubLimeLightLower* m_limeLightLower;
  frc2::CommandXboxController* m_auxController;
  bool m_finished = false;
  int m_povPosition = 0;
  int m_aprilTagID = 0;
};
