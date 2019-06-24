/*
 * Copyright 2018 Amanda de Moura Peres
 * This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at http://mozilla.org/MPL/2.0/.
 */

#include "CircleCollider.hpp"
#include "Math.hpp"

using namespace Adven;

bool CircleCollider::CheckCollision(const CircleCollider& a, const CircleCollider& b)
{
    int xDistance = a.gameObject->GetWorldPosition().x - b.gameObject->GetWorldPosition().x;
    int yDistance = a.gameObject->GetWorldPosition().y - b.gameObject->GetWorldPosition().y;

    return a.squareRadius + b.squareRadius >= Math::Power(xDistance, 2) + Math::Power(yDistance, 2);
}

CircleCollider::CircleCollider(int squareRadius) : squareRadius(squareRadius)
{
    Register(*this);
}
CircleCollider::~CircleCollider()
{
    Unregister(*this);
}
void CircleCollider::Start() {}
void CircleCollider::VDrawUpdate() {}
void CircleCollider::VBlankUpdate() {}