#ifndef DM_COMPONENT
#define DM_COMPONENT

#include "IUpdatable.hpp"
#include "GameObject.hpp"

class GameObject;

class Component : public IUpdatable
{
protected:
    GameObject& gameObject;
public:
    Component(GameObject& gameObject) : gameObject(gameObject) {}
    virtual ~Component();
    virtual void Start() override = 0;
    virtual void VDrawUpdate() override = 0;
    virtual void VBlankUpdate() override = 0;
};

#endif