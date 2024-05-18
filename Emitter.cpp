#pragma once
#include "Emitter.h"
#include "Utils.h"

Emitter::Emitter(VisualGameObject* in_ParentObj) : GameObject("Emitter") {
    parentObj = in_ParentObj;
}

//void Emitter::getParentAbsolutePos(VisualGameObject& in_ParentObj) {
//    std::array<short, 2> parentAbsXY = parentObj.getPos();
//    parentAbs_X = parentAbsXY[0];
//    parentAbs_Y = parentAbsXY[1];
//}
