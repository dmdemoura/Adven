#include "Backgrounds.hpp"
#include "HwUtils.hpp"
#include <tonc.h>

volatile short (* const Backgrounds::backgroundControlRegisters)[BgControlRegisterCount] = (volatile short (*)[BgControlRegisterCount]) 0x04000008;
volatile short (* const Backgrounds::backgroundOffsetRegisters)[BgOffsetRegisterCount] = (volatile short (*)[BgOffsetRegisterCount]) 0x04000010;

void Backgrounds::Clear()
{
    toncset((void *) backgroundControlRegisters, 0, BgControlRegisterCount + BgOffsetRegisterCount);
}
void Backgrounds::SetPriority(int backgroundIndex, int priority)
{
    HwUtils::SetBit((*backgroundControlRegisters)[backgroundIndex], priority, BitOffsets::Priority, BitMasks::Priority);
}
void Backgrounds::SetBaseCharBlock(int backgroundIndex, int baseCharBlock)
{
    HwUtils::SetBit((*backgroundControlRegisters)[backgroundIndex], baseCharBlock, BitOffsets::BaseCharBlock, BitMasks::BaseCharBlock);
}
void Backgrounds::SetIsMosaic(int backgroundIndex, bool isMosaic)
{
    HwUtils::SetBit((*backgroundControlRegisters)[backgroundIndex], isMosaic, BitOffsets::IsMosaic, BitMasks::IsMosaic);
}
void Backgrounds::SetColorMode(int backgroundIndex, Backgrounds::ColorMode colorMode)
{
    HwUtils::SetBit((*backgroundControlRegisters)[backgroundIndex], colorMode, BitOffsets::ColorMode, BitMasks::ColorMode);
}
void Backgrounds::SetBaseScreenBlock(int backgroundIndex, int baseScreenBlock)
{
    HwUtils::SetBit((*backgroundControlRegisters)[backgroundIndex], baseScreenBlock, BitOffsets::BaseScreenBlock, BitMasks::BaseScreenBlock);
}
void Backgrounds::SetAffineWrap(int backgroundIndex, bool affineWrap)
{
    HwUtils::SetBit((*backgroundControlRegisters)[backgroundIndex], affineWrap, BitOffsets::AffineWrap, BitMasks::AffineWrap);
}
void Backgrounds::SetBackgroundSize(int backgroundIndex, Backgrounds::BackgroundSize backgroundSize)
{
    HwUtils::SetBit((*backgroundControlRegisters)[backgroundIndex], backgroundSize, BitOffsets::BackgroundSize, BitMasks::BackgroundSize);
}
void Backgrounds::SetOffset(int backgroundIndex, Vector offset)
{
    HwUtils::SetBit((*backgroundOffsetRegisters)[backgroundIndex * 2], offset.x, BitOffsets::BackgroundOffset, BitMasks::BackgroundOffset);
    HwUtils::SetBit((*backgroundOffsetRegisters)[backgroundIndex * 2 + 1], offset.y, BitOffsets::BackgroundOffset, BitMasks::BackgroundOffset);
}