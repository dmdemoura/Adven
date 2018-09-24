#ifndef DM_ADVEN_COMPONENT_HPP
#define DM_ADVEN_COMPONENT_HPP

#include "IUpdatable.hpp"

namespace Adven
{
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
}

#endif