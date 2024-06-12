#pragma once
#include "VisualGameObject.h"
#include <iostream>
#include <string>
#include <windows.h>
#include <filesystem>

namespace Utils {
    short coord2DTo1D(short in_X, short in_Y, short in_scrW);
    void displayText2D(std::string in_msg, wchar_t* in_canvas, short in_X, short in_Y, short in_scrW);
    bool isIntersecting(VisualGameObject* obj1, VisualGameObject* obj2);
}
