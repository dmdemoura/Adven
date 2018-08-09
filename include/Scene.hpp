#ifndef DM_SCENE
#define DM_SCENE

#include "IUpdatable.hpp"
#include "GameObject.hpp"
#include <vector>

class Scene : IUpdatable
{
protected:
    std::vector<GameObject*> gameObjects;
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
public:
    virtual ~Scene();
    virtual void Start() final override;
    virtual void VDrawUpdate() final override;
    virtual void VBlankUpdate() final override;
};

#endif