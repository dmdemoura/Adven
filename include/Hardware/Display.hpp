#ifndef DM_DISPLAY
#define DM_DISPLAY

class Display {
private:
    enum class BitMask
    {
        VideoMode          = 0b0000000000000111,
        PageSelect         = 0b0000000000010000,
        AllowHBlankOAM     = 0b0000000000100000,
        ObjectMappingMode  = 0b0000000001000000,
        ForceBlank         = 0b0000000010000000,
        DisplayBackground0 = 0b0000000100000000,
        DisplayBackground1 = 0b0000001000000000,
        DisplayBackground2 = 0b0000010000000000,
        DisplayBackground3 = 0b0000100000000000,
        DisplayObjects     = 0b0001000000000000,
        EnableWindow0      = 0b0010000000000000,
        EnableWindow1      = 0b0100000000000000,
        EnableObjectWindow = 0b1000000000000000
    };
    enum class BitOffset
    {
        VideoMode          = 0,
        PageSelect         = 4,
        AllowHBlankOAM     = 5,
        ObjectMappingMode  = 6,
        ForceBlank         = 7,
        DisplayBackground0 = 8,
        DisplayBackground1 = 9,
        DisplayBackground2 = 10,
        DisplayBackground3 = 11,
        DisplayObjects     = 12,
        EnableWindow0      = 13,
        EnableWindow1      = 14,
        EnableObjectWindow = 15
    };
public:
    /**
     * @brief Describes the GBA Display VideoModes. 
     * @details The tiled modes support multiple backgrounds.
     * Bitmaps mode only support background 2. Do not forget to enable it.
     * In tiled modes Charblocks 0 to 4 of 
     */
    enum class VideoMode
    {
        Tiled4Regular,          /**< Mode 0: Tiled mode, 4 regular backgrounds */
        Tiled3Regular1Affine,   /**< Mode 1: Tiled mode, 3 regular backgrounds and 1 affine */
        Tiled2Regular2Affine,   /**< Mode 2: Tiled mode, 2 regular backgrounds and 2 affine */
        BitmapSingleFullColor,  /**< Mode 3: Bitmap mode, VRAM is mapped as a single 240x160 16bpp image.*/
        BitmapPagedPaletted,    /**< Mode 4: Bitmap mode, VRAM is mapped as two pages, each 240x160 8bpp paletted (256 colors) images. */
        BitmapPagedFullColor    /**< Mode 5: Bitmap mode, VRAM is mapped as two pages, each 160x128 16bpp images */
    };
    /**
     * @brief Describes the GBA Object Mapping Modes.
     * @details These affect how object tiles are expected to be arranged in memory.
     */
    enum class ObjectMappingMode
    {
        twoDimensional,        /**<Object VRAM is interpreted as 256px by 256px spritesheet. So the rows of a sprite tiles are offset by the size
                                of the spritesheet. It is usually better to use the oneDimensional mode. */
        oneDimensional         /**<Each sprite is interpreted as a separated image. So the second row of as sprite is expected to be right next to the
                                first row. This mode is usually preffered over twoDimensional mode. */
    };
private:
    volatile static unsigned short * const displayControlRegister;
public:
    /**
     * @brief Resets the display control register to default (zero);
     * @details Always use this when the previous state is unknown.
     */
    static void Clear();
    /**
     * @brief Sets the current video mode, changes how VRAM is interpreted.
     * @see Display::Videomode
     * @param videoMode Video mode to set display to. Defaults to Mode 0, Tiled with 4 regular backgrounds.
     */
    static void SetVideoMode(VideoMode videoMode);
    /**
     * @brief Selects between the front and back pages for paged bitmaps modes (4 and 5).
     * @details Swapping pages is used to have the game draw to a buffer, the back page, and only when drawing is done,
     * display it by swapping pages. Has no effect on non paged modes.
     * @param pageID Page ID can be either 0 or 1. Defaults to zero.
     */
    static void SetCurrentPage(int pageId);
    /**
     * @brief Though OAM is normally write locked during VDRAW, this enables OAM access during HBlanks.
     * @details Doing this will reduce how many sprite pixels can be drawn per line.
     * @param enable True enables access, false disables it. Defaults to false.
     */
    static void EnableHBlankOAMAccess(bool enable);
    /**
     * @brief Sets the current object mapping mode, changes how Object VRAM is interpreted.
     * @see Display::ObjectMappingMode
     * @param mode Mapping mode to set display to. Defaults to twoDimensional.
     */
    static void SetObjectMappingMode(ObjectMappingMode mode);
    static void EnableForcedBlank(bool enable);
    /**
     * @brief Enables drawing of a background.
     * @see Backgroudns
     * @param backgroundID Which background to enable/disable, number from 0 to 3.
     * @param enable True is enabled, false is disabled. Defaults to false.
     */
    static void EnableBackground(int backgroundID, bool enable);
    /**
     * @brief Enables drawing of objects.
     * @see Object
     * @param enable True is enabled, false is disabled. Defaults to false.
     */
    static void EnableObjects(bool enable);
    static void EnableBackgroundWindow(int windowID, bool enable);
    static void EnableObjectWindow(bool enable);
};

#endif