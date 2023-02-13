#ifndef PIXELGAME_ENVIRONMENT_H
#define PIXELGAME_ENVIRONMENT_H
#include "Hitbox.h"

struct EnvironmentRect {
    int x;
    int y;
    int w;
    int h;
    EnvironmentRect(int x, int y, int w, int h) {
        this->x = x;
        this->y = y;
        this->w = w;
        this->h = h;}
};

class Environment {
private:
    const EnvironmentRect envRects[1] = {EnvironmentRect(1, 1, 1, 1)};
    int envRectsNum = 0;
    int optimizeEnvRects();
public:
    Environment();
    int getSolid(int x, int y);
    void setSolid(int x, int y);
    Hitbox* getEnvHitboxes();
};


#endif //PIXELGAME_ENVIRONMENT_H
