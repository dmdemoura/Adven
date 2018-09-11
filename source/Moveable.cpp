#include "Moveable.hpp"

void Moveable::Start() {}
void Moveable::VDrawUpdate()
{
    gameObject->localPosition += speed;
}
void Moveable::VBlankUpdate() {}