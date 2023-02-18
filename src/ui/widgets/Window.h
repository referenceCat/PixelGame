#ifndef PIXELGAME_WINDOW_H
#define PIXELGAME_WINDOW_H
#include "Widget.h"
#include "../constans.h"
#include "allegro5/allegro_primitives.h"

class Window: public Widget{
public:
    virtual void updateBitmap() override;
};


#endif //PIXELGAME_WINDOW_H
