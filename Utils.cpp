#include "Utils.h"

extern short prevPrintMsgLength;

short Utils::coord2DTo1D(short in_X, short in_Y, short in_scrW) {
    return in_Y * in_scrW + in_X;
}

// TODO: normal text display, with x,y beginning coords, maybe i could
// display HP of enemies and player that way
void Utils::displayText2D(std::string in_Msg, wchar_t* in_canvas, short in_X, short in_Y, short in_scrW) {
    std::wstring win_msg = std::filesystem::path(in_Msg).wstring();
    short text1DPos = coord2DTo1D(in_X, in_Y, in_scrW);
    for (int i = 0; i < prevPrintMsgLength; i++) { in_canvas[i] = L' '; }
    for (int i = 0; i < win_msg.size(); i++) {
        // in case of moving text every frame (assuming the text is placed on top of something)
        short textMessGuardPos = text1DPos + i - in_scrW;
        in_canvas[textMessGuardPos - 1] = L' ';
        in_canvas[textMessGuardPos + 1] = L' ';
        // in case of moving text every frame (assuming the text is placed on top of something)

        in_canvas[text1DPos + i] = win_msg[i];
    }
    prevPrintMsgLength = win_msg.size();
}
