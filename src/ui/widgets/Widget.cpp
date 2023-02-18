#include "Widget.h"
#include "iostream"

void Widget::onClick(std::function<void()>& function) {
    this->onClickFunction = function;
}

const RectangleDouble &Widget::getRectangle() const {
    return rectangle;
}

void Widget::setRectangle(RectangleDouble rectangle) {
    Widget::rectangle = rectangle;
    updateBitmap();
}

void Widget::show() {
    visible = 1;
    for (Widget* subWidget: subWidgets) subWidget->show();
}

void Widget::hide() {
    visible = 0;
    for (Widget* subWidget: subWidgets) subWidget->hide();
}

void Widget::destroy() {
    for (Widget* subWidget: subWidgets) subWidget->destroy();
    delete this;
}

void Widget::addSubWidget(Widget* subWidget) {
    subWidgets.push_back(subWidget);
}

ALLEGRO_BITMAP *Widget::getBitmap() {
    if (!bitmap) updateBitmap();
    return bitmap;
}

void Widget::updateBitmap() {
    std::cout << "Widget::updateBitmap()";
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


