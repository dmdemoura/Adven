#include "Collider.hpp"
#include "RectCollider.hpp"
#include "CircleCollider.hpp"
#include "Moveable.hpp"
#include "Debug.hpp"
#include <algorithm>

std::forward_list<Collider*> Collider::colliders;
/*
    Static methods
*/
void Collider::Register(Collider& collider)
{
    colliders.push_front(&collider);
}
void Collider::Unregister(Collider& collider)
{
    colliders.remove(&collider);
}
void Collider::Update()
{
    Collider* last = colliders.front();
    std::for_each(++colliders.begin(), colliders.end(),
        [&](Collider* current) -> void
        {
            if (CheckCollision(*current, *last))
            {
                Moveable* mc = current->gameObject.GetComponent<Moveable>();
                if (mc)
                {
                    current->gameObject.localPosition -= mc->speed;
                    mc->speed = -mc->speed;
                }

                Moveable* ml = last->gameObject.GetComponent<Moveable>();
                if (ml)
                {
                    last->gameObject.localPosition -= ml->speed;
                    ml->speed = -mc->speed;
                }
            }
        }
    );
}
bool Collider::CheckCollision(const Collider& a, const Collider& b)
{
    if (typeid(a) == typeid(RectCollider) && typeid(b) == typeid(RectCollider))
        return RectCollider::CheckCollision(reinterpret_cast<const RectCollider&>(a), reinterpret_cast<const RectCollider&>(b));
    else if (typeid(a) == typeid(CircleCollider) && typeid(b) == typeid(CircleCollider))
        return CircleCollider::CheckCollision(reinterpret_cast<const CircleCollider&>(a), reinterpret_cast<const CircleCollider&>(b));
    else
    {
        Debug::Error("Collider::CheckCollision failed to identify collider type");
        return false;
    }
}
/*
    Instance methods
*/
Collider::Collider(GameObject& parent) : Component(parent) {} 