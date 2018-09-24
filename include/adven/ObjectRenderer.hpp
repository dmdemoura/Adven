#ifndef DM_ADVEN_OBJECTRENDERER_HPP
#define DM_ADVEN_OBJECTRENDERER_HPP

#include <advenCore/Object.hpp>
#include <advenCore/Vector.hpp>
#include "Component.hpp"
#include "GameObject.hpp"
#include "Sprite.hpp"

namespace Adven
{
    class ObjectRenderer : public Component, public AdvenCore::Object
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
}

#endif