/*
 * Copyright 2018 Amanda de Moura Peres
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
#include "Allocator.hpp"

namespace Adven
{
    class Sprite
    {
    private: //Static constants
        static volatile unsigned short * const ObjectVRAM;
        static constexpr int magicLength = 16;
        static constexpr char spriteMagic[magicLength] = "--AdvenSprite--";
    private: //Definitions
        struct Header
        {
            char magic[Sprite::magicLength];
            AdvenCore::Object::SpriteSize spriteSize;
            AdvenCore::Object::ColorMode colorMode;
            unsigned char frameCount;
        };
    public: //Static methods
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
        Adven::Allocator& allocator;
    public: //Methods
        /**
         * Creates a Sprite from a GBFS object.
         * The sprite must have a header.
         * @param spriteFilename The name of the sprite in the gbfs file.
         * @param gbfsFile The gbfsFile where to load the sprite from.
         */
        Sprite(const char* spriteFilename, const GBFS_FILE* gbfsFile, Adven::Allocator& allocator);
        /**
         * Creates a Sprite from a pointer to a location containing the
         * sprite header followed by the image data.
         * @param Pointer to the sprite location.
         */
        Sprite(const void* sprite, Adven::Allocator& allocator);
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