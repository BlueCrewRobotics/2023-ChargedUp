/*-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=*/
/*                       Blue Crew Robotics #6153                             */
/*                            Charged Up 2023                                 */
/*-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=*/
// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#include "subsystems/SubLimeLightBase.h"

SubLimeLightBase::SubLimeLightBase() = default;

// This method will be called once per scheduler run
void SubLimeLightBase::Periodic() {
    
}

bool SubLimeLightBase::GetTarget() {
  if(tblLimeLight->GetNumber("tv",0.0) < 1.0) { 
    return false;
  }
  return true;
  
}

double SubLimeLightBase::GetHorizontalOffset() {
  return tblLimeLight->GetNumber("tx",0.0);

}

double SubLimeLightBase::GetVerticalOffset() {
  return tblLimeLight->GetNumber("ty",0.0);
}

double SubLimeLightBase::GetTargetArea() {
  return tblLimeLight->GetNumber("ta",0.0);
}

double SubLimeLightBase::GetTargetLatency() {
  return tblLimeLight->GetNumber("tl",0.0);
}

double SubLimeLightBase::GetShortestSideOfTargetBoundingBox() {
  return tblLimeLight->GetNumber("tshort",0.0);
}

double SubLimeLightBase::GetLongestSideOfTargetBoundingBox() {
  return tblLimeLight->GetNumber("tlong",0.0);
}

double SubLimeLightBase::GetHorizontalSideLengthOfTargetBoundingBox() {
  return tblLimeLight->GetNumber("thor",0.0);
}

double SubLimeLightBase::GetVerticalSideLengthOfTargetBoundingBox() {
  return tblLimeLight->GetNumber("tvert",0.0);
}

double SubLimeLightBase::GetActivePipeline() {
  return tblLimeLight->GetNumber("getPipe",0.0);
}

void SubLimeLightBase::SetCropValues(double X0, double X1, double Y0, double Y1) {
  double cropValues[4];
  cropValues[0] = X0;
  cropValues[1] = X1;
  cropValues[2] = Y0;
  cropValues[3] = Y1;
  tblLimeLight->GetEntry("crop").SetDoubleArray(cropValues);
}

double SubLimeLightBase::GetAprilTagId() {
  return tblLimeLight->GetNumber("tid",0.0);
}

double SubLimeLightBase::GetBotPoseTargetSpace() {
  return tblLimeLight->GetNumber("botpose_targetspace",0.0);
}

double SubLimeLightBase::GetTargetPoseBotSpace() {
  return tblLimeLight->GetNumber("targetpose_robotspace",0.0);
}

double SubLimeLightBase::GetTargetPoseCameraSpace() {
  return tblLimeLight->GetNumber("targetpose_cameraspace",0.0);
}

double SubLimeLightBase::GetCameraPoseTargetspace() {
  return tblLimeLight->GetNumber("camerapose_targetspace",0.0);
}

/**
   Get the distance from the target
    
    d = (h2-h1) / tan(a1+a2)

    d = distance from camera to target on horizontal plane
    h1 = the height of the camera from the ground
    h2 = the height of the center of the target
    a1 = the angle of the camera with respect to ground
    a2 = the angle of the target with respect to the camera ( LimeLightBase will give this angle "ty" from network tables)

  */

 /*  THIS SHOULD BE CLEANED UP.  THERE SHOULD BE ONLY ONE GetDistanceToTarget IN THE LIMELIGHT
     CLASS.  THE GetDistanceToTarget SHOULD TAKE h1, h2, AND a1 AS FUNCTION VARIABLES.
     THESE WILL BE PASSED TO THE FUNCTION FROM THE COMMANDS.  THIS ALLOWS US TO REUSE THE CLASS
     IN THE FUTURE GAMES AND ALSO USE WITH MULTIPLE COMMAND AND DIFFERENT CAMERAS.  
     WE SHOULD REFRAIN FROM PUTTING GAME SPECIFIC CODE IN THE CLASSES THAT WILL BE 
     REUSED IN THE FUTURE.

     Example:
     
     GetDistanceToTarget(double h1_heightOfCamera, double h2_heightOfCenterTarget,
          double a1_angleOfCameraToGround) {

            double distance = 0.0;
            double a2_angleOfTargetToCamera = tblLimelightShooter->GetNumber("ty",0.0);    
            distance = (h2_heightOfCenterTarget-h1_heightOfCamera) / (tan((a1_angleOfCameraToGround + a2_angleOfTargetToCamera)*3.1416/180));

            return distance;
          }


 */

  // angle up Base LimeLightBase: -28.2209
  // angle of LimeLightLower: 23.8122
  // Hight of middle of cube: 4.5 inches
  // Hight of middle of cone: 6.5 inches
  // Hight of Base Pole: 43.75 inches
  // Hight of Base LimeLight: 51.875 inches
  // Hight of Lower LimeLight: 8.25 inches


