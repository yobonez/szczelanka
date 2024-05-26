#pragma once
#include "VisualGameObject.h"

class Bullet : public VisualGameObject {
private:
    unsigned short health;
    short m_predefControls;
    void setHealth(unsigned short in_Health);
    Bullet* refer();
public:
    Bullet(short direction, short start_X, short start_Y);
};
