#include "Display.hpp"
#include "HwUtils.hpp"

volatile unsigned short * const Display::displayControlRegister = (volatile unsigned short *) 0x04000000;

unsigned short Display::displayControlBuffer = 0;

void Display::Render()
{
    *displayControlRegister = displayControlBuffer;
}
void Display::Clear()
{
    displayControlBuffer = 0;
}
void Display::SetVideoMode(Display::VideoMode videoMode){
    HwUtils::SetBit(displayControlBuffer, videoMode, BitOffset::VideoMode, BitMask::VideoMode);
}
void Display::SetCurrentPage(int pageId)
{
    HwUtils::SetBit(displayControlBuffer, pageId, BitOffset::PageSelect, BitMask::PageSelect);
}
void Display::EnableHBlankOAMAccess(bool enable)
{
    HwUtils::SetBit(displayControlBuffer, enable, BitOffset::AllowHBlankOAM, BitMask::AllowHBlankOAM);
}
void Display::SetObjectMappingMode(ObjectMappingMode mode)
{
    HwUtils::SetBit(displayControlBuffer, mode, BitOffset::ObjectMappingMode, BitMask::ObjectMappingMode);
}
void Display::EnableForcedBlank(bool enable)
{
    HwUtils::SetBit(displayControlBuffer, enable, BitOffset::ForceBlank, BitMask::ForceBlank);
}
void Display::EnableBackground(int backgroundID, bool enable)
{
    HwUtils::SetBit(displayControlBuffer, enable, (int) BitOffset::DisplayBackground0 + backgroundID, (int) BitMask::DisplayBackground0 << backgroundID);
}
void Display::EnableObjects(bool enable)
{
    HwUtils::SetBit(displayControlBuffer, enable, BitOffset::DisplayObjects, BitMask::DisplayObjects);
}
void Display::EnableBackgroundWindow(int windowID, bool enable)
{
    HwUtils::SetBit(displayControlBuffer, enable, (int) BitOffset::EnableWindow0 + windowID, (int) BitMask::EnableWindow0 << windowID);
}
void Display::EnableObjectWindow(bool enable)
{
    HwUtils::SetBit(displayControlBuffer, enable, BitOffset::EnableObjectWindow, BitMask::EnableObjectWindow);
}