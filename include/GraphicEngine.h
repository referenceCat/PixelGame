#ifndef PIXELGAME_GRAPHICENGINE_H
#define PIXELGAME_GRAPHICENGINE_H

#include <allegro5/allegro.h>

class GraphicEngine {
private:
    int cameraX = 0, cameraY = 0;
public:
    void draw();

};

#endif //PIXELGAME_GRAPHICENGINE_H
