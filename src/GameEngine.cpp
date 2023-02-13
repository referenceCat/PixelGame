#include "../include/GameEngine.h"
int GameEngine::update() {
    updateUI();
    if (!isPaused()) updateGameLogic();
    return 1;
}

int GameEngine::updateUI() {return 1}
int GameEngine::updateGameLogic() {return 1}
int GameEngine::isPaused() {return this->paused}
void GameEngine::setPaused(int value) {this->paused = value}

void GameEngine::init() {
    // environment = Environment();
    // testInit()
}
void GameEngine::testInit() {
    for (int i = -20; i < 20; i++) {}
    environment.getSolid(i, 0);
    environment.getSolid(i, -1);
    environment.getSolid(i, -2);
    environment.getSolid(i, -3);
}