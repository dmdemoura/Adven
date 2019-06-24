/*
 * Copyright 2018 Amanda de Moura Peres
 * This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at http://mozilla.org/MPL/2.0/.
 */

#ifndef DM_ADVEN_CAMERA_HPP
#define DM_ADVEN_CAMERA_HPP

#include "Component.hpp"
#include "GameObject.hpp"
#include <advenCore/Vector.hpp>


namespace Adven
{
    class Camera : public Component
    {
        friend class GameObject;
    private:
        static Camera* instance;
    public:
        static AdvenCore::Vector GetPosition();
    private:
        virtual void Start() override;
        virtual void VDrawUpdate() override;
        virtual void VBlankUpdate() override;
    public:
        Camera();
        Camera(const Camera&) = delete;
        Camera(Camera&& camera) = delete;
        void operator=(const Camera&) = delete; 
        void operator=(Camera&& camera) = delete;
        virtual ~Camera();
    };
}

#endif