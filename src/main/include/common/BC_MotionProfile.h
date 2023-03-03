// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#pragma once

#include <pathfinder.h>
#include <ctre/Phoenix.h>
#include "subsystems/BC_FalconFX.h"

class BC_MotionProfile {
 public:
  BC_MotionProfile(Waypoint* autoRoutine, int pointLength, double timeDuration, double maxVelocity, double maxAcceleration, double maxJerk, double wheelBase);

  // Push the motion profile onto the API's top levelbuffer use PushMotionProfileTrajectory(). 
  void PopulateTopBuffer();

  // Process the motion profile buffer.  This pushes the trajectory points from the API's top buffer to the talonSRX (bottom buffer on talon).
  // Use ProcessMotionProfileBuffer() Probably should be done at the command level
  void StartTheMotionProfile(bool pushToTalon, BC_FalconFX* rightTalon, BC_FalconFX* leftTalon);


  Segment* m_pathfinderTrajectory;
  Segment* m_rightPathfinderTrajectory;
  Segment* m_leftPathfinderTrajectory;
  int m_pointLength;
  int m_pathFinderPoint;

  // These are the buffered stream object that will be sent to the talons
  BufferedTrajectoryPointStream m_rightTalonBufferedPointStream;
  BufferedTrajectoryPointStream m_leftTalonBufferedPointStream;

 private:

  TrajectoryCandidate m_candidate;

  double m_wheelBaseWidth;

  //These objects are reused to populate the beffered stream to send to talons
  TrajectoryPoint m_rightTalonTrajectoryPoint;
  TrajectoryPoint m_leftTalonTrajectoryPoint;  


};
