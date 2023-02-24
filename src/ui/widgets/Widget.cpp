#include "Widget.h"

const RectangleDouble &Widget::getRectangle() const {
    return (RectangleDouble) rectangle;
}

void Widget::setRectangle(RectangleDouble rectangle) {
    int change = Widget::rectangle.w != ((RectangleInt) rectangle).w || Widget::rectangle.h != ((RectangleInt) rectangle).h;
    Widget::rectangle = (RectangleInt) rectangle;
    if (change) updateBitmap();
}

void Widget::show() {
    visible = 1;
    for (Widget* subWidget: subWidgets) subWidget->show();
}

void Widget::hide() {
    visible = 0;
    for (Widget* subWidget: subWidgets) subWidget->hide();
}

void Widget::addSubWidget(Widget* subWidget) {
    subWidgets.push_back(subWidget);
}

ALLEGRO_BITMAP *Widget::getBitmap() {
    if (!bitmap) updateBitmap();
    return bitmap;
}

void Widget::updateBitmap() {
    // TODO path
    setBitmap(al_load_bitmap("/Users/digal/CLionProjects/PixelGame/data/missing.png"));
}

void Widget::update() {
    updateBitmap();
}

std::list<Widget*> Widget::getSubWidgets() {
    std::list<Widget*> answer;
    for (Widget* subWidget: subWidgets) answer.push_back(subWidget);
    return answer;
}

int Widget::isVisible() {
    return visible;
}

void Widget::setBitmap(ALLEGRO_BITMAP *bitmap) {
    Widget::bitmap = bitmap;
}

int Widget::getId() const {
    return id;
}

void Widget::setId(int id) {
    Widget::id = id;
}

int Widget::getContentX() {
    return 0;
}

int Widget::getContentY() {
    return 0;
}

int Widget::mouseButtonDown(int keycode, int x, int y) {
    for (Widget* subWidget: subWidgets) {
        RectangleDouble subWidgetRect = subWidget->getRectangle();
        subWidgetRect.x += getContentX();
        subWidgetRect.y += getContentY();
        if (subWidget->isVisible() && subWidgetRect.isInside(x, y)) {
            subWidget->mouseButtonDown(keycode, x - subWidgetRect.x - getContentX(), y - subWidgetRect.y - getContentY());
            return 0;
        }
    }
    mouseButtonDownFunctions[keycode](keycode, x, y);
    return 1;
}

int Widget::mouseButtonUp(int keycode, int x, int y) {
    for (Widget* subWidget: subWidgets) {
        RectangleDouble subWidgetRect = subWidget->getRectangle();
        subWidgetRect.x += getContentX();
        subWidgetRect.y += getContentY();
        if (subWidget->isVisible() && subWidgetRect.isInside(x, y)) {
            subWidget->mouseButtonUp(keycode, x - subWidgetRect.x - getContentX(), y - subWidgetRect.y - getContentY());
            return 0;
        }
    }
    mouseButtonUpFunctions[keycode](keycode, x, y);
    return 1;
}

int Widget::mouseMove(int x, int y) {
    for (Widget* subWidget: subWidgets) {
        RectangleDouble subWidgetRect = subWidget->getRectangle();
        subWidgetRect.x += getContentX();
        subWidgetRect.y += getContentY();
        if (subWidget->isVisible() && subWidgetRect.isInside(x, y)) {
            subWidget->mouseMove(x - subWidgetRect.x, y - subWidgetRect.y);
            return 0;
        }
    }
    return 1;
}

void Widget::removeSubWidget(Widget *widget) {
    for (Widget* subWidget: subWidgets) if (subWidget == widget) subWidgets.remove(subWidget); else removeSubWidget(subWidget);
}

Widget::~Widget() {
    al_destroy_bitmap(getBitmap());
}

void Widget::onMouseButtonUp(std::function<void(int, int, int)> function, int keycode) {
    mouseButtonUpFunctions[keycode] = function;
}

void Widget::onMouseButtonDown(std::function<void(int, int, int)> function, int keycode) {
    mouseButtonDownFunctions[keycode] = function;
}

void Widget::onMouseMove(std::function<void(int, int)> function) {
    mouseMoveFunction = function;
}

Widget::Widget() {
    for (int i = 0; i < 10 + 1; i++) mouseButtonDownFunctions[i] = [](int, int, int){};
    for (int i = 0; i < 10 + 1; i++) mouseButtonUpFunctions[i] = [](int, int, int){};
}



