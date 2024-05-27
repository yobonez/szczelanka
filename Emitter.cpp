#pragma once
#include "Emitter.h"
#include "Utils.h"

Emitter::Emitter(VisualGameObject* in_ParentObj) : InvisibleGameObject(),  parentObj(in_ParentObj) { setDetailedName("Emitter"); }

void Emitter::setEmitterRelativePos(short in_X, short in_Y){
    rel_X = in_X;
    rel_Y = in_Y;
}

std::array<short, 2> Emitter::getEmitterAbsolutePos()
{
    std::array<short, 2> parentPos = parentObj->getPos();

    return {short(parentPos[0] + rel_X), short(parentPos[1] + rel_Y)};
}
