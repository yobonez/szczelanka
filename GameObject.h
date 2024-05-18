#pragma once
#include <iostream>
#include <array>

class GameObject {
private:
    std::string m_Name;
public:
    GameObject();
    GameObject(std::string in_m_Name);

    virtual std::wstring getPattern() = 0;
    virtual void setPattern(std::wstring& in_pattern) = 0;
    virtual void setSize(short x, short y) = 0;
    virtual std::array<size_t, 2> getSize() = 0;

    virtual void setPos(short in_X, short in_Y) = 0;
    virtual std::array<short, 2> getPos() = 0;
    virtual void move(short& direction) = 0;

    virtual std::string getName() const;
    virtual ~GameObject() = 0;

    enum objectVelocityDirection {
        RIGHT = 1<<0,
        LEFT = 1<<1,
        UP = 1<<2,
        DOWN = 1<<3
    };
};
