/*
 * Copyright 2018 Amanda de Moura Peres
 * This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at http://mozilla.org/MPL/2.0/.
 */

#include "ObjectRenderer.hpp"
#include "Camera.hpp"

using namespace AdvenCore;
using namespace Adven;

ObjectRenderer::ObjectRenderer(Sprite* sprite)
{
    if (!sprite) throw std::invalid_argument("ObjectRenderer(): Sprite is null.");

    SetBaseTile(sprite->GetBaseTile(0));
    SetColorMode(sprite->GetColorMode());
    SetSpriteSize(sprite->GetSpriteSize());
}
void ObjectRenderer::Start(){}
void ObjectRenderer::VDrawUpdate(){}
void ObjectRenderer::VBlankUpdate()
{
    SetPosition(gameObject->GetWorldPosition() - Camera::GetPosition());
}