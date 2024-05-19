#include "GameObject.h"

class InvisibleGameObject : public GameObject {
private:
    short m_X, m_Y;
public:
    InvisibleGameObject();

    virtual void setPos(short in_X, short in_Y);
    virtual std::array<short, 2> getPos();
};
