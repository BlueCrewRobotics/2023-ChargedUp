// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#include "common/BC_MotionProfile.h"

BC_MotionProfile::BC_MotionProfile(Waypoint* autoRoutine, int pointLength, double timeDuration, double maxVelocity, double maxAcceleration, double maxJerk, double wheelBase) {
    
    m_wheelBaseWidth = wheelBase;
    pathfinder_prepare(autoRoutine, pointLength, FIT_HERMITE_CUBIC,PATHFINDER_SAMPLES_FAST,timeDuration,maxVelocity,maxAcceleration,maxJerk,&m_candidate);
    
    m_pathfinderTrajectory = new Segment[m_candidate.length];
    m_rightPathfinderTrajectory = new Segment[m_candidate.length];
    m_leftPathfinderTrajectory = new Segment[m_candidate.length];
    m_pathFinderPoint = m_candidate.length;

    pathfinder_generate(&m_candidate, m_pathfinderTrajectory);

    pathfinder_modify_tank(m_pathfinderTrajectory, m_candidate.length, m_leftPathfinderTrajectory, m_rightPathfinderTrajectory, m_wheelBaseWidth);
    

}

void BC_MotionProfile::PopulateTopBuffer() {
    
    for( int i = 0; i < m_pathFinderPoint; i++) {
                /**
				 * Create a trajectory point with specified values
				 * 
				 * @param position The position to servo to (in sensor units).
				 * @param velocity The velocity to feed-forward (in sensor-units per 100ms). 
				 * @param arbFeedFwd Added to the output of PID[0], should be within [-1,+1] where 0.01 = 1%.
				 * @param auxiliaryPos The position for auxiliary PID[1] to target (in sensor units).
				 * @param auxiliaryVel The velocity for auxiliary PID[1] to target. (in sensor-units per 100ms).
				 * @param auxiliaryArbFeedFwd Added to the output of PID[1], should be within [-1,+1] where 0.01 = 1%.
				 * @param profileSlotSelect0 The slot to select for base PIDF gains
				 * @param profileSlotSelect1 The slot to select for auxiliary PIDF gains
				 * @param isLastPoint True if this is the last piont
				 * @param zeroPos True if the motor controller should zero the sensor position
				 * @param timeDur The time duration of this point
				 * @param useAuxPID Enables the auxiliary PID
				 */
        // Left 
        m_leftTalonTrajectoryPoint.position = (m_leftPathfinderTrajectory + i)->position;
        m_leftTalonTrajectoryPoint.velocity = (m_leftPathfinderTrajectory + i)->velocity;
        m_leftTalonTrajectoryPoint.timeDur = (m_leftPathfinderTrajectory + i)->dt;
        if (i == 0)
        {
            m_leftTalonTrajectoryPoint.zeroPos = true; /* set this to true on the first point */
        }

        m_leftTalonTrajectoryPoint.isLastPoint = false;
        if ((i + 1) == m_pathFinderPoint)
        {
            m_leftTalonTrajectoryPoint.isLastPoint = true; /* set this to true on the last point  */
        }
        m_leftTalonBufferedPointStream.Write(m_leftTalonTrajectoryPoint);
        // Right
        m_rightTalonTrajectoryPoint.position = (m_rightPathfinderTrajectory + i)->position;
        m_rightTalonTrajectoryPoint.velocity = (m_rightPathfinderTrajectory + i)->velocity;
        m_rightTalonTrajectoryPoint.timeDur = (m_rightPathfinderTrajectory + i)->dt;
        if (i == 0)
        {
            m_rightTalonTrajectoryPoint.zeroPos = true; /* set this to true on the first point */
        }

        m_rightTalonTrajectoryPoint.isLastPoint = false;
        if ((i + 1) == m_pathFinderPoint)
        {
            m_rightTalonTrajectoryPoint.isLastPoint = true; /* set this to true on the last point  */
        }
        m_rightTalonBufferedPointStream.Write(m_rightTalonTrajectoryPoint);
    }
    
}

void BC_MotionProfile::PushToTalon(){

}

