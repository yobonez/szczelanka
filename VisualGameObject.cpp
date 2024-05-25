#include "VisualGameObject.h"

VisualGameObject::VisualGameObject() : GameObject("VisualGameObject"), m_predefControls(0) { }

void VisualGameObject::setPos(short in_X, short in_Y) {
    m_X = in_X;
    m_Y = in_Y;
}
std::array<short, 2> VisualGameObject::getPos() {
    return {m_X, m_Y};
}

void VisualGameObject::move(short& in_controls) {
    short controls = 0;
    if (in_controls != 0) controls = in_controls;
    else if (m_predefControls != 0) controls = m_predefControls;
    else return;

    std::array<short, 2> curr_pos = getPos();
    short dx = 0, dy = 0;
    if ((controls & controls::RIGHT) != 0) dx += 1;
    if ((controls & controls::LEFT) != 0) dx -= 1;
    if ((controls & controls::UP) != 0) dy -= 1;
    if ((controls & controls::DOWN) != 0) dy += 1;

    setPos(curr_pos[0] + dx, curr_pos[1] + dy);
}

void VisualGameObject::setPredefControls(short& in_controls) {
    m_predefControls = in_controls;
}

void VisualGameObject::setPattern(std::wstring& in_pattern) {
    m_pattern = in_pattern;
}
void VisualGameObject::setSize(short in_X, short in_Y) {
    size_X = in_X;
    size_Y = in_Y;
}
std::array<short, 2> VisualGameObject::getSize() {
    return {size_X, size_Y};
}
std::wstring VisualGameObject::getPattern() {
    return m_pattern;
}
