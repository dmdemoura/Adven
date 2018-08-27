#ifndef DM_GAMEOBJECT
#define DM_GAMEOBJECT

#include <vector>
#include "Component.hpp"
#include "Vector.hpp"
#include "IUpdatable.hpp"
#include <typeinfo>

class Component;

class GameObject : public IUpdatable
{
public:
    GameObject* parent;
    Vector localPosition;
    std::vector<Component*> components;
public:
    GameObject(GameObject* parent);
    GameObject(GameObject* parent, Vector localPosition);
    virtual ~GameObject();
    void Start() override;
    void VDrawUpdate() override;
    void VBlankUpdate() override;
    template <typename T>
    T* GetComponent()
    {
        for (unsigned int i = 0; i < components.size(); i++)
        {
            T* component = dynamic_cast<T*>(components[i]);
            if (component != nullptr)
            {
                return component;
            }
        }
        return nullptr;
    }
    Vector GetWorldPosition();
};

#endif