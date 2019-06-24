/*
 * Copyright 2018 Amanda de Moura Peres
 * This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at http://mozilla.org/MPL/2.0/.
 */

#ifndef DM_ADVEN_COLLIDER_HPP
#define DM_ADVEN_COLLIDER_HPP

#include "GameObject.hpp"
#include "Component.hpp"
#include <forward_list>

namespace Adven
{
    class Collider : public Component
    {
        friend class GameObject;
    private: //Static variables
        static std::forward_list<Collider*> colliders;
    protected: //Static methods
        static void Register(Collider& collider);
        static void Unregister(Collider& collider);
    public: //Static methods
        static void Update();
        static bool CheckCollision(const Collider& a, const Collider& b);
    };
}

#endif