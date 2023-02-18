#include "GameEngine.h"
GameEngine::GameEngine(GraphicEngine &graphicEngine, UIEngine &uiEngine) {
    this->graphicEngine = &graphicEngine;
    setCamera(WORLD_WIDTH_IN_UNITS / 2, WORLD_HEIGHT_IN_UNITS / 2, 960, 540);
    this->uiEngine = &uiEngine;
}

void GameEngine::init() {
    // TODO

    TestChunkGenerator testChunkGenerator = TestChunkGenerator();
    environment.generateChunk(0, 0, testChunkGenerator);
    graphicEngine->addChunkSprite(environment.getChunk(0, 0), 0, 0);

    for (int i = 0; i < WORLD_HEIGHT_IN_CHUNKS / 2 + 16; i++) for (int j = WORLD_WIDTH_IN_CHUNKS / 2 - 3; j < WORLD_WIDTH_IN_CHUNKS / 2 + 3; j++) {
            environment.generateChunk(j, i, testChunkGenerator);
            graphicEngine->addChunkSprite(environment.getChunk(j, i), j, i);
        }
    graphicEngine->addImageSprite(RectangleDouble{WORLD_WIDTH_IN_UNITS / 2, WORLD_HEIGHT_IN_UNITS / 2, 240, 135}, 107, 0, "../data/test_layer_3.png");
    graphicEngine->addImageSprite(RectangleDouble{WORLD_WIDTH_IN_UNITS / 2, WORLD_HEIGHT_IN_UNITS / 2, 240, 135}, 200, 0, "../data/test_layer_4.png");
    graphicEngine->addImageSprite(RectangleDouble{WORLD_WIDTH_IN_UNITS / 2, WORLD_HEIGHT_IN_UNITS / 2, 71, 30}, 100, 200, "../data/test_building_sprites.png");
    Server server;
    server.setRectangle(RectangleInt{WORLD_WIDTH_IN_UNITS/ 2 - 20, WORLD_HEIGHT_IN_UNITS / 2, 16, 20});
    int serverId = environment.addStaticObject(server);
    graphicEngine->addStaticObjectSprite(server);
}
void GameEngine::update() {
    if (uiEngine->isUpPressed() and cameraY < WORLD_HEIGHT_IN_UNITS) setCamera(cameraX, cameraY + cameraMovementSpeed * displayHeightInUnits / 1080, displayWidthInUnits, displayHeightInUnits);
    if (uiEngine->isDownPressed() and cameraY > 0) setCamera(cameraX, cameraY - cameraMovementSpeed * displayHeightInUnits / 1080, displayWidthInUnits, displayHeightInUnits);
    if (uiEngine->isLeftPressed() and cameraX > 0) setCamera(cameraX - cameraMovementSpeed * displayWidthInUnits / 1920, cameraY, displayWidthInUnits, displayHeightInUnits);
    if (uiEngine->isRightPressed() and cameraX < WORLD_WIDTH_IN_UNITS) setCamera(cameraX + cameraMovementSpeed * displayWidthInUnits / 1920, cameraY, displayWidthInUnits, displayHeightInUnits);
    if (uiEngine->isZoomInPressed() and 1920 / displayWidthInUnits < maxScale) setCamera(cameraX, cameraY,  displayWidthInUnits / cameraRescaleSpeed, displayHeightInUnits / cameraRescaleSpeed);
    if (uiEngine->isZoomOutPressed() and 1920 / displayWidthInUnits > minScale) setCamera(cameraX, cameraY,  displayWidthInUnits * cameraRescaleSpeed, displayHeightInUnits * cameraRescaleSpeed);
    updateUI();
    if (!isPaused()) updateGameLogic();
}

void GameEngine::updateUI() {}
void GameEngine::updateGameLogic() {}
int GameEngine::isPaused() {return this->paused;}
void GameEngine::setPaused(int value) {this->paused = value;}

void GameEngine::mouseClick(double x, double y) {

}

void GameEngine::mouseRealise(double x, double y) {

}


void GameEngine::setCamera(double x, double y, double displayWidthInUnits, double displayHeightInUnits) {
    setCameraX(x);
    setCameraY(y);
    setDisplayWidthInUnits(displayWidthInUnits);
    setDisplayHeightInUnits(displayHeightInUnits);
    graphicEngine->setCamera(x, y, displayWidthInUnits, displayHeightInUnits);
}

double GameEngine::getCameraX() const {
    return cameraX;
}

void GameEngine::setCameraX(double cameraX) {
    GameEngine::cameraX = cameraX;
}

double GameEngine::getCameraY() const {
    return cameraY;
}

void GameEngine::setCameraY(double cameraY) {
    GameEngine::cameraY = cameraY;
}

double GameEngine::getDisplayWidthInUnits() const {
    return displayWidthInUnits;
}

void GameEngine::setDisplayWidthInUnits(double displayWidthInUnits) {
    GameEngine::displayWidthInUnits = displayWidthInUnits;
}

double GameEngine::getDisplayHeightInUnits() const {
    return displayHeightInUnits;
}

void GameEngine::setDisplayHeightInUnits(double displayHeightInUnits) {
    GameEngine::displayHeightInUnits = displayHeightInUnits;
}

