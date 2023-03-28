// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#pragma once

#include <frc2/command/CommandBase.h>
#include <frc2/command/CommandHelper.h>

#include <frc2/command/button/CommandXboxController.h>
#include "Constants/ConsControllers.h"

#include "subsystems/SubClawWrist.h"
#include "subsystems/SubHorizontalElevator.h"
#include "subsystems/SubTurret.h"
#include "subsystems/SubVerticalElevator.h"

/**
 * An example command.
 *
 * <p>Note that this extends CommandHelper, rather extending CommandBase
 * directly; this is crucially important, or else the decorator functions in
 * Command will *not* work!
 */
class CmdTurretAndElevatorsServoToHome
    : public frc2::CommandHelper<frc2::CommandBase, CmdTurretAndElevatorsServoToHome> {
 public:
  CmdTurretAndElevatorsServoToHome(SubClawWrist* subClawWrist, SubHorizontalElevator* subHorizontalElevator, SubTurret* subTurret, SubVerticalElevator* subVerticalElevator, frc2::CommandXboxController* auxController);

  void Initialize() override;

  void Execute() override;

  void End(bool interrupted) override;

  bool IsFinished() override;
 private:
  SubClawWrist* m_subClawWrist;
  SubHorizontalElevator* m_subHorizontalElevator;
  SubTurret* m_subTurret;
  SubVerticalElevator* m_subVerticalElevator;
  frc2::CommandXboxController* m_auxController;

  bool m_wristIsHome = false;
  bool m_horizontalElevatorIsHome = false;
  bool m_turretIsHome = false;
  bool m_verticalElevatorIsHome = false;
  bool m_finished = false;
};
