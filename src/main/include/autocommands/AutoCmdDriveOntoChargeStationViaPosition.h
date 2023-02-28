/*-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=*/
/*                       Blue Crew Robotics #6153                             */
/*                            Charged Up 2023                                 */
/*-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=*/
// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

/* This is a command for autonomous that watches
 * the pitch from the navx to drive onto the ChargeStation
 * and stay balanced on it.                    */
#pragma once

#include <frc2/command/CommandBase.h>
#include <frc2/command/CommandHelper.h>

// Subsystem Includes
#include <subsystems/SubDriveTrain.h>


/**
 * An example command.
 *
 * <p>Note that this extends CommandHelper, rather extending CommandBase
 * directly; this is crucially important, or else the decorator functions in
 * Command will *not* work!
 */
class AutoCmdDriveOntoChargeStationViaPosition
    : public frc2::CommandHelper<frc2::CommandBase, AutoCmdDriveOntoChargeStationViaPosition> {
 public:
  AutoCmdDriveOntoChargeStationViaPosition(SubDriveTrain* subDriveTrain);

  void Initialize() override;

  void Execute() override;

  void End(bool interrupted) override;

  bool IsFinished() override;
 
 private:
  SubDriveTrain* m_driveTrain;
  double m_levelPitchValue = 0.0;
  double m_wellOntoRampPitchValue = 0;
  bool m_onChargeStation = false;
  bool m_startedDropping = false;
  bool m_finished = false;
  frc::Timer m_timer;
};
