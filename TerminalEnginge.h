#pragma once
#include <windows.h>
#include "Scene.h"

class TerminalEngine {
private:
    short timer;
    short scr_W, scr_H;
    Scene scene;
    std::vector<VisualGameObject*>* visibleObjects;
    std::vector<InvisibleGameObject*>* invisibleObjects;
    wchar_t* canvas;
    HANDLE hConsole;
    unsigned int charsWritten;
    void placePatternsOnCanvas();
    void handleKeys();
    void handleMovement();
    void draw();

    void doEvents();

public:
    TerminalEngine();
    void init();
    void tick();
};
