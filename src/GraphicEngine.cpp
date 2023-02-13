#include "../include/GraphicEngine.h"

void GraphicEngine::draw() {
    al_clear_to_color(al_map_rgb(random()*255, 10, 0));
    al_flip_display();
}