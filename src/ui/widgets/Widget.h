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
    std::function<void()> onClickFunction = []{};

public:
    void onClick(std::function<void()>);
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
    virtual int clickMouseLeft(double x, double y);
    virtual int clickMouseRight(double x, double y);
    virtual int clickMouseMiddle(double x, double y);
    virtual int realiseMouseLeft(double x, double y);
    virtual int realiseMouseRight(double x, double y);
    virtual int realiseMouseMiddle(double x, double y);
    virtual int mouseMove(double x, double y);
    virtual void updateBitmap();
    virtual void update();
    virtual int getContentX();
    virtual int getContentY();
    virtual ~Widget();

};


#endif //PIXELGAME_WIDGET_H
