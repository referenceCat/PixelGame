#include "Layout.h"

Layout::Layout(int w, int h) {
    setRectangle(RectangleInt{0,0, w, h});
}

void Layout::updateBitmap() {
    setBitmap(al_create_bitmap(1, 1));
    al_set_target_bitmap(getBitmap());
    al_clear_to_color(al_map_rgba(0, 0, 0, 0));
}
