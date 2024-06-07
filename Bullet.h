#pragma once
#include "VisualGameObject.h"

class Bullet : public VisualGameObject {
private:
    unsigned short m_health;
    unsigned short m_damage = 100;
    short m_predefControls;
    void setHealth(unsigned short in_Health);
public:
    Bullet(short direction, short start_X, short start_Y);
    void tryDealingDamage(VisualGameObject* in_Obj);
    Bullet* refer();

    // not relevant to Bullet
    void dealDamage(unsigned short in_Damage);
};
