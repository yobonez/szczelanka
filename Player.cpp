#include "Player.h"

Player::Player() : VisualGameObject("Player") {
    std::wstring pattern = L"     #---\>` .//|#-->`::|||#-----|>` .\\|#-->`     #---/>";

    setHealth(100);
    setPos(30,30);
    setPattern(pattern);
}
void Player::setHealth(int in_Health) {

}

