#include "Object.hpp"
#include "HwUtils.hpp"
#include "/home/gabriel/opt/devkitpro/libtonc/include/tonc.h"


volatile Object::ObjectAttr (* const Object::objectAttributeMemory)[MaxObjectCount] = (volatile ObjectAttr (*)[MaxObjectCount]) 0x07000000;
Object::ObjectAttr Object::objectAttributeBuffer[MaxObjectCount] = {};
bool Object::usedObjectIDs[MaxObjectCount] = {};
/*
    Will crash if you try to create more than 128 objects.
*/
Object::Object()
{
    objectID = findFreeObjectID();
    usedObjectIDs[objectID] = true;
}
Object::~Object()
{
    __toncset((void*) &objectAttributeBuffer[objectID], 0, sizeof(ObjectAttr));
    HwUtils::SetBit(objectAttributeBuffer[objectID].attr0, ObjectMode::Hide, Attr0Offsets::ObjectMode, Attr0Masks::ObjectMode);
    usedObjectIDs[objectID] = false;
}
/*
    Finds the first free object ID, returns -1 on fail.
*/
int Object::findFreeObjectID()
{
    for (int i = 0; i < MaxObjectCount; i++)
    {
        if (!usedObjectIDs[i])
            return i;
    }
    return -1;
}
void Object::HideAll()
{
    for (int i = 0; i < MaxObjectCount; i++){
        HwUtils::SetBit(objectAttributeBuffer[i].attr0, ObjectMode::Hide, Attr0Offsets::ObjectMode, Attr0Masks::ObjectMode);
    }
}
void Object::Render()
{
    tonccpy((void*)(*objectAttributeMemory), objectAttributeBuffer, sizeof(ObjectAttr) * MaxObjectCount);
}
void Object::SetPosition(Vector position)
{
    HwUtils::SetBit(objectAttributeBuffer[objectID].attr0 , position.y, 0, Attr0Masks::PositionY);
    HwUtils::SetBit(objectAttributeBuffer[objectID].attr1 , position.x, 0, Attr1Masks::PositionX);
}
void Object::SetObjectMode(ObjectMode objectMode)
{
    HwUtils::SetBit(objectAttributeBuffer[objectID].attr0 , objectMode, Attr0Offsets::ObjectMode, Attr0Masks::ObjectMode);
}
void Object::SetGraphicsMode(GraphicsMode graphicsMode)
{
    HwUtils::SetBit(objectAttributeBuffer[objectID].attr0 , graphicsMode, Attr0Offsets::GraphicsMode, Attr0Masks::GraphicsMode);
}
void Object::SetColorMode(ColorMode colorMode)
{
    HwUtils::SetBit(objectAttributeBuffer[objectID].attr0 , colorMode, Attr0Offsets::ColorMode, Attr0Masks::ColorMode);
}
void Object::SetSpriteSize(SpriteSize spriteSize)
{
    HwUtils::SetBit(objectAttributeBuffer[objectID].attr0 , (int) spriteSize >> 2, Attr0Offsets::SpriteShape, Attr0Masks::SpriteShape);
    HwUtils::SetBit(objectAttributeBuffer[objectID].attr1 , spriteSize, Attr1Offsets::SpriteSize, Attr1Masks::SpriteSize);
}
void Object::SetIsMosaic(bool isMosaic)
{
    HwUtils::SetBit(objectAttributeBuffer[objectID].attr0 , isMosaic, Attr0Offsets::IsMosaic, Attr0Masks::IsMosaic);
}
void Object::SetVerticalFlip(bool enable)
{
    HwUtils::SetBit(objectAttributeBuffer[objectID].attr1 , enable, Attr1Offsets::VerticalFlip, Attr1Masks::VerticalFlip);
}
void Object::SetHorizontalFlip(bool enable)
{
    HwUtils::SetBit(objectAttributeBuffer[objectID].attr1 , enable, Attr1Offsets::HorizontalFlip, Attr1Masks::HorizontalFlip);
}
void Object::SetAffineIndex(int affineIndex)
{
    HwUtils::SetBit(objectAttributeBuffer[objectID].attr1 , affineIndex, Attr1Offsets::AffineIndex, Attr1Masks::AffineIndex);
}
void Object::SetBaseTile(int baseTile)
{
    HwUtils::SetBit(objectAttributeBuffer[objectID].attr2 , baseTile, Attr2Offsets::BaseTile, Attr2Masks::BaseTile);
}
void Object::SetPriority(int priority)
{
    HwUtils::SetBit(objectAttributeBuffer[objectID].attr2 , priority, Attr2Offsets::Priority, Attr2Masks::Priority);
}
void Object::SetPaletteBank(int paletteBank)
{
    HwUtils::SetBit(objectAttributeBuffer[objectID].attr2 , paletteBank, Attr2Offsets::PaletteBank, Attr2Masks::PaletteBank);
}
