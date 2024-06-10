#include "Enemy.h"

Enemy::Enemy() : VisualGameObject() {
    std::wstring pattern = L"  </--#`<|----#|:::`  <\\--#";

    setDetailedName("Enemy");

    short controls = GameObject::controls::LEFT;
    setObjFacing(controls);
    setPredefControls(controls);
    setPattern(pattern);
    setSize(11, 3);
    setHealth(99);

    srand(time(NULL));

    short rnd_X = (rand() % 60) + 60;
    short rnd_Y = (rand() % 10) + 10;
    setPos(rnd_X, rnd_Y);

    attachGun(new Gun(this, 25,0, 1, 50));
}

void Enemy::attachGun(Gun* gun) {
    guns.emplace_back(gun);
}

void Enemy::setHealth(short in_Health) {
    m_health = in_Health;
}
short Enemy::getHealth() { return m_health; }

void Enemy::dealDamage(short in_Damage) {
    m_health -= in_Damage;
    if (m_health <= 0) {
        for (Gun* gun : guns) {
            delete gun;
        }
        guns.clear();

        // remove the object visually on the last render
        std::wstring noPattern = L" ";
        setPattern(noPattern);

        markForDeath(); // mark for deletion in the next tick
    }
}

void Enemy::shoot(std::vector<VisualGameObject*>* bulletContainer) {
    for (Gun* gun : guns) {
        Bullet* bullet = gun->shoot(GameObject::controls::LEFT);
        if (bullet != nullptr) bulletContainer->emplace_back(bullet);
    }
}

Enemy* Enemy::refer() { return  this; }
