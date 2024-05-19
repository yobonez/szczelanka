#pragma once
#include "VisualGameObject.h"
#include "Gun.h"

class Player : public VisualGameObject {
private:
    unsigned short health;
    std::vector<Gun*> guns;
public:
    Player();
    void setHealth(unsigned short in_Health);
    void attachGun(Gun* gun);
    Player* refer();
//    void shoot();
};
