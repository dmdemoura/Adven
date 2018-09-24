#ifndef DM_ADVEN_CIRCLECOLLIDER_HPP
#define DM_ADVEN_CIRCLECOLLIDER_HPP

#include "Collider.hpp"

namespace Adven
{
    class CircleCollider : public Collider
    {
        friend class GameObject;
    public:
        static bool CheckCollision(const CircleCollider& a, const CircleCollider& b);
    private:
        int squareRadius;
    private:
        virtual void Start() override;
        virtual void VDrawUpdate() override;
        virtual void VBlankUpdate() override;
    public:
        CircleCollider(int squareRadius);
        virtual ~CircleCollider();
    };
}

#endif