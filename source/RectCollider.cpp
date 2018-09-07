#include "RectCollider.hpp"

bool RectCollider::CheckCollision(const RectCollider& a, const RectCollider& b)
{
    bool xOverlap = b.GetMinPos().x >= a.GetMaxPos().x && b.GetMaxPos().x >= a.GetMinPos().x;
    bool yOverlap = b.GetMinPos().y >= a.GetMaxPos().y && b.GetMaxPos().y >= a.GetMinPos().y;

    return xOverlap && yOverlap;
}

Vector RectCollider::GetMinPos() const
{
    return minOffset + gameObject.GetWorldPosition();
}
Vector RectCollider::GetMaxPos() const
{
    return maxOffset + gameObject.GetWorldPosition();
}

RectCollider::RectCollider(GameObject& parent, Vector minOffset, Vector maxOffset) : Collider(parent), minOffset(minOffset), maxOffset(maxOffset)
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