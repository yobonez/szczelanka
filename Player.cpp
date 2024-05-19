#include "Player.h"

Player::Player() : VisualGameObject() { // sprawdz se potem czy mozesz po referencji in_guns wziac
    std::wstring pattern = L"     #---\\>` .//|#-->`::|||#-----|>` .\\\\|#-->`     #---/>";

    setPattern(pattern);
    setSize(13, 5);
    setHealth(100);
    setPos(0,10);
}
void Player::setHealth(unsigned short in_Health) {
    health = in_Health;
}
void Player::attachGun(Gun* gun) {
    guns.emplace_back(gun);
}
Player* Player::refer() { return this; }

void Player::shoot(short& in_controls) {
    if ((in_controls & controls::SHOOT) != 0){
        for (Gun* gun : guns) {
            gun->shoot(1);
        }
    }
}

