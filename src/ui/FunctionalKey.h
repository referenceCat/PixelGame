#ifndef PIXELGAME_FUNCTIONALKEY_H
#define PIXELGAME_FUNCTIONALKEY_H
#include "functional"
#include "allegro5/allegro.h"

struct FunctionalKey {
    int down = 0;
    const char* name;
    int keycode;
    std::function<void()> clickFunction = []{}, realiseFunction = []{};

    FunctionalKey(const char *name, int keycode): name(name), keycode(keycode) {};

    static FunctionalKey MOVE_UP;
    static FunctionalKey MOVE_DOWN;
    static FunctionalKey MOVE_LEFT;
    static FunctionalKey MOVE_RIGHT;
    static FunctionalKey ZOOM_IN;
    static FunctionalKey ZOOM_OUT;

    static FunctionalKey allKeys[6];

private:
    void operator=(const FunctionalKey&) = delete;
};


#endif //PIXELGAME_FUNCTIONALKEY_H

