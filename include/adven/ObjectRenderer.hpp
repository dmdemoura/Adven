/*
 * Copyright 2018 Amanda de Moura Peres
 * This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at http://mozilla.org/MPL/2.0/.
 */

#ifndef DM_ADVEN_OBJECTRENDERER_HPP
#define DM_ADVEN_OBJECTRENDERER_HPP

#include <advenCore/Object.hpp>
#include <advenCore/Vector.hpp>
#include "Component.hpp"
#include "GameObject.hpp"
#include "Sprite.hpp"

namespace Adven
{
    class ObjectRenderer : public Component, public AdvenCore::Object
    {
        friend class GameObject;
    private:
        void Start() override;
        void VDrawUpdate() override;
        void VBlankUpdate() override;
    public:
        explicit ObjectRenderer(Sprite* sprite = nullptr);
        ~ObjectRenderer() override = default;
    };
}

#endif