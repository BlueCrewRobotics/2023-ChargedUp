// See Documentation :
// https://www.revrobotics.com/content/docs/REV-11-1105-UM.pdf page 14
//
// This is implemented using Spark not Pulse Width
//
// Variable Notation
// Pattern Type_StripPatternColorPalette_NormalAdjustment
// Example:
// 		FPP_RP_PD
//
// 		FPP = Fixed Palette Pattern
// 		RP = Raindbow Palette
// 		PD = Pattern Density
//
//
// Break down of all codes
// Pattern Types:
// 		FPP = Fixed Palette Pattern
// 		COL1 = Color 1 Pattern
// 		COL2 = Color 2 Pattern
// 		COL12 = Color 1 and 2 Pattern
// 		SOL = Solid Colors
//
// Strip Patterns:
// 		RBRB = Rainbow with Rainbow Palette
// 		RBPP = Rainbow with Party Palette
// 		RBOP = Rainbow with Ocean Palette
// 		RBLP = Rainbow with Lave Palette
// 		RBFP = Rainbow with Forest Palette
// 		RBG = Rainbow with Glitter
// 		CONF = Confetti
// 		SHOTR = Shot Red
// 		SHOTB = Shot Blue
//
// 		--!-- There are about 100 more, it would be good to add them at
// some point --!--
//
// Normal Adjustment:
// PD = Pattern Density
// WD = Width Density
// DIM = DIMMING
//
//
// I am only creating the Variables for the ones that we will be using
// as of 2019
//

#include "frc/motorcontrol/Spark.h"

constexpr double BLINKIN_BREATH_BLUE = -0.15;
constexpr double BLINKIN_BREATH_RED = -0.17;
constexpr double BLINKIN_SOLID_RED = 0.61;
constexpr double BLINKIN_SOLID_ORANGE = 0.65;
constexpr double BLINKIN_SOLID_BLUE = 0.87;
constexpr double BLINKIN_SOLID_YELLOW = 0.69;
constexpr double BLINKIN_STROBE_RED = -0.11;
constexpr double BLINKIN_STROBE_BLUE = -0.09;
constexpr double BLINKIN_CONFETTI = -0.87;
constexpr double BLINKIN_BLUE_CHASE =  -0.29;
constexpr double BLINKIN_RAINBOW = -0.99;
constexpr double BLINKIN_FIRE_LARGE = -0.57;
constexpr double BLINKIN_COLOR_WAVE_FOREST = -0.37;
constexpr double BLINKIN_SOLID_BLACK = 0.99;
constexpr double BLINKIN_SOLID_PINK = 0.57;
constexpr double BLINKIN_SOLID_GREEN = 0.77;
constexpr double BLINKIN_SOLID_GOLD = 0.67;
constexpr double BLINKIN_SOLID_VIOLET = 0.91;




class BC_Blinkin {
    public:
        BC_Blinkin(int channel);
        void Set(double setting);


    private:
        frc::Spark* ptr_BlinkinOutput = nullptr;

};
