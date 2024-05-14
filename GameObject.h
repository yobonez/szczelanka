#pragma once
#include <iostream>

class GameObject {
private:
    short int x, y;
    std::string name;
public:
    GameObject();
    std::string ToString();
    virtual ~GameObject() = 0;
};
