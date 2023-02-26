#ifndef PIXELGAME_BUTTON_H
#define PIXELGAME_BUTTON_H
#include "Widget.h"
#include "allegro5/allegro.h"
#include "allegro5/allegro_primitives.h"
#include "allegro5/allegro_font.h"
#include "allegro5/allegro_ttf.h"
#include "../../../data/ui/colors.h"

class Button: public Widget{
private:
    const char* text = "default text";
    ALLEGRO_FONT* font;

public:
    Button();

    virtual void updateBitmap() override;

    void setText(char *text);

    char *getText() const;
};


#endif //PIXELGAME_BUTTON_H
