#pragma once
#include "VisualGameObject.h"
#include "Utils.h"

class Bullet : public VisualGameObject {
private:
    short m_health;
    short m_damage;
    short m_predefControls;
public:
    Bullet(short in_Direction, short in_Damage, short start_X, short start_Y);
    void tryDealingDamage(VisualGameObject* in_Obj);
    short getHealth();
    void setHealth(short in_Health);
    Bullet* refer();

    void dealDamage(short in_Damage);
};
