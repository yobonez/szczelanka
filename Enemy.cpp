#include "Enemy.h"

Enemy::Enemy() : VisualGameObject("Enemy") {
    std::wstring pattern = L"  </--#`<|----#|:::`  <\--#";

    setHealth(100);
    setPos(30,30);
    setPattern(pattern);
}

void Enemy::setHealth(int in_Health) {}
