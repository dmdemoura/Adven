#include "Display.hpp"
#include "HwUtils.hpp"

volatile unsigned short * const Display::displayControlRegister = (volatile unsigned short *) 0x04000000;

void Display::Clear()
{
    *displayControlRegister = 0;
}
void Display::SetVideoMode(Display::VideoMode videoMode){
    HwUtils::SetBit(*displayControlRegister, videoMode, BitOffset::VideoMode, BitMask::VideoMode);
}
void Display::SetCurrentPage(int pageId)
{
    HwUtils::SetBit(*displayControlRegister, pageId, BitOffset::PageSelect, BitMask::PageSelect);
}
void Display::EnableHBlankOAMAccess(bool enable)
{
    HwUtils::SetBit(*displayControlRegister, enable, BitOffset::AllowHBlankOAM, BitMask::AllowHBlankOAM);
}
void Display::SetObjectMappingMode(ObjectMappingMode mode)
{
    HwUtils::SetBit(*displayControlRegister, mode, BitOffset::ObjectMappingMode, BitMask::ObjectMappingMode);
}
void Display::EnableForcedBlank(bool enable)
{
    HwUtils::SetBit(*displayControlRegister, enable, BitOffset::ForceBlank, BitMask::ForceBlank);
}
void Display::EnableBackground(int backgroundID, bool enable)
{
    HwUtils::SetBit(*displayControlRegister, enable, (int) BitOffset::DisplayBackground0 + backgroundID, (int) BitMask::DisplayBackground0 << backgroundID);
}
void Display::EnableObjects(bool enable)
{
    HwUtils::SetBit(*displayControlRegister, enable, BitOffset::DisplayObjects, BitMask::DisplayObjects);
}
void Display::EnableBackgroundWindow(int windowID, bool enable)
{
    HwUtils::SetBit(*displayControlRegister, enable, (int) BitOffset::EnableWindow0 + windowID, (int) BitMask::EnableWindow0 << windowID);
}
void Display::EnableObjectWindow(bool enable)
{
    HwUtils::SetBit(*displayControlRegister, enable, BitOffset::EnableObjectWindow, BitMask::EnableObjectWindow);
}