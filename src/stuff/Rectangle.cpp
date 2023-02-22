#include "Rectangle.h"

double RectangleDouble::getCenterX() {
    return x + w / 2;
}

double RectangleDouble::getCenterY() {
    return y + h / 2;
}

RectangleDouble::operator RectangleInt() const {
    return RectangleInt{(int) x, (int) y, (int) w, (int) h};
}

int RectangleInt::getCenterX() {
    return x + w / 2;
}

int RectangleInt::getCenterY() {
    return y + h / 2;
}

RectangleInt::operator RectangleDouble() const {
    return RectangleDouble{(double) x, (double) y, (double) w, (double) h};
}

int RectangleInt::isInside(const double x, const double y) {
    return (this->x < x && x < this->x + this->w && this->y < y && y < this->y + this->h);
}

int RectangleDouble::isInside(const double x, const double y) {
    return (this->x < x && x < this->x + this->w && this->y < y && y < this->y + this->h);
}