double SubLimeLightBase::GetDistanceToTarget(double h1_heightOfCamera, double h2_heightOfCenterOfTarget, double a1_angleOfCamera) {  
  double d = 0.0;

  double a2 = tblLimeLight->GetNumber("ty",0.0);
  
  d = (h2_heightOfCenterOfTarget-h1_heightOfCamera) / (tan((a1_angleOfCamera + a2)*3.1416/180));
  
  return d;
}

  /**
    Get the skew of the target
  */
double SubLimeLightBase::GetSkew() {
  return tblLimeLight->GetNumber("ts",0.0);
}

/**
   Get the camera mounting angle
    
    a1 = (atan(h2 - h1 / d) - (a2 * 3.14 / 180)) * 180/3.14

    d = distance from camera to target on horizontal plane meaured with tape measure
    h1 = the height of the camera from the ground
    h2 = the height of the center of the target
    a1 = the angle of the camera with respect to ground
    a2 = the angle of the target with respect to the camera ( LimeLightBase will give this angle "ty" from network tables)


h1 = 51.875
h2 = 4.5
a2 = -7.45
d = 66

  */
double SubLimeLightBase::GetCameraMountAngle(double distance) {
  double d = distance;
  double h1 = (54.3/12); // inches
  double h2 = (43.75/12); // inches
  double a1 = 0.0; // degrees
  double a2 = tblLimeLight->GetNumber("ty",0.0);
  
  a1 = (atan((h2-h1)/d)-(a2*3.1416/180))*180/3.1416;

  return a1;
}

/**
  Set the LimeLightBase LED state.
      
  0 - Use the LED Mode set in the current pipeline
  1 - Force LEDS off
  2 - Force LEDs to blink
  3 - Force LEDs on
  
  @param mode the mode to set for the LEDs
  */
void SubLimeLightBase::SetLEDState(int mode) {
  tblLimeLight->PutNumber("ledMode",mode);

}

/** Set the LimeLightBase camera mode.
  
  0 - Use Vision processing
  1 - Use Limeligt as Driver Camera (Increases exposure, disables vision processing)
  
  @param mode the mode to set for the Camera
*/
void SubLimeLightBase::SetCameraMode(int mode) {
  tblLimeLight->PutNumber("camMode",mode);

}

/** Select the vision pipline to use for targeting.
  
  0 - 9 Vision pipeline to use
  
  @param pipeline the pipeline to select for the vision targeting
*/
void SubLimeLightBase::SelectPipeline(int pipeline) {
  tblLimeLight->PutNumber("pipeline", pipeline);
}

int SubLimeLightBase::GetSelectedPipeline() {
  return tblLimeLight->GetNumber("pipeline", -1);
}

/** Select LimeLightBase's streaming mode.
  
  0 - Standard Side-by-Side stream if a webcam is attached to LimeLightBase.
  1 - PiP Main - The secondary camera stream is placed in the lower-right corner of the primary camera stream
  2 - PiP Secondary - The primary camera stream is placed in the lower-right corner of the secondary camera stream
  
  @param mode the streaming mode selected
*/
void SubLimeLightBase::SelectStreamMode(int mode) {
  tblLimeLight->PutNumber("stream",mode);

}

/** Select LimeLightBase's snapshot mode.
  
  0 - Stop taking snapshots.
  1 - Take two snapshots per second
  
  @param mode the streaming mode selected
*/
void SubLimeLightBase::SelectSnapshotMode(int mode) {
  tblLimeLight->PutNumber("snapshot",mode);

}

/** Get the LimeLightBase distance value
 * Returns the stored distance
 */
double SubLimeLightBase::GetLimeLightBaseDistance() {
  return m_distance;
}

/** Set the LimeLightBase distance value
 * 
 * @param distance the distance to the target
 */
void SubLimeLightBase::SetLimeLightBaseDistance(double distance) {
  m_distance = distance;

}
