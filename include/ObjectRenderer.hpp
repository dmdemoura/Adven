#ifndef DM_OBJECTRENDERER
#define DM_OBJECTRENDERER

#include "Component.hpp"
#include "GameObject.hpp"
#include "Hardware/Object.hpp"
#include "Vector.hpp"
#include "Sprite.hpp"

class ObjectRenderer : public Component, public Object
{
    friend class GameObject;
private:
    virtual void Start() override;
    virtual void VDrawUpdate() override;
    virtual void VBlankUpdate() override;
public:
    ObjectRenderer(Sprite* sprite = nullptr);
    virtual ~ObjectRenderer();
};

#endif