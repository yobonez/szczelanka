#include "Player.h"

Player::Player() : VisualGameObject() { // sprawdz se potem czy mozesz po referencji in_guns wziac
    std::wstring pattern = L"     #---\\>` .//|#-->`::|||#-----|>` .\\\\|#-->`     #---/>";

    setDetailedName("Player");
    setPattern(pattern);
    setSize(13, 5);
    setHealth(100);
    setPos(0,10);

    attachGun(new Gun(this, 10, 0));
    attachGun(new Gun(this, 12, 2));
    attachGun(new Gun(this, 10, 4));
}
void Player::attachGun(Gun* gun) {
    guns.emplace_back(gun);
}

void Player::setHealth(unsigned short in_Health) {
    health = in_Health;
}

std::vector<Bullet*>* Player::shoot(short& in_controls) {
    if ((in_controls & controls::SHOOT) != 0){
        for (Gun* gun : guns) {
            bullets.emplace_back(gun->shoot(GameObject::controls::RIGHT));
        }
    }
    return &bullets;
}

Player* Player::refer() { return this; }

