#include <iostream>
#include <windows.h>

int main()
{
    // resizable zrobic jak bedzie czas
    const int scrH = 120;
    const int scrW = 30;
    wchar_t* screen = new wchar_t[scrH*scrW];
    HANDLE hConsole = CreateConsoleScreenBuffer(GENERIC_READ | GENERIC_WRITE, 2, NULL, CONSOLE_TEXTMODE_BUFFER, NULL);
    SetConsoleActiveScreenBuffer(hConsole);

    unsigned int charsWritten = 0;
    while(true) {
            if (i > 0) {
            screen[i - 1] = L' ';
            }
            screen[i] = L'X';

            WriteConsoleOutputCharacterW(hConsole, screen, scrH*scrW, { 0,0 }, &charsWritten);
            if (i > scrH*scrW) {
                return 0;
            }
    }
    return 0;
}
