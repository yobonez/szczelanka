#include "TerminalEnginge.h"
#include "Player.h"

TerminalEngine::TerminalEngine() : scr_H(30), scr_W(120){
    hConsole = CreateConsoleScreenBuffer(GENERIC_READ | GENERIC_WRITE, 2, NULL, CONSOLE_TEXTMODE_BUFFER, NULL);
    SetConsoleActiveScreenBuffer(hConsole);
    charsWritten = 0;
}

void TerminalEngine::createScene() {
    canvas = new wchar_t[scr_W*scr_H];

    scene.createPlayer();
}

void TerminalEngine::placePatternsOnCanvas() {
    std::vector<GameObject*>* objects = scene.get_GameObjects();
    //std::vector<std::array<short,2>> objectsCoordinates;

    for (int i = 0; i < objects->size(); i++) {
        std::array<short,2> objectCoordinates = (*objects)[i]->getPos();
        short coord_1D = objectCoordinates[0] + scr_W * objectCoordinates[1];

        std::wstring objectPattern = (*objects)[i]->getPattern();
        size_t objectPatternLength = objectPattern.length();
        short rowCount = 0;
        short colCount = 0;
        for(int i = 0; i < objectPatternLength; i++) {
            if (objectPattern[i] != L'`') {
                canvas[coord_1D + rowCount + (scr_W * colCount)] = objectPattern[i];
                rowCount++;
            }
            else
            {
                colCount++;
                rowCount = 0;
            }
        }
    }
}

void TerminalEngine::draw() {


    WriteConsoleOutputCharacterW(hConsole, canvas, scr_H*scr_W, { 0,0 }, &charsWritten);
}
