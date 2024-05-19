#pragma once
#include <windows.h>
#include "Scene.h"

class TerminalEngine {
private:
    short scr_W, scr_H;
    Scene scene;
    std::vector<VisualGameObject*>* visibleObjects;
    wchar_t* canvas;
    HANDLE hConsole;
    unsigned int charsWritten;
    void placePatternsOnCanvas();
    void handleKeys();
    void draw();

public:
    TerminalEngine();
    void createScene();
    void tick();
};
