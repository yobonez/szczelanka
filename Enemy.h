#pragma once
#include "VisualGameObject.h"
#include "Gun.h"
#include <random>

class Enemy : public VisualGameObject {
private:
    short m_health;
    short m_predefControls;
    std::vector<Gun*> guns;
    std::vector<Bullet*> bullets;
    void attachGun(Gun* gun);
public:
    Enemy();
    void setHealth(short in_Health);
    short getHealth();
    void dealDamage(short in_Damage);
    Enemy* refer();
    void shoot(std::vector<VisualGameObject*>* bulletContainer);
};
