/*
 * Copyright 2018 Amanda de Moura Peres
 * This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at http://mozilla.org/MPL/2.0/.
 */

#include <tonc.h>
#include <advenCore/Backgrounds.hpp>
#include <advenCore/Object.hpp>
#include <advenCore/Input.hpp>
#include "Input.hpp"
#include "Scene.hpp"
#include "Collider.hpp"
#include "GameInit.hpp"

using namespace AdvenCore;
using namespace Adven;

int main()
{
    try
    {
        irq_init(NULL);
        irq_add(II_VBLANK, NULL);

        Object::HideAll();
        GameInit();
        while (true)
        {
            Adven::Input::KeyUpdate();
            Adven::Input::Update();

            Scene::currentScene->VDrawUpdate();
            Collider::Update();

            VBlankIntrWait();

            Scene::currentScene->VBlankUpdate();
            Object::Render();
        }
    }
    catch(std::exception& e)
    {
        Log::Debug << "ERROR at main(): Unhandled exception: " << e.what() << std::endl;
    }
}