/*-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=*/
/*                       Blue Crew Robotics #6153                             */
/*                            Charged Up 2023                                 */
/*-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=*/
// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#include "subsystems/SubLimeLightLower.h"

SubLimeLightLower::SubLimeLightLower() = default;

// This method will be called once per scheduler run
void SubLimeLightLower::Periodic() {
}

bool SubLimeLightLower::GetTarget() {
  if(tblLimeLightLower->GetNumber("tv",0.0) < 1.0) { 
    return false;
  }
  return true;
  
}

double SubLimeLightLower::GetHorizontalOffset() {
  return tblLimeLightLower->GetNumber("tx",0.0);

}

double SubLimeLightLower::GetVerticalOffset() {
  return tblLimeLightLower->GetNumber("ty",0.0);
}

/**
   Get the distance from the target
    
    d = (h2-h1) / tan(a1+a2)

    d = distance from camera to target on horizontal plane
    h1 = the height of the camera from the ground
    h2 = the height of the center of the target
    a1 = the angle of the camera with respect to ground
    a2 = the angle of the target with respect to the camera ( LimeLightLower will give this angle "ty" from network tables)

  */

   // angle up upper LimeLight: -24.8492
   // angle up of lower limelight: 23.8122

double SubLimeLightLower::GetDistanceToTarget(double h1_heightOfCamera, double h2_heightOfCenterOfTarget, double a1_angleOfCamera) {  
  double d = 0.0;

  double a2 = tblLimeLightLower->GetNumber("ty",0.0);
  
  d = (h2_heightOfCenterOfTarget-h1_heightOfCamera) / (tan((a1_angleOfCamera + a2)*3.1416/180));
  
  return d;
}

  /**
    Get the skew of the target
  */
double SubLimeLightLower::GetSkew() {
  return tblLimeLightLower->GetNumber("ts",0.0);
}

/**
   Get the camera mounting angle
    
    a1 = (atan(h2 - h1 / d) - (a2 * 3.14 / 180)) * 180/3.14

    d = distance from camera to target on horizontal plane meaured with tape measure
    h1 = the height of the camera from the ground
    h2 = the height of the center of the target
    a1 = the angle of the camera with respect to ground
    a2 = the angle of the target with respect to the camera ( LimeLightLower will give this angle "ty" from network tables)


h1 = 8.25
h2 = 15.5
a2 = -16.5
d = 56.5

  */
double SubLimeLightLower::GetCameraMountAngle(double distance) {
  double d = distance;
  double h1 = (17.25/12); // inches
  double h2 = (43.75/12); // inches
  double a1 = 0.0; // degrees
  double a2 = tblLimeLightLower->GetNumber("ty",0.0);
  
  a1 = (atan((h2-h1)/d)-(a2*3.1416/180))*180/3.1416;

  return a1;
}

/**
  Set the LimeLightLower LED state.
      
  0 - Use the LED Mode set in the current pipeline
  1 - Force LEDS off
  2 - Force LEDs to blink
  3 - Force LEDs on
  
  @param mode the mode to set for the LEDs
  */
void SubLimeLightLower::SetLEDState(int mode) {
  tblLimeLightLower->PutNumber("ledMode",mode);

}

/** Set the LimeLightLower camera mode.
  
  0 - Use Vision processing
  1 - Use Limeligt as Driver Camera (Increases exposure, disables vision processing)
  
  @param mode the mode to set for the Camera
*/
void SubLimeLightLower::SetCameraMode(int mode) {
  tblLimeLightLower->PutNumber("camMode",mode);

}

/** Select the vision pipline to use for targeting.
  
  0 - 9 Vision pipeline to use
  
  @param pipeline the pipeline to select for the vision targeting
*/
void SubLimeLightLower::SelectPipeline(int pipeline) {
  tblLimeLightLower->PutNumber("pipeline",pipeline);
}

int SubLimeLightLower::GetSelectedPipeline() {
  return tblLimeLightLower->GetNumber("pipeline", -1);
}

/** Select LimeLightLower's streaming mode.
  
  0 - Standard Side-by-Side stream if a webcam is attached to LimeLightLower.
  1 - PiP Main - The secondary camera stream is placed in the lower-right corner of the primary camera stream
  2 - PiP Secondary - The primary camera stream is placed in the lower-right corner of the secondary camera stream
  
  @param mode the streaming mode selected
*/
void SubLimeLightLower::SelectStreamMode(int mode) {
  tblLimeLightLower->PutNumber("stream",mode);

}

/** Select LimeLightLower's snapshot mode.
  
  0 - Stop taking snapshots.
  1 - Take two snapshots per second
  
  @param mode the streaming mode selected
*/
void SubLimeLightLower::SelectSnapshotMode(int mode) {
  tblLimeLightLower->PutNumber("snapshot",mode);

}

/** Get the LimeLightLower distance value
 * Returns the stored distance
 */
double SubLimeLightLower::GetLimeLightLowerDistance() {
  return m_distance;
}

/** Set the LimeLightLower distance value
 * 
 * @param distance the distance to the target
 */
void SubLimeLightLower::SetLimeLightLowerDistance(double distance) {
  m_distance = distance;

}
