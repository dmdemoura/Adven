#ifndef DM_VRAM
#define DM_VRAM

class VramManager
{
private:
    volatile static short * const Vram;
public:
    static void alloc(int halfwordCount);
    static void allocTileset4bit(int tileCount);
    static void allocTileset8bit(int tileCount);
    static void allocSprite4bit(int tileCount);
    static void allocSprite8bit(int tileCount);
    static void allocRegularTilemap(int mapCount);
    //static void allocAffineTilemap(int mapSize);
};

#endif