#ifndef DM_HWUTILS
#define DM_HWUTILS

class HwUtils
{
public:
    template <typename T, typename T1, typename T2, typename T3>
    static void SetBit(T& dest, T1 value, T2 bitOffset, T3 bitMask)
    {
        dest = (dest & ~((int) bitMask)) | ((int) value << (int) bitOffset & (int) bitMask);
    }
};

#endif