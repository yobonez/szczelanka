#include "Player.h"

Player::Player() : VisualGameObject() { // sprawdz se potem czy mozesz po referencji in_guns wziac
    std::wstring pattern = L"     #---\\>` .//|#-->`::|||#-----|>` .\\\\|#-->`     #---/>";

    setDetailedName("Player");

    setObjFacing(GameObject::controls::RIGHT);
    setPattern(pattern);
    setSize(13, 5);
    setHealth(100);
    setPos(0,10);

    attachGun(new Gun(this, 10, 0, 26));
    attachGun(new Gun(this, 12, 2, 26));
    attachGun(new Gun(this, 10, 4, 26));
}
void Player::attachGun(Gun* gun) {
    guns.emplace_back(gun);
}

void Player::setHealth(unsigned short in_Health) {
    m_health = in_Health;
}

void Player::dealDamage(unsigned short in_Damage) {
    m_health -= in_Damage;
    if (m_health <= 0) {
        for (Gun* gun : guns) {
            delete gun;
        }
        guns.clear();
        markForDeath(); // mark for deletion
    }
}

void Player::shoot(short& in_controls, std::vector<VisualGameObject*>* bulletContainer) {
    if ((in_controls & controls::SHOOT) != 0){
        for (Gun* gun : guns) {
            Bullet* bullet = gun->shoot(GameObject::controls::RIGHT);
            if (bullet != nullptr) bulletContainer->emplace_back(bullet);
        }
    }
}

Player* Player::refer() { return this; }

