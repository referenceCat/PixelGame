#ifndef PIXELGAME_GAMEENGINE_H
#define PIXELGAME_GAMEENGINE_H
#include <string>
#include "../logic/environment/Environment.h"
#include "../graphics/GraphicEngine.h"
#include "../ui/UIGraphicEngine.h"
#include "../logic/environment/TestChunkGenerator.h"

class GameEngine {
private:
    void operator=(const GameEngine&);

private:
    int paused = 1;
    int testInit();
    Environment environment;
    GraphicEngine* graphicEngine;
    UIGraphicEngine* uiGraphicEngine;

public:
    GameEngine();
    void init(GraphicEngine &graphicEngine, UIGraphicEngine &uiGraphicEngine);
    void update();
    void updateUI();
    void updateGameLogic();
    int isPaused();
    void setPaused(int value);

};


#endif //PIXELGAME_GAMEENGINE_H
