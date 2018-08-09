#include "Moveable.hpp"

Moveable::Moveable(GameObject& gameObject) : Component(gameObject) {}
void Moveable::Start() {}
void Moveable::VDrawUpdate()
{
    gameObject.localPosition += speed;
}
void Moveable::VBlankUpdate() {}