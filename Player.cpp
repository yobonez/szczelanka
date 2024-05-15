#include "Player.h"

Player::Player() : VisualGameObject("Player") {
    std::string pattern = "####<`##`#######>`##`####<";

    setHealth(100);
    setPos(0,0);
    setPattern(pattern);
}
void Player::setHealth(int in_Health) {
    health = in_Health;
}

