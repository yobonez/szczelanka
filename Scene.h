#pragma once
#include <vector>
#include <memory>
#include "GameObject.h"

class Scene {
private:
    short scr_W, scr_H;
    std::vector<GameObject*> m_GameObjects;
public:
    Scene();
    std::vector<GameObject*> get_GameObjects() { return m_GameObjects; }
    void set_GameObjects(std::vector<GameObject*> in_GameObjects) { m_GameObjects = in_GameObjects; }
};
