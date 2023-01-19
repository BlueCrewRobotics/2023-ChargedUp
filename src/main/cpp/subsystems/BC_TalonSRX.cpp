/*-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=*/
/*                       Blue Crew Robotics #6153                             */
/*                           Rapid React 2022                                 */
/*-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=*/


#include "subsystems/BC_TalonSRX.h"
#include "Constants.h"
#include <ctre/Phoenix.h>
#include <iostream>

BC_TalonSRX::BC_TalonSRX(int device) {

  BC_TalonSRX::ptr_talonSRX = new TalonSRX(device);
}

// speed is a percentage as a decimal between 0 and 1 (1 = 100%)
void BC_TalonSRX::Set(double speed) {

	// Run in low gear
	if(m_bSelectedGear == false){  
		// multiplying % speed by motor max speed gives actual motor speed to use
		speed = speed*m_dMaxSpeed; // jhouse: why not VELOCITY_SP_MAX_LG ??
		ptr_talonSRX->Set(ControlMode::Velocity, speed);
		m_dSpeed = speed;
		ptr_talonSRX->SelectProfileSlot(0,0);
	}
	// Run in high gear
	if(m_bSelectedGear == true){  
		// multiplying % speed by motor max speed gives actual motor speed to use
		speed = speed*VELOCITY_SP_MAX_HG;
		ptr_talonSRX->Set(ControlMode::Velocity, speed);
		m_dSpeed = speed;
		ptr_talonSRX->SelectProfileSlot(1,0);
	}

}

void BC_TalonSRX::SetMotionMagic(double position){
	ptr_talonSRX->Set(ControlMode::MotionMagic, position);
}

void BC_TalonSRX::PIDWrite(double output) {}

double BC_TalonSRX::Get() const { return m_dSpeed; }

void BC_TalonSRX::SetInverted(bool isInverted) {

  ptr_talonSRX->SetInverted(isInverted);
}

bool BC_TalonSRX::GetInverted() const { return ptr_talonSRX->GetInverted(); }

void BC_TalonSRX::Disable() {
  ptr_talonSRX->SetNeutralMode(NeutralMode::Coast);
  
}

void BC_TalonSRX::StopMotor() {
  ptr_talonSRX->SetNeutralMode(NeutralMode::Coast);
}

int BC_TalonSRX::GetCtrlLoopError() {
  return ptr_talonSRX->GetClosedLoopError(0);
}

double BC_TalonSRX::GetCtrlLoopTarget() {
  return ptr_talonSRX->GetClosedLoopTarget(0);
}

// 'false' is low gear
void BC_TalonSRX::SetGear(bool gear) { m_bSelectedGear = gear; }

// 'false' is low gear
bool BC_TalonSRX::GetGear() const {
	return m_bSelectedGear;
}
void BC_TalonSRX::SetMaxSpeed(double maxSpeed) {
	m_dMaxSpeed = maxSpeed;
}
double BC_TalonSRX::GetMaxSpeed() {
	return m_dMaxSpeed;
}
void BC_TalonSRX::ResetSensorPosition() {
	ptr_talonSRX->SetSelectedSensorPosition(0, 0, 0);
}

void BC_TalonSRX::SetConfig_kF(int profileSlot, double value) {
	ptr_talonSRX->Config_kF(profileSlot, value, 0);
}

void BC_TalonSRX::SetConfig_kP(int profileSlot, double value) {
	ptr_talonSRX->Config_kP(profileSlot, value, 0);
}

void BC_TalonSRX::SetConfig_kI(int profileSlot, double value) {
	ptr_talonSRX->Config_kI(profileSlot, value, 0);
}

void BC_TalonSRX::SetConfig_kD(int profileSlot, double value) {
	ptr_talonSRX->Config_kD(profileSlot, value, 0);
}

void BC_TalonSRX::ClearStickyFault() {
	ptr_talonSRX->ClearStickyFaults();
}

void BC_TalonSRX::SetFollower(TalonSRX *motor, bool inverted)
{
	ptr_talonSRX->Follow(*motor);
	ptr_talonSRX->SetInverted(inverted);
}

TalonSRX* BC_TalonSRX::GetMotorController() {
	return ptr_talonSRX;
}

void BC_TalonSRX::SetSelectedFeedbackSensor(FeedbackDevice device) {
	ptr_talonSRX->ConfigSelectedFeedbackSensor(device,0,0);

}

void BC_TalonSRX::SetSupplyCurrentLimit(bool enable, double limit, double trigger, double triggerTime) {
	ptr_talonSRX->ConfigSupplyCurrentLimit(SupplyCurrentLimitConfiguration(enable,limit,trigger,triggerTime));

}

void BC_TalonSRX::SetNominalPeakOutput(int profileSlot) {
	ptr_talonSRX->SelectProfileSlot(profileSlot,0);
	ptr_talonSRX->ConfigNominalOutputForward(0,0);
	ptr_talonSRX->ConfigNominalOutputReverse(0,0);
	ptr_talonSRX->ConfigPeakOutputForward(1.0,0);
	ptr_talonSRX->ConfigPeakOutputReverse(-1.0,0);
}

void BC_TalonSRX::ConfigureMotionMagic() {
	ptr_talonSRX->ConfigMotionAcceleration(8192,0);
	ptr_talonSRX->ConfigMotionCruiseVelocity(8192,0);
}

void BC_TalonSRX::DriveWithMotionMagic(double position) {
	ptr_talonSRX->Set(ControlMode::MotionMagic, position);
}
double BC_TalonSRX::GetEncoderValue() {
	return ptr_talonSRX->GetSelectedSensorPosition(0);
}

double BC_TalonSRX::GetError() {
	return ptr_talonSRX->GetClosedLoopError(0);
}
void BC_TalonSRX::ResetEncoder() {
	ptr_talonSRX->SetSelectedSensorPosition(0,0,0);
}


void BC_TalonSRX::SetRamp(double ramp) {
	ptr_talonSRX->ConfigClosedloopRamp(ramp,0);
}

void BC_TalonSRX::ConfigureMotionVelocity(int velocity, int timeout) {
	ptr_talonSRX->ConfigMotionCruiseVelocity(velocity, timeout);
}

void BC_TalonSRX::ConfigureMotionAcceleration(int acceleration, int timeout) {
	ptr_talonSRX->ConfigMotionAcceleration(acceleration, timeout);
}
void BC_TalonSRX::ConfigureMotionCurveStrength(int curveStrength, int timeout) {
	ptr_talonSRX->ConfigMotionSCurveStrength(curveStrength, timeout);
}

int BC_TalonSRX::GetMotorPosition() {
	return ptr_talonSRX->GetSelectedSensorPosition();
}