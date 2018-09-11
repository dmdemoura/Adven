#ifndef DM_MOVEABLE
#define DM_MOVEABLE

#include "Component.hpp"
#include "GameObject.hpp"

class Moveable : public Component
{
    friend class GameObject;
private:
    virtual void Start() override;
    virtual void VDrawUpdate() override;
    virtual void VBlankUpdate() override;
public:
    Vector speed;
};

#endif