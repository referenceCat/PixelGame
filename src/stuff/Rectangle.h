#ifndef PIXELGAME_RECTANGLE_H
#define PIXELGAME_RECTANGLE_H


struct RectangleDouble{
    double x, y, w, h;
    double getCenterX();
    double getCenterY();
};

struct RectangleInt{
    int x, y, w, h;
    int getCenterX();
    int getCenterY();
};

#endif //PIXELGAME_RECTANGLE_H
