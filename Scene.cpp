#include "Scene.h"
#include "Player.h"
#include "Enemy.h"

Scene::Scene() {
}

void Scene::createPlayer() {
    m_VisualGameObjects.emplace_back(new Player());
    ply = (Player*)m_VisualGameObjects[0]->refer();
}
void Scene::createEnemy() {
    // difficulty? ez - 3, mid - 6, etc.
    if (m_VisualGameObjects.size() > 3) return;
    m_VisualGameObjects.emplace_back(new Enemy());
}

void Scene::forwardPlayerActions(short& in_controls) {
    if (!m_VisualGameObjects.empty()) {
        ply->move(in_controls, 2);
        ply->shoot(in_controls, &m_VisualGameObjects);
    }
}
