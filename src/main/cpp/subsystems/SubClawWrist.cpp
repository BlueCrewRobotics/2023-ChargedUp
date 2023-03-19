// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#include "subsystems/SubClawWrist.h"

SubClawWrist::SubClawWrist() = default;

// This method will be called once per scheduler run
void SubClawWrist::Periodic() {
    // Holding the position
    if(m_enableHoldPosition == true) {
        m_wristClawController.SetReference(m_holdPosition, rev::ControlType::kPosition); 
    }
}

void SubClawWrist::ConfigureMotor() {
    /******* Setup the wrist motor *******/
    // Setup the soft limits
    m_motorWristClaw.SetSoftLimit(rev::CANSparkMax::SoftLimitDirection::kReverse,WRIST_CLAW_MIN_LIMIT);
    m_motorWristClaw.SetSoftLimit(rev::CANSparkMax::SoftLimitDirection::kForward,WRIST_CLAW_MAX_LIMIT); 
    m_motorWristClaw.SetSmartCurrentLimit(20);
    m_motorWristClaw.SetClosedLoopRampRate(0.2);

    // set PID coefficients
    m_wristClawController.SetP(0.025); //0.02
    m_wristClawController.SetI(0.000001);
    m_wristClawController.SetD(2.0);
    m_wristClawController.SetIZone(0.0);
    m_wristClawController.SetFF(0.0);
    m_wristClawController.SetOutputRange(-1.0, 1.0); // This can be sped up possibly




    /******* Setup the intake motor *******/
    m_motorIntake->ClearStickyFaults();
    m_motorIntake->SetInverted(false);
    // Select the feedback device (encoder) for the motor
    m_motorIntake->ConfigSelectedFeedbackSensor(FeedbackDevice::IntegratedSensor);
    m_motorIntake->SetInverted(TalonFXInvertType::CounterClockwise);

    // Set PID coefficients
    m_motorIntake->Config_kF(0,0.0, 0);
    m_motorIntake->Config_kP(0,0.01, 0);
    m_motorIntake->Config_kI(0,0.0000, 0);
    m_motorIntake->Config_kD(0,0.0, 0);
    m_motorIntake->SetNeutralMode(Brake);
    m_motorIntake->ConfigNeutralDeadband(0.001);
    // Set output limit
    m_motorIntake->ConfigSupplyCurrentLimit(SupplyCurrentLimitConfiguration(true,10,12,100));
}

double SubClawWrist::GetPosition() {
    // This should return the elevator position
    return m_wristClawEncoder.GetPosition(); // TODO return correct value
}

void SubClawWrist::ServoToPosition(double position) {
    // This function will be used by the Cmd to move the elevator to a position
    // Make sure you check that the position is within the range specified
    if(position > m_motorWristClaw.GetSoftLimit(rev::CANSparkMax::SoftLimitDirection::kForward))
    {
        position = m_motorWristClaw.GetSoftLimit(rev::CANSparkMax::SoftLimitDirection::kForward);
    }

    if(position < m_motorWristClaw.GetSoftLimit(rev::CANSparkMax::SoftLimitDirection::kReverse))
    {
        position = m_motorWristClaw.GetSoftLimit(rev::CANSparkMax::SoftLimitDirection::kReverse);
    }

    if(GetEngagedClaw() == false) { // go up/down slower when not holding piece
        m_wristClawController.SetOutputRange(-0.4, 0.4);
    }
    else {
        m_wristClawController.SetOutputRange(-0.7, 0.7);
    }
    SetHoldPosition(position); 
}

void SubClawWrist::ControlMotorManually(double speed) {
    m_motorWristClaw.Set(speed);
}

void SubClawWrist::EngageClaw(bool engage) {
    m_wristClawSolenoid.Set(engage);
}

bool SubClawWrist::GetEngagedClaw() {
    return m_wristClawSolenoid.Get();
}

void SubClawWrist::SpinIntake(double speed) {
//    speed = speed * INTAKE_MOTOR_MAX_SPEED;
    m_motorIntake->Set(ControlMode::PercentOutput, speed);
}

double SubClawWrist::GetIntakeOutput() {
    return m_motorIntake->GetSupplyCurrent();
}

void SubClawWrist::EnableHoldPosition(bool hold) {
    m_enableHoldPosition = hold;
}

void SubClawWrist::SetHoldPosition(double position) {
    if(position < m_bottomSoftLimit) {
        position = m_bottomSoftLimit;
    }
    else if(position > m_topSoftLimit) {
        position = m_topSoftLimit;
    }
    m_holdPosition = position; 
}
