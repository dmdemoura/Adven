#include "ObjectRenderer.hpp"
#include "Camera.hpp"

ObjectRenderer::ObjectRenderer(Sprite* sprite)
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
    SetPosition(gameObject->GetWorldPosition() - Camera::GetPosition());
}