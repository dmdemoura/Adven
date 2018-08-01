#include "Backgrounds.hpp"
#include "HwUtils.hpp"
#include <tonc.h>

volatile short (* const Backgrounds::backgroundControlRegisters)[4] = (volatile short (*)[4]) 0x04000008;
volatile short (* const Backgrounds::backgroundOffsetRegisters)[8] = (volatile short (*)[8]) 0x04000010;

short Backgrounds::backgroundControlBuffer[4] = {};
short Backgrounds::backgroundOffsetBuffer[8] = {};

void Backgrounds::Render()
{
    tonccpy((void *) backgroundControlRegisters, backgroundControlBuffer, sizeof(unsigned short) * 4);
    memcpy16((void *) backgroundOffsetRegisters, backgroundOffsetBuffer, sizeof(unsigned short) * 4);
}
void Backgrounds::SetPriority(int backgroundIndex, int priority)
{
    HwUtils::SetBit(backgroundControlBuffer[backgroundIndex], priority, BitOffsets::Priority, BitMasks::Priority);
}
void Backgrounds::SetBaseCharBlock(int backgroundIndex, int baseCharBlock)
{
    HwUtils::SetBit(backgroundControlBuffer[backgroundIndex], baseCharBlock, BitOffsets::BaseCharBlock, BitMasks::BaseCharBlock);
}
void Backgrounds::SetIsMosaic(int backgroundIndex, bool isMosaic)
{
    HwUtils::SetBit(backgroundControlBuffer[backgroundIndex], isMosaic, BitOffsets::IsMosaic, BitMasks::IsMosaic);
}
void Backgrounds::SetColorMode(int backgroundIndex, Backgrounds::ColorMode colorMode)
{
    HwUtils::SetBit(backgroundControlBuffer[backgroundIndex], colorMode, BitOffsets::ColorMode, BitMasks::ColorMode);
}
void Backgrounds::SetBaseScreenBlock(int backgroundIndex, int baseScreenBlock)
{
    HwUtils::SetBit(backgroundControlBuffer[backgroundIndex], baseScreenBlock, BitOffsets::BaseScreenBlock, BitMasks::BaseScreenBlock);
}
void Backgrounds::SetAffineWrap(int backgroundIndex, bool affineWrap)
{
    HwUtils::SetBit(backgroundControlBuffer[backgroundIndex], affineWrap, BitOffsets::AffineWrap, BitMasks::AffineWrap);
}
void Backgrounds::SetBackgroundSize(int backgroundIndex, Backgrounds::BackgroundSize backgroundSize)
{
    HwUtils::SetBit(backgroundControlBuffer[backgroundIndex], backgroundSize, BitOffsets::BackgroundSize, BitMasks::BackgroundSize);
}
void Backgrounds::SetOffset(int backgroundIndex, Vector offset)
{
    HwUtils::SetBit(backgroundOffsetBuffer[backgroundIndex], offset.x, BitOffsets::BackgroundOffset, BitMasks::BackgroundOffset);
    HwUtils::SetBit(backgroundOffsetBuffer[backgroundIndex + 1], offset.y, BitOffsets::BackgroundOffset, BitMasks::BackgroundOffset);
}