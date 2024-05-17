#pragma once
#include <array>
#include "GameObject.h"

class VisualGameObject : public GameObject {
private:
    short m_X, m_Y;
    std::wstring m_pattern;
    short size_X, size_Y;
public:
    VisualGameObject();
    VisualGameObject(std::string in_Name);

    virtual std::wstring getPattern();
    virtual void setPattern(std::wstring& in_pattern);
    virtual void setSize(short x, short y);
    virtual std::array<size_t, 2> getSize();

    virtual void setPos(short in_X, short in_Y);
    virtual std::array<short, 2> getPos();
    virtual void move(short& direction);

    virtual void setHealth(unsigned short in_Health) = 0;
};
