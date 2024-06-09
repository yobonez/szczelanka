#pragma once
#include "VisualGameObject.h"
#include "Utils.h"

class Bullet : public VisualGameObject {
private:
    short m_health;
    short m_damage;
    short m_predefControls;
    void setHealth(short in_Health);
public:
    Bullet(short in_Direction, short in_Damage, short start_X, short start_Y);
    void tryDealingDamage(VisualGameObject* in_Obj, wchar_t* canvas);
    Bullet* refer();

    void dealDamage(short in_Damage);
};
