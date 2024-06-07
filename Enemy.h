#pragma once
#include "VisualGameObject.h"
#include "Gun.h"
#include <random>

class Enemy : public VisualGameObject {
private:
    unsigned short m_health;
    short m_predefControls;
    std::vector<Gun*> guns;
    std::vector<Bullet*> bullets;
    void attachGun(Gun* gun);
public:
    Enemy();
    void setHealth(unsigned short in_Health);
    void dealDamage(unsigned short in_Damage);
    Enemy* refer();
    void shoot(std::vector<VisualGameObject*>* bulletContainer);
};
