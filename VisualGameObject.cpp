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

void VisualGameObject::move(short& direction, short& rate, std::array<short, 2>& destination) {
    return;
}

void VisualGameObject::setPattern(std::wstring& in_pattern) {
    m_pattern = in_pattern;
}
std::wstring VisualGameObject::getPattern() {
    return m_pattern;
}
