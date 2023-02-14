#ifndef PIXELGAME_GRAPHICENGINE_H
#define PIXELGAME_GRAPHICENGINE_H

#include <allegro5/allegro.h>
#include <allegro5/allegro_primitives.h>


class GraphicEngine {
private:
    double MAIN_LAYER_Z = 100, parallax_x = 1, parallax_y = 0.5;
    double cameraX = 0, cameraY = 0, pixelsToUnitRatio = 8;
    int displayWidth, displayHeight;

    struct Sprite {
        int id;
        ALLEGRO_BITMAP* bitmap;
        double x, y, z, w, h;
    };

    int isSpriteIdEmpty[100];
    struct Sprite sprites[100];

private:
    Sprite getSprite(int id);

    void drawSprite(Sprite sprite);

public:
    void init(int displayWidth, int displayHeight);

    void draw();

    double getCameraX() const;

    double getCameraY() const;

    void moveCamera(double x, double y);

    int getDisplayWidth() const;

    void setDisplayWidth(int displayWidth);

    int getDisplayHeight() const;

    void setDisplayHeight(int displayHeight);

    double getPixelsToUnitRatio() const;

    void setPixelsToUnitRatio(double pixelsToUnitRatio);

    void drawRect(double x, double y, double w, double h);

    int addSprite(ALLEGRO_BITMAP* bitmap, double x, double y, double z, double w, double h);

    void deleteSprite(int id);

    int addRectSprite(double x, double y, double z, double w, double h);

    int addImageSprite(double x, double y, double z, double w, double h, char *name);
};

#endif //PIXELGAME_GRAPHICENGINE_H
