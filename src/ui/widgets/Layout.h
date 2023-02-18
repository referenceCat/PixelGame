#ifndef PIXELGAME_LAYOUT_H
#define PIXELGAME_LAYOUT_H
#include "Widget.h"

class Layout: public Widget {
public:
    Layout(int w, int h);
    virtual void updateBitmap();
};


#endif //PIXELGAME_LAYOUT_H
