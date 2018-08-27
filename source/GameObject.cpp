#include "GameObject.hpp"

GameObject::GameObject(GameObject* parent) : parent(parent), localPosition({0,0}) {}
GameObject::GameObject(GameObject* parent, Vector localPosition) : parent(parent), localPosition(localPosition) {}
GameObject::~GameObject()
{
    for (unsigned int i = 0; i < components.size(); i++)
    {
        delete components[i];
    }
}
void GameObject::Start()
{
    for (unsigned int i = 0; i < components.size(); i++){
        components[i]->Start();
    }
}
void GameObject::VDrawUpdate()
{
    for (unsigned int i = 0; i < components.size(); i++){
        components[i]->VDrawUpdate();
    }
}
void GameObject::VBlankUpdate()
{
    for (unsigned int i = 0; i < components.size(); i++){
        components[i]->VBlankUpdate();
    }
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