#include "Gun.h"

Gun::Gun(short in_X, short in_Y) : InvisibleObjectAttachable("Gun") {
    setRelativePos(in_X, in_Y);
}
