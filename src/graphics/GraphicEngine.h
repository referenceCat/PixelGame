#ifndef PIXELGAME_GRAPHICENGINE_H
#define PIXELGAME_GRAPHICENGINE_H

#include <allegro5/allegro.h>
#include <allegro5/allegro_primitives.h>
#include <list>
#include <iterator>
#include "../logic/environment/Chunk.h"
#include "../logic/environment/constans.h"


class GraphicEngine {
private:
    void operator=(const GraphicEngine&);

private:
    double MAIN_LAYER_Z = 100, parallax_x = 0.5, parallax_y = 0.1;
    double cameraX = WORLD_WIDTH_IN_UNITS / 2, cameraY = WORLD_HEIGHT_IN_UNITS / 2, pixelsToUnitRatio = 2;
    int displayWidth, displayHeight;

    struct Sprite {
        int id;
        ALLEGRO_BITMAP* bitmap;
        double x, y, z, w, h, priority;
    };

    int new_id = 0;
    std::list<Sprite> sprites;

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

    int addSprite(ALLEGRO_BITMAP* bitmap, double x, double y, double z, double w, double h, double priority);

    void deleteSprite(int id);

    int addRectSprite(double x, double y, double z, double w, double h, double priority);

    int addImageSprite(double x, double y, double z, double w, double h, double priority, char *name);

    int addChunkSprite(Chunk& chunk, int chunkX, int chunkY);
};

#endif //PIXELGAME_GRAPHICENGINE_H
