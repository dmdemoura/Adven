#include "Scene.hpp"

Scene* Scene::currentScene = nullptr;

Scene::~Scene()
{
    for (unsigned int i = 0; i < gameObjects.size(); i++)
    {
        delete gameObjects[i];
    }
}
void Scene::Start()
{
    for (unsigned int i = 0; i < gameObjects.size(); i++)
    {
        gameObjects[i]->Start();
    }
}
void Scene::VDrawUpdate()
{
    for (unsigned int i = 0; i < gameObjects.size(); i++)
    {
        gameObjects[i]->VDrawUpdate();
    }
}
void Scene::VBlankUpdate()
{
    for (unsigned int i = 0; i < gameObjects.size(); i++)
    {
        gameObjects[i]->VBlankUpdate();
    }
} 