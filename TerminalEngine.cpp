#pragma once
#include "TerminalEnginge.h"
#include "GameObject.h"
#include "Player.h"
//#include <bitset>

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
    // czyscic jakos po sobie po poruszeniu sie obiektu

//    std::bitset<16> x(test);
//    std::string xxtest = x.to_string();
//    std::wstring xtest(xxtest.length(), L' ');
//    std::copy(xxtest.begin(), xxtest.end(), xtest.begin());
//    for(int i = 0; i < xtest.length(); i++) {
//        canvas[i] = xtest[i];
//    }
}

void TerminalEngine::handleKeys() {
    short playerDirection = 0;

    if (GetAsyncKeyState('W') & 0x8000) playerDirection |= GameObject::objectVelocityDirection::UP;
    if (GetAsyncKeyState('A') & 0x8000) playerDirection |= GameObject::objectVelocityDirection::LEFT;
    if (GetAsyncKeyState('S') & 0x8000) playerDirection |= GameObject::objectVelocityDirection::DOWN;
    if (GetAsyncKeyState('D') & 0x8000) playerDirection |= GameObject::objectVelocityDirection::RIGHT;

    scene.forwardPlayerActions(playerDirection);

    test = playerDirection;
}

void TerminalEngine::tick() {
    handleKeys();

    draw();
}

void TerminalEngine::draw() {
    placePatternsOnCanvas();
    WriteConsoleOutputCharacterW(hConsole, canvas, scr_H*scr_W, { 0,0 }, &charsWritten);
}
