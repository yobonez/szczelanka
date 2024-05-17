#pragma once
#include "TerminalEnginge.h"
#include "GameObject.h"
#include "Player.h"

TerminalEngine::TerminalEngine() : scr_H(30), scr_W(120){
    hConsole = CreateConsoleScreenBuffer(GENERIC_READ | GENERIC_WRITE, 2, NULL, CONSOLE_TEXTMODE_BUFFER, NULL);
    SetConsoleActiveScreenBuffer(hConsole);
    charsWritten = 0;
}

void TerminalEngine::createScene() {
    canvas = new wchar_t[scr_W*scr_H];

    scene.createPlayer();
    scene.createEnemy();
}

void TerminalEngine::placePatternsOnCanvas() {
    std::vector<GameObject*>* objects = scene.get_GameObjects();

    for (int i = 0; i < objects->size(); i++) {
        GameObject* currentObject = (*objects)[i];

        std::array<short, 2> objectCoordinates = currentObject->getPos();
        short coord_1D = objectCoordinates[0] + scr_W * objectCoordinates[1];

        std::wstring objectPattern = currentObject->getPattern();
        size_t objectPatternLength = objectPattern.length();

        std::array<size_t, 2> objectSizeXY = currentObject->getSize();

        short rowCount = 0;
        short colCount = 0;
        short patternUpSideLength = 0, patternDownSideLength = 0;

        for (int Y = 0; Y <= objectSizeXY[1] + 1; Y++) {
            for (int X = 0; X <= objectSizeXY[0] + 1; X++) {
                canvas[coord_1D - scr_W - 1 + X + (scr_W * Y)] = L' ';
            }
        }
        for (int i = 0; i < objectPatternLength; i++) {
            if (objectPattern[i] != L'`') {
                canvas[coord_1D + rowCount + (scr_W * colCount)] = objectPattern[i];
                rowCount++;
            }
            else
            {
                colCount++;
                if (colCount == 1) patternUpSideLength = rowCount;
                patternDownSideLength = rowCount;
                rowCount = 0;
            }
        }
    }
}

void TerminalEngine::handleKeys() {
    short playerDirection = 0;

    if (GetAsyncKeyState('W') & 0x8000) playerDirection |= GameObject::objectVelocityDirection::UP;
    if (GetAsyncKeyState('A') & 0x8000) playerDirection |= GameObject::objectVelocityDirection::LEFT;
    if (GetAsyncKeyState('S') & 0x8000) playerDirection |= GameObject::objectVelocityDirection::DOWN;
    if (GetAsyncKeyState('D') & 0x8000) playerDirection |= GameObject::objectVelocityDirection::RIGHT;

    scene.forwardPlayerActions(playerDirection);
}

void TerminalEngine::tick() {
    handleKeys();
    // handleCollisions();
    draw();
}

void TerminalEngine::draw() {
    placePatternsOnCanvas();
    WriteConsoleOutputCharacterW(hConsole, canvas, scr_H*scr_W, { 0,0 }, &charsWritten);
}
