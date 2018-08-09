#ifndef DM_MOVEABLE
#define DM_MOVEABLE

#include "Component.hpp"

class Moveable : public Component
{
public:
    Vector speed;
    Moveable(GameObject& gameObject);
    virtual void Start() override;
    virtual void VDrawUpdate() override;
    virtual void VBlankUpdate() override;
};

#endif