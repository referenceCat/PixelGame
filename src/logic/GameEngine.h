#ifndef PIXELGAME_GAMEENGINE_H
#define PIXELGAME_GAMEENGINE_H
#include <string>
#include "../logic/environment/Environment.h"
#include "../graphics/GraphicEngine.h"
#include "../ui/graphics/GUIEngine.h"
#include "../logic/environment/TestChunkGenerator.h"

#include "math.h"

 class GameEngine {
private:
    int upKeyPressed = 0, downKeyPressed = 0, leftKeyPressed = 0, rightKeyPressed = 0, zoomInKeyPressed = 0, zoomOutKeyPressed = 0;
    double cameraX = 0, cameraY = 0, scale = 4, cameraMovementSpeed = 20, cameraRescaleSpeed = 1.05, maxScale = 8, minScale = 2;
    void operator=(const GameEngine&);

private:
    int paused = 1;
    int testInit();
    Environment environment;
    GraphicEngine* graphicEngine;
    GUIEngine* uiGraphicEngine;

public:
    GameEngine();
    void init(GraphicEngine &graphicEngine, GUIEngine &uiGraphicEngine);
    void update();
    void updateUI();
    void updateGameLogic();
    int isPaused();
    void setPaused(int value);
    void mouseClick(double x, double y);
    void mouseRealise(double x, double y);
    void upButtonClick();
    void upButtonRealise();
    void downButtonClick();
    void downButtonRealise();
    void leftButtonClick();
    void leftButtonRealise();
    void rightButtonClick();
    void rightButtonRealise();
    void zoomInButtonClick();
    void zoomInButtonRealise();
    void zoomOutButtonClick();
    void zoomOutButtonRealise();
    void setCamera(double x, double y, double scale);
 };


#endif //PIXELGAME_GAMEENGINE_H
