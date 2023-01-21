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


class SubLimeLight : public frc2::SubsystemBase {
 public:
  SubLimeLight();

  /**
   * Will be called periodically whenever the CommandScheduler runs.
   */
  void Periodic() override;

    /**
     Get whether or not limelight has a target
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
     Get the distance from the target
     
     d = (h2-h1) / tan(a1+a2)

     d = distance from camera to target on horizontal plane
     h1 = the height of the camera from the ground
     h2 = the height of the center of the target
     a1 = the angle of the camera with respect to ground
     a2 = the angle of the target with respect to the camera ( limelight will give this angle "ty" from network tables)

    */
  double GetDistanceToPurpleCubeTarget();

  double GetDistanceToYellowConeTarget();

  double GetDistanceToTopPollTarget();
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
     a2 = the angle of the target with respect to the camera ( limelight will give this angle "ty" from network tables)

   */
  double GetCameraMountAngle(double distance);

  /**
    \Set the Limelight LED state.
        
    \0 - Use the LED Mode set in the current pipeline
    \1 - Force LEDS off
    \2 - Force LEDs to blink
    \3 - Force LEDs on
   
    @param mode the mode to set for the LEDs
   */
  void SetLEDState(int mode);

  /** Set the Limelight camera mode.
    
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
  
  /** Select limelight's streaming mode.
    
    0 - Standard Side-by-Side stream if a webcam is attached to limelight.
    1 - PiP Main - The secondary camera stream is placed in the lower-right corner of the primary camera stream
    2 - PiP Secondary - The primary camera stream is placed in the lower-right corner of the secondary camera stream
    
    @param mode the streaming mode selected
  */
  void SelectStreamMode(int mode);
  
  /** Select limelight's snapshot mode.
    
    0 - Stop taking snapshots.
    1 - Take two snapshots per second
    
    @param mode the streaming mode selected
  */
  void SelectSnapshotMode(int mode);

  /** Get the Limelight distance value
   * Returns the stored distance
   */
  double GetLimelightDistance();

  /** Set the Limelight distance value
   * 
   * @param distance the distance to the target
   */
  void SetLimelightDistance(double distance);

 private:
  // Components (e.g. motor controllers and sensors) should generally be
  // declared private and exposed only through public methods.

  std::shared_ptr<nt::NetworkTable> tblLimelight = nt::NetworkTableInstance::GetDefault().GetTable("limelight");

  double m_distance = 11.5;
};

