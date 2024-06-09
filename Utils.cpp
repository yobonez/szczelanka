#include "Utils.h"

extern short prevDebugMsgLength;

short Utils::coord2DTo1D(short in_X, short in_Y, short in_scrW) {
    return in_Y * in_scrW + in_X;
}

// TODO: normal text display, with x,y beginning coords, maybe i could
// display HP of enemies and player that way
void Utils::debugDisplay(std::string in_msg, wchar_t* in_canvas) {
    std::wstring win_msg = std::filesystem::path(in_msg).wstring();
    for (int i = 0; i < prevDebugMsgLength; i++) { in_canvas[i] = L' '; }
    for (int i = 0; i < win_msg.size(); i++) { in_canvas[i] = win_msg[i]; }
    prevDebugMsgLength = win_msg.size();
}
