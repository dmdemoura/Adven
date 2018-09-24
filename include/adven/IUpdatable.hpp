#ifndef DM_ADVEN_IUPDATABLE_HPP
#define DM_ADVEN_IUPDATABLE_HPP

namespace Adven
{
    class IUpdatable
    {
    private:
        virtual void Start() = 0;
        virtual void VDrawUpdate() = 0;
        virtual void VBlankUpdate() = 0;
    };
}

#endif