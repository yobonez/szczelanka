#include "Scene.h"
#include "Player.h"

Scene::Scene() {
}

void Scene::createPlayer() {
    m_GameObjects.emplace_back(new Player());
}
