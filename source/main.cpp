#include <tonc.h>
#include <advenCore/Backgrounds.hpp>
#include <advenCore/Object.hpp>
#include <advenCore/Input.hpp>
#include "Scene.hpp"
#include "Collider.hpp"

using namespace AdvenCore;
using namespace Adven;

int main()
{
    irq_init(NULL);
    irq_add(II_VBLANK, NULL);

    Object::HideAll();
    // Scene::LoadScene<TestScene>();
    while (true)
    {
        Input::KeyUpdate();

        Scene::currentScene->VDrawUpdate();
        Collider::Update();

        VBlankIntrWait();

        Scene::currentScene->VBlankUpdate();
        Object::Render();
    }
}