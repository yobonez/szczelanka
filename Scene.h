#pragma once
#include <vector>
#include <memory>
#include "GameObject.h"

// Scene contains all visible and invisible game objects. Then all relevant data is pulled to canvas in engine to draw.
class Scene {
private:
    bool player_exists;
    std::vector<GameObject*> m_GameObjects;
public:
    Scene();
    std::vector<GameObject*> get_GameObjects() { return m_GameObjects; }
    void set_GameObjects(std::vector<GameObject*> in_GameObjects) { m_GameObjects = in_GameObjects; }
    void createPlayer();
};
