#include "TerminalEnginge.h"
#include "VisualGameObject.h"
#include "Player.h"

int main()
{
    TerminalEngine game;
    game.init();
    // a menu, perhaps?

    while(true) {
        game.tick();
        Sleep(17); // 60 FPS
    }
    return 0;
}
