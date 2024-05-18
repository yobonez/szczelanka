#include "Player.h"

Player::Player(std::vector<Gun*> in_Guns) : VisualGameObject(), guns(in_Guns) { // sprawdz se potem czy mozesz po referencji in_guns wziac
    std::wstring pattern = L"     #---\\>` .//|#-->`::|||#-----|>` .\\\\|#-->`     #---/>";

    setPattern(pattern);
    setSize(13, 5);
    setHealth(100);
    setPos(0,10);
}
void Player::setHealth(unsigned short in_Health) {
    health = in_Health;
}

void Player::shoot() {
    for (Gun* gun : guns) {
        gun->shoot(1);
    }
}

