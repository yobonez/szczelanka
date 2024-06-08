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

void Bullet::setHealth(short in_Health) {
    m_health = in_Health;
}

void Bullet::tryDealingDamage(VisualGameObject* in_Obj, wchar_t* canvas) {
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

    std::string debug = "Bullet impact X: " + std::to_string(bullet_XY[0] + bulletSize[0]) + " | Enemy X: " + std::to_string(obj_XY[0]);
//    Utils::debugDisplay(debug, canvas);


    short bulletImpactX = 0;
    short objX1 = obj_XY[0];
    short objX2 = obj_XY[0] + objSize[0];

    short bulletImpactY = bullet_XY[1];
    short objY1 = obj_XY[1];
    short objY2 = obj_XY[1] + objSize[1];

    // it only takes y = 1 wide bullets into account
    if (bulletDirection == GameObject::controls::RIGHT) {
        bulletImpactX = bullet_XY[0] + bulletSize[0];

        if ((bulletImpactX >= objX1 && bulletImpactX <= objX2) &&
            (bulletImpactY >= objY1 && bulletImpactY <  objY2))
            {
                in_Obj->dealDamage(m_damage);
                dealDamage(m_damage);
            }
    }
    else {
        short bulletImpactX = bullet_XY[0];

        if ((bulletImpactX <= objX2 && bulletImpactX >= objX1) &&
            (bulletImpactY >= objY1 && bulletImpactY <  objY2))
            {
                in_Obj->dealDamage(m_damage);
                dealDamage(m_damage);
            }
    }
}

void Bullet::dealDamage(short in_Damage) {
    std::wstring noPattern = L" ";
    setPattern(noPattern);

    markForDeath();
}

Bullet* Bullet::refer() { return this; }


