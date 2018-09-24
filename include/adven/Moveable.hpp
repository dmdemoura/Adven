#ifndef DM_ADVEN_MOVEABLE_HPP
#define DM_ADVEN_MOVEABLE_HPP

#include "Component.hpp"
#include "GameObject.hpp"

namespace Adven
{
    class Moveable : public Component
    {
        friend class GameObject;
    private:
        virtual void Start() override;
        virtual void VDrawUpdate() override;
        virtual void VBlankUpdate() override;
    public:
        AdvenCore::Vector speed;
    };
}

#endif