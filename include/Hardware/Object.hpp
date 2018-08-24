#ifndef DM_OBJECT
#define DM_OBJECT

#include  "../Vector.hpp"

class Object
{
private:
    struct ObjectAttr
    {
        unsigned short attr0;
        unsigned short attr1;
        unsigned short attr2;
        unsigned short affineAttr;
    };
    enum class Attr0Masks
    {
        PositionY      = 0b0000000011111111,
        ObjectMode     = 0b0000001100000000,
        GraphicsMode   = 0b0000110000000000,
        IsMosaic       = 0b0001000000000000,
        ColorMode      = 0b0010000000000000,
        SpriteShape    = 0b1100000000000000
    };
    enum class Attr1Masks
    {
        PositionX      = 0b0000000111111111,
        AffineIndex    = 0b0011111000000000,
        HorizontalFlip = 0b0001000000000000,
        VerticalFlip   = 0b0010000000000000,
        SpriteSize     = 0b1100000000000000
    };
    enum class Attr2Masks
    {
        BaseTile       = 0b0000001111111111,
        Priority       = 0b0000110000000000,
        PaletteBank    = 0b1111000000000000
    };
    enum class Attr0Offsets
    {
        PositionY      = 0,
        ObjectMode     = 8,
        GraphicsMode   = 10,
        IsMosaic       = 12,
        ColorMode      = 13,
        SpriteShape    = 14
    };
    enum class Attr1Offsets
    {
        PositionX      = 0,
        AffineIndex    = 9,
        HorizontalFlip = 12,
        VerticalFlip   = 13,
        SpriteSize     = 14
    };
    enum class Attr2Offsets
    {
        BaseTile       = 0,
        Priority       = 10,
        PaletteBank    = 12
    };
public:
    enum class ObjectMode
    {
        Regular,
        Affine,
        Hide,
        AffineDouble
    };
    enum class GraphicsMode
    {
        Normal,
        AlphaBlending,
        Window,
    };
    enum class ColorMode : unsigned char
    {
        color4bit,
        color8bit
    };
    enum class SpriteSize : unsigned char
    {
        square8x8   = 0b0000,
        square16x16 = 0b0001,
        square32x32 = 0b0010,
        square64x64 = 0b0011,
        wide16x8    = 0b0100,
        wide32x8    = 0b0101,
        wide32x16   = 0b0110,
        wide64x32   = 0b0111,
        tall8x16    = 0b1000,
        tall8x32    = 0b1001,
        tall16x32   = 0b1010,
        tall32x64   = 0b1011 
    };
private:
    constexpr static int MaxObjectCount = 128;
    volatile static ObjectAttr (* const objectAttributeMemory)[MaxObjectCount];
    static ObjectAttr objectAttributeBuffer[MaxObjectCount];
    /*
        List of objectID currently assigned to an instance of Object.
        True means in use, False means not in use.
    */
    static bool usedObjectIDs[MaxObjectCount];
private:
    int objectID;
private:
    static int findFreeObjectID();
public:
    static void HideAll();
    static void Render();
public:
    Object();
    virtual ~Object();
    void SetPosition(Vector position);
    void SetObjectMode(ObjectMode objectMode);
    void SetGraphicsMode(GraphicsMode graphicsMode);
    void SetColorMode(ColorMode colorMode);
    void SetSpriteSize(SpriteSize spriteSize);
    void SetIsMosaic(bool isMosaic);
    void SetVerticalFlip(bool enable);
    void SetHorizontalFlip(bool enable);
    void SetAffineIndex(int affineIndex);
    void SetBaseTile(int baseTile);
    void SetPriority(int priority);
    void SetPaletteBank(int paletteBank);
};

#endif