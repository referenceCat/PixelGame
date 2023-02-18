#ifndef PIXELGAME_GRAPHICENGINE_H
#define PIXELGAME_GRAPHICENGINE_H

#include <allegro5/allegro.h>
#include <allegro5/allegro_primitives.h>
#include <list>
#include <iterator>
#include "../logic/environment/chunks/Chunk.h"
#include "../logic/environment/constans.h"
#include "../graphics/constans.h"
#include "../stuff/Rectangle.h"
#include "../logic/environment/static_objects/StaticObject.h"


class GraphicEngine {
private:
    void operator=(const GraphicEngine&);

private:
    double cameraX = 0, cameraY = 0, displayWidthInUnits = 960, displayHeightInUnits = 540;

    int displayWidth, displayHeight;

    struct Sprite {
        int id;
        ALLEGRO_BITMAP* bitmap;
        RectangleDouble globalRect;
        double z, priority;
    };

    int new_id = 0;
    std::list<Sprite> sprites;

    // TODO
    struct ChunkPair {int id, x, y;};
    std::list<ChunkPair> chunksId;

private:
    Sprite getSprite(int id);

    void drawSprite(Sprite sprite);

public:
    GraphicEngine(int displayWidth, int displayHeight);

    void draw();

    double getCameraX() const;

    double getCameraY() const;

    int getDisplayWidth() const;

    void setDisplayWidth(int displayWidth);

    int getDisplayHeight() const;

    void setDisplayHeight(int displayHeight);

    int addSprite(ALLEGRO_BITMAP* bitmap, RectangleDouble rectangle, double z, double priority);

    int addStaticSprite(ALLEGRO_BITMAP* bitmap, RectangleDouble rectangle, double z, double priority);

    void deleteSprite(int id);

    int addRectSprite(RectangleDouble rectangle, double z, double priority);

    int addImageSprite(RectangleDouble rectangle, double z, double priority, char *name);

    int addChunkSprite(Chunk& chunk, int chunkX, int chunkY);

    void setCamera(double x, double y, double displayWidthInUnits, double displayHeightInUnits);

    void setCameraX(double cameraX);

    void setCameraY(double cameraY);

    double getDisplayWidthInUnits() const;

    void setDisplayWidthInUnits(double displayWidthInUnits);

    double getDisplayHeightInUnits() const;

    void setDisplayHeightInUnits(double displayHeightInUnits);

    int getChunkSpriteId(int x, int y);

    int addStaticObjectSprite(StaticObject& staticObject);
};

#endif //PIXELGAME_GRAPHICENGINE_H
