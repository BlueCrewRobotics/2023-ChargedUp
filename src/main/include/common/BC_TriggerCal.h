/*-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=*/
/*                       Blue Crew Robotics #6153                             */
/*                        Infinite Recharge 2020                              */
/*-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=*/

class BC_TriggerCal {

public:
  /*-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=--=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=--=+=--=+=-
  // Calibrates the controller trigger to remove the deadband in the trigger.
  //
  // @param inverted
  //           Reverses the output to be negative -1.0-0.
  //-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=--=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=--=+=--=+=-
  */
  BC_TriggerCal(bool inverted);

  /*-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=--=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=--=+=--=+=-
  // Calibrates the controller trigger to remove the deadband in the trigger.
  //
  // @param xValue
  //           Input from the trigger typically 0-1.0.
  // @param outputDeadband
  //           Deadband of when the motor starts to move when trigger is pulled.
  // @param joyStickZero
  //           The value of the joystick that cuts the output to 0.  Must be
  //          greater than zero, typically 0.02.
  //-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=--=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=--=+=--=+=-
  */
  double GetCalibratedTrigger(double xValue, double outputDeadband,
                              double joyStickZero);

private:
  bool m_bInverted;
};