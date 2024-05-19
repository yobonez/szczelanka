#include "InvisibleGameObject.h"
#include "VisualGameObject.h"

class Emitter : public InvisibleGameObject {
private:
    short rel_X, rel_Y;
    VisualGameObject* parentObj;
public:
    Emitter(VisualGameObject* in_ParentObj);
    virtual void setEmitterRelativePos(short in_X, short in_Y);
    virtual std::array<short, 2> getEmitterAbsolutePos();
};
