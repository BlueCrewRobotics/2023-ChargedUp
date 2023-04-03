// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#include "subsystems/SubRobotGlobals.h"

SubRobotGlobals::SubRobotGlobals() = default;

// This method will be called once per scheduler run
void SubRobotGlobals::Periodic() {
    if(g_gameState.selectedPieceType == ConePiece) {
        m_blinkin->Set(BLINKIN_SOLID_YELLOW);
    }
    else if(g_gameState.selectedPieceType == CubePiece) {
        m_blinkin->Set(BLINKIN_SOLID_VIOLET);
    }
}

void SubRobotGlobals::SetColor(double color){
    m_blinkin->Set(color);
}
