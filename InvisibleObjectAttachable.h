#include "GameObject.h"


class InvisibleObjectAttachable : public GameObject {
public:
    InvisibleObjectAttachable();
    InvisibleObjectAttachable(std::string in_Name);
    short rel_X, rel_Y;
    virtual void setRelativePos(short in_X, short in_Y);
    virtual ~InvisibleObjectAttachable() = 0;
};
