#pragma once
#include "VisualGameObject.h"
#include "Gun.h"

class Player : public VisualGameObject {
private:
    unsigned short health;
    std::vector<Gun*> guns;
public:
    Player(std::vector<Gun*> in_Guns);
    void setHealth(unsigned short in_Health);
    void shoot();
};
