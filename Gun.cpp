#include "Gun.h"

extern short timer;

Gun::Gun(VisualGameObject* in_ParentObj, short in_X, short in_Y, short in_Cooldown) : Emitter(in_ParentObj) {
    setDetailedName("Gun");
    setEmitterRelativePos(in_X, in_Y);
    setCooldown(in_Cooldown);
}

void Gun::setCooldown(short in_Cooldown) {
    cooldown = in_Cooldown;
}

Bullet* Gun::shoot(short in_Direction) {
    if (timer % cooldown == 0) {
        std::array<short, 2> bulletStartPos = getEmitterAbsolutePos();
        return (new Bullet(in_Direction, bulletStartPos[0], bulletStartPos[1]));
    }
    else {
        return nullptr;
    }
}
