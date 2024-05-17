#include "VisualGameObject.h"

VisualGameObject::VisualGameObject() : GameObject("VisualGameObject") { }
VisualGameObject::VisualGameObject(std::string in_Name) : GameObject(in_Name) { }

void VisualGameObject::setPos(short in_X, short in_Y) {
    m_X = in_X;
    m_Y = in_Y;
}
std::array<short, 2> VisualGameObject::getPos() {
    return {m_X, m_Y};
}

void VisualGameObject::move(short& direction) {
    std::array<short, 2> curr_pos = getPos();
    short dx = 0, dy = 0;
    if ((direction & objectVelocityDirection::RIGHT) != 0) dx += 1;
    if ((direction & objectVelocityDirection::LEFT) != 0) dx -= 1;
    if ((direction & objectVelocityDirection::UP) != 0) dy -= 1;
    if ((direction & objectVelocityDirection::DOWN) != 0) dy += 1;

    setPos(curr_pos[0] + dx, curr_pos[1] + dy);
}

void VisualGameObject::setPattern(std::wstring& in_pattern) {
    m_pattern = in_pattern;
}
void VisualGameObject::setSize(short in_X, short in_Y) {
    size_X = in_X;
    size_Y = in_Y;
}
std::array<size_t, 2> VisualGameObject::getSize() {
    return {size_X, size_Y};
}
std::wstring VisualGameObject::getPattern() {
    return m_pattern;
}
