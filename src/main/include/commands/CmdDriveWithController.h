/*-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=*/
/*                       Blue Crew Robotics #6153                             */
/*                           Rapid React 2022                                 */
/*-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=*/

#pragma once

#include <frc2/command/CommandBase.h>
#include <frc2/command/CommandHelper.h>

#include "subsystems/SubDriveTrain.h"
#include <frc/Joystick.h>
#include "common/BC_TriggerCal.h"

/**
 * An example command.
 *
 * <p>Note that this extends CommandHelper, rather extending CommandBase
 * directly; this is crucially important, or else the decorator functions in
 * Command will *not* work!
 */
class CmdDriveWithController
    : public frc2::CommandHelper<frc2::CommandBase, CmdDriveWithController> {
 public:
  CmdDriveWithController(SubDriveTrain* driveTrain, frc::Joystick *driverController);

  void Initialize() override;

  void Execute() override;

  void End(bool interrupted) override;

  bool IsFinished() override;

 private:
  SubDriveTrain* m_driveTrain;
  frc::Joystick* m_driverController;
  BC_TriggerCal m_lReverseTriggerCal = BC_TriggerCal(true);
  BC_TriggerCal m_rForwardTiggerCal = BC_TriggerCal(false);

};
