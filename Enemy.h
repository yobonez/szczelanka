#pragma once
#include "VisualGameObject.h"
#include <random>

class Enemy : public VisualGameObject {
private:
    unsigned short health;
    short m_predefControls;
public:
    Enemy();
    void setHealth(unsigned short in_Health);
    Enemy* refer();
};
