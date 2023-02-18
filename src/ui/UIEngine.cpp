#include "UIEngine.h"

UIEngine::UIEngine(double w, double h) {
    displayWidth = w, displayHeight = h;
}

void UIEngine::keyCLick(int keyId) {
    switch (keyId) {
        case ALLEGRO_KEY_W:
            upPressed = 1;
            onUpClickFunction();
            break;
        case ALLEGRO_KEY_S:
            downPressed = 1;
            onDownClickFunction();
            break;
        case ALLEGRO_KEY_A:
            leftPressed = 1;
            onLeftClickFunction();
            break;
        case ALLEGRO_KEY_D:
            rightPressed = 1;
            onRightClickFunction();
            break;
        case ALLEGRO_KEY_EQUALS:
            zoomInPressed = 1;
            onZoomInClickFunction();
            break;
        case ALLEGRO_KEY_MINUS:
            zoomOutPressed = 1;
            onZoomOutClickFunction();
            break;
    }
}

void UIEngine::keyRealise(int keyId) {
    switch (keyId) {
        case ALLEGRO_KEY_W:
            upPressed = 0;
            break;
        case ALLEGRO_KEY_S:
            downPressed = 0;
            break;
        case ALLEGRO_KEY_A:
            leftPressed = 0;
            break;
        case ALLEGRO_KEY_D:
            rightPressed = 0;
            break;
        case ALLEGRO_KEY_EQUALS:
            zoomInPressed = 0;
            break;
        case ALLEGRO_KEY_MINUS:
            zoomOutPressed = 0;
            break;
    }
}

void UIEngine::mouseMove(int x, int y) {

}

void UIEngine::mouseClick(int mouseKeyId) {
    switch (mouseKeyId) {
        case 1:
            mouseLeftPressed = 1;
            onMouseLeftClickFunction();
            break;
        case 2:
            mouseMiddlePressed = 1;
            onMouseMiddleClickFunction();
            break;
        case 3:
            mouseRightPressed = 1;
            onMouseRightClickFunction();
            break;
    }
}

void UIEngine::mouseRealise(int mouseKeyId) {
    switch (mouseKeyId) {
        case 1:
            mouseLeftPressed = 0;
            break;
        case 2:
            mouseMiddlePressed = 0;
            break;
        case 3:
            mouseRightPressed = 0;
            break;
    }
}

void UIEngine::onUpClick(std::function<void()> &function) {
    this->onUpClickFunction = function;
}

void UIEngine::onDownClick(std::function<void()> &function) {
    this->onDownClickFunction = function;
}

void UIEngine::onLeftClick(std::function<void()> &function) {
    this->onLeftClickFunction = function;
}

void UIEngine::onRightClick(std::function<void()> &function) {
    this->onRightClickFunction = function;
}

void UIEngine::onZoomInClick(std::function<void()> &function) {
    this->onZoomInClickFunction = function;
}

void UIEngine::onZoomOutClick(std::function<void()> &function) {
    this->onZoomOutClickFunction = function;
}

void UIEngine::onMouseLeftClick(std::function<void()> &function) {
    this->onMouseLeftClickFunction = function;
}

void UIEngine::onMouseRightClick(std::function<void()> &function) {
    this->onMouseRightClickFunction = function;
}

void UIEngine::onMouseMiddleClick(std::function<void()> &function) {
    this->onMouseMiddleClickFunction = function;
}

void UIEngine::onMouseMove(std::function<void(int, int)> &function) {
    this->onMouseMoveFunction = function;
}

int UIEngine::isUpPressed() const {
    return upPressed;
}
int UIEngine::isDownPressed() const {
    return downPressed;
}
int UIEngine::isLeftPressed() const {
    return leftPressed;
}
int UIEngine::isRightPressed() const {
    return rightPressed;
}
int UIEngine::isMouseLeftPressed() const {
    return mouseLeftPressed;
}
int UIEngine::isMouseRightPressed() const {
    return mouseRightPressed;
}
int UIEngine::isMouseMiddlePressed() const {
    return mouseMiddlePressed;
}
int UIEngine::isZoomOutPressed() const {
    return zoomOutPressed;
}
int UIEngine::isZoomInPressed() const {
    return zoomInPressed;
}

void UIEngine::draw() {

}
