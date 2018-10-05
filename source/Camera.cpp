#include "Camera.hpp"

using namespace AdvenCore;
using namespace Adven;

Camera* Camera::instance = nullptr;
/**
 * Static methods
 */
Vector Camera::GetPosition()
{
    if (instance)
        return instance->gameObject->GetWorldPosition() - Vector{120, 80};
    else
        return {0,0};
}
/**
 * Instance methods
 */
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
void Camera::Start() {}
void Camera::VDrawUpdate() {}
void Camera::VBlankUpdate() {}