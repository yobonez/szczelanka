#include "Scene.h"
#include "Player.h"
#include "Enemy.h"

extern short ext_scrH;
extern short ext_scrW;

Scene::Scene() {
}

void Scene::createPlayer() {
    m_VisualGameObjects.emplace_back(new Player());
    ply = (Player*)m_VisualGameObjects[0]->refer();
}
void Scene::createEnemy() {
    VisualGameObject* newEnemy = new Enemy(0, 0);
    std::array<short, 2> newEnemySize = newEnemy->getSize();

    // difficulty? ez - 3, mid - 6, etc.
    short enemyCount = 0;
    for (VisualGameObject* obj : m_VisualGameObjects) {
        if (obj->getDetailedName() == "Enemy") {
            enemyCount++;
        }
    }

    srand(time(NULL));
    short rnd_X = (rand() % (ext_scrW/2)) + (ext_scrW/2);
    short rnd_Y = (rand() % (ext_scrH/4)) + (ext_scrH/4);
    newEnemy->setPos(rnd_X, rnd_Y);

//    bool canSpawn = true;
//    if (enemyCount > 0) {
//        canSpawn = false;
//
//        while(!canSpawn) {
//            srand(time(NULL));
//            short rnd_X = (rand() % 60) + 60;
//            short rnd_Y = (rand() % 10) + 10;
//            newEnemy->setPos(rnd_X, rnd_Y);
//
//            for(VisualGameObject* existingEnemy : m_VisualGameObjects) {
//                if (existingEnemy->getDetailedName() != "Enemy") continue;
//                if (!Utils::isIntersecting(newEnemy, existingEnemy)){
//                    canSpawn = true;
//                }
//            }
//        }
//    }

    if (enemyCount > 4){
        delete newEnemy;
        return;
    }
    /*if (canSpawn) */ m_VisualGameObjects.emplace_back(newEnemy);
}

void Scene::forwardPlayerActions(short& in_controls) {
    if (!m_VisualGameObjects.empty()) {
        ply->move(in_controls, 2);
        ply->shoot(in_controls, &m_VisualGameObjects);
    }
}

void Scene::purge() {
    for (int i = 0; i < m_VisualGameObjects.size(); i++) {
        VisualGameObject* obj = m_VisualGameObjects[i];
        if(!(obj->isDead())) {
            obj->dealDamage(100);
            delete obj;
        }
    }
    delete ply;
    m_VisualGameObjects.clear();
}
