#ifndef DM_IUPDATABLE
#define DM_IUPDATABLE

class IUpdatable
{
public:
    virtual void Start() = 0;
    virtual void VDrawUpdate() = 0;
    virtual void VBlankUpdate() = 0;
};

#endif