#include "GameEngine.h"
GameEngine::GameEngine() {}

void GameEngine::init(GraphicEngine &graphicEngine, GUIEngine &uiGraphicEngine) {
    this->graphicEngine = &graphicEngine;
    graphicEngine.moveCamera(cameraX, cameraY);
    graphicEngine.setPixelsToUnitRatio(scale);
    setCamera(WORLD_WIDTH_IN_UNITS / 2, WORLD_HEIGHT_IN_UNITS / 2, 4);
    this->uiGraphicEngine = &uiGraphicEngine;
    TestChunkGenerator testChunkGenerator = TestChunkGenerator();

    for (int i = WORLD_HEIGHT_IN_CHUNKS / 2 - 1; i < WORLD_HEIGHT_IN_CHUNKS / 2 + 1; i++) for (int j = WORLD_WIDTH_IN_CHUNKS / 2- 5; j < WORLD_WIDTH_IN_CHUNKS / 2 + 5; j++) {
            environment.generateChunk(j, i, testChunkGenerator);
            graphicEngine.addChunkSprite(environment.getChunk(j, i), j, i);
            environment.deleteChunk(j, i);
        }
    //graphicEngine.addRectSprite(0, 50, 11, 50, 50);
    //graphicEngine.addRectSprite(50, 50, 11, 50, 50);
    //graphicEngine.addRectSprite(0, 0, 10, 50, 50);
    //graphicEngine.addRectSprite(50, 0, 10, 50, 50);
}
void GameEngine::update() {
    if (upKeyPressed and cameraY < WORLD_HEIGHT_IN_UNITS) setCamera(cameraX, cameraY + cameraMovementSpeed / scale, scale);
    if (downKeyPressed and cameraY > 0) setCamera(cameraX, cameraY - cameraMovementSpeed / scale, scale);
    if (leftKeyPressed and cameraX > 0) setCamera(cameraX - cameraMovementSpeed / scale, cameraY, scale);
    if (rightKeyPressed and cameraX < WORLD_WIDTH_IN_UNITS) setCamera(cameraX + cameraMovementSpeed / scale, cameraY, scale);
    if (zoomInKeyPressed and scale < maxScale) setCamera(cameraX, cameraY,  scale * cameraRescaleSpeed);
    if (zoomOutKeyPressed and scale > minScale) setCamera(cameraX, cameraY,  scale / cameraRescaleSpeed);
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

void GameEngine::upButtonClick() {
    upKeyPressed = 1;
}

void GameEngine::upButtonRealise() {
    upKeyPressed = 0;
}

void GameEngine::downButtonClick() {
    downKeyPressed = 1;
}

void GameEngine::downButtonRealise() {
    downKeyPressed = 0;
}

void GameEngine::leftButtonClick() {
    leftKeyPressed = 1;
}

void GameEngine::leftButtonRealise() {
    leftKeyPressed = 0;
}

void GameEngine::rightButtonClick() {
    rightKeyPressed = 1;
}

void GameEngine::rightButtonRealise() {
    rightKeyPressed = 0;
}

void GameEngine::zoomInButtonClick() {
    zoomInKeyPressed = 1;
}

void GameEngine::zoomInButtonRealise() {
    zoomInKeyPressed = 0;
}

void GameEngine::zoomOutButtonClick() {
    zoomOutKeyPressed = 1;
}

void GameEngine::zoomOutButtonRealise() {
    zoomOutKeyPressed = 0;
}

void GameEngine::setCamera(double x, double y, double scale) {
    cameraX = x;
    cameraY = y;
    this->scale = scale;
    graphicEngine->moveCamera(x, y);
    graphicEngine->setPixelsToUnitRatio(scale);
}

