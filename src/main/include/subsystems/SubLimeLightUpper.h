/*-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=*/
/*                       Blue Crew Robotics #6153                             */
/*                            Charged Up 2023                                 */
/*-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=*/
// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#pragma once

#include <frc2/command/SubsystemBase.h>
#include <frc/smartdashboard/SmartDashboard.h>
#include <networktables/NetworkTable.h>
#include <networktables/NetworkTableInstance.h>


class SubLimeLightUpper : public frc2::SubsystemBase {
 public:
  SubLimeLightUpper();

  /**
   * Will be called periodically whenever the CommandScheduler runs.
   */
  void Periodic() override;

    /**
     Get whether or not LimeLightUpper has a target
    */
  bool GetTarget();

  /**
     Get horizontal Offset in degrees from Crosshair to target
     Horizontal field of view (FOV) for Limielight is (-29.8 to 29.8)
    */
  double GetHorizontalOffset();

  /**
     Get vertical Offset in degrees from Crosshair to target
     Vertical field of view (FOV) for Limielight is (-24.85 to 24.85)
    */
  double GetVerticalOffset();

/**
      Get Target Area From 0% of the image to 100% of the image
    */
  double GetTargetArea();

  /**
   * The Pipelines Latency contribution(ms) Add at least 11 ms for image capture latency
  */
  double GetTargetLatency();

 /**
  * Sidelength of the shortest side of the fitted bounding box(pixels)
 */
  double GetShortestSideOfTargetBoundingBox();

  /**
  * Sidelength of the Longest side of the fitted bounding box(pixels)
 */
  double GetLongestSideOfTargetBoundingBox();

  /**
   * Horizontal Side length of the bouinding box
  */
 double GetHorizontalSideLengthOfTargetBoundingBox();

  /**
   * Vertical Side length of the bouinding box
  */
  double GetVerticalSideLengthOfTargetBoundingBox();

  /**
   * Get Id of the primary in-view AprilTag
  */

  double GetAprilTagId();

 /**
   * True active pipelineindex of the camera
  */
  double GetActivePipeline();

  void SetCropValues(double X0, double X1, double Y0, double Y1);

/**
 * 3D transform of the robot in the coordinate system of the primary in-view AprilTag
*/
  double GetBotPoseTargetSpace();
/**
 * 3D transform of the primary in-view AprilTag in the coordinate system of the Robot
*/
  double GetTargetPoseBotSpace();
/**
 * 3D transform of the primary in-view AprilTag in the coordinate system of the Camera
*/
  double GetTargetPoseCameraSpace();
/**
 * 3D transform of the camera in the coordinate system of the primary in-view AprilTag
*/
  double GetCameraPoseTargetspace(); 
  
  /** 
     Get the distance from the target
     
     d = (h2-h1) / tan(a1+a2)

     d = distance from camera to target on horizontal plane
     h1 = the height of the camera from the ground
     h2 = the height of the center of the target
     a1 = the angle of the camera with respect to ground
     a2 = the angle of the target with respect to the camera ( LimeLightUpper will give this angle "ty" from network tables)

    */

 /*  THIS SHOULD BE CLEANED UP.  THERE SHOULD BE ONLY ONE GetDistanceToTarget IN THE LIMELIGHT
     CLASS.  THE GetDistanceToTarget SHOULD TAKE h1, h2, AND a1 AS FUNCTION VARIABLES.
     THESE WILL BE PASSED TO THE FUNCTION FROM THE COMMANDS.  THIS ALLOWS US TO REUSE THE CLASS
     IN THE FUTURE AND ALSO USE WITH MULTIPLE COMMAND WHILE USING DIFFERENT CAMERAS.  
     WE SHOULD REFRAIN FROM PUTTING GAME SPECIFIC CODE IN THE CLASSES THAT WILL BE 
     REUSED IN THE FUTURE.

     Example
     GetDistanceToTarget(double h1_heightOfCamera, double h2_heightOfCenterTarget,
          double a1_angleOfCameraToGround) {

            double distance = 0.0;
            double a2_angleOfTargetToCamera = tblLimelightShooter->GetNumber("ty",0.0);    
            distance = (h2_heightOfCenterTarget-h1_heightOfCamera) / (tan((a1_angleOfCameraToGround + a2_angleOfTargetToCamera)*3.1416/180));

            return distance;
          }


 */

  double GetDistanceToTarget(double h1_heightOfCamera, double h2_heightOfCenter, double a1_angleOfCamera);

  /**
      Get the skew of the target
    */
  double GetSkew();

  /**
     Get the camera mounting angle THIS IS WRONG! NEEDS WORK ON EQUATION!
     
     d = (h2-h1) / tan(a1+a2)

     d = distance from camera to target on horizontal plane
     h1 = the height of the camera from the ground
     h2 = the height of the center of the target
     a1 = the angle of the camera with respect to ground
     a2 = the angle of the target with respect to the camera ( LimeLightUpper will give this angle "ty" from network tables)

   */
  double GetCameraMountAngle(double distance);

  /**
    \Set the LimeLightUpper LED state.
        
    \0 - Use the LED Mode set in the current pipeline
    \1 - Force LEDS off
    \2 - Force LEDs to blink
    \3 - Force LEDs on
   
    @param mode the mode to set for the LEDs
   */
  void SetLEDState(int mode);

  /** Set the LimeLightUpper camera mode.
    
    0 - Use Vision processing
    1 - Use Limeligt as Driver Camera (Increases exposure, disables vision processing)
   
    @param mode the mode to set for the Camera
  */
  void SetCameraMode(int mode);

  /** Select the vision pipline to use for targeting.
    
    0 - 9 Vision pipeline to use
    
    @param pipeline the pipeline to select for the vision targeting
  */
  void SelectPipeline(int pipeline);
  
  /**
   * Get which pipeline id is currently selected
   */
  int GetSelectedPipeline();

  /** Select LimeLightUpper's streaming mode.
    
    0 - Standard Side-by-Side stream if a webcam is attached to LimeLightUpper.
    1 - PiP Main - The secondary camera stream is placed in the lower-right corner of the primary camera stream
    2 - PiP Secondary - The primary camera stream is placed in the lower-right corner of the secondary camera stream
    
    @param mode the streaming mode selected
  */
  void SelectStreamMode(int mode);
  
  /** Select LimeLightUpper's snapshot mode.
    
    0 - Stop taking snapshots.
    1 - Take two snapshots per second
    
    @param mode the streaming mode selected
  */
  void SelectSnapshotMode(int mode);

  /** Get the LimeLightUpper distance value
   * Returns the stored distance
   */
  double GetLimeLightUpperDistance();

  /** Set the LimeLightUpper distance value
   * 
   * @param distance the distance to the target
   */
  void SetLimeLightUpperDistance(double distance);

 private:
  // Components (e.g. motor controllers and sensors) should generally be
  // declared private and exposed only through public methods.

  std::shared_ptr<nt::NetworkTable> tblLimeLightUpper = nt::NetworkTableInstance::GetDefault().GetTable("limelight-top");

  double m_distance = 11.5;
};

