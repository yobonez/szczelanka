#include "Scene.h"

class TerminalEngine {
private:
    Scene scene;
public:
    TerminalEngine();
    void tick();
    int draw();
};
