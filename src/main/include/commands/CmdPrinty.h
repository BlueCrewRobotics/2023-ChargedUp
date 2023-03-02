/*-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=*/
/*                       Blue Crew Robotics #6153                             */
/*                            Charged Up 2023                                 */
/*-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=*/
// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#pragma once

#include <frc2/command/CommandBase.h>
#include <frc2/command/CommandHelper.h>
#include <frc2/command/button/CommandXboxController.h>

#include "subsystems/SubDriveTrain.h"
#include "subsystems/SubTurret.h"
#include "subsystems/SubHorizontalElevator.h"
#include "subsystems/SubLimeLightLower.h"
#include "subsystems/SubLimeLightUpper.h"
#include "subsystems/SubLimeLightSwitcher.h"
#include <frc/Joystick.h>
//#include "common/BC_TriggerCal.h"

/**
 * An example command.
 *
 * <p>Note that this extends CommandHelper, rather extending CommandBase
 * directly; this is crucially important, or else the decorator functions in
 * Command will *not* work!
 */
class CmdPrinty
    : public frc2::CommandHelper<frc2::CommandBase, CmdPrinty> {
 public:
  CmdPrinty(SubDriveTrain* driveTrain, SubTurret* subTurret, SubHorizontalElevator* subHorizontalElevator, SubLimeLightLower* subLimeLightLower, SubLimeLightUpper* subLimeLightUpper, SubLimeLightSwitcher* subLimeLightSwitcher, frc2::CommandXboxController *driverController);

  void Initialize() override;

  void Execute() override;

  void End(bool interrupted) override;

  bool IsFinished() override;

 private:
  bool m_isFinished = false;
  SubDriveTrain* m_driveTrain;
  SubTurret* m_subTurret;
  SubHorizontalElevator* m_subHorizontalElevator;
  SubLimeLightLower* m_subLimeLightLower;
  SubLimeLightUpper* m_subLimeLightUpper;
  SubLimeLightSwitcher* m_subLimeLightSwitcher;
  frc2::CommandXboxController* m_driverController;
};

