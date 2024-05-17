#pragma once
#include "VisualGameObject.h"
#include <random>

class Enemy : public VisualGameObject {
private:
    unsigned short health;
    std::random_device rd;
public:
    Enemy();
    void setHealth(unsigned short in_Health);
};
