#include "ObjectRenderer.hpp"
#include "Hardware/VBAPrint.hpp"
#include <cstdio>

ObjectRenderer::ObjectRenderer(GameObject& gameObject) : Component(gameObject) {}
ObjectRenderer::~ObjectRenderer(){}
void ObjectRenderer::Start(){}
void ObjectRenderer::VDrawUpdate(){}
void ObjectRenderer::VBlankUpdate()
{
    SetPosition(gameObject.localPosition);
}