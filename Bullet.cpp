#include "Bullet.h"

Bullet::Bullet(short in_Direction, short in_Damage, short start_X, short start_Y) : VisualGameObject() {
    std::wstring pattern = L"---";
    m_damage = in_Damage;

    setDetailedName("Bullet");

    setPredefControls(in_Direction);
    setObjFacing(in_Direction);
    setPattern(pattern);
    setSize(3,1);
    setHealth(1);
    setPos(start_X, start_Y);
}

void Bullet::setHealth(short in_Health) {
    m_health = in_Health;
}
short Bullet::getHealth() { return m_health; }

// maybe bullet - bullet collisions?
void Bullet::tryDealingDamage(VisualGameObject* in_Obj) {
    short bulletDirection, objectDirection;
    bulletDirection = getObjFacing();
    objectDirection = in_Obj->getObjFacing();

    if (bulletDirection == objectDirection) return; // dont check collisions for your own bullets

    if (Utils::isIntersecting(this, in_Obj)) {
        in_Obj->dealDamage(m_damage);
        dealDamage(m_damage);
    }
}

void Bullet::dealDamage(short in_Damage) {
    std::wstring noPattern = L" ";
    setPattern(noPattern);

    markForDeath();
}

Bullet* Bullet::refer() { return this; }


