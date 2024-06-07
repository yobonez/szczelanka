#pragma once
#include "TerminalEnginge.h"
#include "GameObject.h"
#include "Player.h"
#include "Enemy.h"
#include "Gun.h"
#include "Utils.h"
#include <algorithm>
#include <bitset>

short timer = 0;
short visObjectCount = 0;

TerminalEngine::TerminalEngine() : scr_W(120), scr_H(30) {
    hConsole = CreateConsoleScreenBuffer(GENERIC_READ | GENERIC_WRITE, 2, NULL, CONSOLE_TEXTMODE_BUFFER, NULL);
    SetConsoleActiveScreenBuffer(hConsole);
    charsWritten = 0;
}

void TerminalEngine::init() {
    timer = 0;
    canvas = new wchar_t[scr_W*scr_H]();

    scene.createPlayer();

    visibleObjects = scene.get_PtrVisibleGameObjects();
}

void TerminalEngine::doEvents() {
    if(timer % 50 == 0) {
        scene.createEnemy();
    }
    for(VisualGameObject* obj : *visibleObjects) {
        if(obj->getDetailedName() == "Enemy") {
            Enemy* enemy = (Enemy*)obj->refer();
            enemy->shoot(visibleObjects);
        }
    }
}

void TerminalEngine::placePatternsOnCanvas() {
    for (int i = 0; i < visibleObjects->size(); i++) {
        VisualGameObject* currentObject = (*visibleObjects)[i];

        std::array<short, 2> objectCoordinates = currentObject->getPos();
        short coord_1D = Utils::coord2DTo1D(objectCoordinates[0], objectCoordinates[1], scr_W);

        std::wstring objectPattern = currentObject->getPattern();
        size_t objectPatternLength = objectPattern.length();

        std::array<short, 2> objectSizeXY = currentObject->getSize();

        short rowCount = 0;
        short colCount = 0;
//        short patternUpSideLength = 0, patternDownSideLength = 0;

        // primitive clearing before rendering, so the terminal isn't gonna be cluttered with mess
        // will make a better version if i'll have time
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
//                if (colCount == 1) patternUpSideLength = rowCount;
//                patternDownSideLength = rowCount;
                rowCount = 0;
            }
        }
    }
}

void TerminalEngine::handleKeys() {
    playerControls = 0;

    if (GetAsyncKeyState('W') & 0x8000) playerControls |= GameObject::controls::UP;
    if (GetAsyncKeyState('A') & 0x8000) playerControls |= GameObject::controls::LEFT;
    if (GetAsyncKeyState('S') & 0x8000) playerControls |= GameObject::controls::DOWN;
    if (GetAsyncKeyState('D') & 0x8000) playerControls |= GameObject::controls::RIGHT;

    if (GetAsyncKeyState(VK_SPACE) & 0x8000) playerControls |= GameObject::controls::SHOOT;

    scene.forwardPlayerActions(playerControls);
}

void TerminalEngine::handleMovement(){
    short direction = 0;
    for(VisualGameObject* obj : *visibleObjects) {
        if (obj->getDetailedName() == "Bullet") obj->move(direction, 1);
        if (obj->getDetailedName() == "Enemy") obj->move(direction, 5);
    }

    std::bitset<16> binDirection(playerControls);
    std::string debugStr = "Controls: " + binDirection.to_string() + " | " + std::to_string(visObjectCount);

    Utils::debugDisplay(debugStr, canvas);
}

void TerminalEngine::handleCollisions() {
    // Get player, enemies and bullets
    std::vector<VisualGameObject*> shipsToCheck;
    std::vector<Bullet*> bulletsChecking;

    shipsToCheck.emplace_back((*visibleObjects)[0]);

    for (int i = 1; i < visibleObjects->size(); i++) {
        VisualGameObject* obj = (*visibleObjects)[i];
        if (obj->getDetailedName() == "Enemy") shipsToCheck.emplace_back(obj);
        if (obj->getDetailedName() == "Bullet") bulletsChecking.emplace_back((Bullet*)obj->refer());
    }

    // "ask" a bullet whether is it colliding with a player/enemy
    for(Bullet* bullet : bulletsChecking) {
        for(int i = 0; i < shipsToCheck.size(); i++) {
            bullet->tryDealingDamage(shipsToCheck[i]);
        }
    }
    // if so,
    // each bullet checks for enemy/player collision

//    Player* player = (Player*)visibleObjects[0]->refer();
//    for (VisualGameObject* obj : *visibleObjects) {
//    }
}

void TerminalEngine::tick() {
    timer++;
    if (timer >= 50) { timer = 0; }

    visObjectCount = visibleObjects->size();
    handleKeys();
    handleMovement();
    handleCollisions();
    doEvents();
    draw();
}

void TerminalEngine::draw() {
    placePatternsOnCanvas();
    WriteConsoleOutputCharacterW(hConsole, canvas, scr_H*scr_W, { 0,0 }, &charsWritten);
}
