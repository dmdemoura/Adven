#ifndef DM_SCENE
#define DM_SCENE

#include "IUpdatable.hpp"
#include "GameObject.hpp"
#include "Vector.hpp"
#include <list>

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
    virtual void Start() final override;
    virtual void VDrawUpdate() final override;
    virtual void VBlankUpdate() final override;
    GameObject& AddGameObject(GameObject&& gameObject);
    void RemoveGameObject(const GameObject& gameObject);
    void RemoveGameObject(std::function<bool(const GameObject&)> compare);
};

#endif