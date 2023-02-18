#include "Window.h"

#include "iostream"

 void Window::updateBitmap() {
    std::cout << "Window::updateBitmap()";
     setBitmap(al_create_bitmap(getRectangle().w, getRectangle().h));
     al_set_target_bitmap(getBitmap());
     al_clear_to_color(al_map_rgb(DARK_ORANGE));
     al_draw_rectangle(0, 0, getRectangle().w, getRectangle().h, al_map_rgb(DARK_ORANGE), 2);
}
