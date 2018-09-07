#ifndef DM_ADVEN_CIRCLECOLLIDER_HPP
#define DM_ADVEN_CIRCLECOLLIDER_HPP

#include "Collider.hpp"

class CircleCollider : public Collider
{
private:
    int squareRadius;
public:
    static bool CheckCollision(const CircleCollider& a, const CircleCollider& b);
public:
    CircleCollider(GameObject& parent, int squareRadius);
    virtual ~CircleCollider();
    virtual void Start() override;
    virtual void VDrawUpdate() override;
    virtual void VBlankUpdate() override;
};

#endif