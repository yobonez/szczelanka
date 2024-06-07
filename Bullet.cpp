#include "Bullet.h"

Bullet::Bullet(short direction, short start_X, short start_Y) : VisualGameObject() {
    std::wstring pattern = L"---";

    setDetailedName("Bullet");

    setPredefControls(direction);
    setObjFacing(direction);
    setPattern(pattern);
    setSize(3,1);
    setHealth(1);
    setPos(start_X, start_Y);
}

void Bullet::setHealth(unsigned short in_Health) {
    m_health = in_Health;
}

void Bullet::tryDealingDamage(VisualGameObject* in_Obj) {
    short bulletDirection, objectDirection;
    bulletDirection = getFacingDirection();
    objectDirection = in_Obj->getFacingDirection();

    if (bulletDirection == objectDirection) return; // dont check collisions for your own bullets

    std::array<short, 2> bullet_XY, bulletSize;
    bullet_XY = getPos();
    bulletSize = getSize();
    std::array<short, 2> obj_XY, objSize;
    obj_XY = in_Obj->getPos();
    objSize = in_Obj->getSize();

    if (bulletDirection == GameObject::controls::LEFT) {

    }

    if (() && ())
    else return;
}

Bullet* Bullet::refer() { return this; }
