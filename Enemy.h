#pragma once
#include "VisualGameObject.h"
#include <random>

class Enemy : public VisualGameObject {
private:
    unsigned short health;
public:
    Enemy();
    void setPredefControls(short& in_controls);
    void setHealth(unsigned short in_Health);
    Enemy* refer();
};
