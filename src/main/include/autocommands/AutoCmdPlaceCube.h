// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#pragma once

#include <frc2/command/CommandBase.h>
#include <frc2/command/CommandHelper.h>

#include <frc/Timer.h>

#include "subsystems/SubClawWrist.h"
#include "subsystems/SubTurret.h"
#include "subsystems/SubHorizontalElevator.h"
#include "subsystems/SubVerticalElevator.h"

/**
 * An example command.
 *
 * <p>Note that this extends CommandHelper, rather extending CommandBase
 * directly; this is crucially important, or else the decorator functions in
 * Command will *not* work!
 */
class AutoCmdPlaceCube
    : public frc2::CommandHelper<frc2::CommandBase, AutoCmdPlaceCube> {
 public:
  AutoCmdPlaceCube(SubVerticalElevator* subVerticalElevator, SubTurret* subTurret, SubHorizontalElevator* subHorizontalElevator, SubClawWrist* subClawWrist, frc::Timer* timer);

  void Initialize() override;

  void Execute() override;

  void End(bool interrupted) override;

  bool IsFinished() override;

 private:
  SubVerticalElevator* m_subVerticalElevator;
  SubTurret* m_subTurret;
  SubHorizontalElevator* m_subHorizontalElevator;
  SubClawWrist* m_subClawWrist;
  frc::Timer* m_timer;

  bool m_verticalElevatorIsUp = false;
  bool m_turretIsTurned = false;
  bool m_horizontalElevatorIsOut = false;
  bool m_WristIsDown = false;
  bool m_cubeIsPlaced = false;
  bool m_finished = false;
};
