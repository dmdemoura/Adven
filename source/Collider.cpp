/*
 * Copyright 2018 Gabriel de Moura Peres
 * This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at http://mozilla.org/MPL/2.0/.
 */

#include "Collider.hpp"
#include "RectCollider.hpp"
#include "CircleCollider.hpp"
#include "Moveable.hpp"
#include "Debug.hpp"
#include <algorithm>

using namespace Adven;

std::forward_list<Collider*> Collider::colliders;
/*
    Static methods
*/
void Collider::Register(Collider& collider)
{
    colliders.push_front(&collider);
}
void Collider::Unregister(Collider& collider)
{
    colliders.remove(&collider);
}
void Collider::Update()
{
    Collider* last = nullptr;
    for (auto& collider :  colliders)
    {
        if (last && CheckCollision(*collider, *last))
        {
            Moveable* mc = collider->gameObject->GetComponent<Moveable>();
            if (mc)
            {
                collider->gameObject->localPosition -= mc->speed;
                mc->speed = -mc->speed;
            }

            Moveable* ml = last->gameObject->GetComponent<Moveable>();
            if (ml)
            {
                last->gameObject->localPosition -= ml->speed;
                ml->speed = -mc->speed;
            }
        }
        last = collider;
    }
}
bool Collider::CheckCollision(const Collider& a, const Collider& b)
{
    if (typeid(a) == typeid(RectCollider) && typeid(b) == typeid(RectCollider))
        return RectCollider::CheckCollision(reinterpret_cast<const RectCollider&>(a), reinterpret_cast<const RectCollider&>(b));
    else if (typeid(a) == typeid(CircleCollider) && typeid(b) == typeid(CircleCollider))
        return CircleCollider::CheckCollision(reinterpret_cast<const CircleCollider&>(a), reinterpret_cast<const CircleCollider&>(b));
    else
    {
        Debug::Error("Collider::CheckCollision failed to identify collider type");
        return false;
    }
}