#include "Scene.h"
#include "Player.h"

Scene::Scene() {
}

void Scene::createPlayer() {
    m_GameObjects.emplace_back(new Player());
}

void Scene::forwardPlayerActions(short& direction) {
    if (!m_GameObjects.empty()) {
        m_GameObjects[0]->move(direction);
    }
}
