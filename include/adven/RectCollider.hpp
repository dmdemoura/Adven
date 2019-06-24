/*
 * Copyright 2018 Amanda de Moura Peres
 * This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at http://mozilla.org/MPL/2.0/.
 */

#ifndef DM_ADVEN_RECTCOLLIDER_HPP
#define DM_ADVEN_RECTCOLLIDER_HPP

#include "Collider.hpp"

namespace Adven
{
    class RectCollider : public Collider
    {
        friend class GameObject;
    private:
        AdvenCore::Vector minOffset;
        AdvenCore::Vector maxOffset;
    public:
        static bool CheckCollision(const RectCollider& a, const RectCollider& b);
    private:
        AdvenCore::Vector GetMinPos() const;
        AdvenCore::Vector GetMaxPos() const;
        virtual void Start() override;
        virtual void VDrawUpdate() override;
        virtual void VBlankUpdate() override;
    public:
        RectCollider(AdvenCore::Vector minOffset, AdvenCore::Vector maxOffset);
        virtual ~RectCollider();
    };
}

#endif