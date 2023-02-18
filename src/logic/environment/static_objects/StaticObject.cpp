#include "StaticObject.h"

const RectangleInt &StaticObject::getRectangle() const {
    return rectangle;
}

void StaticObject::setRectangle(const RectangleInt &rectangle) {
    StaticObject::rectangle = rectangle;
}

int StaticObject::getSpriteId() const {
    return spriteId;
}

void StaticObject::setSpriteId(int spriteId) {
    StaticObject::spriteId = spriteId;
}

int StaticObject::getId() const {
    return id;
}

void StaticObject::setId(int id) {
    if (StaticObject::id == -1)
    StaticObject::id = id;
}

char *StaticObject::getImageFile() {
    return "../data/missing.png";
}
