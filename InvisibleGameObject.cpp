#include "InvisibleGameObject.h"

InvisibleGameObject::InvisibleGameObject() : GameObject("InvisibleGameObject") {}

std::array<short, 2> InvisibleGameObject::getPos() {
    return {m_X, m_Y};
}

void InvisibleGameObject::setPos(short in_X, short in_Y) {
    m_X = in_X;
    m_Y = in_Y;
}
