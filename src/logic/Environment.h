#ifndef PIXELGAME_ENVIRONMENT_H
#define PIXELGAME_ENVIRONMENT_H
#include "Hitbox.h"

struct EnvironmentRect {
    int x, y, w, h;
};

class Environment {
private:
    EnvironmentRect envRects[100];
    int envRectsNum = 0;
    int optimizeEnvRects();
public:
    int getSolid(int x, int y);
    void setSolid(int x, int y);
    Hitbox* getEnvHitboxes();
};


#endif //PIXELGAME_ENVIRONMENT_H
