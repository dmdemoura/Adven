#include "CircleCollider.hpp"
#include "Math.hpp"

using namespace Adven;

bool CircleCollider::CheckCollision(const CircleCollider& a, const CircleCollider& b)
{
    int xDistance = a.gameObject->GetWorldPosition().x - b.gameObject->GetWorldPosition().x;
    int yDistance = a.gameObject->GetWorldPosition().y - b.gameObject->GetWorldPosition().y;

    return a.squareRadius + b.squareRadius >= Math::Power(xDistance, 2) + Math::Power(yDistance, 2);
}

CircleCollider::CircleCollider(int squareRadius) : squareRadius(squareRadius)
{
    Register(*this);
}
CircleCollider::~CircleCollider()
{
    Unregister(*this);
}
void CircleCollider::Start() {}
void CircleCollider::VDrawUpdate() {}
void CircleCollider::VBlankUpdate() {}