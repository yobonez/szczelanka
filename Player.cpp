#include "Player.h"

Player::Player() : VisualGameObject("Player") {
    std::wstring pattern = L"     #---\\>` .//|#-->`::|||#-----|>` .\\\\|#-->`     #---/>";

    setPattern(pattern);
    setSize(13, 5);
    setHealth(100);
    setPos(0,10);
}
void Player::setHealth(unsigned short in_Health) {
    health = in_Health;
}

