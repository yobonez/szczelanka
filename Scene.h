#pragma once
#include <vector>
#include <memory>
#include "VisualGameObject.h"
#include "Player.h"
#include "Gun.h"

// Scene contains all visible and invisible game objects. Then all relevant data is pulled to canvas in engine to draw.
class Scene {
private:
    Player* ply;
    std::vector<VisualGameObject*> m_VisualGameObjects;
public:
    Scene();
    std::vector<VisualGameObject*>* get_GameObjects() { return &m_VisualGameObjects; }
    void set_GameObjects(std::vector<VisualGameObject*> in_VisualGameObjects) { m_VisualGameObjects = in_VisualGameObjects; }
    void createPlayer();
    void createEnemy();
    void forwardPlayerActions(short& in_controls);
};
