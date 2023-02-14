#include "Environment.h"

Hitbox * Environment::getEnvHitboxes() {
    Hitbox hitboxes [envRectsNum];
    for (int i = 0; i < envRectsNum; i++) {
        struct Hitbox hitbox;
        hitbox.x = envRects[i].x - 0.5;
        hitbox.y = envRects[i].y - 0.5;
        hitbox.w = envRects[i].w;
        hitbox.h = envRects[i].h;
    }
    return hitboxes;
}

void Environment::setSolid(int x, int y) {
    if (!getSolid(x, y)) {
        EnvironmentRect rect;
        rect.x = x;
        rect.y = y;
        rect.w = 1;
        rect.h = 1;
        envRects[envRectsNum] = rect;
        envRectsNum += 1;
    }

}

int Environment::getSolid(int x, int y) {
    for (int i = 0; i < envRectsNum; i++) if (envRects[i].x <= x and x < envRects[i].x + envRects[i].w and envRects[i].y <= y and y < envRects[i].y + envRects[i].h) return 1;
    return 0;
}

