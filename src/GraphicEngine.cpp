#include "../include/GraphicEngine.h"

void GraphicEngine::draw() {
    al_clear_to_color(al_map_rgb(200, 150, 100));
    // drawRect(200, 200, 150, 150);
    for (int i = 0; i < 100; i++) {
        if (!isSpriteIdEmpty[i]) drawSprite(getSprite(i));
    }
}

void GraphicEngine::init(int displayWidth, int displayHeight) {
    for (int i = 0; i < 100; i++) isSpriteIdEmpty[i] = 1;
    this->displayWidth = displayWidth;
    this->displayHeight = displayHeight;
}

double GraphicEngine::getCameraX() const {
    return cameraX;
}

double GraphicEngine::getCameraY() const {
    return cameraY;
}

void GraphicEngine::moveCamera(double x, double y) {
    this->cameraX = x;
    this->cameraY = y;
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

double GraphicEngine::getPixelsToUnitRatio() const {
    return pixelsToUnitRatio;
}

void GraphicEngine::setPixelsToUnitRatio(double pixelsToUnitRatio) {
    GraphicEngine::pixelsToUnitRatio = pixelsToUnitRatio;
}

void GraphicEngine::drawRect(double x, double y, double w, double h) {
    al_draw_filled_rectangle(x, y, x+w, y+h, al_map_rgb(255, 255, 255));
}


GraphicEngine::Sprite GraphicEngine::getSprite(int id) {
    return sprites[id];
}

int GraphicEngine::addSprite(ALLEGRO_BITMAP *bitmap, double x, double y, double z, double w, double h) {
   for (int i = 0; i < 100; i++) {
            if (isSpriteIdEmpty[i]) {
                isSpriteIdEmpty[i] = 0;
                Sprite sprite = Sprite();
                sprite.bitmap = bitmap;
                sprite.x = x;
                sprite.y = y;
                sprite.z = z;
                sprite.w = w;
                sprite.h = h;
                sprite.id = i;
                sprites[i] = sprite;
                return i;
            }
    }

    return -1;
}

void GraphicEngine::deleteSprite(int id) {
    Sprite sprite = getSprite(id);
    al_destroy_bitmap(sprite.bitmap);
    isSpriteIdEmpty[id] = 1;
}

int GraphicEngine::addRectSprite(double x, double y, double z, double w, double h) {
    ALLEGRO_BITMAP* bitmap = al_load_bitmap("../data/missing.png");
    return addSprite(bitmap, x, y, z, w, h);
}

int GraphicEngine::addImageSprite(double x, double y, double z, double w, double h, char* name) {
    ALLEGRO_BITMAP* bitmap = al_load_bitmap(name);
    return addSprite(bitmap, x, y, z, w, h);
}

void GraphicEngine::drawSprite(Sprite sprite) {
    double sx, sy, sw, sh, dx, dy, dw, dh;
    sx = 0;
    sy = 0;
    sw = al_get_bitmap_width(sprite.bitmap);
    sh = al_get_bitmap_height(sprite.bitmap);
    dw = sprite.w * pixelsToUnitRatio;
    dh = sprite.h * pixelsToUnitRatio;
    dx = (sprite.x - getCameraX() )* pixelsToUnitRatio * MAIN_LAYER_Z / sprite.z * parallax_x - dw / 2 + displayWidth / 2;
    dy = (-sprite.y + getCameraY())* pixelsToUnitRatio * MAIN_LAYER_Z / sprite.z * parallax_y - dh / 2 + displayHeight / 2;
    al_draw_scaled_bitmap(sprite.bitmap, sx, sy, sw, sh, dx, dy, dw, dh, 0);
}
