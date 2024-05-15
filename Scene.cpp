#include "Scene.h"

Scene::Scene() {
    player_exists = false;
}

void Scene::createPlayer() {
    if (!player_exists)
        m_GameObjects.emplace_back(new Player());
        player_exists = true;
    }
}
