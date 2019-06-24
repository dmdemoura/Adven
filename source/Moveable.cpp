/*
 * Copyright 2018 Amanda de Moura Peres
 * This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at http://mozilla.org/MPL/2.0/.
 */

#include "Moveable.hpp"

using namespace Adven;

void Moveable::Start() {}
void Moveable::VDrawUpdate()
{
    gameObject->localPosition += speed;
}
void Moveable::VBlankUpdate() {}