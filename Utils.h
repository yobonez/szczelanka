#pragma once
#include <iostream>
#include <string>
#include <windows.h>
#include <filesystem>

namespace Utils {
    short coord2DTo1D(short in_X, short in_Y, short in_scrW);
    void debugMsg(std::string in_msg, wchar_t* in_canvas);
}
