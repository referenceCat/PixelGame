#include "Button.h"

char *Button::getText() const {
    return strdup(text);
}

void Button::setText(char *text) {
    Button::text = text;
    updateBitmap();
}

void Button::updateBitmap() {
    setBitmap(al_create_bitmap(getRectangle().w, getRectangle().h));
    al_set_target_bitmap(getBitmap());
    al_clear_to_color(al_map_rgb(LIGHT_ORANGE));
    al_draw_multiline_text(font, al_map_rgb(DARK_ORANGE), 0, 0, getRectangle().w, getRectangle().h, 0, text);
}

Button::Button() {
    // TODO path
    font = al_load_ttf_font("/Users/digal/CLionProjects/PixelGame/data/ui/clacon2.ttf", 16, 0);
}