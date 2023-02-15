#ifndef PIXELGAME_UIGRAPHICENGINE_H
#define PIXELGAME_UIGRAPHICENGINE_H
#include <allegro5/allegro.h>
#include <allegro5/allegro_primitives.h>

class UIGraphicEngine {
private:
    void operator=(const UIGraphicEngine&);

private:
    int displayWidth, displayHeight;

public:
    void init(int displayWidth, int displayHeight);
    void draw();
};


#endif //PIXELGAME_UIGRAPHICENGINE_H
