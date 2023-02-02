/*-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=*/
/*                       Blue Crew Robotics #6153                             */
/*                            Charged Up 2023                                 */
/*-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=*/
// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#include "subsystems/SubLimeLightUpper.h"

SubLimeLightUpper::SubLimeLightUpper() = default;

// This method will be called once per scheduler run
void SubLimeLightUpper::Periodic() {
}

bool SubLimeLightUpper::GetTarget() {
  if(tblLimeLightUpper->GetNumber("tv",0.0) < 1.0) { 
    return false;
  }
  return true;
  
}

double SubLimeLightUpper::GetHorizontalOffset() {
  return tblLimeLightUpper->GetNumber("tx",0.0);

}

double SubLimeLightUpper::GetVerticalOffset() {
  return tblLimeLightUpper->GetNumber("ty",0.0);
}

/**
   Get the distance from the target
    
    d = (h2-h1) / tan(a1+a2)

    d = distance from camera to target on horizontal plane
    h1 = the height of the camera from the ground
    h2 = the height of the center of the target
    a1 = the angle of the camera with respect to ground
    a2 = the angle of the target with respect to the camera ( LimeLightUpper will give this angle "ty" from network tables)

  */
double SubLimeLightUpper::GetDistanceToPurpleCubeTarget() {
  double d = 0.0; // feet
  double h1 = (17.25/12.0); // feet
  double h2 = (4.5/12.0); // feet   // purple cube is 9" tall
  double a1 =  -3.18;//37.95; // degrees
  double a2 = tblLimeLightUpper->GetNumber("ty",0.0);    

  d = (h2-h1) / (tan((a1 + a2)*3.1416/180));

  return d;
}

double SubLimeLightUpper::GetDistanceToYellowConeTarget() {
  double d = 0.0; // feet
  double h1 = (17.25/12.0); // feet
  double h2 = (6.5/12.0); // feet   // yellow cone is 13" tall standing, 8" tall on side
  double a1 =  -3.18;//37.95; // degrees
  double a2 = tblLimeLightUpper->GetNumber("ty",0.0);    

  d = (h2-h1) / (tan((a1 + a2)*3.1416/180));

  return d;
}

double SubLimeLightUpper::GetDistanceToTopPoleTarget() {  
  double d = 0.0;
  double h1 = (17.25/12); // inches
  double h2 = (43.75/12); // inches
  double a1 = -3.18; // degrees
  double a2 = tblLimeLightUpper->GetNumber("ty",0.0);
  
  d = (h2-h1) / (tan((a1 + a2)*3.1416/180));
  
  return d;
}

   // angle up upper LimeLightUpper: -24.8492

double SubLimeLightUpper::GetDistanceToTarget() {  
  double d = 0.0;
  double h1 = (17.25/12); // inches

  double h2 = 0;
  if(GetSelectedPipeline() == 8) {
    h2 = 4.5/12.0;
  }
  else if(GetSelectedPipeline() == 9) {
    h2 = 6.5/12.0;
  }  
  else if(GetSelectedPipeline() == 0) {
    h2 = 43.75/12.0;
  }  

  double a1 = -3.18; // degrees
  double a2 = tblLimeLightUpper->GetNumber("ty",0.0);
  
  d = (h2-h1) / (tan((a1 + a2)*3.1416/180));
  
  return d;
}

  /**
    Get the skew of the target
  */
double SubLimeLightUpper::GetSkew() {
  return tblLimeLightUpper->GetNumber("ts",0.0);
}

/**
   Get the camera mounting angle
    
    a1 = (atan(h2 - h1 / d) - (a2 * 3.14 / 180)) * 180/3.14

    d = distance from camera to target on horizontal plane meaured with tape measure
    h1 = the height of the camera from the ground
    h2 = the height of the center of the target
    a1 = the angle of the camera with respect to ground
    a2 = the angle of the target with respect to the camera ( LimeLightUpper will give this angle "ty" from network tables)


h1 = 54
h2 = 4.5
a2 = -2.1
d = 80

  */
double SubLimeLightUpper::GetCameraMountAngle(double distance) {
  double d = distance;
  double h1 = (17.25/12); // inches
  double h2 = (43.75/12); // inches
  double a1 = 0.0; // degrees
  double a2 = tblLimeLightUpper->GetNumber("ty",0.0);
  
  a1 = (atan((h2-h1)/d)-(a2*3.1416/180))*180/3.1416;

  return a1;
}

/**
  Set the LimeLightUpper LED state.
      
  0 - Use the LED Mode set in the current pipeline
  1 - Force LEDS off
  2 - Force LEDs to blink
  3 - Force LEDs on
  
  @param mode the mode to set for the LEDs
  */
void SubLimeLightUpper::SetLEDState(int mode) {
  tblLimeLightUpper->PutNumber("ledMode",mode);

}

/** Set the LimeLightUpper camera mode.
  
  0 - Use Vision processing
  1 - Use Limeligt as Driver Camera (Increases exposure, disables vision processing)
  
  @param mode the mode to set for the Camera
*/
void SubLimeLightUpper::SetCameraMode(int mode) {
  tblLimeLightUpper->PutNumber("camMode",mode);

}

/** Select the vision pipline to use for targeting.
  
  0 - 9 Vision pipeline to use
  
  @param pipeline the pipeline to select for the vision targeting
*/
void SubLimeLightUpper::SelectPipeline(int pipeline) {
  tblLimeLightUpper->PutNumber("pipeline",pipeline);
}

int SubLimeLightUpper::GetSelectedPipeline() {
  return tblLimeLightUpper->GetNumber("pipeline", -1);
}

/** Select LimeLightUpper's streaming mode.
  
  0 - Standard Side-by-Side stream if a webcam is attached to LimeLightUpper.
  1 - PiP Main - The secondary camera stream is placed in the lower-right corner of the primary camera stream
  2 - PiP Secondary - The primary camera stream is placed in the lower-right corner of the secondary camera stream
  
  @param mode the streaming mode selected
*/
void SubLimeLightUpper::SelectStreamMode(int mode) {
  tblLimeLightUpper->PutNumber("stream",mode);

}

/** Select LimeLightUpper's snapshot mode.
  
  0 - Stop taking snapshots.
  1 - Take two snapshots per second
  
  @param mode the streaming mode selected
*/
void SubLimeLightUpper::SelectSnapshotMode(int mode) {
  tblLimeLightUpper->PutNumber("snapshot",mode);

}

/** Get the LimeLightUpper distance value
 * Returns the stored distance
 */
double SubLimeLightUpper::GetLimeLightUpperDistance() {
  return m_distance;
}

/** Set the LimeLightUpper distance value
 * 
 * @param distance the distance to the target
 */
void SubLimeLightUpper::SetLimeLightUpperDistance(double distance) {
  m_distance = distance;

}
