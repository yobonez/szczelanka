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
    bulletDirection = getObjFacing();
    objectDirection = in_Obj->getObjFacing();

    if (bulletDirection == objectDirection) return; // dont check collisions for your own bullets

    std::array<short, 2> bullet_XY, bulletSize;
    bullet_XY = getPos();
    bulletSize = getSize();
    std::array<short, 2> obj_XY, objSize;
    obj_XY = in_Obj->getPos();
    objSize = in_Obj->getSize();

    short xDist = 0;
    if (bulletDirection == GameObject::controls::LEFT) {
        xDist = bullet_XY[0] - obj_XY[0] + objSize[0]; // + objsize because its right facing
    }
    else {
        xDist = obj_XY[0] - bullet_XY[0] + bulletSize[0]; // + bulletsize because its right facing
    }
    if (xDist <= 0) {
        short upperEdgeYDist = obj_XY[1] - bullet_XY[1];
        short lowerEdgeYDist = bullet_XY[1] - obj_XY[1] + objSize[1];

        if ((upperEdgeYDist <= 0) && (lowerEdgeYDist <= 0)) in_Obj->dealDamage(m_damage);
    }
    else return;
}

Bullet* Bullet::refer() { return this; }

// not relevant to Bullet
void Bullet::dealDamage(unsigned short in_Damage) {
    return;
}

