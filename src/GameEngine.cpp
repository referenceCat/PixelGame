#include "../include/GameEngine.h"
void GameEngine::update() {
    updateUI();
    if (!isPaused()) updateGameLogic();
}

void GameEngine::updateUI() {}
void GameEngine::updateGameLogic() {}
int GameEngine::isPaused() {return this->paused;}
void GameEngine::setPaused(int value) {this->paused = value;}

void GameEngine::init(GraphicEngine &graphicEngine, UIGraphicEngine &uiGraphicEngine) {
    this->graphicEngine = graphicEngine;
    this->uiGraphicEngine = uiGraphicEngine;
    this->environment = Environment();

    //graphicEngine.addRectSprite(0, 50, 11, 50, 50);
    //graphicEngine.addRectSprite(50, 50, 11, 50, 50);
    //graphicEngine.addRectSprite(0, 0, 10, 50, 50);
    //graphicEngine.addRectSprite(50, 0, 10, 50, 50);

    graphicEngine.addImageSprite(0, 0, 300, 240, 135, "../data/test_layer_5.png");
    graphicEngine.addImageSprite(0, 0, 150, 240, 135, "../data/test_layer_4.png");
    graphicEngine.addImageSprite(0, 0, 107, 240, 135, "../data/test_layer_3.png");
    graphicEngine.addImageSprite(0, 0, 102, 240, 135, "../data/test_layer_2.png");
    graphicEngine.addImageSprite(0, 0, 100, 240, 135, "../data/test_layer_1.png");

}
