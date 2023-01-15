/*-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=*/
/*                       Blue Crew Robotics #6153                             */
/*                           Rapid React 2022                                 */
/*-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=*/
// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#include "commands/CmdDriveWithController.h"

CmdDriveWithController::CmdDriveWithController(SubDriveTrain* driveTrain, frc::Joystick *driverController) 
  : m_driveTrain{driveTrain}, m_driverController{driverController} {
  // Use addRequirements() here to declare subsystem dependencies.
  AddRequirements(driveTrain);

}

// Called when the command is initially scheduled.
void CmdDriveWithController::Initialize() {}

// Called repeatedly when this Command is scheduled to run
void CmdDriveWithController::Execute() {

  double speed;

  // This sets up the virtual low gear
  if(m_driverController->GetRawButton(BUTTON_B)==1) {
    m_driveTrain->SetMaxSpeed(VELOCITY_SP_MAX_LL);
  }
  else {
    m_driveTrain->SetMaxSpeed(VELOCITY_SP_MAX_LG);

  }

  // This is controlling the speed of the drive train
  if(m_driverController->GetRawAxis(AXIS_R_TRIG) > 0)
  {
    speed = -1*m_driverController->GetRawAxis(AXIS_R_TRIG);
  }
  else
  {
    speed = m_driverController->GetRawAxis(AXIS_L_TRIG);
  }

  // This is the steering section of the drive train
  double rotation;

/*  if(m_driverController->GetRawButton(BUTTON_R_BUMP)==1){
    double hTargetPosition;
    double hTargetAngle;

    double gain = 0.5;
    double offset = 0;

    if(m_subLimelightIntake->GetTarget()==true)
    {
      // Get the robots horizontal offset from the ball center
      hTargetAngle = m_subLimelightIntake->GetHorizontalOffset();

      // Normalize the horizontal position to the ball
      hTargetPosition = (-1*(hTargetAngle/29.8))*gain;

      // Rotate the drive train to point at the ball
      rotation = -hTargetPosition;
      
    }
    else {
        if(m_driveTrain->GetDriveTrainGear()==false) {
          rotation = m_driverController->GetRawAxis(AXIS_LX)*0.8;
        }
        else {
          rotation = m_driverController->GetRawAxis(AXIS_LX)*0.4;
        }
    }
  
  }*/
/*
  if(m_driverController->GetRawAxis(AXIS_LX) < 0.02 && m_driverController->GetRawAxis(AXIS_LX) > -0.02) {
    m_driveTrain->ZeroYaw();
    if(m_driveTrain->GetYaw() > 0){
      rotation = 1-(180-m_driveTrain->GetYaw())/180;
    }
    if(m_driveTrain->GetYaw() < 0){
      rotation = (180+m_driveTrain->GetYaw())/180 -1;
    }
  }*/
 // else{
    if(m_driveTrain->GetDriveTrainGear()==false) {
        rotation = m_driverController->GetRawAxis(AXIS_LX)*1;
    }
    else {
        rotation = m_driverController->GetRawAxis(AXIS_LX)*0.7;
    }
//  }


  // This actually drives the drive train
  m_driveTrain->Drive(speed, rotation);

}

// Called once the command ends or is interrupted.
void CmdDriveWithController::End(bool interrupted) {}

// Returns true when the command should end.
bool CmdDriveWithController::IsFinished() {
  return false;
}
