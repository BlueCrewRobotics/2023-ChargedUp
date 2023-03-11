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
    std::cout << "Limelight Upper distance: " << m_subLimeLightUpper->GetDistanceToTarget(LL_LIMELIGHT_UPPER_HEIGHT, TARGET_APRILTAG_GRID_HEIGHT, LL_LIMELIGHT_UPPER_ANGLE) << std::endl;
    m_subLimeLightLower->SelectPipeline(LL_PIPELINE_APRILTAG_2n7);
      std::cout << "AprilTag 2 or 7 Selected"<< std::endl;
      m_aprilTagCycle = m_aprilTagCycle + 1;
  }
  if(m_timer.HasElapsed(((units::time::second_t)0.75)) == true && m_aprilTagCycle == 2){
    m_subLimeLightLower->SelectPipeline(LL_PIPELINE_APRILTAG_3n6);
      std::cout << "AprilTag 3 or 6 Selected"<< std::endl;
      m_aprilTagCycle = m_aprilTagCycle + 1;
  }
  // ****************************************************************************************************************
  // Check if there is an AprilTag target and move the turret to the middle cube self.
    if(m_subLimeLightLower->GetTarget()==true && (m_auxController->GetPOV() == DPAD_VALUE_MIDDLE_CENTER) && m_subRobotGlobals->g_gameState.selectedPieceType == CubePiece)
    {
      double distance = m_subLimeLightLower->GetDistanceToTarget(LL_LIMELIGHT_LOWER_HEIGHT,TARGET_APRILTAG_GRID_HEIGHT,LL_LIMELIGHT_LOWER_ANGLE);
      std::cout << "Middle Center Self - Lower LL distance: " << distance << std::endl;
      double targetAngle = m_subLimeLightLower->GetHorizontalOffset();
      std::cout << "Middle Center Self - Lower LL target angle: " << targetAngle << std::endl;
      double turretOffsetAngle = (atan((tan(targetAngle*3.1415/180)*distance)/(distance + FIELD_POS_OFFSET_FROM_TAG_SHELF_MIDDLE.y)))*180/3.1415;
      std::cout << "Middle Center Self - Lower LL offset angle: " << turretOffsetAngle << std::endl;
      // Calculate the new current poistion to move too.
      double newTurretPosition = m_subTurret->GetDegrees() - turretOffsetAngle;
      std::cout << "Middle Center Self - Lower LL current angle: " << m_subTurret->GetDegrees() << std::endl;
      // Move turret to center target by updating the hold position.
      m_subTurret->RotateToDegree(newTurretPosition);
      std::cout << "Middle Center Self - Lower LL Rotate to: " << newTurretPosition << std::endl;
      m_isFinished = true;
      
      
    }
    // **************************************************************************************************************
    // Check if there is an AprilTag target and move the turret to the upper cube self.
    if(m_subLimeLightLower->GetTarget()==true && (m_auxController->GetPOV() == DPAD_VALUE_MIDDLE_UP) && m_subRobotGlobals->g_gameState.selectedPieceType == CubePiece)
    {
      double distance = m_subLimeLightLower->GetDistanceToTarget(LL_LIMELIGHT_LOWER_HEIGHT,TARGET_APRILTAG_GRID_HEIGHT,LL_LIMELIGHT_LOWER_ANGLE);
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
    }
    // ****************************************************************************************************************
    // Check if there is an AprilTag target and move the turret to the upper right cone poll if cone is selected
    if(m_subLimeLightLower->GetTarget()==true && (m_auxController->GetPOV() == DPAD_VALUE_RIGHT_UP) && m_subRobotGlobals->g_gameState.selectedPieceType == ConePiece)
    {
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
    }

    // ****************************************************************************************************************
    // Check if there is an AprilTag target and move the turret to the middle right cone poll if cone is selected
    if(m_subLimeLightLower->GetTarget()==true && (m_auxController->GetPOV() == DPAD_VALUE_RIGHT_CENTER) && m_subRobotGlobals->g_gameState.selectedPieceType == ConePiece)
    {
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
    }

    // ****************************************************************************************************************
    // Check if there is an AprilTag target and move the turret to the upper left cone poll if cone is selected
    if(m_subLimeLightLower->GetTarget()==true && (m_auxController->GetPOV() == DPAD_VALUE_LEFT_UP) && m_subRobotGlobals->g_gameState.selectedPieceType == ConePiece)
    {
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
    }

    // ****************************************************************************************************************
    // Check if there is an AprilTag target and move the turret to the middle left cone poll if cone is selected
    if(m_subLimeLightLower->GetTarget()==true && (m_auxController->GetPOV() == DPAD_VALUE_LEFT_CENTER) && m_subRobotGlobals->g_gameState.selectedPieceType == ConePiece)
    {
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
    }


    // Will need to use the upper limelight to target the aprilTags for hybrid placement becasue lower limelight can't see the target
    
    // ****************************************************************************************************************
    // Check if there is an AprilTag target and move the turret to the lower left hybrid location

    // ****************************************************************************************************************
    // Check if there is an AprilTag target and move the turret to the lower middle hybrid location

    // ****************************************************************************************************************
    // Check if there is an AprilTag target and move the turret to the lower right hybrid location

    


  if(m_aprilTagCycle == 3){
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
