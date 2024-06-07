#pragma once
#include <array>
#include "GameObject.h"

class VisualGameObject : public GameObject {
private:
    short id;
    short m_X, m_Y;
    std::wstring m_pattern;
    short size_X, size_Y;
    short m_predefControls;
    short m_currentFacing;
    bool m_markedForDeath = false;
public:
    VisualGameObject();

    virtual std::wstring getPattern();
    virtual void setPattern(std::wstring& in_pattern);
    virtual void setSize(short x, short y);
    virtual std::array<short, 2> getSize();

    virtual void setPos(short in_X, short in_Y);
    virtual std::array<short, 2> getPos();
    virtual void setPredefControls(short& in_controls);
    virtual void setObjFacing(short in_Facing);
    virtual short getObjFacing();
    virtual void move(short& in_controls, short interval);

    virtual bool isDead();
    virtual void markForDeath();

    virtual void setHealth(unsigned short in_Health) = 0;
    virtual void dealDamage(unsigned short in_Damage) = 0;
    virtual VisualGameObject* refer() = 0;
};
