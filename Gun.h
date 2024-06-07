#pragma once
#include <vector>
#include "VisualGameObject.h"
#include "Emitter.h"
#include "Bullet.h"

class Gun : public Emitter {
private:
    short cooldown;
public:
    Gun(VisualGameObject* in_ParentObj, short in_X, short in_Y, short in_Cooldown);
    void setCooldown(short in_Cooldown);
    void getParentAbsolutePos();

    Bullet* shoot(short in_Direction);
};
