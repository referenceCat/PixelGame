#include "Widget.h"

void Widget::onClick(std::function<void()> function) {
    this->onClickFunction = function;
}

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

int Widget::clickMouseLeft(double x, double y) {
    for (Widget* subWidget: subWidgets) {
        RectangleDouble subWidgetRect = subWidget->getRectangle();
        subWidgetRect.x += getContentX();
        subWidgetRect.y += getContentY();
        if (subWidget->isVisible() && subWidgetRect.isInside(x, y)) {
            subWidget->clickMouseLeft(x - subWidgetRect.x, y - subWidgetRect.y);
            return 0;
        }
    }
    onClickFunction();
    return 1;
}

int Widget::clickMouseRight(double x, double y) {
    for (Widget* subWidget: subWidgets) {
        RectangleDouble subWidgetRect = subWidget->getRectangle();
        subWidgetRect.x += getContentX();
        subWidgetRect.y += getContentY();
        if (subWidget->isVisible() && subWidgetRect.isInside(x, y)) {
            subWidget->clickMouseRight(x - subWidgetRect.x, y - subWidgetRect.y);
            return 0;
        }
    }
    return 1;
}

int Widget::clickMouseMiddle(double x, double y) {
    for (Widget* subWidget: subWidgets) {
        RectangleDouble subWidgetRect = subWidget->getRectangle();
        subWidgetRect.x += getContentX();
        subWidgetRect.y += getContentY();
        if (subWidget->isVisible() && subWidgetRect.isInside(x, y)) {
            subWidget->clickMouseLeft(x - subWidgetRect.x, y - subWidgetRect.y);
            return 0;
        }
    }
    return 1;
}

int Widget::realiseMouseLeft(double x, double y) {
    for (Widget* subWidget: subWidgets) {
        RectangleDouble subWidgetRect = subWidget->getRectangle();
        subWidgetRect.x += getContentX();
        subWidgetRect.y += getContentY();
        if (subWidget->isVisible() && subWidgetRect.isInside(x, y)) {
            subWidget->realiseMouseLeft(x - subWidgetRect.x, y - subWidgetRect.y);
            return 0;
        }
    }
    return 1;
}

int Widget::realiseMouseRight(double x, double y) {
    for (Widget* subWidget: subWidgets) {
        RectangleDouble subWidgetRect = subWidget->getRectangle();
        subWidgetRect.x += getContentX();
        subWidgetRect.y += getContentY();
        if (subWidget->isVisible() && subWidgetRect.isInside(x, y)) {
            subWidget->realiseMouseRight(x - subWidgetRect.x, y - subWidgetRect.y);
            return 0;
        }
    }
    return 1;
}

int Widget::realiseMouseMiddle(double x, double y) {
    for (Widget* subWidget: subWidgets) {
        RectangleDouble subWidgetRect = subWidget->getRectangle();
        subWidgetRect.x += getContentX();
        subWidgetRect.y += getContentY();
        if (subWidget->isVisible() && subWidgetRect.isInside(x, y)) {
            subWidget->realiseMouseMiddle(x - subWidgetRect.x, y - subWidgetRect.y);
            return 0;
        }
    }
    return 1;
}

int Widget::mouseMove(double x, double y) {
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


