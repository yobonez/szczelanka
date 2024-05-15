#pragma once
#include <array>
#include "GameObject.h"

class VisualGameObject : public GameObject {
private:
    short m_X, m_Y;
    std::string m_pattern;
public:
    VisualGameObject();
    VisualGameObject(std::string in_Name);

    virtual std::string getPattern();
    virtual void setPattern(std::string& in_pattern);

    virtual void setPos(short in_X, short in_Y);
    virtual std::array<short, 2> getPos();
    virtual void move(short& direction, short& rate, std::array<short, 2>& destination);

    virtual void setHealth(int in_Health) = 0;
};
