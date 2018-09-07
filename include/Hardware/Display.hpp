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
    enum class ObjectMappingMode
    {
        twoDimensional,
        oneDimensional
    };
private:
    volatile static unsigned short * const displayControlRegister;
public:
    static void Clear();
    static void SetVideoMode(VideoMode videoMode);
    static void SetCurrentPage(int pageId);
    static void EnableHBlankOAMAccess(bool enable);
    static void SetObjectMappingMode(ObjectMappingMode mode);
    static void EnableForcedBlank(bool enable);
    static void EnableBackground(int backgroundID, bool enable);
    static void EnableObjects(bool enable);
    static void EnableBackgroundWindow(int windowID, bool enable);
    static void EnableObjectWindow(bool enable);
};

#endif