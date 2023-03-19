// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#include "commands/CmdTurretGridPiecePlacement.h"

CmdTurretGridPiecePlacement::CmdTurretGridPiecePlacement(SubRobotGlobals* subRobotGlobals, SubTurret* subTurret, frc2::CommandXboxController* auxController, SubLimeLightLower* subLimeLightLower, SubLimeLightUpper* subLimeLightUpper) 
: m_subRobotGlobals{subRobotGlobals}, m_subTurret{subTurret}, m_auxController{auxController}, m_subLimeLightLower{subLimeLightLower}, m_subLimeLightUpper{subLimeLightUpper} {
  // Use addRequirements() here to declare subsystem dependencies.
  AddRequirements(subTurret);
}

// Called when the command is initially scheduled.
void CmdTurretGridPiecePlacement::Initialize() {
  //m_aprilTagCycle = 0;
  m_isFinished = false;
  m_timer.Reset();
  m_timer.Start();
  
  
  
}

// Called repeatedly when this Command is scheduled to run
void CmdTurretGridPiecePlacement::Execute() {

  /*********************** PIECE PLACEMENT ***************************    
    Configure the limelight for the aprilTag and place the  piece that is 
    selected by the DPad.  Work down through the aprilTag selections until  
    we find a target over several execution of the robot code.
  */ 

 std::cout << "m_aprilTagCycle: "<< m_aprilTagCycle << std::endl;

  if(m_timer.HasElapsed(((units::time::second_t)0.25)) == true && m_aprilTagCycle == 0){
    m_subLimeLightLower->SelectPipeline(LL_PIPELINE_APRILTAG_1n8);
    m_subLimeLightUpper->SelectPipeline(LL_PIPELINE_APRILTAG_1n8);
      std::cout << "AprilTag 1 or 8 Selected "<< std::endl;
      m_aprilTagCycle = m_aprilTagCycle + 1;
    
  }
  if(m_timer.HasElapsed(((units::time::second_t)0.5)) == true && m_aprilTagCycle == 1){
    std::cout << "Limelight Upper angle: " << m_subLimeLightUpper->GetCameraMountAngle(42.125) << std::endl;
    m_subLimeLightLower->SelectPipeline(LL_PIPELINE_APRILTAG_2n7);
    m_subLimeLightUpper->SelectPipeline(LL_PIPELINE_APRILTAG_2n7);
      std::cout << "AprilTag 2 or 7 Selected"<< std::endl;
      m_aprilTagCycle = m_aprilTagCycle + 1;
  }
  if(m_timer.HasElapsed(((units::time::second_t)0.75)) == true && m_aprilTagCycle == 2){
    m_subLimeLightLower->SelectPipeline(LL_PIPELINE_APRILTAG_3n6);
    m_subLimeLightUpper->SelectPipeline(LL_PIPELINE_APRILTAG_3n6);
      std::cout << "AprilTag 3 or 6 Selected"<< std::endl;
      m_aprilTagCycle = m_aprilTagCycle + 1;
  }
  // ****************************************************************************************************************
  // Check if there is an AprilTag target and move the turret to the middle cube self.
    if(m_subLimeLightLower->GetTarget()==true && (m_auxController->GetPOV() == DPAD_VALUE_MIDDLE_CENTER) && m_subRobotGlobals->g_gameState.selectedPieceType == CubePiece)
    {
/*      // Calculate the angle of inside edge of the target using pixels
      double pixels = m_subLimeLightLower->GetHorizontalSideLengthOfTargetBoundingBox();
      std::cout << "Middle Center Self - Lower LL bounding box number of pixels: " << pixels << std::endl;
      double pixelsFromCenterToTarget = m_subLimeLightLower->GetHorizontalOffset() * 5.369;
      double angleFromCenter = m_subLimeLightLower->GetHorizontalOffset()*(pixelsFromCenterToTarget-(pixels/2))/pixelsFromCenterToTarget;
      double insideAngle = m_subLimeLightLower->GetHorizontalOffset() - angleFromCenter;
      
      std::cout << "Lucien's Variables: Pixel offest            :" << pixelsFromCenterToTarget << std::endl;
      std::cout << "Lucien's Variables: Center Angle            :" << angleFromCenter  << std::endl;
      std::cout << "Lucien's Variables: Inside Angle            :" << insideAngle << std::endl;
      
      // Get the distance to the target
      double distance = m_subLimeLightLower->GetDistanceToTarget(LL_LIMELIGHT_LOWER_HEIGHT,TARGET_APRILTAG_GRID_HEIGHT,LL_LIMELIGHT_LOWER_ANGLE);
      std::cout << "Middle Center Self - Lower LL distance: " << distance << std::endl;

      // Find the coordinate transform angle
      double C_Angle = 180 - ((asin(distance*sin(insideAngle * 3.1415/180)/3)) * 180/3.1415);
      double A_Angle = (180 - insideAngle - C_Angle);
      double sideA = 3*sin(A_Angle * 3.1415/180)/sin(insideAngle*3.1415/180);
      double rotationNum = sideA*sin((m_subLimeLightLower->GetHorizontalOffset()+insideAngle)*3.1415/180) - distance*sin(m_subLimeLightLower->GetHorizontalOffset()*3.1415/180);
      double rotationDem = sideA*cos((m_subLimeLightLower->GetHorizontalOffset()+insideAngle)*3.1415/180) - distance*cos(m_subLimeLightLower->GetHorizontalOffset()*3.1415/180);
      double coordTransformAngle = atan(rotationNum/rotationDem) * 180/3.1415; // Might be limelight offset minus or plus the coordTransform Angle
      

      // https://www.desmos.com/calculator/sggkyenxqg

      std::cout << "Lucien's Variables: C_Angle                 :" << C_Angle << std::endl;
      std::cout << "Lucien's Variables: A_Angle                 :" << A_Angle << std::endl;
      std::cout << "Lucien's Variables: Side A                  :" << sideA << std::endl;
      std::cout << "Lucien's Variables: Rotation Numerator      :" << rotationNum << std::endl;
      std::cout << "Lucien's Variables: Rotation Denominator    :" << rotationDem << std::endl;
      std::cout << "Lucien's Variables: Rotation Transform Angle:" << coordTransformAngle << std::endl;
      

      // Find selected vector in robot coordinate frame
      // DEFINE VECTORS SOMEWHERE
      double placementX = 0; // Example vector from april tag to target location
      double placementY = 8.5;

      double rotatedPlacementX = placementX * cos(-1 * coordTransformAngle * 3.1415/180) - placementY * sin(-1 * coordTransformAngle * 3.1415/180);
      double rotatedPlacementY = placementX * sin(-1 * coordTransformAngle * 3.1415/180) + placementY * cos(-1 * coordTransformAngle * 3.1415/180);
      std::cout << "Lucien's Variables: Rotated Placement X    :" << rotatedPlacementX  << std::endl;
      std::cout << "Lucien's Variables: Rotated Placement Y    :" << rotatedPlacementY << std::endl;

      // Find resulting vector and calculate turrent position
      double finalLocationX = rotatedPlacementX + distance*sin(m_subLimeLightLower->GetHorizontalOffset()*3.1415/180);
      double finalLocationY = rotatedPlacementY + distance*cos(m_subLimeLightLower->GetHorizontalOffset()*3.1415/180);
      std::cout << "Lucien's Variables: Final Location X    :" << finalLocationX  << std::endl;
      std::cout << "Lucien's Variables: Final Location Y    :" << finalLocationY << std::endl;

      double turretRotationAngle = atan(finalLocationY/finalLocationX) * 180/3.1415; // In degrees
      std::cout << "Middle Center Self - Lower LL New Turret Rotation Angle: " << turretRotationAngle  << std::endl;      

      double targetAngle = m_subLimeLightLower->GetHorizontalOffset();
      std::cout << "Middle Center Self - Lower LL target angle: " << targetAngle << std::endl;
      //double turretOffsetAngle = (atan((tan(targetAngle*3.1415/180)*distance)/(distance + FIELD_POS_OFFSET_FROM_TAG_SHELF_MIDDLE.y)))*180/3.1415;
      //std::cout << "Middle Center Self - Lower LL offset angle: " << turretOffsetAngle << std::endl;
      // Calculate the new current poistion to move too.
      //double newTurretPosition = m_subTurret->GetDegrees() - turretOffsetAngle;
      std::cout << "Middle Center Self - Lower LL current angle: " << m_subTurret->GetDegrees() << std::endl;
      // Move turret to center target by updating the hold position.
      //m_subTurret->RotateToDegree((m_subTurret->GetDegrees() - turretRotationAngle));
      std::cout << "Middle Center Self - Lower LL Rotate to: " << ((m_subTurret->GetDegrees() - turretRotationAngle)) << std::endl;
      m_isFinished = true;
*/      
      // Get the distance to the target
      double distance = m_subLimeLightLower->GetDistanceToTarget(LL_LIMELIGHT_LOWER_HEIGHT,TARGET_APRILTAG_GRID_HEIGHT,LL_LIMELIGHT_LOWER_ANGLE);
      std::cout << "Middle Center Self - Lower LL distance: " << distance << std::endl;
      // Get the angle to the target
      double angleFromCenter = m_subLimeLightLower->GetHorizontalOffset();
      std::cout << "Middle Center Self - Lower LL Target Angle: " << angleFromCenter << std::endl;
      // Calculate the existing target X offest
      double Xoffset = sin(angleFromCenter*3.14/180)*distance;
      std::cout << "Middle Center Self - Lower LL X Offset: " << Xoffset << std::endl;
      // Calculate the existing target Y offset
      double Yoffset = cos(angleFromCenter*3.14/180)*distance;
      std::cout << "Middle Center Self - Lower LL Y Offset: " << Yoffset << std::endl;

      // Calulate the new targeted X offset
      double XoffsetNew = FIELD_POS_OFFSET_FROM_TAG_SHELF_MIDDLE.x + Xoffset;
      std::cout << "Middle Center Self - Lower LL New X Offset: " << XoffsetNew << std::endl;
      // Calulate the new targeted Y offset
      double YoffsetNew = FIELD_POS_OFFSET_FROM_TAG_SHELF_MIDDLE.y + Yoffset;
      std::cout << "Middle Center Self - Lower LL New Y Offset: " << YoffsetNew << std::endl;

      // Calculate the new targeted angle
      double turretOffsetAngle = atan(XoffsetNew/YoffsetNew)*180/3.14;
      std::cout << "Middle Center Self - Lower LL Turret Angle Offset: " << turretOffsetAngle  << std::endl;

      //Calculate the new turret angle.
      double newTurretPosition = m_subTurret->GetDegrees() + turretOffsetAngle*-1;
      std::cout << "Middle Center Self - Lower LL current turret angle: " << m_subTurret->GetDegrees() << std::endl;
      std::cout << "Middle Center Self - Lower LL new turret angle: " << newTurretPosition << std::endl;

      m_subTurret->RotateToDegree(newTurretPosition);
      m_isFinished = true;  
    }

    // **************************************************************************************************************
    // Check if there is an AprilTag target and move the turret to the upper cube self.
    if(m_subLimeLightLower->GetTarget()==true && (m_auxController->GetPOV() == DPAD_VALUE_MIDDLE_UP) && m_subRobotGlobals->g_gameState.selectedPieceType == CubePiece)
    {
      // Get the distance to the target
      double distance = m_subLimeLightLower->GetDistanceToTarget(LL_LIMELIGHT_LOWER_HEIGHT,TARGET_APRILTAG_GRID_HEIGHT,LL_LIMELIGHT_LOWER_ANGLE);
      std::cout << "Middle Upper Self - Lower LL distance: " << distance << std::endl;
      // Get the angle to the target
      double angleFromCenter = m_subLimeLightLower->GetHorizontalOffset();
      std::cout << "Middle Upper Self - Lower LL Target Angle: " << angleFromCenter << std::endl;
      // Calculate the existing target X offest
      double Xoffset = sin(angleFromCenter*3.14/180)*distance;
      std::cout << "Middle Upper Self - Lower LL X Offset: " << Xoffset << std::endl;
      // Calculate the existing target Y offset
      double Yoffset = cos(angleFromCenter*3.14/180)*distance;
      std::cout << "Middle Upper Self - Lower LL Y Offset: " << Yoffset << std::endl;

      // Calulate the new targeted X offset
      double XoffsetNew = FIELD_POS_OFFSET_FROM_TAG_SHELF_TOP.x + Xoffset;
      std::cout << "Middle Upper Self - Lower LL New X Offset: " << XoffsetNew << std::endl;
      // Calulate the new targeted Y offset
      double YoffsetNew = FIELD_POS_OFFSET_FROM_TAG_SHELF_TOP.y + Yoffset;
      std::cout << "Middle Upper Self - Lower LL New Y Offset: " << YoffsetNew << std::endl;

      // Calculate the new targeted angle
      double turretOffsetAngle = atan(XoffsetNew/YoffsetNew)*180/3.14;
      std::cout << "Middle Upper Self - Lower LL Turret Angle Offset: " << turretOffsetAngle  << std::endl;

      //Calculate the new turret angle.
      double newTurretPosition = m_subTurret->GetDegrees() + turretOffsetAngle*-1;
      std::cout << "Middle Upper Self - Lower LL current turret angle: " << m_subTurret->GetDegrees() << std::endl;
      std::cout << "Middle Upper Self - Lower LL new turret angle: " << newTurretPosition << std::endl;

      m_subTurret->RotateToDegree(newTurretPosition);
      m_isFinished = true;  
    /*  double distance = m_subLimeLightLower->GetDistanceToTarget(LL_LIMELIGHT_LOWER_HEIGHT,TARGET_APRILTAG_GRID_HEIGHT,LL_LIMELIGHT_LOWER_ANGLE);
      std::cout << "Middle Upper Self - Lower LL distance: " << distance << std::endl;
      double targetAngle = m_subLimeLightLower->GetHorizontalOffset();
      std::cout << "Middle Upper Self - Lower LL target angle: " << targetAngle << std::endl;
      double turretOffsetAngle = (atan((tan(targetAngle*3.1415/180)*distance)/(distance + FIELD_POS_OFFSET_FROM_TAG_SHELF_TOP.y)))*180/3.1415;
      std::cout << "Middle Upper Self - Lower LL offset angle: " << turretOffsetAngle << std::endl;
      // Calculate the new current poistion to move too.
      double newTurretPosition = m_subTurret->GetDegrees() - turretOffsetAngle;
      std::cout << "Middle Upper Self - Lower LL current angle: " << m_subTurret->GetDegrees() << std::endl;
      // Move turret to center target by updating the hold position.
      m_subTurret->RotateToDegree(newTurretPosition);
      std::cout << "Middle Upper Self - Lower LL Rotate to: " << newTurretPosition << std::endl;
      m_isFinished = true;
      */
    }
    // ****************************************************************************************************************
    // Check if there is an AprilTag target and move the turret to the upper right cone poll if cone is selected
    if(m_subLimeLightLower->GetTarget()==true && (m_auxController->GetPOV() == DPAD_VALUE_LEFT_UP) && m_subRobotGlobals->g_gameState.selectedPieceType == ConePiece)
    {
      // Get the distance to the target
      double distance = m_subLimeLightLower->GetDistanceToTarget(LL_LIMELIGHT_LOWER_HEIGHT,TARGET_APRILTAG_GRID_HEIGHT,LL_LIMELIGHT_LOWER_ANGLE);
      std::cout << "Right Upper Cone - Lower LL distance: " << distance << std::endl;
      // Get the angle to the target
      double angleFromCenter = m_subLimeLightLower->GetHorizontalOffset();
      std::cout << "Right Upper Cone  - Lower LL Target Angle: " << angleFromCenter << std::endl;
      // Calculate the existing target X offest
      double Xoffset = sin(angleFromCenter*3.14/180)*distance;
      std::cout << "Right Upper Cone  - Lower LL X Offset: " << Xoffset << std::endl;
      // Calculate the existing target Y offset
      double Yoffset = cos(angleFromCenter*3.14/180)*distance;
      std::cout << "Right Upper Cone  - Lower LL Y Offset: " << Yoffset << std::endl;

      // Calulate the new targeted X offset
      double XoffsetNew = FIELD_POS_OFFSET_FROM_TAG_CONE_NODE_RIGHT_UPPER.x + Xoffset;
      std::cout << "Right Upper Cone  - Lower LL New X Offset: " << XoffsetNew << std::endl;
      // Calulate the new targeted Y offset
      double YoffsetNew = FIELD_POS_OFFSET_FROM_TAG_CONE_NODE_RIGHT_UPPER.y + Yoffset;
      std::cout << "Right Upper Cone  - Lower LL New Y Offset: " << YoffsetNew << std::endl;

      // Calculate the new targeted angle
      double turretOffsetAngle = atan(XoffsetNew/YoffsetNew)*180/3.14;
      std::cout << "Right Upper Cone  - Lower LL Turret Angle Offset: " << turretOffsetAngle  << std::endl;

      //Calculate the new turret angle.
      double newTurretPosition = m_subTurret->GetDegrees() + turretOffsetAngle*-1;
      std::cout << "Right Upper Cone  - Lower LL current turret angle: " << m_subTurret->GetDegrees() << std::endl;
      std::cout << "Right Upper Cone  - Lower LL new turret angle: " << newTurretPosition << std::endl;

      m_subTurret->RotateToDegree(newTurretPosition);
      m_isFinished = true;  
    /*  
      double distance = m_subLimeLightLower->GetDistanceToTarget(LL_LIMELIGHT_LOWER_HEIGHT,TARGET_APRILTAG_GRID_HEIGHT,LL_LIMELIGHT_LOWER_ANGLE);
      std::cout << "Upper Right Cone Poll - Lower LL distance: " << distance << std::endl;
      double targetAngle = m_subLimeLightLower->GetHorizontalOffset();
      std::cout << "Upper Right Cone Poll - Lower LL target angle: " << targetAngle << std::endl;
      double turretOffsetAngle = (atan((tan(targetAngle*3.1415/180)*distance)/(distance + FIELD_POS_OFFSET_FROM_TAG_CONE_NODE_RIGHT_UPPER.y)))*180/3.1415;
      std::cout << "Upper Right Cone Poll - Lower LL offset angle: " << turretOffsetAngle << std::endl;
      // Calculate the new current poistion to move too.
      double newTurretPosition = m_subTurret->GetDegrees() - turretOffsetAngle;
      std::cout << "Upper Right Cone Poll - Lower LL current angle: " << m_subTurret->GetDegrees() << std::endl;
      // Move turret to center target by updating the hold position.
      m_subTurret->RotateToDegree(newTurretPosition);
      std::cout << "Upper Right Cone Poll - Lower LL Rotate to: " << newTurretPosition << std::endl;
      m_isFinished = true;
      */
    }

    // ****************************************************************************************************************
    // Check if there is an AprilTag target and move the turret to the middle right cone poll if cone is selected
    if(m_subLimeLightLower->GetTarget()==true && (m_auxController->GetPOV() == DPAD_VALUE_LEFT_CENTER) && m_subRobotGlobals->g_gameState.selectedPieceType == ConePiece)
    {
      // Get the distance to the target
      double distance = m_subLimeLightLower->GetDistanceToTarget(LL_LIMELIGHT_LOWER_HEIGHT,TARGET_APRILTAG_GRID_HEIGHT,LL_LIMELIGHT_LOWER_ANGLE);
      std::cout << "Right Lower Cone  - Lower LL distance: " << distance << std::endl;
      // Get the angle to the target
      double angleFromCenter = m_subLimeLightLower->GetHorizontalOffset();
      std::cout << "Right Lower Cone - Lower LL Target Angle: " << angleFromCenter << std::endl;
      // Calculate the existing target X offest
      double Xoffset = sin(angleFromCenter*3.14/180)*distance;
      std::cout << "Right Lower Cone - Lower LL X Offset: " << Xoffset << std::endl;
      // Calculate the existing target Y offset
      double Yoffset = cos(angleFromCenter*3.14/180)*distance;
      std::cout << "Right Lower Cone- Lower LL Y Offset: " << Yoffset << std::endl;

      // Calulate the new targeted X offset
      double XoffsetNew = FIELD_POS_OFFSET_FROM_TAG_CONE_NODE_RIGHT_LOWER.x + Xoffset;
      std::cout << "Right Lower Cone - Lower LL New X Offset: " << XoffsetNew << std::endl;
      // Calulate the new targeted Y offset
      double YoffsetNew = FIELD_POS_OFFSET_FROM_TAG_CONE_NODE_RIGHT_LOWER.y + Yoffset;
      std::cout << "Right Lower Cone - Lower LL New Y Offset: " << YoffsetNew << std::endl;

      // Calculate the new targeted angle
      double turretOffsetAngle = atan(XoffsetNew/YoffsetNew)*180/3.14;
      std::cout << "Right Lower Cone - Lower LL Turret Angle Offset: " << turretOffsetAngle  << std::endl;

      //Calculate the new turret angle.
      double newTurretPosition = m_subTurret->GetDegrees() + turretOffsetAngle*-1;
      std::cout << "Right Lower Cone - Lower LL current turret angle: " << m_subTurret->GetDegrees() << std::endl;
      std::cout << "Right Lower Cone - Lower LL new turret angle: " << newTurretPosition << std::endl;

      m_subTurret->RotateToDegree(newTurretPosition);
      m_isFinished = true;  
      /*
      double distance = m_subLimeLightLower->GetDistanceToTarget(LL_LIMELIGHT_LOWER_HEIGHT,TARGET_APRILTAG_GRID_HEIGHT,LL_LIMELIGHT_LOWER_ANGLE);
      std::cout << "Middle Right Cone Poll - Lower LL distance: " << distance << std::endl;
      double targetAngle = m_subLimeLightLower->GetHorizontalOffset();
      std::cout << "Middle Right Cone Poll - Lower LL target angle: " << targetAngle << std::endl;
      double turretOffsetAngle = (atan((tan(targetAngle*3.1415/180)*distance)/(distance + FIELD_POS_OFFSET_FROM_TAG_CONE_NODE_RIGHT_LOWER.y)))*180/3.1415;
      std::cout << "Middle Right Cone Poll - Lower LL offset angle: " << turretOffsetAngle << std::endl;
      // Calculate the new current poistion to move too.
      double newTurretPosition = m_subTurret->GetDegrees() - turretOffsetAngle;
      std::cout << "Middle Right Cone Poll - Lower LL current angle: " << m_subTurret->GetDegrees() << std::endl;
      // Move turret to center target by updating the hold position.
      m_subTurret->RotateToDegree(newTurretPosition);
      std::cout << "Middle Right Cone Poll - Lower LL Rotate to: " << newTurretPosition << std::endl;
      m_isFinished = true;
      */
    }

    // ****************************************************************************************************************
    // Check if there is an AprilTag target and move the turret to the upper left cone poll if cone is selected
    if(m_subLimeLightLower->GetTarget()==true && (m_auxController->GetPOV() == DPAD_VALUE_RIGHT_UP) && m_subRobotGlobals->g_gameState.selectedPieceType == ConePiece)
    {
            // Get the distance to the target
      double distance = m_subLimeLightLower->GetDistanceToTarget(LL_LIMELIGHT_LOWER_HEIGHT,TARGET_APRILTAG_GRID_HEIGHT,LL_LIMELIGHT_LOWER_ANGLE);
      std::cout << "Left Upper Cone - Lower LL distance: " << distance << std::endl;
      // Get the angle to the target
      double angleFromCenter = m_subLimeLightLower->GetHorizontalOffset();
      std::cout << "Left Upper Cone - Lower LL Target Angle: " << angleFromCenter << std::endl;
      // Calculate the existing target X offest
      double Xoffset = sin(angleFromCenter*3.14/180)*distance;
      std::cout << "Left Upper Cone - Lower LL X Offset: " << Xoffset << std::endl;
      // Calculate the existing target Y offset
      double Yoffset = cos(angleFromCenter*3.14/180)*distance;
      std::cout << "Left Upper Cone - Lower LL Y Offset: " << Yoffset << std::endl;

      // Calulate the new targeted X offset
      double XoffsetNew = FIELD_POS_OFFSET_FROM_TAG_CONE_NODE_LEFT_UPPER.x + Xoffset;
      std::cout << "Left Upper Cone - Lower LL New X Offset: " << XoffsetNew << std::endl;
      // Calulate the new targeted Y offset
      double YoffsetNew = FIELD_POS_OFFSET_FROM_TAG_CONE_NODE_LEFT_UPPER.y + Yoffset;
      std::cout << "Left Upper Cone - Lower LL New Y Offset: " << YoffsetNew << std::endl;

      // Calculate the new targeted angle
      double turretOffsetAngle = atan(XoffsetNew/YoffsetNew)*180/3.14;
      std::cout << "Left Upper Cone - Lower LL Turret Angle Offset: " << turretOffsetAngle  << std::endl;

      //Calculate the new turret angle.
      double newTurretPosition = m_subTurret->GetDegrees() + turretOffsetAngle*-1;
      std::cout << "Left Upper Cone - Lower LL current turret angle: " << m_subTurret->GetDegrees() << std::endl;
      std::cout << "Left Upper Cone - Lower LL new turret angle: " << newTurretPosition << std::endl;

      m_subTurret->RotateToDegree(newTurretPosition);
      m_isFinished = true;  
      /*
      double distance = m_subLimeLightLower->GetDistanceToTarget(LL_LIMELIGHT_LOWER_HEIGHT,TARGET_APRILTAG_GRID_HEIGHT,LL_LIMELIGHT_LOWER_ANGLE);
      std::cout << "Upper Left Cone Poll - Lower LL distance: " << distance << std::endl;
      double targetAngle = m_subLimeLightLower->GetHorizontalOffset();
      std::cout << "Upper Left Cone Poll - Lower LL target angle: " << targetAngle << std::endl;
      double turretOffsetAngle = (atan((tan(targetAngle*3.1415/180)*distance)/(distance + FIELD_POS_OFFSET_FROM_TAG_CONE_NODE_LEFT_UPPER.y)))*180/3.1415;
      std::cout << "Upper Left Cone Poll - Lower LL offset angle: " << turretOffsetAngle << std::endl;
      // Calculate the new current poistion to move too.
      double newTurretPosition = m_subTurret->GetDegrees() - turretOffsetAngle;
      std::cout << "Upper Left Cone Poll - Lower LL current angle: " << m_subTurret->GetDegrees() << std::endl;
      // Move turret to center target by updating the hold position.
      m_subTurret->RotateToDegree(newTurretPosition);
      std::cout << "Upper Left Cone Poll - Lower LL Rotate to: " << newTurretPosition << std::endl;
      m_isFinished = true;
      */
    }

    // ****************************************************************************************************************
    // Check if there is an AprilTag target and move the turret to the middle left cone poll if cone is selected
    if(m_subLimeLightLower->GetTarget()==true && (m_auxController->GetPOV() == DPAD_VALUE_RIGHT_CENTER) && m_subRobotGlobals->g_gameState.selectedPieceType == ConePiece)
    {
            // Get the distance to the target
      double distance = m_subLimeLightLower->GetDistanceToTarget(LL_LIMELIGHT_LOWER_HEIGHT,TARGET_APRILTAG_GRID_HEIGHT,LL_LIMELIGHT_LOWER_ANGLE);
      std::cout << "Left Lower Cone - Lower LL distance: " << distance << std::endl;
      // Get the angle to the target
      double angleFromCenter = m_subLimeLightLower->GetHorizontalOffset();
      std::cout << "Left Lower Cone - Lower LL Target Angle: " << angleFromCenter << std::endl;
      // Calculate the existing target X offest
      double Xoffset = sin(angleFromCenter*3.14/180)*distance;
      std::cout << "Left Lower Cone - Lower LL X Offset: " << Xoffset << std::endl;
      // Calculate the existing target Y offset
      double Yoffset = cos(angleFromCenter*3.14/180)*distance;
      std::cout << "Left Lower Cone - Lower LL Y Offset: " << Yoffset << std::endl;

      // Calulate the new targeted X offset
      double XoffsetNew = FIELD_POS_OFFSET_FROM_TAG_CONE_NODE_LEFT_LOWER.x + Xoffset;
      std::cout << "Left Lower Cone - Lower LL New X Offset: " << XoffsetNew << std::endl;
      // Calulate the new targeted Y offset
      double YoffsetNew = FIELD_POS_OFFSET_FROM_TAG_CONE_NODE_LEFT_LOWER.y + Yoffset;
      std::cout << "Left Lower Cone - Lower LL New Y Offset: " << YoffsetNew << std::endl;

      // Calculate the new targeted angle
      double turretOffsetAngle = atan(XoffsetNew/YoffsetNew)*180/3.14;
      std::cout << "Left Lower Cone - Lower LL Turret Angle Offset: " << turretOffsetAngle  << std::endl;

      //Calculate the new turret angle.
      double newTurretPosition = m_subTurret->GetDegrees() + turretOffsetAngle*-1;
      std::cout << "Left Lower Cone - Lower LL current turret angle: " << m_subTurret->GetDegrees() << std::endl;
      std::cout << "Left Lower Cone - Lower LL new turret angle: " << newTurretPosition << std::endl;

      m_subTurret->RotateToDegree(newTurretPosition);
      m_isFinished = true;  
      /*
      double distance = m_subLimeLightLower->GetDistanceToTarget(LL_LIMELIGHT_LOWER_HEIGHT,TARGET_APRILTAG_GRID_HEIGHT,LL_LIMELIGHT_LOWER_ANGLE);
      std::cout << "Middle Left Cone Poll - Lower LL distance: " << distance << std::endl;
      double targetAngle = m_subLimeLightLower->GetHorizontalOffset();
      std::cout << "Middle Left Cone Poll - Lower LL target angle: " << targetAngle << std::endl;
      double turretOffsetAngle = (atan((tan(targetAngle*3.1415/180)*distance)/(distance + FIELD_POS_OFFSET_FROM_TAG_CONE_NODE_LEFT_LOWER.y)))*180/3.1415;
      std::cout << "Middle Left Cone Poll - Lower LL offset angle: " << turretOffsetAngle << std::endl;
      // Calculate the new current poistion to move too.
      double newTurretPosition = m_subTurret->GetDegrees() - turretOffsetAngle;
      std::cout << "Middle Left Cone Poll - Lower LL current angle: " << m_subTurret->GetDegrees() << std::endl;
      // Move turret to center target by updating the hold position.
      m_subTurret->RotateToDegree(newTurretPosition);
      std::cout << "Middle Left Cone Poll - Lower LL Rotate to: " << newTurretPosition << std::endl;
      m_isFinished = true;
      */
    }


    // Will need to use the upper limelight to target the aprilTags for hybrid placement becasue lower limelight can't see the target
    
    // ****************************************************************************************************************
    // Check if there is an AprilTag target and move the turret to the lower left hybrid location
    if(m_subLimeLightUpper->GetTarget()==true && (m_auxController->GetPOV() == DPAD_VALUE_RIGHT_DOWN))
    {
      // Get the distance to the target
      double distance = m_subLimeLightUpper->GetDistanceToTarget(LL_LIMELIGHT_UPPER_HEIGHT,TARGET_APRILTAG_GRID_HEIGHT,LL_LIMELIGHT_UPPER_ANGLE);
      std::cout << "Left Hybrid - Lower LL distance: " << distance << std::endl;
      // Get the angle to the target
      double angleFromCenter = m_subLimeLightUpper->GetHorizontalOffset();
      std::cout << "Left Hybrid - Lower LL Target Angle: " << angleFromCenter << std::endl;
      // Calculate the existing target X offest
      double Xoffset = sin(angleFromCenter*3.14/180)*distance;
      std::cout << "Left Hybrid - Lower LL X Offset: " << Xoffset << std::endl;
      // Calculate the existing target Y offset
      double Yoffset = cos(angleFromCenter*3.14/180)*distance;
      std::cout << "Left Hybrid - Lower LL Y Offset: " << Yoffset << std::endl;

      // Calulate the new targeted X offset
      double XoffsetNew = FIELD_POS_OFFSET_FROM_TAG_FLOOR_LEFT.x + Xoffset;
      std::cout << "Left Hybrid - Lower LL New X Offset: " << XoffsetNew << std::endl;
      // Calulate the new targeted Y offset
      double YoffsetNew = FIELD_POS_OFFSET_FROM_TAG_FLOOR_LEFT.y + Yoffset;
      std::cout << "Left Hybrid - Lower LL New Y Offset: " << YoffsetNew << std::endl;

      // Calculate the new targeted angle
      double turretOffsetAngle = atan(XoffsetNew/YoffsetNew)*180/3.14;
      std::cout << "Left Hybrid - Lower LL Turret Angle Offset: " << turretOffsetAngle  << std::endl;

      //Calculate the new turret angle.
      double newTurretPosition = m_subTurret->GetDegrees() + turretOffsetAngle*-1;
      std::cout << "Left Hybrid - Lower LL current turret angle: " << m_subTurret->GetDegrees() << std::endl;
      std::cout << "Left Hybrid - Lower LL new turret angle: " << newTurretPosition << std::endl;

      m_subTurret->RotateToDegree(newTurretPosition);
      m_isFinished = true;  
      /*
      double distance = m_subLimeLightUpper->GetDistanceToTarget(LL_LIMELIGHT_LOWER_HEIGHT,TARGET_APRILTAG_GRID_HEIGHT,LL_LIMELIGHT_LOWER_ANGLE);
      std::cout << "Lower Left Hybrid - Lower LL distance: " << distance << std::endl;
      double targetAngle = m_subLimeLightUpper->GetHorizontalOffset();
      std::cout << "Lower Left Hybrid - Lower LL target angle: " << targetAngle << std::endl;
      double turretOffsetAngle = (atan((tan(targetAngle*3.1415/180)*distance)/(distance + FIELD_POS_OFFSET_FROM_TAG_FLOOR_LEFT.y)))*180/3.1415;
      std::cout << "Lower Left Hybrid - Lower LL offset angle: " << turretOffsetAngle << std::endl;
      // Calculate the new current poistion to move too.
      double newTurretPosition = m_subTurret->GetDegrees() - turretOffsetAngle;
      std::cout << "Lower Left Hybrid - Lower LL current angle: " << m_subTurret->GetDegrees() << std::endl;
      // Move turret to center target by updating the hold position.
      m_subTurret->RotateToDegree(newTurretPosition);
      std::cout << "Lower Left Hybrid - Lower LL Rotate to: " << newTurretPosition << std::endl;
      m_isFinished = true;
      //std::cout << "Limelight Upper distance: " << m_subLimeLightUpper->GetDistanceToTarget(LL_LIMELIGHT_UPPER_HEIGHT, TARGET_APRILTAG_GRID_HEIGHT, LL_LIMELIGHT_UPPER_ANGLE) << std::endl;
      */
    }

    // ****************************************************************************************************************
    // Check if there is an AprilTag target and move the turret to the lower middle hybrid location
    if(m_subLimeLightUpper->GetTarget()==true && (m_auxController->GetPOV() == DPAD_VALUE_MIDDLE_DOWN))
    {
      // Get the distance to the target
      double distance = m_subLimeLightUpper->GetDistanceToTarget(LL_LIMELIGHT_UPPER_HEIGHT,TARGET_APRILTAG_GRID_HEIGHT,LL_LIMELIGHT_UPPER_ANGLE);
      std::cout << "Center Hybrid - Lower LL distance: " << distance << std::endl;
      // Get the angle to the target
      double angleFromCenter = m_subLimeLightUpper->GetHorizontalOffset();
      std::cout << "Center Hybrid - Lower LL Target Angle: " << angleFromCenter << std::endl;
      // Calculate the existing target X offest
      double Xoffset = sin(angleFromCenter*3.14/180)*distance;
      std::cout << "Center Hybrid - Lower LL X Offset: " << Xoffset << std::endl;
      // Calculate the existing target Y offset
      double Yoffset = cos(angleFromCenter*3.14/180)*distance;
      std::cout << "Center Hybrid - Lower LL Y Offset: " << Yoffset << std::endl;

      // Calulate the new targeted X offset
      double XoffsetNew = FIELD_POS_OFFSET_FROM_TAG_FLOOR_CENTER.x + Xoffset;
      std::cout << "Center Hybrid - Lower LL New X Offset: " << XoffsetNew << std::endl;
      // Calulate the new targeted Y offset
      double YoffsetNew = FIELD_POS_OFFSET_FROM_TAG_FLOOR_CENTER.y + Yoffset;
      std::cout << "Center Hybrid - Lower LL New Y Offset: " << YoffsetNew << std::endl;

      // Calculate the new targeted angle
      double turretOffsetAngle = atan(XoffsetNew/YoffsetNew)*180/3.14;
      std::cout << "Center Hybrid - Lower LL Turret Angle Offset: " << turretOffsetAngle  << std::endl;

      //Calculate the new turret angle.
      double newTurretPosition = m_subTurret->GetDegrees() + turretOffsetAngle*-1;
      std::cout << "Center Hybrid - Lower LL current turret angle: " << m_subTurret->GetDegrees() << std::endl;
      std::cout << "Center Hybrid - Lower LL new turret angle: " << newTurretPosition << std::endl;

      m_subTurret->RotateToDegree(newTurretPosition);
      m_isFinished = true;  
      /*
      double distance = m_subLimeLightUpper->GetDistanceToTarget(LL_LIMELIGHT_LOWER_HEIGHT,TARGET_APRILTAG_GRID_HEIGHT,LL_LIMELIGHT_LOWER_ANGLE);
      std::cout << "Lower Center Hybrid - Lower LL distance: " << distance << std::endl;
      double targetAngle = m_subLimeLightUpper->GetHorizontalOffset();
      std::cout << "Lower Center Hybrid - Lower LL target angle: " << targetAngle << std::endl;
      double turretOffsetAngle = (atan((tan(targetAngle*3.1415/180)*distance)/(distance + FIELD_POS_OFFSET_FROM_TAG_FLOOR_CENTER.y)))*180/3.1415;
      std::cout << "Lower Center Hybrid - Lower LL offset angle: " << turretOffsetAngle << std::endl;
      // Calculate the new current poistion to move too.
      double newTurretPosition = m_subTurret->GetDegrees() - turretOffsetAngle;
      std::cout << "Lower Center Hybrid - Lower LL current angle: " << m_subTurret->GetDegrees() << std::endl;
      // Move turret to center target by updating the hold position.
      m_subTurret->RotateToDegree(newTurretPosition);
      std::cout << "Lower Center Hybrid - Lower LL Rotate to: " << newTurretPosition << std::endl;
      m_isFinished = true;
      */
    }

    // ****************************************************************************************************************
    // Check if there is an AprilTag target and move the turret to the lower right hybrid location
    if(m_subLimeLightUpper->GetTarget()==true && (m_auxController->GetPOV() == DPAD_VALUE_LEFT_DOWN))
    {
      // Get the distance to the target
      double distance = m_subLimeLightUpper->GetDistanceToTarget(LL_LIMELIGHT_UPPER_HEIGHT,TARGET_APRILTAG_GRID_HEIGHT,LL_LIMELIGHT_UPPER_ANGLE);
      std::cout << "Right Hybrid - Lower LL distance: " << distance << std::endl;
      // Get the angle to the target
      double angleFromCenter = m_subLimeLightUpper->GetHorizontalOffset();
      std::cout << "Right Center Self - Lower LL Target Angle: " << angleFromCenter << std::endl;
      // Calculate the existing target X offest
      double Xoffset = sin(angleFromCenter*3.14/180)*distance;
      std::cout << "Right Center Self - Lower LL X Offset: " << Xoffset << std::endl;
      // Calculate the existing target Y offset
      double Yoffset = cos(angleFromCenter*3.14/180)*distance;
      std::cout << "Right Center Self - Lower LL Y Offset: " << Yoffset << std::endl;

      // Calulate the new targeted X offset
      double XoffsetNew = FIELD_POS_OFFSET_FROM_TAG_FLOOR_RIGHT.x + Xoffset;
      std::cout << "Right Center Self - Lower LL New X Offset: " << XoffsetNew << std::endl;
      // Calulate the new targeted Y offset
      double YoffsetNew = FIELD_POS_OFFSET_FROM_TAG_FLOOR_RIGHT.y + Yoffset;
      std::cout << "Right Center Self - Lower LL New Y Offset: " << YoffsetNew << std::endl;

      // Calculate the new targeted angle
      double turretOffsetAngle = atan(XoffsetNew/YoffsetNew)*180/3.14;
      std::cout << "Right Center Self - Lower LL Turret Angle Offset: " << turretOffsetAngle  << std::endl;

      //Calculate the new turret angle.
      double newTurretPosition = m_subTurret->GetDegrees() + turretOffsetAngle*-1;
      std::cout << "Right Center Self - Lower LL current turret angle: " << m_subTurret->GetDegrees() << std::endl;
      std::cout << "Right Center Self - Lower LL new turret angle: " << newTurretPosition << std::endl;

      m_subTurret->RotateToDegree(newTurretPosition);
      m_isFinished = true;  
      /*
      double distance = m_subLimeLightUpper->GetDistanceToTarget(LL_LIMELIGHT_LOWER_HEIGHT,TARGET_APRILTAG_GRID_HEIGHT,LL_LIMELIGHT_LOWER_ANGLE);
      std::cout << "Lower Right Hybrid - Lower LL distance: " << distance << std::endl;
      double targetAngle = m_subLimeLightUpper->GetHorizontalOffset();
      std::cout << "Lower Right Hybrid - Lower LL target angle: " << targetAngle << std::endl;
      double turretOffsetAngle = (atan((tan(targetAngle*3.1415/180)*distance)/(distance + FIELD_POS_OFFSET_FROM_TAG_FLOOR_RIGHT.y)))*180/3.1415;
      std::cout << "Lower Right Hybrid - Lower LL offset angle: " << turretOffsetAngle << std::endl;
      // Calculate the new current poistion to move too.
      double newTurretPosition = m_subTurret->GetDegrees() - turretOffsetAngle;
      std::cout << "Lower Right Hybrid - Lower LL current angle: " << m_subTurret->GetDegrees() << std::endl;
      // Move turret to center target by updating the hold position.
      m_subTurret->RotateToDegree(newTurretPosition);
      std::cout << "Lower Right Hybrid - Lower LL Rotate to: " << newTurretPosition << std::endl;
      m_isFinished = true;
      */
    }
    


  if((m_aprilTagCycle == 3) && (m_timer.HasElapsed(((units::time::second_t)1.0))== true)){
    m_aprilTagCycle =0;
    m_isFinished = true;
  }
}

// Called once the command ends or is interrupted.
void CmdTurretGridPiecePlacement::End(bool interrupted) {
}

// Returns true when the command should end.
bool CmdTurretGridPiecePlacement::IsFinished() {
  std::cout << "Auto Turret GridPlacement ended " << m_isFinished << std::endl;
  return m_isFinished;
}
