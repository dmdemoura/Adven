/*
 * Copyright 2018 Amanda de Moura Peres
 * This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at http://mozilla.org/MPL/2.0/.
 */

#ifndef DM_ADVEN_MOVEABLE_HPP
#define DM_ADVEN_MOVEABLE_HPP

#include "Component.hpp"
#include "GameObject.hpp"

namespace Adven
{
    class Moveable : public Component
    {
        friend class GameObject;
    private:
        virtual void Start() override;
        virtual void VDrawUpdate() override;
        virtual void VBlankUpdate() override;
    public:
        AdvenCore::Vector speed;
    };
}

#endif