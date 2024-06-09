#include "Gun.h"

extern short timer;

Gun::Gun(VisualGameObject* in_ParentObj, short in_BulletDamage, short in_X, short in_Y, short in_Cooldown) : Emitter(in_ParentObj) {
    m_owner = in_ParentObj;
    m_bulletDamage = in_BulletDamage;

    setDetailedName("Gun");
    setEmitterRelativePos(in_X, in_Y);
    setCooldown(in_Cooldown);
}

void Gun::setCooldown(short in_Cooldown) {
    m_cooldown = in_Cooldown;
}

Bullet* Gun::shoot(short in_Direction) {
    if (timer % m_cooldown == 0) {
        std::array<short, 2> bulletStartPos = getEmitterAbsolutePos();
        return (new Bullet(in_Direction, m_bulletDamage, bulletStartPos[0], bulletStartPos[1]));
    }
    else {
        return nullptr;
    }
}
