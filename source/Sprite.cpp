#include "Sprite.hpp"
#include "Hardware/VBAPrint.hpp"
#include <cstring>

Charblock (* const Sprite::ObjectVRAM)[2] = (Charblock(*)[2]) 0x06010000;
Sprite::FreeBlock* Sprite::firstBlock = nullptr;

/*
    Private static methods
*/
void Sprite::Init()
{
    FreeBlock* lastBlock = nullptr;
    for (int i = 0; i * MaxAllocationBlockSize < ObjectVRAMSize; i++)
    {
        FreeBlock* currentBlock = (FreeBlock*) ((char*) ObjectVRAM + MaxAllocationBlockSize * i);

        currentBlock->blockSize = MaxAllocationBlockSize;
        currentBlock->previousBlock = lastBlock;
        currentBlock->nextBlock = nullptr;
        if (lastBlock)
            lastBlock->nextBlock = currentBlock;

        lastBlock = currentBlock;
    }
    firstBlock = (FreeBlock*) ObjectVRAM;
}
Sprite::FreeBlock* Sprite::SplitBlock(FreeBlock* block)
{
    block->blockSize = block->blockSize >> 1;
    FreeBlock* newBlock = (FreeBlock*) ((char*) block + block->blockSize);
    newBlock->blockSize = block->blockSize;
    newBlock->previousBlock = block;
    newBlock->nextBlock = block->nextBlock;
    block->nextBlock = newBlock;
    return newBlock;
}
Sprite::FreeBlock* Sprite::FindBlock(int blockSize)
{
    FreeBlock* currentBlock = firstBlock;
    while(currentBlock && currentBlock->blockSize != blockSize)
    {
        currentBlock = currentBlock->nextBlock;
    }
    return currentBlock;
}
void* Sprite::AllocSpace(int blockSize)
{
    FreeBlock* block = nullptr;

    int increasingBlockSize = blockSize;

    while (block == nullptr && increasingBlockSize <= MaxAllocationBlockSize)
    {
        block = FindBlock(increasingBlockSize);
        increasingBlockSize *= 2;
    }
    
    if (block != nullptr)
    {
        while (block->blockSize != blockSize)
        {
            SplitBlock(block); 
        }
    }
    block->previousBlock->nextBlock = block->nextBlock;
    block->nextBlock->previousBlock = block->previousBlock;

    if (block == firstBlock)
        firstBlock = block->nextBlock;

    return block;
}
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
Sprite::Sprite(const char* spriteFilename, const GBFS_FILE* gbfsFile) : Sprite(gbfs_get_obj(gbfsFile, spriteFilename, nullptr)) {}
Sprite::Sprite(const void* sprite)
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
        VBAPrint("Invalid sprite header");
}
bool Sprite::LoadToVRAM()
{
    Vector spriteSize = SpriteSizeToVector(header->spriteSize);

    unsigned int blockSize = spriteSize.x * spriteSize.y;
    if (header->colorMode == Object::ColorMode::color4bit)
        blockSize = blockSize >> 1;

    for (int i = 0; i < header->frameCount; i++)
    {
        void* space = AllocSpace(blockSize);
        
        if (space)
        {
            tonccpy(space, imageData, blockSize);

            int tileID = ((int) space - (int) ObjectVRAM) >> 5;
            vramBaseTiles.push_back(tileID);
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