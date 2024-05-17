#include "Enemy.h"

Enemy::Enemy() : VisualGameObject("Enemy") {
    std::wstring pattern = L"  </--#`<|----#|:::`  <\\--#";

    setPattern(pattern);
    setSize(11, 3);
    setHealth(100);

    std::mt19937 rng_X(rd());
	std::uniform_int_distribution<int> uni_X(50, 110);
    std::mt19937 rng_Y(rd());
	std::uniform_int_distribution<int> uni_Y(0, 22);

	short rnd_X = uni_X(rng_X);
	short rnd_Y = uni_Y(rng_Y);
    setPos(rnd_X, rnd_Y);
}
void Enemy::setHealth(unsigned short in_Health) {
    health = in_Health;
}
