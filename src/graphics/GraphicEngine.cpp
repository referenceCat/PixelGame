#include "GraphicEngine.h"
#include <math.h>
void GraphicEngine::draw() {
    al_set_target_bitmap(al_get_backbuffer(al_get_current_display()));
    al_clear_to_color(al_map_rgb(200, 150, 100));
    // drawRect(200, 200, 150, 150);
    al_hold_bitmap_drawing(true);
    for (Sprite sprite: sprites) drawSprite(sprite);
    al_hold_bitmap_drawing(false);
}

GraphicEngine::GraphicEngine(int displayWidth, int displayHeight) {
    this->displayWidth = displayWidth;
    this->displayHeight = displayHeight;
}


GraphicEngine::Sprite GraphicEngine::getSprite(int id) {
    for (auto iter = sprites.begin(); iter != sprites.end(); iter++) {
        if (iter->id == id) return *iter;
    }
}

// x, y, w, h in game units
int GraphicEngine::addSprite(ALLEGRO_BITMAP *bitmap, RectangleDouble rectangle, double z, double priority) {
    Sprite new_sprite{new_id, bitmap, rectangle, z, priority};
    new_id++;
    for (auto iter = sprites.begin(); iter != sprites.end(); iter++) {
        if (iter->z < z || (iter->z == z && iter->priority >= priority)) {
            sprites.insert(iter, new_sprite);
            return new_id;
        }
    }
    sprites.push_back(new_sprite);
    return new_id;
}

void GraphicEngine::deleteSprite(int id) {
    Sprite sprite = getSprite(id);
    al_destroy_bitmap(sprite.bitmap);
    for (auto iter = sprites.begin(); iter != sprites.end(); iter++) {
        if (iter->id == id) sprites.erase(iter);
    }
}

// x, y, w, h in game units
int GraphicEngine::addRectSprite(RectangleDouble rectangle, double z, double priority) {
    ALLEGRO_BITMAP* bitmap = al_load_bitmap("../data/missing.png");
    return addSprite(bitmap,rectangle, z, priority);
}

// x, y, w, h in game units
int GraphicEngine::addImageSprite(RectangleDouble rectangle, double z, double priority, char* name) {
    ALLEGRO_BITMAP* bitmap = al_load_bitmap(name);
    return addSprite(bitmap,rectangle, z, priority);
}

void GraphicEngine::drawSprite(Sprite sprite) {
    double sx, sy, sw, sh, dx, dy, dw, dh;
    if ((sprite.globalRect.x - cameraX) * pow(MAIN_Z / sprite.z, PARALLAX_COEFFICIENT_X) > displayWidthInUnits / 2 ||
            (sprite.globalRect.x - cameraX) * pow(MAIN_Z / sprite.z, PARALLAX_COEFFICIENT_X) + sprite.globalRect.w < -displayWidthInUnits / 2 ||
            (sprite.globalRect.y - cameraY) * pow(MAIN_Z / sprite.z, PARALLAX_COEFFICIENT_Y) > displayHeightInUnits / 2 ||
            (sprite.globalRect.y - cameraY) * pow(MAIN_Z / sprite.z, PARALLAX_COEFFICIENT_Y) + sprite.globalRect.h < -displayHeightInUnits / 2) return;
    sx = 0;
    sy = 0;
    sw = al_get_bitmap_width(sprite.bitmap);
    sh = al_get_bitmap_height(sprite.bitmap);
    dw = sprite.globalRect.w * displayWidth / displayWidthInUnits;
    dh = sprite.globalRect.h * displayHeight / displayHeightInUnits;
    dx = (sprite.globalRect.x - getCameraX()) * displayWidth / displayWidthInUnits * pow(MAIN_Z / sprite.z, PARALLAX_COEFFICIENT_X) + displayWidth / 2;
    dy = (-sprite.globalRect.y - sprite.globalRect.h + getCameraY()) * displayHeight / displayHeightInUnits * pow(MAIN_Z / sprite.z, PARALLAX_COEFFICIENT_Y) + displayHeight / 2;
    al_draw_scaled_bitmap(sprite.bitmap, sx, sy, sw, sh, dx, dy, dw, dh, 0);
}

