#ifndef PIXELGAME_WIDGET_H
#define PIXELGAME_WIDGET_H
#include <functional>
#include <list>
#include "../../stuff/Rectangle.h"
#include "allegro5/allegro.h"

class Widget {
private:
    void operator=(const Widget&);
    int id;
public:
    int getId() const;

    void setId(int id);

private:
    std::list<Widget*> subWidgets;

private:
    RectangleInt rectangle{0, 0, 0, 0};
    ALLEGRO_BITMAP* bitmap = NULL;

private:
    int visible = 1;
    int mouseButtonsDown[10] = {};
    std::function<void(int, int, int)> mouseButtonDownFunctions[10] = {};
    std::function<void(int, int, int)> mouseButtonUpFunctions[10] = {};
    std::function<void(int, int)> mouseMoveFunction = [](int, int){};

public:
    Widget();
    const RectangleDouble &getRectangle() const;
    virtual void setRectangle(RectangleDouble rectangle);
    void addSubWidget(Widget* subWidget);
    ALLEGRO_BITMAP* getBitmap();
    void setBitmap(ALLEGRO_BITMAP *bitmap);
    std::list<Widget*> getSubWidgets();
    void removeSubWidget(Widget* widget);

    void show();
    void hide();
    int isVisible();
    void onMouseButtonUp(std::function<void(int, int, int)>, int);
    void onMouseButtonDown(std::function<void(int, int, int)>, int);
    void onMouseMove(std::function<void(int, int)>);
    virtual int mouseButtonDown(int keycode, int x, int y);
    virtual int mouseButtonUp(int keycode, int x, int y);
    virtual int mouseMove(int x, int y);
    virtual void updateBitmap();
    virtual void update();
    virtual int getContentX();
    virtual int getContentY();
    virtual ~Widget();
};


#endif //PIXELGAME_WIDGET_H
