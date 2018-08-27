#include "ObjectRenderer.hpp"

ObjectRenderer::ObjectRenderer(GameObject& gameObject, Sprite* sprite) : Component(gameObject)
{
    if (sprite)
    {
        SetBaseTile(sprite->GetBaseTile(0));
        SetColorMode(sprite->GetColorMode());
        SetSpriteSize(sprite->GetSpriteSize());
    }
}
ObjectRenderer::~ObjectRenderer(){}
void ObjectRenderer::Start(){}
void ObjectRenderer::VDrawUpdate(){}
void ObjectRenderer::VBlankUpdate()
{
    SetPosition(gameObject.GetWorldPosition());
}