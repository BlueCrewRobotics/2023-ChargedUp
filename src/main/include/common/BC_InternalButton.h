/*-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=*/
/*                       Blue Crew Robotics #6153                             */
/*                           Rapid React 2022                                 */
/*-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=*/

#pragma once

#include <frc2/command/button/Trigger.h>
#include <frc2/command/button/Button.h>

class BC_InternalButton : public frc2::Button {
 public:
  BC_InternalButton();
  bool Get();
  void Set(bool value);

 private:
  bool m_button = 0;

};
