#include "InvisibleObjectAttachable.h"
#include "Projectile.h"

class Gun : public InvisibleObjectAttachable {
public:
    Gun();
    void emitProjectile();
};
