#pragma once
#include <vector>
#include "Emitter.h"
#include "Bullet.h"

class Gun : public Emitter {
public:
    std::vector<Bullet*> bullets;

    Gun(VisualGameObject* in_ParentObj, short in_X, short in_Y);
    void setEmitterRelativePos(short in_X, short in_Y);
//    std::array<short, 2> getEmitterAbsolutePos(VisualGameObject& in_ParentObj);

    void shoot(short speed);
};
