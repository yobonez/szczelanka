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
    // random X and Y for new Enemy pos
    srand(time(NULL));
    short rnd_X = (rand() % 60) + 60;
    short rnd_Y = (rand() % 10) + 10;
    std::array<short, 2> currentEnemyPos = {0, 0};

    // difficulty? ez - 3, mid - 6, etc.
    short enemyCount = 0;
    for (VisualGameObject* obj : m_VisualGameObjects) {
        if (obj->getDetailedName() == "Enemy") {
            enemyCount++;

            std::array<short, 2> currentEnemyPos = obj->getPos();
            std::array<short, 2> currentEnemySize = obj->getSize();
            // repeat getting random x,y pos if enemies intersecting
            if ( ! ((rnd_X > currentEnemyPos[0]) &&
                    (rnd_X < currentEnemyPos[0] + currentEnemySize[0]) &&
                    (rnd_Y > currentEnemyPos[1]) &&
                    (rnd_Y < currentEnemyPos[1] + currentEnemySize[1]))) {
                short rnd_X = (rand() % 60) + 60;
                short rnd_Y = (rand() % 10) + 10;
            }
        }
    }

    if (enemyCount > 3) return;
    m_VisualGameObjects.emplace_back(new Enemy(rnd_X, rnd_Y));
}

void Scene::forwardPlayerActions(short& in_controls) {
    if (!m_VisualGameObjects.empty()) {
        ply->move(in_controls, 2);
        ply->shoot(in_controls, &m_VisualGameObjects);
    }
}
