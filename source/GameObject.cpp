/*
 * Copyright 2018 Gabriel de Moura Peres
 * This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at http://mozilla.org/MPL/2.0/.
 */

#include "GameObject.hpp"
#include <algorithm>

using namespace AdvenCore;
using namespace Adven;

GameObject::GameObject(GameObject* parent) : parent(parent), localPosition({0,0}) {}
GameObject::GameObject(GameObject* parent, Vector localPosition) : parent(parent), localPosition(localPosition) {}
void GameObject::Start()
{
    for (auto& component : components)
        component->Start();
}
void GameObject::VDrawUpdate()
{
    for (auto& component : components)
        component->VDrawUpdate();
}
void GameObject::VBlankUpdate()
{
    for (auto& component : components)
        component->VBlankUpdate();
}
GameObject* GameObject::GetParent()
{
    return parent;
}
Vector GameObject::GetWorldPosition()
{
    Vector worldPos = localPosition;
    
    for (GameObject* object = parent; object != nullptr; object=object->parent)
    {
        worldPos += object->localPosition;
    }

    return worldPos;
}
void GameObject::RemoveComponent(const Component& component)
{
    auto compare = [&component](const Component& component2)
    {
         return &component == &component2; 
    };
    RemoveComponent(compare);
}
void GameObject::RemoveComponent(std::function<bool(const Component&)> compare)
{
    auto i = std::find_if(components.cbegin(), components.cend(), [&compare](const std::unique_ptr<Component>& component) { return compare(*component);});
    components.erase(i);
}