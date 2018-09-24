#ifndef DM_ADVEN_COLLIDER_HPP
#define DM_ADVEN_COLLIDER_HPP

#include "GameObject.hpp"
#include "Component.hpp"
#include <forward_list>

namespace Adven
{
    class Collider : public Component
    {
        friend class GameObject;
    private: //Static variables
        static std::forward_list<Collider*> colliders;
    protected: //Static methods
        static void Register(Collider& collider);
        static void Unregister(Collider& collider);
    public: //Static methods
        static void Update();
        static bool CheckCollision(const Collider& a, const Collider& b);
    };
}

#endif