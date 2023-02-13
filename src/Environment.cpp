#include "../include/Environment.h"

Hitbox [] Environment::getEnvHitboxes() {
    Hitbox[envRects] hitboxes;
    for (int i = 0; i < envRectsNum; i++) {
        hitboxes[i] = Hitbox(envRects[i].x - 0.5, envRects[i].y - 0.5, envRects[i].w, envRects[i].h);
    }
    return hitboxes;
}

int Environment::setSolid(int x, int y) {
    if (getSolid(x, y)) return 0;
    envRects[envRectsNum] = EnvironmentRect(x, y, 1, 1);
    envRectsNum += 1;
    return 1;
}

int Environment::getSolid(int x, int y) {
    for (int i = 0; i < envRectsNum; i++) if (envRects[i].x <= x and x < envRects[i].x + envRects[i].w and envRects[i].y <= y and y < envRects[i].y + envRects[i].h) return 1;
    return 0;
}

