#include "VisualGameObject.h"

class Player : public VisualGameObject {
private:
    unsigned short health;
public:
    Player();
    void setHealth(int in_Health);
};
