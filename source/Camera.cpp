#include "Camera.hpp"

using namespace AdvenCore;
using namespace Adven;

Camera* Camera::instance = nullptr;
Camera::Camera()
{
    if (instance)
        instance->gameObject->RemoveComponent(*instance);

    instance = this;
}
Camera::~Camera()
{
    instance = nullptr;
}
Vector Camera::GetPosition()
{
    return instance->gameObject->GetWorldPosition() - Vector{120, 80};
}
void Camera::Start() {}
void Camera::VDrawUpdate() {}
void Camera::VBlankUpdate() {}