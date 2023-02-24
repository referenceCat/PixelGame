#include "Window.h"

#include <utility>

 void Window::updateBitmap() {
     setBitmap(al_create_bitmap(getRectangle().w, getRectangle().h));
     al_set_target_bitmap(getBitmap());
     al_clear_to_color(al_map_rgb(DARK_ORANGE));
     al_draw_rectangle(0, 0, getRectangle().w, getRectangle().h, al_map_rgb(LIGHT_ORANGE), 2);
     al_draw_rectangle(4, 22, getRectangle().w - 3, getRectangle().h - 4, al_map_rgb(LIGHT_ORANGE), 1);
     if (closeable) {
         al_draw_line(getRectangle().w - 7, 7, getRectangle().w - 15, 15, al_map_rgb(LIGHT_ORANGE), 1);
         al_draw_line(getRectangle().w - 7, 15, getRectangle().w - 15, 7, al_map_rgb(LIGHT_ORANGE), 1);
     } else {
         al_draw_line(getRectangle().w - 7, 7, getRectangle().w - 15, 15, al_map_rgb(100, 50, 10), 1);
         al_draw_line(getRectangle().w - 7, 15, getRectangle().w - 15, 7, al_map_rgb(100, 50, 10), 1);
     }

}

int Window::getMoveable() const {
    return moveable;
}

void Window::setMoveable(int moveable) {
    Window::moveable = moveable;
    updateBitmap();
}

int Window::getCloseable() const {
    return closeable;
}

void Window::setCloseable(int closeable) {
    Window::closeable = closeable;
    updateBitmap();
}

int Window::getContentX() {
    return 8;
}

int Window::getContentY() {
    return 8 + 20;
}

int Window::mouseButtonDown(int keycode, int x, int y) {
    if (!Widget::mouseButtonDown(keycode, x, y)) return 0;
    if (keycode != 1) return 1;
    if (RectangleDouble{getRectangle().w - 16, 6, 10, 10}.isInside(x, y)) {
        hide();
        onCloseFunction();
        return 1;
    } else if (RectangleDouble{0, 0, getRectangle().w, 22}.isInside(x, y)) {
        printf("%f %f\n", x, y);
        mouseMoveClickX = x;
        mouseMoveClickY = y;
        inMovement = 1;
    }
    return 1;
}

int Window::mouseButtonUp(int keycode, int x, int y) {
    if (keycode == 1) inMovement = 0;
    return Widget::mouseButtonUp(keycode, x, y);
}

int Window::mouseMove(int x, int y) {
    if (inMovement) {
        printf("in move");
        RectangleDouble rect = getRectangle();
        printf("%f %f\n", x, y);
        rect.x += x - mouseMoveClickX;
        rect.y += y - mouseMoveClickY;
        printf("%f %f\n", rect.x, rect.y);
        setRectangle(rect);
    }
    return Widget::mouseMove(x, y);
}

void Window::onClose(std::function<void()> function) {
    onCloseFunction = std::move(function);
}


