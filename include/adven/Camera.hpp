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