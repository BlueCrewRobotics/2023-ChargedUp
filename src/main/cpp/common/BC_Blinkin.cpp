/*-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-*/
/*     Blue Crew Robotics #6153    */
/*         Charged Up 2023         */
/*-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-*/ 

#include "common/BC_Blinkin.h"

BC_Blinkin::BC_Blinkin(int channel){
    ptr_BlinkinOutput = new frc::Spark(channel);
}
void BC_Blinkin::Set(double setting){
    ptr_BlinkinOutput->Set(setting);
}