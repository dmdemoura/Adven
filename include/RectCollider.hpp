#ifndef DM_ADVEN_RECTCOLLIDER_HPP
#define DM_ADVEN_RECTCOLLIDER_HPP

#include "Collider.hpp"

class RectCollider : public Collider
{
    friend class GameObject;
private:
    Vector minOffset;
    Vector maxOffset;
public:
    static bool CheckCollision(const RectCollider& a, const RectCollider& b);
private:
    Vector GetMinPos() const;
    Vector GetMaxPos() const;
    virtual void Start() override;
    virtual void VDrawUpdate() override;
    virtual void VBlankUpdate() override;
public:
    RectCollider(Vector minOffset, Vector maxOffset);
    virtual ~RectCollider();
};

#endif