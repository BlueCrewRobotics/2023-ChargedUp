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
  m_aprilTagCycle = 0;
  m_isFinished = false;
}

// Called repeatedly when this Command is scheduled to run
void CmdTurretGridPiecePlacement::Execute() {

  /*********************** CUBE PLACEMENT ***************************    
    Configure the limelight for the cube piece that is selected
    Work down through the aprilTag selections until we find a target 
    over several execution of the robot code.
  */ 
  if(m_subRobotGlobals->g_gameState.selectedPieceType == CubePiece && m_aprilTagCycle == 0){
    m_subLimeLightLower->SelectPipeline(LL_PIPELINE_APRILTAG_1n8);
    m_subLimeLightUpper->SelectPipeline(LL_PIPELINE_APRILTAG_1n8);
  }
  if(m_subRobotGlobals->g_gameState.selectedPieceType == CubePiece && m_aprilTagCycle == 1){
    m_subLimeLightLower->SelectPipeline(LL_PIPELINE_APRILTAG_2n7);
    m_subLimeLightUpper->SelectPipeline(LL_PIPELINE_APRILTAG_2n7);
  }
  if(m_subRobotGlobals->g_gameState.selectedPieceType == CubePiece && m_aprilTagCycle == 2){
    m_subLimeLightLower->SelectPipeline(LL_PIPELINE_APRILTAG_3n6);
    m_subLimeLightUpper->SelectPipeline(LL_PIPELINE_APRILTAG_3n6);
  }

  // Check if the target is within range to place cube.  Might have to move verical elevator so aprilTag can be seen
  if(m_subLimeLightUpper->GetTarget()==true || m_subLimeLightLower->GetTarget()==true){
    // *************************************************************************************************************
    // Check if there is a target for the middle cube shelf
    if(m_subLimeLightUpper->GetTarget()==true && (m_auxController->GetPOV() == DPAD_VALUE_MIDDLE_CENTER))
    {
      double distance = m_subLimeLightUpper->GetDistanceToTarget(LL_LIMELIGHT_UPPER_HEIGHT,TARGET_APRILTAG_GRID_HEIGHT,LL_LIMELIGHT_UPPER_ANGLE);
      double targetAngle = m_subLimeLightUpper->GetHorizontalOffset();
      double turretOffsetAngle = atan((tan(targetAngle)*distance)/(distance + FIELD_POS_OFFSET_FROM_TAG_SHELF_MIDDLE.y));
      // See if target placement location is within max range extension of horizontal evelvator 
      if(100/* Change this 100 to the max reach distance of the horizontal elevator*/ - ((distance + FIELD_POS_OFFSET_FROM_TAG_SHELF_MIDDLE.y)/ cos(turretOffsetAngle)) < 0 ){
        // Calculate the new current poistion to move too.
        double newTurretPosition = m_subTurret->GetDegrees() + turretOffsetAngle;
        // Move turret to center target by updating the hold position.
        m_subTurret->RotateToDegree(newTurretPosition);

      }
    }
    else if(m_subLimeLightLower->GetTarget()==true && (m_auxController->GetPOV() == DPAD_VALUE_MIDDLE_CENTER))
    {
      double distance = m_subLimeLightLower->GetDistanceToTarget(LL_LIMELIGHT_LOWER_HEIGHT,TARGET_APRILTAG_GRID_HEIGHT,LL_LIMELIGHT_LOWER_ANGLE);
      double targetAngle = m_subLimeLightLower->GetHorizontalOffset();
      double turretOffsetAngle = atan((tan(targetAngle)*distance)/(distance + FIELD_POS_OFFSET_FROM_TAG_SHELF_MIDDLE.y));
      // See if target placement location is within max range extension of horizontal evelvator 
      if(100/* Change this 100 to the max reach distance of the horizontal elevator*/ - ((distance + FIELD_POS_OFFSET_FROM_TAG_SHELF_MIDDLE.y)/ cos(turretOffsetAngle)) < 0 ){
        // Calculate the new current poistion to move too.
        double newTurretPosition = m_subTurret->GetDegrees() + turretOffsetAngle;
        // Move turret to center target by updating the hold position.
        m_subTurret->RotateToDegree(newTurretPosition);
      }
    }
    // **************************************************************************************************************
    // Check if there is a target for the upper cude shelf
    if(m_subLimeLightUpper->GetTarget()==true && (m_auxController->GetPOV() == DPAD_VALUE_MIDDLE_UP))
    {
      double distance = m_subLimeLightUpper->GetDistanceToTarget(LL_LIMELIGHT_UPPER_HEIGHT,TARGET_APRILTAG_GRID_HEIGHT,LL_LIMELIGHT_UPPER_ANGLE);
      double targetAngle = m_subLimeLightUpper->GetHorizontalOffset();
      double turretOffsetAngle = atan((tan(targetAngle)*distance)/(distance + FIELD_POS_OFFSET_FROM_TAG_SHELF_TOP.y));
      // See if target placement location is within max range extension of horizontal evelvator 
      if(100/* Change this 100 to the max reach distance of the horizontal elevator*/ - ((distance + FIELD_POS_OFFSET_FROM_TAG_SHELF_TOP.y)/ cos(turretOffsetAngle)) < 0 ){
        // Calculate the new current poistion to move too.
        double newTurretPosition = m_subTurret->GetDegrees() + turretOffsetAngle;
        // Move turret to center target by updating the hold position.
        m_subTurret->RotateToDegree(newTurretPosition);

      }
    }
    else if(m_subLimeLightLower->GetTarget()==true && (m_auxController->GetPOV() == DPAD_VALUE_MIDDLE_UP))
    {
      double distance = m_subLimeLightLower->GetDistanceToTarget(LL_LIMELIGHT_LOWER_HEIGHT,TARGET_APRILTAG_GRID_HEIGHT,LL_LIMELIGHT_LOWER_ANGLE);
      double targetAngle = m_subLimeLightLower->GetHorizontalOffset();
      double turretOffsetAngle = atan((tan(targetAngle)*distance)/(distance + FIELD_POS_OFFSET_FROM_TAG_SHELF_TOP.y));
      // See if target placement location is within max range extension of horizontal evelvator 
      if(100/* Change this 100 to the max reach distance of the horizontal elevator*/ - ((distance + FIELD_POS_OFFSET_FROM_TAG_SHELF_TOP.y)/ cos(turretOffsetAngle)) < 0 ){
        // Calculate the new current poistion to move too.
        double newTurretPosition = m_subTurret->GetDegrees() + turretOffsetAngle;
        // Move turret to center target by updating the hold position.
        m_subTurret->RotateToDegree(newTurretPosition);
      }
    }

    else{
      if(m_aprilTagCycle == 3){
        m_isFinished = true;
      }
      m_aprilTagCycle = m_aprilTagCycle++;
    }

  }
  
  /*********************** CONE PLACEMENT ***************************    
   Configure the limelight for the cone piece that is selected by DPAD
   Determine if the cone piece location is within range to place the cone.
  */ 
    
  if (m_subRobotGlobals->g_gameState.selectedPieceType == ConePiece && (m_auxController->GetPOV() == DPAD_VALUE_MIDDLE_UP))
  {
    m_subLimeLightLower->SelectPipeline(LL_PIPLINE_TARGET_UPPER_CONE);
    m_subLimeLightUpper->SelectPipeline(LL_PIPLINE_TARGET_UPPER_CONE);   
  }

  // Check if we have a target based on the game piece selection and DPAD pressed location

  

  // Check if the target is within range to place
  if(m_subLimeLightUpper->GetTarget()==true){

  }
  
  if((m_subRobotGlobals->g_gameState.selectedPieceType == ConePiece) && (m_auxController->GetPOV() == DPAD_VALUE_MIDDLE_UP) || (m_auxController->GetPOV() == DPAD_VALUE_LEFT_UP) || (m_auxController->GetPOV() == DPAD_VALUE_RIGHT_UP) ){
    //m_subVerticalElevator->ServoToPosition(VERTICAL_ELEV_POS_CONE_NODE_UPPER);
  }
  if((m_subRobotGlobals->g_gameState.selectedPieceType == ConePiece) && (m_auxController->GetPOV() == DPAD_VALUE_MIDDLE_CENTER) || (m_auxController->GetPOV() == DPAD_VALUE_LEFT_CENTER) || (m_auxController->GetPOV() == DPAD_VALUE_RIGHT_CENTER) ){
    //m_subVerticalElevator->ServoToPosition(VERTICAL_ELEV_POS_CONE_NODE_LOWER);
  }
  if((m_subRobotGlobals->g_gameState.selectedPieceType == ConePiece || m_subRobotGlobals->g_gameState.selectedPieceType == CubePiece) && (m_auxController->GetPOV() == DPAD_VALUE_MIDDLE_DOWN) || (m_auxController->GetPOV() == DPAD_VALUE_LEFT_DOWN) || (m_auxController->GetPOV() == DPAD_VALUE_RIGHT_DOWN) ){
    //m_subVerticalElevator->ServoToPosition(VERTICAL_ELEV_POS_HYBRID_NODE);
  }
  if((m_subRobotGlobals->g_gameState.selectedPieceType == CubePiece) && (m_auxController->GetPOV() == DPAD_VALUE_MIDDLE_UP) || (m_auxController->GetPOV() == DPAD_VALUE_RIGHT_DOWN) || (m_auxController->GetPOV() == DPAD_VALUE_RIGHT_UP) ){
    //m_subVerticalElevator->ServoToPosition(VERTICAL_ELEV_POS_CUBE_NODE_UPPER);
  }
  if((m_subRobotGlobals->g_gameState.selectedPieceType == CubePiece) && (m_auxController->GetPOV() == DPAD_VALUE_MIDDLE_CENTER) || (m_auxController->GetPOV() == DPAD_VALUE_LEFT_CENTER) || (m_auxController->GetPOV() == DPAD_VALUE_RIGHT_CENTER) ){
    //m_subVerticalElevator->ServoToPosition(VERTICAL_ELEV_POS_CUBE_NODE_LOWER);
  }
}

// Called once the command ends or is interrupted.
void CmdTurretGridPiecePlacement::End(bool interrupted) {}

// Returns true when the command should end.
bool CmdTurretGridPiecePlacement::IsFinished() {
  return m_isFinished;
}
