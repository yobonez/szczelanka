#include "TerminalEnginge.h"
#include "VisualGameObject.h"
#include "Player.h"

int main()
{
    TerminalEngine game;
    game.init();

    while(true) {
        game.tick();
        Sleep(33);
    }
    return 0;
}
