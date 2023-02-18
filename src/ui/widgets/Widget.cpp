#include "Widget.h"

int Widget::getId() const {
    return id;
}

void Widget::onClick(std::function<void()>& function) {
    this->onClickFunction = function;
}
