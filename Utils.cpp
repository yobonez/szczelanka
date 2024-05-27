#include "Utils.h"

short Utils::coord2DTo1D(short in_X, short in_Y, short in_scrW) {
    return in_Y * in_scrW + in_X;
}
void Utils::debugMsg(std::string in_msg, wchar_t* in_canvas) {
    std::wstring win_msg = std::filesystem::path(in_msg).wstring();
    for (int i = 0; i < win_msg.size(); i++) { in_canvas[i] = win_msg[i]; }
}
