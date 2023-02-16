#ifndef PIXELGAME_UIEVENTMANAGER_H
#define PIXELGAME_UIEVENTMANAGER_H
#include "../logic/GameEngine.h"

class UIEventManager {
private:
    GameEngine* gameEngine;

public:
    UIEventManager(GameEngine& gameEngine);
    void keyCLick(int keyId);
    void keyRealise(int keyId);
    void mouseMove(int x, int y);
    void mouseClick(int mouseKeyId);

};


#endif //PIXELGAME_UIEVENTMANAGER_H
