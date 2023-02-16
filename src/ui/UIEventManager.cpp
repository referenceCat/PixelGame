//
// Created by Yuriy Buyanov on 16/02/2023.
//

#include "UIEventManager.h"


void UIEventManager::keyCLick(int keyId) {
    switch (keyId) {
        case ALLEGRO_KEY_W:
            gameEngine->upButtonClick();
            break;
        case ALLEGRO_KEY_S:
            gameEngine->downButtonClick();
            break;
        case ALLEGRO_KEY_A:
            gameEngine->leftButtonClick();
            break;
        case ALLEGRO_KEY_D:
            gameEngine->rightButtonClick();
            break;
        case ALLEGRO_KEY_EQUALS:
            printf("eq");
            gameEngine->zoomInButtonClick();
            break;
        case ALLEGRO_KEY_MINUS:
            gameEngine->zoomOutButtonClick();
            break;
    }
}

void UIEventManager::keyRealise(int keyId) {
    switch (keyId) {
        case ALLEGRO_KEY_W:
            gameEngine->upButtonRealise();
            break;
        case ALLEGRO_KEY_S:
            gameEngine->downButtonRealise();
            break;
        case ALLEGRO_KEY_A:
            gameEngine->leftButtonRealise();
            break;
        case ALLEGRO_KEY_D:
            gameEngine->rightButtonRealise();
            break;
        case ALLEGRO_KEY_EQUALS:
            gameEngine->zoomInButtonRealise();
            break;
        case ALLEGRO_KEY_MINUS:
            gameEngine->zoomOutButtonRealise();
            break;
    }
}

void UIEventManager::mouseMove(int x, int y) {

}

void UIEventManager::mouseClick(int mouseKeyId) {

}

UIEventManager::UIEventManager(GameEngine &gameEngine) {
    this->gameEngine = &gameEngine;
}
