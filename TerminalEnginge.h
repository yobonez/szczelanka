#pragma once
#include <windows.h>
#include "Scene.h"

class TerminalEngine {
private:
    short scr_W, scr_H;
    short playerControls;
    Scene scene;
    std::vector<VisualGameObject*>* visibleObjects;
    std::vector<InvisibleGameObject*>* invisibleObjects;
    wchar_t* canvas;
    HANDLE hConsole;
    DWORD charsWritten;
    void placePatternsOnCanvas();
    void handleKeys();
    void handleMovement();
    void handleCollisions();
    void draw();

    void doEvents();

public:
    TerminalEngine();
    void init();
    void tick();
};
