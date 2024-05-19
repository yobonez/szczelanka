#include "VisualGameObject.h"

class Bullet : public VisualGameObject {
public:
    Bullet(short speed, short start_X, short start_Y);
private:
    unsigned short health;
    void setHealth(unsigned short in_Health);
    Bullet* refer();
};
