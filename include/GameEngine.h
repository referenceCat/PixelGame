#ifndef PIXELGAME_GAMEENGINE_H
#define PIXELGAME_GAMEENGINE_H
#include <string>
#include "Environment.h"

class GameEngine {
private:
    int paused = 1;
    int testInit();
    // Environment environment;

public:
    int init();
    int update();
    int updateUI();
    int updateGameLogic();
    int isPaused();
    void setPaused(int value);

};


#endif //PIXELGAME_GAMEENGINE_H
