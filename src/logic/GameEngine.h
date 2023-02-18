#ifndef PIXELGAME_GAMEENGINE_H
#define PIXELGAME_GAMEENGINE_H
#include <string>
#include "../logic/environment/Environment.h"
#include "../graphics/GraphicEngine.h"
#include "../ui/UIEngine.h"
#include "environment/chunks/TestChunkGenerator.h"
#include "environment/static_objects/server/Server.h"
#include "../ui/widgets/Widget.h"
#include "../ui/widgets/Window.h"

#include "math.h"

 class GameEngine {
 private:
     void operator=(const GameEngine&);
private:
    double cameraX = 0,
    cameraY = 0,
    displayWidthInUnits = 960,
    displayHeightInUnits = 540,
    cameraMovementSpeed = 25,
    cameraRescaleSpeed = 1.05,
    maxScale = 8, minScale = 2;
    int testWindowId = 10;
     Window window{};

 public:
     double getCameraX() const;

     void setCameraX(double cameraX);

     double getCameraY() const;

     void setCameraY(double cameraY);

     double getDisplayWidthInUnits() const;

     void setDisplayWidthInUnits(double displayWidthInUnits);

     double getDisplayHeightInUnits() const;

     void setDisplayHeightInUnits(double displayHeightInUnits);

private:
    int paused = 1;
    Environment environment;
    GraphicEngine* graphicEngine;
    UIEngine* uiEngine;

public:
    GameEngine(GraphicEngine &graphicEngine, UIEngine &uiEngine);
    void init();
    void update();
    void updateUI();
    void updateGameLogic();
    int isPaused();
    void setPaused(int value);
    void mouseClick(double x, double y);
    void mouseRealise(double x, double y);
    void setCamera(double x, double y, double displayWidthInUnits, double displayHeightInUnits);
 };


#endif //PIXELGAME_GAMEENGINE_H
