#include "GameEngine.h"
GameEngine::GameEngine() {}

void GameEngine::init(GraphicEngine &graphicEngine, GUIEngine &uiGraphicEngine) {
    this->graphicEngine = &graphicEngine;
    graphicEngine.setCameraX(cameraX);
    graphicEngine.setCameraY(cameraY);
    graphicEngine.setDisplayWidthInUnits(displayWidthInUnits);
    graphicEngine.setDisplayHeightInUnits(displayHeightInUnits);
    setCamera(WORLD_WIDTH_IN_UNITS / 2, WORLD_HEIGHT_IN_UNITS / 2, 960, 540);
    this->uiGraphicEngine = &uiGraphicEngine;
    TestChunkGenerator testChunkGenerator = TestChunkGenerator();


    environment.generateChunk(0, 0, testChunkGenerator);
    graphicEngine.addChunkSprite(environment.getChunk(0, 0), 0, 0);

    for (int i = WORLD_HEIGHT_IN_CHUNKS / 2 - 5; i < WORLD_HEIGHT_IN_CHUNKS / 2 + 5; i++) for (int j = WORLD_WIDTH_IN_CHUNKS / 2 - 5; j < WORLD_WIDTH_IN_CHUNKS / 2 + 5; j++) {
            environment.generateChunk(j, i, testChunkGenerator);
            // if (i < 16 && j < 64)
            graphicEngine.addChunkSprite(environment.getChunk(j, i), j, i);
            // environment.deleteChunk(j, i);
        }
    graphicEngine.addImageSprite(WORLD_WIDTH_IN_UNITS / 2, WORLD_HEIGHT_IN_UNITS / 2 + 90, 107, 240, 135, 0, "../data/test_layer_3.png");
    graphicEngine.addImageSprite(WORLD_WIDTH_IN_UNITS / 2, WORLD_HEIGHT_IN_UNITS / 2 + 90, 200, 240, 135, 0, "../data/test_layer_4.png");
    graphicEngine.addImageSprite(WORLD_WIDTH_IN_UNITS / 2, WORLD_HEIGHT_IN_UNITS / 2 + 78.5, 100, 71, 30, 200, "../data/test_building_sprites.png");
    //graphicEngine.addRectSprite(0, 50, 11, 50, 50);
    //graphicEngine.addRectSprite(50, 50, 11, 50, 50);
    //graphicEngine.addRectSprite(0, 0, 10, 50, 50);
    //graphicEngine.addRectSprite(50, 0, 10, 50, 50);
}
void GameEngine::update() {
    if (upKeyPressed and cameraY < WORLD_HEIGHT_IN_UNITS) setCamera(cameraX, cameraY + cameraMovementSpeed * displayHeightInUnits / 1080, displayWidthInUnits, displayHeightInUnits);
    if (downKeyPressed and cameraY > 0) setCamera(cameraX, cameraY - cameraMovementSpeed * displayHeightInUnits / 1080, displayWidthInUnits, displayHeightInUnits);
    if (leftKeyPressed and cameraX > 0) setCamera(cameraX - cameraMovementSpeed * displayWidthInUnits / 1920, cameraY, displayWidthInUnits, displayHeightInUnits);
    if (rightKeyPressed and cameraX < WORLD_WIDTH_IN_UNITS) setCamera(cameraX + cameraMovementSpeed * displayWidthInUnits / 1920, cameraY, displayWidthInUnits, displayHeightInUnits);
    if (zoomInKeyPressed and 1920 / displayWidthInUnits < maxScale) setCamera(cameraX, cameraY,  displayWidthInUnits / cameraRescaleSpeed, displayHeightInUnits / cameraRescaleSpeed);
    if (zoomOutKeyPressed and 1920 / displayWidthInUnits > minScale) setCamera(cameraX, cameraY,  displayWidthInUnits * cameraRescaleSpeed, displayHeightInUnits * cameraRescaleSpeed);
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

