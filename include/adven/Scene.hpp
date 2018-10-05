#ifndef DM_ADVEN_SCENE_HPP
#define DM_ADVEN_SCENE_HPP

#include "IUpdatable.hpp"
#include "GameObject.hpp"
#include <advenCore/Vector.hpp>
#include <list>

namespace Adven
{
    class Scene : IUpdatable
    {
        friend class GameObject;
    public:
        static Scene* currentScene;
    public:
        template<typename T>
        static void LoadScene()
        {
            delete currentScene;
            currentScene = new T();
            currentScene->Start();
        }
    private:
        std::list<GameObject> gameObjects;
    public:
        virtual ~Scene();
        virtual void Start() final override;
        virtual void VDrawUpdate() final override;
        virtual void VBlankUpdate() final override;
        GameObject& AddGameObject(GameObject&& gameObject);
        void RemoveGameObject(const GameObject& gameObject);
        void RemoveGameObject(std::function<bool(const GameObject&)> compare);
    };
}

#endif