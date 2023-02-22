#include "Label.h"
char *Label::getText() const {
    return strdup(text);
}

void Label::setText(char *text) {
    Label::text = text;
    updateBitmap();
}

void Label::updateBitmap() {
    setBitmap(al_create_bitmap(getRectangle().w, getRectangle().h));
    al_set_target_bitmap(getBitmap());
    al_clear_to_color(al_map_rgba(0, 0, 0, 0));
    al_draw_multiline_text(font, al_map_rgb(LIGHT_ORANGE), 0, 0, getRectangle().w, 16, 0, text);
}

Label::Label() {
    // TODO path
    font = al_load_ttf_font("/Users/digal/CLionProjects/PixelGame/data/ui/clacon2.ttf", 16, 0);
}
