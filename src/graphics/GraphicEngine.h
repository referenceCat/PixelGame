#ifndef PIXELGAME_GRAPHICENGINE_H
#define PIXELGAME_GRAPHICENGINE_H

#include <allegro5/allegro.h>
#include <allegro5/allegro_primitives.h>
#include <list>
#include <iterator>
#include "../logic/environment/Chunk.h"
#include "../logic/environment/constans.h"
#include "../graphics/constans.h"
#include "../stuff/Rectangle.h"


class GraphicEngine {
private:
    void operator=(const GraphicEngine&);

private:
    double cameraX = 0, cameraY = 0, displayWidthInUnits = 960, displayHeightInUnits = 540;

    int displayWidth, displayHeight;

    struct Sprite {
        int id;
        ALLEGRO_BITMAP* bitmap;
        Rectangle globalRect;
        double z, priority;


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

    int addSprite(ALLEGRO_BITMAP* bitmap, Rectangle rectangle, double z, double priority);

    void deleteSprite(int id);

    int addRectSprite(Rectangle rectangle, double z, double priority);

    int addImageSprite(Rectangle rectangle, double z, double priority, char *name);

    int addChunkSprite(Chunk& chunk, int chunkX, int chunkY);

    void setCamera(double x, double y, double displayWidthInUnits, double displayHeightInUnits);

    void setCameraX(double cameraX);

    void setCameraY(double cameraY);

    double getDisplayWidthInUnits() const;

    void setDisplayWidthInUnits(double displayWidthInUnits);

    double getDisplayHeightInUnits() const;

    void setDisplayHeightInUnits(double displayHeightInUnits);
};

#endif //PIXELGAME_GRAPHICENGINE_H
