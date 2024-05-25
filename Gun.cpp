#include "Gun.h"

Gun::Gun(VisualGameObject* in_ParentObj, short in_X, short in_Y) : Emitter(in_ParentObj) {
    setDetailedName("Gun");
    setEmitterRelativePos(in_X, in_Y);
}

Bullet* Gun::shoot(short in_Direction) {
    std::array<short, 2> bulletStartPos = getEmitterAbsolutePos();
    return (new Bullet(in_Direction, bulletStartPos[0], bulletStartPos[1]));
}
