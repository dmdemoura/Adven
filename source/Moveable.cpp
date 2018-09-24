#include "Moveable.hpp"

using namespace Adven;

void Moveable::Start() {}
void Moveable::VDrawUpdate()
{
    gameObject->localPosition += speed;
}
void Moveable::VBlankUpdate() {}