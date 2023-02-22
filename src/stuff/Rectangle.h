#ifndef PIXELGAME_RECTANGLE_H
#define PIXELGAME_RECTANGLE_H

struct RectangleDouble;

struct RectangleInt{
    int x, y, w, h;
    int getCenterX();
    int getCenterY();
    int isInside(const double x, const double y);
    explicit operator RectangleDouble() const;
};

struct RectangleDouble{
    double x, y, w, h;
    double getCenterX();
    double getCenterY();
    int isInside(const double x, const double y);
    explicit operator RectangleInt() const;
};


#endif //PIXELGAME_RECTANGLE_H
