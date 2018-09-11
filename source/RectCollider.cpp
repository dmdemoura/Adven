#include "RectCollider.hpp"

bool RectCollider::CheckCollision(const RectCollider& a, const RectCollider& b)
{
    int a0x = a.GetMinPos().x, a1x = a.GetMaxPos().x;
    int a0y = a.GetMinPos().y, a1y = a.GetMaxPos().y;
    int b0x = b.GetMinPos().x, b1x = b.GetMaxPos().x;
    int b0y = b.GetMinPos().y, b1y = b.GetMaxPos().y;

    bool xOverlap = (a0x <= b0x && b0x <= a1x) || (a0x <= b1x && b1x <= a1x);
    bool yOverlap = (a0y <= b0y && b0y <= a1y) || (a0y <= b1y && b1y <= a1y);

    return xOverlap && yOverlap;
}

Vector RectCollider::GetMinPos() const
{
    return minOffset + gameObject->GetWorldPosition();
}
Vector RectCollider::GetMaxPos() const
{
    return maxOffset + gameObject->GetWorldPosition();
}

RectCollider::RectCollider(Vector minOffset, Vector maxOffset) : minOffset(minOffset), maxOffset(maxOffset)
{
    Register(*this);
}
RectCollider::~RectCollider()
{
    Unregister(*this);
}
void RectCollider::Start() {}
void RectCollider::VDrawUpdate() {}
void RectCollider::VBlankUpdate() {}