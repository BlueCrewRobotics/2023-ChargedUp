/*-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=*/
/*                       Blue Crew Robotics #6153                             */
/*                           Charged Up 2023                                  */
/*-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=*/

#pragma once
#include <ctre/Phoenix.h>
#include "Constants/ConsDrivetrain.h"

class BC_TalonSRX : public virtual frc::MotorController {

	public: 
		BC_TalonSRX(int device);

		// Overides for the MotorController class
		void Set(double speed);
		void SetMotionMagic(double position);
		void PIDWrite(double output);
		double Get() const;
		void SetInverted(bool isInverted);
		bool GetInverted() const;
		void Disable();
		void StopMotor();
		void SetGear(bool gear);
		bool GetGear() const;
		void SetMaxSpeed(double maxSpeed);
		double GetMaxSpeed();
		void ResetSensorPosition();

		// Sets the control mode of the TalonFX
		void SetControlMode(ctre::phoenix::motorcontrol::ControlMode mode);
		// Configure the feedforward tuning parameter
		void SetConfig_kF(int profileSlot, double value);
		// Configure the proportional tuning parameter
		void SetConfig_kP(int profileSlot, double value);
		// Configure the intergral tuning parameter
		void SetConfig_kI(int profileSlot, double value);
		// Configure the derivitive tuning parameter
		void SetConfig_kD(int profileSlot, double value);

		// Clear the sticky faults of the TalonFX
  		void ClearStickyFault();
		// Set the follower
  		void SetFollower(TalonSRX* motor, bool inverted);
		// Get motor controller pointer
  		TalonSRX* GetMotorController();
		// Configure the feedback sensor
  		void SetSelectedFeedbackSensor(FeedbackDevice device);
		// Configure the Supply current limit
		// enabled | Limit(amp) | Trigger Threshold(amp) | Trigger Threshold Time(s)
		void SetSupplyCurrentLimit(bool enable, double limit, double trigger, double triggerTime);
		// Set nominal and peak outs on the motors
  		void SetNominalPeakOutput(int profileSlot);
		// Configure motion magic velocity and acceleration
  		void ConfigureMotionMagic();
		// Drive with motion magic
  		void DriveWithMotionMagic(double position);
	 	// Set ramp time
  		void SetRamp(double ramp);
		// Get encoder value
		double GetEncoderValue();
		// Get closed loop error value
		double GetError();
		//Reset Encoder
		void ResetEncoder();

		// Added calls
		int GetCtrlLoopError();
		double GetCtrlLoopTarget();
		void ConfigureMotionVelocity(int velocity, int timeout);
		void ConfigureMotionAcceleration(int acceleration, int timeout);
		void ConfigureMotionCurveStrength(int curveStrength, int timeout);
		int GetMotorPosition();
		// This changes the farme rate of the talon SRX
		void SetChangeMotionControlFrameRate(int frameRate);
		
		void WriteMotionProfileToTalon();

		// Motion profiling functions

		// Update the motion profile status of the talon SRX
		void UpdateMotionStatus(); 

		TalonSRX* ptr_talonSRX = nullptr;  

		// The motion profiling status indication of the talon SRX
		MotionProfileStatus m_statusTalonSRX;

	private:
		double m_dSpeed = 0;
		bool m_bSelectedGear = 0;
		int m_iCount;
		double m_dMaxSpeed = VELOCITY_SP_MAX_LG;


};
