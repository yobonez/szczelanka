#pragma once
#include <vector>
#include "VisualGameObject.h"
#include "Emitter.h"
#include "Bullet.h"

class Gun : public Emitter {
public:
    Gun(VisualGameObject* in_ParentObj, short in_X, short in_Y);
    void getParentAbsolutePos();

    Bullet* shoot(short in_Direction);
};
