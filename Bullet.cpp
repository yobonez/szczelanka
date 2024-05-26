#include "Bullet.h"

Bullet::Bullet(short direction, short start_X, short start_Y) : VisualGameObject() {
    std::wstring pattern = L"-->";

    setPredefControls(direction);
    setDetailedName("Bullet");
    setPattern(pattern);
    setSize(3,1);
    setHealth(1);
    setPos(start_X, start_Y);
}

void Bullet::setHealth(unsigned short in_Health) {
    health = in_Health;
}

Bullet* Bullet::refer() { return this; }
