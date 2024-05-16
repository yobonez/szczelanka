#pragma once
#include <windows.h>
#include "Scene.h"

class TerminalEngine {
private:
    short scr_W, scr_H;
    Scene scene;
    wchar_t* canvas;
    HANDLE hConsole;
    unsigned int charsWritten;

public:
    TerminalEngine();
    void createScene();
    void placePatternsOnCanvas();
    void tick();
    void draw();
};
