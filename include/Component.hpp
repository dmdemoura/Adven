#ifndef DM_COMPONENT
#define DM_COMPONENT

#include "IUpdatable.hpp"

class GameObject;

class Component : public IUpdatable
{
    friend class GameObject;
private:
    virtual void Start() override = 0;
    virtual void VDrawUpdate() override = 0;
    virtual void VBlankUpdate() override = 0;
protected:
    GameObject* gameObject;
};

#endif