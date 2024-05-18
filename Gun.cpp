#include "Gun.h"

void Gun::setEmitterRelativePos(short in_X, short in_Y){
    rel_X = in_X;
    rel_Y = in_Y;
}

Gun::Gun(VisualGameObject* in_ParentObj, short in_X, short in_Y) : Emitter(in_ParentObj) {
    setEmitterRelativePos(in_X, in_Y);
}

void Gun::shoot(short in_Speed) {
    std::array<short, 2> bulletStartPos = getEmitterAbsolutePos();
    bullets.emplace_back(new Bullet(in_Speed, bulletStartPos[0], bulletStartPos[1]));
}

//std::array<short, 2> getEmitterAbsolutePos(VisualGameObject& parentObj)
//{
//
//}
