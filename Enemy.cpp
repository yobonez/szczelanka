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
}

void Enemy::setHealth(unsigned short in_Health) {
    health = in_Health;
}

Enemy* Enemy::refer() { return  this; }
