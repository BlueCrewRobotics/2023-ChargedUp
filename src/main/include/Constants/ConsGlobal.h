/*-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=*/
/*                       Blue Crew Robotics #6153                             */
/*                            Charged Up 2023                                 */
/*-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=*/
// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#pragma once

/**
 * The Constants header provides a convenient place for teams to hold robot-wide
 * numerical or boolean constants.  This should not be used for any other
 * purpose.
 *
 * It is generally a good idea to place constants into subsystem- or
 * command-specific namespaces within this header, which can then be used where
 * they are needed.
 */


enum pieceTypes { ConePiece = 1, CubePiece =2, NoPiece = 0 };
enum nodeTypes { ConeNode = 1, CubeNode = 2, HybridNode = 5, NoNode = 0 };

// Field Measurements (inches)
//    When facing/looking directly at center point of april tag ...
//      x = horizontal (left, right) distance from center point of april tag
//      y = depth (in, out) distance from center point of april tag
//      z = vertical (up, down) distance from center point of april tag
struct fieldpos { float x, y, z; nodeTypes nodeType; };

struct game_state {
  pieceTypes selectedPieceType = ConePiece;
  
};


static game_state g_gameState;



namespace OperatorConstants {
}  // namespace OperatorConstants
