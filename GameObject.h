#pragma once
#include <iostream>
#include <array>

class GameObject {
private:
    std::string m_Name;
public:
    GameObject();
    GameObject(std::string in_m_Name);

    virtual void setPos(short in_X, short in_Y) = 0;
    virtual std::array<short, 2> getPos() = 0;

    virtual std::string getName() const;
    virtual ~GameObject() = 0;

    enum controls {
        RIGHT = 1<<0,
        LEFT = 1<<1,
        UP = 1<<2,
        DOWN = 1<<3,
        SHOOT = 1<<4
    };
};
