#ifndef PIXELGAME_GUIENGINE_H
#define PIXELGAME_GUIENGINE_H
#include <allegro5/allegro.h>
#include <allegro5/allegro_primitives.h>

class GUIEngine {
private:
    void operator=(const GUIEngine&);

private:
    int displayWidth, displayHeight;

public:
    void init(int displayWidth, int displayHeight);
    void draw();
};


#endif //PIXELGAME_GUIENGINE_H
