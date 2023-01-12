/*-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-*/
/*     Blue Crew Robotics #6153    */
/*         Deep Space 2019         */
/*-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-*/

#include "common/BC_TriggerCal.h"

BC_TriggerCal::BC_TriggerCal(bool inverted) { m_bInverted = inverted; }

double BC_TriggerCal::GetCalibratedTrigger(double xValue, double outputDeadband, double joyStickZero) {
  if (xValue > joyStickZero) {
    // Do calculation
    double y;
    y = (((1 - outputDeadband) / 1) * xValue) + outputDeadband;
    if (m_bInverted == true) {
      y = y * -1;
    }
    return y;

  } else {
    return 0;
  }
}