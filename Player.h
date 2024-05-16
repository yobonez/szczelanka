#pragma once
#include "VisualGameObject.h"

class Player : public VisualGameObject {
private:
    unsigned short health;
public:
    Player();
    void setHealth(unsigned short in_Health);
};
