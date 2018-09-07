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
    /**
     * Background sizes for tiled Display::VideoMode.
     */
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
    enum class ColorMode
    {
        color4Bit, /**< 2 pixels per byte, use for 16 paletted colors with 16 palette banks */ 
        color8Bit  /**< 1 pixel per byte, use for 256 paletted colors with 1 palette bank */
    };
private:
    static constexpr int BgControlRegisterCount = 4;
    static constexpr int BgOffsetRegisterCount = 8;
    volatile static short (* const backgroundControlRegisters)[BgControlRegisterCount];
    volatile static short (* const backgroundOffsetRegisters)[BgOffsetRegisterCount];
public:
    /**
     * @brief Sets all Display variables to defaults (zero).
     * @details Always use this when the previous state is unknown.
     */
    static void Clear();
    /**
     * @brief Sets the drawing priority of the background.
     * @details Background with higher priority are drawn first, which means they get
     * covered by background and sprites with lower priority.
     * In case a background has the same priority as another, the background
     * of lowest index is drawn first.
     * @see Object::SetPriority(int)
     * @param backgroundIndex Between 0 and 3.
     * @param priority Between 0 and 3. 0 is higher.
     */
    static void SetPriority(int backgroundIndex, int priority);
    /**
     * @brief Sets the base CharBlock for tile indexing.
     * @details The tile index will start at the start of the base CharBlock, however
     * it is possible to use the subsequent CharBlocks as well.
     * Do note that you may not use CharBlocks 4 or 5 for backgrounds, as a base
     * CharBlock or as a subsequent CharBlock.
     * @param backgroundIndex Between 0 and 3.
     * @param baseCharBlock Between 0 and 3. (Background CharBlocks)
     */
    static void SetBaseCharBlock(int backgroundIndex, int baseCharBlock);
    /**
     * @brief Enable the mosaic effect.
     * @details Currently not fully supported.
     * @see Object::SetIsMosaic(bool)
     * @param backgroundIndex Between 0 and 3.
     * @param isMosaic true is enabled, false is disabled. 
     */
    static void SetIsMosaic(int backgroundIndex, bool isMosaic);
    /**
     * @brief Sets the colorMode for a tiled Display::VideoMode.
     * @see Backgrounds::ColorMode
     * @param backgroundIndex Between 0 and 3.
     * @param colorMode 4bit or 8bit.
     */
    static void SetColorMode(int backgroundIndex, ColorMode colorMode);
    /**
     * @brief Sets the starting screenblock of the tilemap to be rendered.
     * @param backgroundIndex Between 0 and 3.
     * @param baseScrenBlock Between 0 and 31.
     */
    static void SetBaseScreenBlock(int backgroundIndex, int baseScreenBlock);
    /**
     * @brief Enables affine backgrounds to wrap around.
     * @details Regular background are not affected, and always wrap around.
     * @param backgroundIndex Between 0 and 3.
     * @param affineWrap true enables wrapping, false disables it.
     */
    static void SetAffineWrap(int backgroundIndex, bool affineWrap);
    /**
     * @brief Sets the backgroundSize for a tiled Display::VideoMode.
     * @see Backgrounds::BackgroundSize.
     * @param backgroundIndex Between 0 and 3.
     * @param backgroundSize BackgroundSize enum.
     */
    static void SetBackgroundSize(int backgroundIndex, BackgroundSize backgroundSize);
    /**
     * @brief Set the position of the screen on the map.
     * @param backgroundIndex Between 0 and 3.
     */
    static void SetOffset(int backgroundIndex, Vector offset);
};

#endif