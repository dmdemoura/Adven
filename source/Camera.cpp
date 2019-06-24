/*
 * Copyright 2018 Amanda de Moura Peres
 * This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at http://mozilla.org/MPL/2.0/.
 */

#include "Camera.hpp"

using namespace AdvenCore;
using namespace Adven;

Camera* Camera::instance = nullptr;
/**
 * Static methods
 */
Vector Camera::GetPosition()
{
    if (instance)
        return instance->gameObject->GetWorldPosition() - Vector{120, 80};
    else
        return {0,0};
}
/**
 * Instance methods
 */
Camera::Camera()
{
    if (instance)
        instance->gameObject->RemoveComponent(*instance);

    instance = this;
}
Camera::~Camera()
{
    instance = nullptr;
}
void Camera::Start() {}
void Camera::VDrawUpdate() {}
void Camera::VBlankUpdate() {}