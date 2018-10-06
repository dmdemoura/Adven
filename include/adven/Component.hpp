/*
 * Copyright 2018 Gabriel de Moura Peres
 * This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at http://mozilla.org/MPL/2.0/.
 */

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