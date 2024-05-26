#pragma once
#include "VisualGameObject.h"
#include "Gun.h"
#include "Bullet.h"

class Player : public VisualGameObject {
private:
    unsigned short health;
    std::vector<Gun*> guns;
    std::vector<Bullet*> bullets;
    void attachGun(Gun* gun);
public:
    Player();
    void setHealth(unsigned short in_Health);
    Player* refer();
    std::vector<Bullet*>* shoot(short& in_controls);
};
