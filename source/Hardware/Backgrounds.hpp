#ifndef DM_BACKGROUNDS
#define DM_BACKGROUNDS

#include "../Vector.hpp"

class Backgrounds
{
private:
    enum class BitMasks
    {
        Priority           = 0b0000000000000011,
        BaseCharBlock      = 0b0000000000001100,
        IsMosaic           = 0b0000000001000000,
        ColorMode          = 0b0000000010000000,
        BaseScreenBlock    = 0b0001111100000000,
        AffineWrap         = 0b0010000000000000,
        BackgroundSize     = 0b1100000000000000,
        BackgroundOffset   = 0b0000000111111111
    };
    enum class BitOffsets
    {
        Priority             = 0,
        BaseCharBlock        = 2,
        IsMosaic             = 6,
        ColorMode            = 7,
        BaseScreenBlock      = 8,
        AffineWrap           = 13,
        BackgroundSize       = 14,
        BackgroundOffset     = 0
    };
public:
    enum class BackgroundSize
    { 
        regular32x32  = 0,
        regular64x32  = 1,
        regular32x64  = 2,
        regular64x64  = 3,
        affine16x16   = 0,
        affine32x32   = 1,
        affine64x64   = 2,
        affine128x128 = 3
    };
    enum class ColorMode { color4Bit, color8Bit };
private:
    volatile static short (* const backgroundControlRegisters)[4];
    volatile static short (* const backgroundOffsetRegisters)[8];
private:
    static short backgroundControlBuffer[4];
    static short backgroundOffsetBuffer[8];
public:
    static void Render();
    static void SetPriority(int backgroundIndex, int priority);
    static void SetBaseCharBlock(int backgroundIndex, int baseCharBlock);
    static void SetIsMosaic(int backgroundIndex, bool isMosaic);
    static void SetColorMode(int backgroundIndex, ColorMode colorMode);
    static void SetBaseScreenBlock(int backgroundIndex, int baseScreenBlock);
    static void SetAffineWrap(int backgroundIndex, bool affineWrap);
    static void SetBackgroundSize(int backgroundIndex, BackgroundSize backgroundSize);
    static void SetOffset(int backgroundIndex, Vector offset);
};

#endif