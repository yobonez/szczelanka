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
short prevPrintMsgLength = 0;
short ext_scrW = 0;
short ext_scrH = 0;

TerminalEngine::TerminalEngine() {
    CONSOLE_SCREEN_BUFFER_INFO csbi;
    if (!GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &csbi)) {
        std::cout << "GetConsoleScreenBufferInfo error: " << GetLastError() << std::endl;
    }
    scr_W = csbi.srWindow.Right - csbi.srWindow.Left + 1;
    scr_H = csbi.srWindow.Bottom - csbi.srWindow.Top + 1;

    ext_scrH = scr_H;
    ext_scrW = scr_W;

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
    for(int i = 0; i < visibleObjects->size(); i++) {
        VisualGameObject* obj = (*visibleObjects)[i];
        if(obj->getDetailedName() == "Player" && obj->isDead())
        {
            scene.purge();
            return;
        }
        if(obj->isDead()) {
            delete obj;
            visibleObjects->erase(visibleObjects->begin() + i);
            continue;
        }
        if(obj->getDetailedName() == "Enemy") {
            Enemy* enemy = (Enemy*)obj->refer();
            enemy->shoot(visibleObjects);
        }
    }

    if(timer % 75 == 0) {
        scene.createEnemy();
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

        // primitive clearing before rendering, so the terminal isn't gonna be cluttered with mess
        // will make a better version if i'll have time
        for (int Y = 0; Y <= objectSizeXY[1] + 1; Y++) {
            for (int X = 0; X <= objectSizeXY[0] + 1; X++) {
                canvas[coord_1D - scr_W - 1 + X + (scr_W * Y)] = L' ';
            }
        }

        std::string currObjName = currentObject->getDetailedName();
        if (currObjName == "Player" || currObjName == "Enemy") {
            std::string healthDisplay = "|" + std::to_string(currentObject->getHealth()) + " HP|";
            Utils::displayText2D(healthDisplay, canvas, objectCoordinates[0] + (objectSizeXY[0] / 2) - 2, objectCoordinates[1] - 1, scr_W);
        }
        if (currentObject->isDead()) {
            std::string spaces(objectSizeXY[0] + 2, ' ');
            Utils::displayText2D(spaces, canvas, objectCoordinates[0] - 2, objectCoordinates[1], scr_W);
            continue;
        }

        for (int i = 0; i < objectPatternLength; i++) {
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

void TerminalEngine::clearCanvas() {
    for (int Y = 0; Y < scr_H; Y++) {
        for (int X = 0; X < scr_W; X++) {
            canvas[Utils::coord2DTo1D(X, Y, scr_W)] = L' ';
        }
    }

    draw(false);
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

//    std::bitset<16> binDirection(playerControls);
//    std::string debugStr = "Controls: " + binDirection.to_string() + " | Objects: " + std::to_string(visObjectCount);
//
//    Utils::displayText2D(debugStr, canvas, 0, 1, scr_W);
}

void TerminalEngine::handleCollisions() {
    if (visibleObjects->size() == 0) return;
    // Get player, enemies and bullets
    std::vector<VisualGameObject*> shipsToCheck;
    std::vector<Bullet*> bulletsChecking;

    shipsToCheck.emplace_back((*visibleObjects)[0]);

    for (int i = 0; i < visibleObjects->size(); i++) {
        VisualGameObject* obj = (*visibleObjects)[i];
        std::string objName = obj->getDetailedName();

        std::array<short, 2> obj_XY = obj->getPos();
        std::array<short, 2> objSize = obj->getSize();

        if (obj_XY[0] > scr_W - objSize[0])
        {
            obj->setPos(obj_XY[0] - 1, obj_XY[1]);
            if (objName == "Bullet") obj->dealDamage(100); continue;
        }
        if (obj_XY[0] < 0)
        {
            obj->setPos(obj_XY[0] + 1, obj_XY[1]);
            if (objName == "Enemy") {
                obj->dealDamage(100);
                shipsToCheck[0]->dealDamage(25); continue;
            }
            if (objName == "Bullet") obj->dealDamage(100); continue;
        }
        if (obj_XY[1] >= scr_H - objSize[1]) obj->setPos(obj_XY[0], obj_XY[1] - 1);
        if (obj_XY[1] <= 0) obj->setPos(obj_XY[0], obj_XY[1] + 1);

        if (objName == "Enemy") shipsToCheck.emplace_back(obj);
        if (objName == "Bullet") bulletsChecking.emplace_back((Bullet*)obj->refer());
    }

    // "ask" a bullet whether is it colliding with a player/enemy
    // and deal damage if it's indeed colliding
    for (Bullet* bullet : bulletsChecking) {
        for(VisualGameObject* ship : shipsToCheck) {
            bullet->tryDealingDamage(ship);
        }
    }
}

void TerminalEngine::tick() {
    timer++;
    if (timer >= 100) { timer = 0; }

    visObjectCount = visibleObjects->size();
    handleKeys();
    handleMovement();
    handleCollisions();
    draw(true);
    doEvents();

    // death
    if (visObjectCount == 0) {
        bool keyPressed = false;
        clearCanvas();
        std::string urDead = "Your ship has been destroyed. Press [ENTER] to restart";
        Utils::displayText2D(urDead, canvas, scr_W/2 - urDead.length()/2 - 1, scr_H/2 - 1, scr_W); draw(false);

        while(!keyPressed) {
            Sleep(1);
            if (GetAsyncKeyState(VK_RETURN) & 0x8000) {
                init();
                return;
            }
        }
    }
}

void TerminalEngine::draw(bool in_WithPatterns) {
    if (in_WithPatterns) placePatternsOnCanvas();
    WriteConsoleOutputCharacterW(hConsole, canvas, scr_H*scr_W, { 0,0 }, &charsWritten);
}
