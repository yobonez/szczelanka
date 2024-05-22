#include "TerminalEnginge.h"
#include "GameObject.h"
#include "Player.h"
#include "Gun.h"
#include "Utils.h"

TerminalEngine::TerminalEngine() : scr_W(120), scr_H(30) {
    hConsole = CreateConsoleScreenBuffer(GENERIC_READ | GENERIC_WRITE, 2, NULL, CONSOLE_TEXTMODE_BUFFER, NULL);
    SetConsoleActiveScreenBuffer(hConsole);
    charsWritten = 0;
}

void TerminalEngine::init() {
    timer = 0;
    canvas = new wchar_t[scr_W*scr_H];

    scene.createPlayer();

    visibleObjects = scene.get_PtrVisibleGameObjects();
//    Player* ply = (Player*)(*visibleObjects)[0]->refer();
    // "attachGun" -> "gunOwner"
    // invisibleObj array to Scene class
    // make a method(?) or another way to update both inv and visibile objects??????????
    // TIMERS!!! we cant spam every 33ms with bullets when we shoot, make timers
    // bullet ?queue?
//    ply->attachGun(new Gun(ply, 2, 12));
}

void TerminalEngine::doEvents() {
    if(timer % 50 == 0) {
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
        short patternUpSideLength = 0, patternDownSideLength = 0;

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
                if (colCount == 1) patternUpSideLength = rowCount;
                patternDownSideLength = rowCount;
                rowCount = 0;
            }
        }
    }
}

void TerminalEngine::handleKeys() {
    short playerControls = 0;

    if (GetAsyncKeyState('W') & 0x8000) playerControls |= GameObject::controls::UP;
    if (GetAsyncKeyState('A') & 0x8000) playerControls |= GameObject::controls::LEFT;
    if (GetAsyncKeyState('S') & 0x8000) playerControls |= GameObject::controls::DOWN;
    if (GetAsyncKeyState('D') & 0x8000) playerControls |= GameObject::controls::RIGHT;

    if (GetAsyncKeyState(VK_SPACE) & 0x8000) playerControls |= GameObject::controls::SHOOT;

    scene.forwardPlayerActions(playerControls);
}

// TODO: void handleMovement - playerControls jako pole w TerminalEngine i tak samo dla enemy

void TerminalEngine::tick() {
    timer++;
    if (timer > 50) { timer = 0; }

    handleKeys();
    doEvents();
    // if objectName = "InvisibleObjectAttachable" then update pozycje czy coœtam etc
    // handleCollisions();
    draw();
}

void TerminalEngine::draw() {
    placePatternsOnCanvas();
    WriteConsoleOutputCharacterW(hConsole, canvas, scr_H*scr_W, { 0,0 }, &charsWritten);
}
