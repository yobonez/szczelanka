#include "InvisibleObjectAttachable.h"

InvisibleObjectAttachable::InvisibleObjectAttachable() : GameObject("InvisibleObjectAttachable") {}
InvisibleObjectAttachable::InvisibleObjectAttachable(std::string in_Name) : GameObject(in_Name) {

}
void InvisibleObjectAttachable::setRelativePos(short in_X, short in_Y){
    rel_X = in_X;
    rel_Y = in_Y;
}
