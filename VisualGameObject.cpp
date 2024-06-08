#include "VisualGameObject.h"

extern short timer;
extern short visObjectCount;

VisualGameObject::VisualGameObject() : GameObject("VisualGameObject"), m_predefControls(0) {
    id = visObjectCount;
}

void VisualGameObject::setPos(short in_X, short in_Y) {
    m_X = in_X;
    m_Y = in_Y;
}
void VisualGameObject::setPos(std::array<short, 2> in_Pos) {
    m_X = in_Pos[0];
    m_Y = in_Pos[1];
}
std::array<short, 2> VisualGameObject::getPos() {
    return {m_X, m_Y};
}

void VisualGameObject::setPredefControls(short& in_controls) {
    m_predefControls = in_controls;
}

void VisualGameObject::setObjFacing(short in_Facing) {
    m_currentFacing = in_Facing;
}
short VisualGameObject::getObjFacing() {
    return m_currentFacing;
}

void VisualGameObject::move(short& in_controls, short interval) {
    std::array<short, 2> curr_pos = getPos();
    std::array<short, 2> new_pos = {0, 0};
    bool alreadyMoved = false;

    if (timer % interval == 0){
        short controls = 0;
        if (in_controls != 0) controls = in_controls;
        else if (m_predefControls != 0) controls = m_predefControls;
        else return;

        short dx = 0, dy = 0;
        if ((controls & controls::RIGHT) != 0) dx += 1;
        if ((controls & controls::LEFT) != 0) dx -= 1;
        if ((controls & controls::UP) != 0) dy -= 1;
        if ((controls & controls::DOWN) != 0) dy += 1;

        new_pos = {curr_pos[0] + dx, curr_pos[1] + dy};
        setPos(new_pos);
        alreadyMoved = true;
    }
    if (alreadyMoved && getDetailedName() == "Enemy" && timer % 5 == 0) {
        srand(time(NULL));
        short rnd_Dy = (rand() % 3) - 1;
        setPos(new_pos[0], new_pos[1] + rnd_Dy);
    }
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

bool VisualGameObject::isDead() { return m_markedForDeath; }
void VisualGameObject::markForDeath() { m_markedForDeath = true; }
