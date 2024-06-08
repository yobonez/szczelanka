#pragma once
#include "VisualGameObject.h"
#include "Gun.h"
#include "Bullet.h"

class Player : public VisualGameObject {
private:
    short m_health;
    std::vector<Gun*> guns;
    void attachGun(Gun* gun);
public:
    Player();
    void setHealth(short in_Health);
    void dealDamage(short in_Damage);
    Player* refer();
    void shoot(short& in_controls, std::vector<VisualGameObject*>* bulletContainer);
};
