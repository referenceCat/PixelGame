#ifndef PIXELGAME_LABEL_H
#define PIXELGAME_LABEL_H
#include "Widget.h"
#include "cstring"
#include "allegro5/allegro.h"
#include "allegro5/allegro_primitives.h"
#include "allegro5/allegro_font.h"
#include "allegro5/allegro_ttf.h"
#include "../constans.h"

// TODO auto-resizeable rect
class Label: public Widget{
private:
    const char* text = "default text";
    ALLEGRO_FONT* font;
public:
    Label();

    char* getText() const;

    void setText(char *text);

    void updateBitmap() override;





};


#endif //PIXELGAME_LABEL_H
