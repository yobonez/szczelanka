#pragma once
#include "VisualGameObject.h"
#include "Gun.h"
#include <random>

class Enemy : public VisualGameObject {
private:
    unsigned short health;
    short m_predefControls;
    std::vector<Gun*> guns;
    std::vector<Bullet*> bullets;
    void attachGun(Gun* gun);
public:
    Enemy();
    void setHealth(unsigned short in_Health);
    Enemy* refer();
    std::vector<Bullet*>* shoot();
};
