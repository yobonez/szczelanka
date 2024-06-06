#include "Enemy.h"

Enemy::Enemy() : VisualGameObject() {
    std::wstring pattern = L"  </--#`<|----#|:::`  <\\--#";

    short controls = GameObject::controls::LEFT;
    setPredefControls(controls);
    setDetailedName("Enemy");
    setPattern(pattern);
    setSize(11, 3);
    setHealth(100);

    srand(time(NULL));

    short rnd_X = (rand() % 100) + 50;
    short rnd_Y = (rand() % 10) + 10;
    setPos(rnd_X, rnd_Y);

    attachGun(new Gun(this, 0, 1));
}

void Enemy::attachGun(Gun* gun) {
    guns.emplace_back(gun);
}

void Enemy::setHealth(unsigned short in_Health) {
    health = in_Health;
}

std::vector<Bullet*>* Enemy::shoot() {
    for (Gun* gun : guns) {
        bullets.emplace_back(gun->shoot(GameObject::controls::LEFT));
    }
    return &bullets;
}

Enemy* Enemy::refer() { return  this; }
