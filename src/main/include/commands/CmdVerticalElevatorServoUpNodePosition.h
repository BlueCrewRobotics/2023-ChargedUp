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

#include <frc/Joystick.h>
//#include "common/BC_TriggerCal.h"
#include "subsystems/SubVerticalElevator.h"

/**
 * An example command.
 *
 * <p>Note that this extends CommandHelper, rather extending CommandBase
 * directly; this is crucially important, or else the decorator functions in
 * Command will *not* work!
 */
class CmdVerticalElevatorServoUpNodePosition
    : public frc2::CommandHelper<frc2::CommandBase, CmdVerticalElevatorServoUpNodePosition> {
 public:
  CmdVerticalElevatorServoUpNodePosition(SubVerticalElevator* subVerticalElevator, frc2::CommandXboxController *auxController);

  void Initialize() override;

  void Execute() override;

  void End(bool interrupted) override;

  bool IsFinished() override;

 private:
  bool m_isFinished = false;
  frc2::CommandXboxController* m_auxController;
  SubVerticalElevator* m_subVerticalElevator;
};

