#include "../include/UIGraphicEngine.h"

void UIGraphicEngine::draw() {
    al_draw_filled_rectangle(10, 10, 100, 100, al_map_rgb(255, 255, 255));
    al_draw_filled_rectangle(displayWidth - 110, displayHeight - 110, displayWidth - 10, displayHeight - 10, al_map_rgb(255, 255, 255));
}

void UIGraphicEngine::init(int displayWidth, int displayHeight) {
    this->displayWidth = displayWidth;
    this->displayHeight = displayHeight;
}