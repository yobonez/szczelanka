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

bool Utils::isIntersecting(VisualGameObject* obj1, VisualGameObject* obj2)
{
    std::array<short, 2> obj1XY = obj1->getPos();
    std::array<short, 2> obj1Size = obj1->getSize();
    std::array<short, 2> obj2XY = obj2->getPos();
    std::array<short, 2> obj2Size = obj2->getSize();

    std::array<short, 2> obj1Vertices[4] = {
        {obj1XY[0], obj1XY[1]},
        {obj1XY[0] + obj1Size[0], obj1XY[1]},
        {obj1XY[0], obj1XY[1] + obj1Size[1]},
        {obj1XY[0] + obj1Size[0], obj1XY[1] + obj1Size[1]}
    };

//    return !(obj1XY[0] > obj2XY[0] + obj2Size[0] ||
//             obj1XY[0] + obj1Size[0] < obj2XY[0] ||
//             obj1XY[1] > obj2XY[1] + obj2Size[1] ||
//             obj1XY[1] + obj1Size[1] < obj2XY[1]);

    for(int i = 0; i < 4; i++) {
        if ((obj1Vertices[i][0] > obj2XY[0]) &&
            (obj1Vertices[i][0] < obj2XY[0] + obj2Size[0]) &&
            (obj1Vertices[i][1] > obj2XY[1]) &&
            (obj1Vertices[i][1] < obj2XY[1] + obj2Size[1]))
        {
            return true;
        }
    }
    return false;
}
