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
class AutoCmdTurnAround
    : public frc2::CommandHelper<frc2::CommandBase, AutoCmdTurnAround> {
 public:
  AutoCmdTurnAround(SubDriveTrain* SubDriveTrain);

  void Initialize() override;

  void Execute() override;

  void End(bool interrupted) override;

  bool IsFinished() override;
 
 private:
  SubDriveTrain* m_driveTrain;
  bool m_finished = false;
  double m_initialYaw = 0.0;
  double m_turnedAroundYaw = 0.0;
};
