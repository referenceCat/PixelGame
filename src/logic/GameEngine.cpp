#include "GameEngine.h"
GameEngine::GameEngine() {}

void GameEngine::init(GraphicEngine &graphicEngine, UIGraphicEngine &uiGraphicEngine) {
    this->graphicEngine = &graphicEngine;
    this->uiGraphicEngine = &uiGraphicEngine;
    TestChunkGenerator testChunkGenerator = TestChunkGenerator();

    for (int i = 0; i < 2; i++) for (int j = 0; j < 2; j++) {
            environment.generateChunk(j, i, testChunkGenerator);
            graphicEngine.addChunkSprite(environment.getChunk(j, i), j, i);
        }
    //graphicEngine.addRectSprite(0, 50, 11, 50, 50);
    //graphicEngine.addRectSprite(50, 50, 11, 50, 50);
    //graphicEngine.addRectSprite(0, 0, 10, 50, 50);
    //graphicEngine.addRectSprite(50, 0, 10, 50, 50);
}
void GameEngine::update() {
    updateUI();
    if (!isPaused()) updateGameLogic();
}

void GameEngine::updateUI() {}
void GameEngine::updateGameLogic() {}
int GameEngine::isPaused() {return this->paused;}
void GameEngine::setPaused(int value) {this->paused = value;}

