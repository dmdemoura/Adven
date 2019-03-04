/*
 * Copyright 2018 Gabriel de Moura Peres
 * This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at http://mozilla.org/MPL/2.0/.
 */

#ifndef DM_ADVEN_SPRITE_HPP
#define DM_ADVEN_SPRITE_HPP

#include <vector>
#include <advenCore/Types.hpp>
#include <advenCore/Object.hpp>
#include <advenCore/Vector.hpp>
#include <gbfs.h>

namespace Adven
{
    class Sprite
    {
    private: //Static constants
        static AdvenCore::Charblock (* const ObjectVRAM)[2];
        static constexpr int ObjectVRAMSize = 32768;
        static constexpr int MinAllocationBlockSize = 64;
        static constexpr int MaxAllocationBlockSize = 4096;
        static constexpr int magicLength = 16;
        static constexpr char spriteMagic[magicLength] = "--AdvenSprite--";
    private: //Definitions
        struct FreeBlock
        {
            FreeBlock* previousBlock;
            FreeBlock* nextBlock;
            int blockSize;
        };
        struct Header
        {
            char magic[Sprite::magicLength];
            AdvenCore::Object::SpriteSize spriteSize;
            AdvenCore::Object::ColorMode colorMode;
            unsigned char frameCount;
        };
    private: //Static variables
        static FreeBlock* firstBlock;
    private: //Static methods
        /**
         * Splits a free block into two, updating the next block.
         * @param block Block to split.
         * @returns The new block split from the first.
         */
        static FreeBlock* SplitBlock(FreeBlock* block);
        /**
         * Tries to find a preexisting block of size equal to blockSize.
         * @param blockSize Size of the block to search for.
         * @see AllocSpace()
         * @return A free block, if possible, otherwise a nullptr.
         */
        static FreeBlock* FindBlock(int blockSize);
        /**
         * Tries to find or create a block of size equal to blockSize.
         * @param blockSize Size of the block to be returned.
         * @see FindBlock()
         * @returns A free block, if possible, otherwise a nullptr.
         */
        static void* AllocSpace(int blockSize);
    public: //Static methods
        /**
         *  Marks the all the ObjectVRAM as free, initializing all free blocks.
         *  Should be called before any other function, but can be called more than once.
         */
        static void Init();
        /**
         * Converts the sprite size represented by the SpriteSize enum to a vector.
         * @param spriteSize Enumerated sprite size to be converted;
         * @returns A Vector equivalent to spriteSize.
         */
        static AdvenCore::Vector SpriteSizeToVector(AdvenCore::Object::SpriteSize spriteSize);
    private: //Variables
        const Header* header;
        const void* imageData;
        int* vramBaseTiles;
    public: //Methods
        /**
         * Creates a Sprite from a GBFS object.
         * The sprite must have a header.
         * @param spriteFilename The name of the sprite in the gbfs file.
         * @param gbfsFile The gbfsFile where to load the sprite from.
         */
        Sprite(const char* spriteFilename, const GBFS_FILE* gbfsFile);
        /**
         * Creates a Sprite from a pointer to a location containing the
         * sprite header followed by the image data.
         * @param Pointer to the sprite location.
         */
        Sprite(const void* sprite);
        /**
         * Loads this sprite to VRAM, and sets vramCharblock and vramBaseTile to reflect its location.
         * @returns true if successful, false on failure.
         */
        bool LoadToVRAM();
        /**
         * Get the starting tile index that the frame is loaded to.
         * @params frame to return base tile of.
         * @returns The tile index or -1 if the sprite hasn't been loaded, or the frame number was invalid.
         */
        int GetBaseTile(int frame) const;
        /**
         * Get the color mode of the image according to the file header.
         * @returns A colorMode enum.
         */
        AdvenCore::Object::ColorMode GetColorMode() const ;
        /**
         * Get the sprite size of the image according to the file header.
         * @returns A SpriteSize enum value.
         */
        AdvenCore::Object::SpriteSize GetSpriteSize() const;
        /**
         * Get the number of frames this sprite has according to the file header.
         * @returns The number of frames.
         */
        int GetFrameCount() const;
};
}

#endif