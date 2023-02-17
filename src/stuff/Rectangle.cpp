#include "Rectangle.h"

double RectangleDouble::getCenterX() {
    return x + w / 2;
}

double RectangleDouble::getCenterY() {
    return y + h / 2;
}

int RectangleInt::getCenterX() {
    return x + w / 2;
}

int RectangleInt::getCenterY() {
    return y + h / 2;
}