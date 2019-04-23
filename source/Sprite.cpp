/*
 * Copyright 2018 Gabriel de Moura Peres
 * This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at http://mozilla.org/MPL/2.0/.
 */

#include <tonc.h>
#include "Sprite.hpp"
#include "Debug.hpp"

using namespace AdvenCore;
using namespace Adven;

volatile unsigned short * const Sprite::ObjectVRAM = (volatile unsigned short * const) 0x06000000;
/*
    Public static methods
*/
Vector Sprite::SpriteSizeToVector(Object::SpriteSize spriteSize)
{
    switch(spriteSize)
    {
        case Object::SpriteSize::square8x8:
            return Vector(8,8);
        case Object::SpriteSize::square16x16:
            return Vector(16,16);
        case Object::SpriteSize::square32x32:
            return Vector(32,32);
        case Object::SpriteSize::square64x64:
            return Vector(64,64);
        case Object::SpriteSize::wide16x8:
            return Vector(16,8);
        case Object::SpriteSize::wide32x8:
            return Vector(32,8);
        case Object::SpriteSize::wide32x16:
            return Vector(32,16);
        case Object::SpriteSize::wide64x32:
            return Vector(64,32);
        case Object::SpriteSize::tall8x16:
            return Vector(8,16);
        case Object::SpriteSize::tall8x32:
            return Vector(8,32);
        case Object::SpriteSize::tall16x32:
            return Vector(16,32);
        case Object::SpriteSize::tall32x64:
            return Vector(32,64);
        default:
            return Vector(0,0);
    }
}
/*
    Public instance methods
*/
Sprite::Sprite(const char* spriteFilename, const GBFS_FILE* gbfsFile, Adven::Allocator& allocator)
    : Sprite(gbfs_get_obj(gbfsFile, spriteFilename, nullptr), allocator) {}
Sprite::Sprite(const void* sprite, Adven::Allocator& allocator) : allocator(allocator)
{
    header = (Header*) sprite;
    bool valid = true;
    for (int i = 0; i < magicLength; i++)
    {
        if (header->magic[i] != spriteMagic[i])
        {
            valid = false;
            break;
        }
    }
    if (valid)
        imageData = (char*) sprite + sizeof(Header);
    else
        Debug::Error("Invalid sprite header");
}
bool Sprite::LoadToVRAM()
{
    Vector spriteSize = SpriteSizeToVector(header->spriteSize);

    unsigned int blockSize = (unsigned int) spriteSize.x * spriteSize.y;
    if (header->colorMode == Object::ColorMode::color4bit)
        blockSize = blockSize >> 1;

    vramBaseTiles = new int[header->frameCount];
    for (int i = 0; i < header->frameCount; i++)
    {
        void* space = allocator.Allocate(blockSize);
        
        if (space)
        {    
            int frameOffset = i * blockSize;
            void* frameData = (char*) imageData + frameOffset;
            tonccpy(space, frameData, blockSize);

            int tileID = ((int) space - (int) ObjectVRAM) >> 5;
            vramBaseTiles[i] = tileID;
        }
        else
            return false;
    }
    return true;
}
int Sprite::GetBaseTile(int frame) const
{
    return vramBaseTiles[frame];
}
Object::ColorMode Sprite::GetColorMode() const
{
    return header->colorMode;
}
Object::SpriteSize Sprite::GetSpriteSize() const
{
    return header->spriteSize;
}
int Sprite::GetFrameCount() const
{
    return header->frameCount;
}