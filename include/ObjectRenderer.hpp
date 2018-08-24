#ifndef DM_OBJECTRENDERER
#define DM_OBJECTRENDERER

#include "Component.hpp"
#include "Hardware/Object.hpp"
#include "Vector.hpp"
#include "Sprite.hpp"

class ObjectRenderer : public Component, public Object
{
public:
    ObjectRenderer(GameObject& gameObject, Sprite* sprite = nullptr);
    virtual ~ObjectRenderer();
    virtual void Start() override;
    virtual void VDrawUpdate() override;
    virtual void VBlankUpdate() override;
};

#endif