int  GraphicEngine::addChunkSprite(Chunk& chunk, int chunkX, int chunkY) {
    ALLEGRO_BITMAP* bitmap = al_create_bitmap(CHUNK_SIZE, CHUNK_SIZE);
    al_set_target_bitmap(bitmap);
    Material materialMap[CHUNK_SIZE][CHUNK_SIZE];
    chunk.getMaterialMap(materialMap);
    for (int i = 0; i < CHUNK_SIZE; i++) for (int j = 0; j < CHUNK_SIZE; j++) {
        // al_put_pixel(j, Chunk::SIZE - 1 - i, al_map_rgb(255 * (chunkX - j), 0, 255 * (chunkY - i)));
        if (materialMap[i][j].id == 1) al_put_pixel(j, CHUNK_SIZE - 1 - i, al_map_rgb(100, 100, 100));
        else if (materialMap[i][j].id == 2) al_put_pixel(j, CHUNK_SIZE - 1 - i, al_map_rgb(200, 0, 0));
    }
    int id = addStaticSprite(bitmap, RectangleDouble{(double) chunkX * CHUNK_SIZE,(double) chunkY * CHUNK_SIZE, CHUNK_SIZE, CHUNK_SIZE}, MAIN_Z, 100);
    chunksId.push_back({id, chunkX, chunkY});
    return id;
}

double GraphicEngine::getCameraX() const {
    return cameraX;
}

void GraphicEngine::setCameraX(double cameraX) {
    GraphicEngine::cameraX = cameraX;
}

double GraphicEngine::getCameraY() const {
    return cameraY;
}

void GraphicEngine::setCameraY(double cameraY) {
    GraphicEngine::cameraY = cameraY;
}

double GraphicEngine::getDisplayWidthInUnits() const {
    return displayWidthInUnits;
}

void GraphicEngine::setDisplayWidthInUnits(double displayWidthInUnits) {
    GraphicEngine::displayWidthInUnits = displayWidthInUnits;
}

double GraphicEngine::getDisplayHeightInUnits() const {
    return displayHeightInUnits;
}

void GraphicEngine::setDisplayHeightInUnits(double displayHeightInUnits) {
    GraphicEngine::displayHeightInUnits = displayHeightInUnits;
}


int GraphicEngine::getDisplayWidth() const {
    return displayWidth;
}

void GraphicEngine::setDisplayWidth(int displayWidth) {
    GraphicEngine::displayWidth = displayWidth;
}

int GraphicEngine::getDisplayHeight() const {
    return displayHeight;
}

void GraphicEngine::setDisplayHeight(int displayHeight) {
    GraphicEngine::displayHeight = displayHeight;
}

void GraphicEngine::setCamera(double x, double y, double displayWidthInUnits, double displayHeightInUnits) {
    setCameraX(x);
    setCameraY(y);
    setDisplayWidthInUnits(displayWidthInUnits);
    setDisplayHeightInUnits(displayHeightInUnits);
}

int GraphicEngine::addStaticSprite(ALLEGRO_BITMAP *bitmap, RectangleDouble rectangle, double z, double priority) {
    // TODO
    return addSprite(bitmap, rectangle, z, priority);
}

int GraphicEngine::getChunkSpriteId(int x, int y) {
    // TODO bad algorithm
    for (auto chunkPair: chunksId) if (chunkPair.x == x && chunkPair.y == y) return chunkPair.id;
}

int GraphicEngine::addStaticObjectSprite(StaticObject& staticObject) {
    int id = addStaticSprite(al_load_bitmap(staticObject.getImageFile()), (RectangleDouble) staticObject.getRectangle(), MAIN_Z, 10);
    staticObject.setSpriteId(id);
    return id;
}
