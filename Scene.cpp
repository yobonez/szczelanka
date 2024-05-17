#include "Scene.h"
#include "Player.h"
#include "Enemy.h"

Scene::Scene() {
}

void Scene::createPlayer() {
    m_GameObjects.emplace_back(new Player());
}
void Scene::createEnemy() {
    // difficulty? ez - 3, mid - 6, etc.
    if (m_GameObjects.size() > 3) return;
    m_GameObjects.emplace_back(new Enemy());
}

void Scene::forwardPlayerActions(short& direction) {
    if (!m_GameObjects.empty()) {
        m_GameObjects[0]->move(direction);
    }
}
