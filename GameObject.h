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

    virtual void setPos(short in_X, short in_Y) = 0;
    virtual std::array<short, 2> getPos() = 0;
    virtual void move(short& direction, short& rate, std::array<short, 2>& destination) = 0;

    virtual std::string name() const;
    virtual ~GameObject() = 0;
};
