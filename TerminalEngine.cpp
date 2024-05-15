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

void TerminalEngine::placePatternsOnCanvas(Scene& s) {
    std::vector<GameObject*> objects = s.get_GameObjects();
    // cordy trzeba
    // cordy x,y rozbiæ na 1D i u¿yæ poni¿ej
    for (int i = 0; i < objects.size()) {

    }
    for(int i = 0; i < pattern.length()) {

    }
}

void TerminalEngine::draw() {


    WriteConsoleOutputCharacterW(hConsole, canvas, scr_H*scr_W, { 0,0 }, &charsWritten);
}
