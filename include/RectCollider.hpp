#ifndef DM_ADVEN_RECTCOLLIDER_HPP
#define DM_ADVEN_RECTCOLLIDER_HPP

#include "Collider.hpp"

class RectCollider : public Collider
{
private:
    Vector minOffset;
    Vector maxOffset;
public:
    static bool CheckCollision(const RectCollider& a, const RectCollider& b);
private:
    Vector GetMinPos() const;
    Vector GetMaxPos() const;
public:
    RectCollider(GameObject& parent, Vector minOffset, Vector maxOffset);
    virtual ~RectCollider();
    virtual void Start() override;
    virtual void VDrawUpdate() override;
    virtual void VBlankUpdate() override;
};

#endif