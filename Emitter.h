#include "VisualGameObject.h"

class Emitter : public GameObject {
private:
    VisualGameObject* parentObj;
public:
    Emitter(VisualGameObject* in_ParentObj);
    short parentAbs_X, parentAbs_Y, rel_X, rel_Y;
    virtual void getParentAbsolutePos();
    virtual std::array<short, 2> getEmitterAbsolutePos(VisualGameObject* in_ParentObj) = 0;
    virtual void setEmitterRelativePos(short in_X, short in_Y) = 0;
    virtual void emitProjectile() = 0;
};
