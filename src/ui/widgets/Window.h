#ifndef PIXELGAME_WINDOW_H
#define PIXELGAME_WINDOW_H
#include "Widget.h"
#include "../constans.h"
#include "allegro5/allegro_primitives.h"

class Window: public Widget{
private:
    int moveable = 0, closeable = 0, inMovement = 0;
    double mouseMoveClickX = 0, mouseMoveClickY = 0;
    std::function<void()> onCloseFunction = []{};
public:
    int getMoveable() const;
    void setMoveable(int moveable);
    int getCloseable() const;
    void setCloseable(int closeable);
    void updateBitmap() override;
    int getContentX() override;
    int getContentY() override;
    int clickMouseLeft(double x, double y) override;
    int realiseMouseLeft(double x, double y) override;
    int mouseMove(double x, double y) override;
    void onClose(std::function<void()>);
};


#endif //PIXELGAME_WINDOW_H
