#pragma once
#include "VisualGameObject.h"

class Enemy : public VisualGameObject {
private:
    unsigned short health;
public:
    Enemy();
    void setHealth(int in_Health);
};
