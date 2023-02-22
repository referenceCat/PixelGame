#include "TextInput.h"
#include "../constans.h"

char *TextInput::getText() const {
    return strdup(text);
}

void TextInput::setText(char *text) {
    TextInput::text = text;
    updateBitmap();
}

void TextInput::updateBitmap() {
    int text_len = strlen(text);
    setBitmap(al_create_bitmap(getRectangle().w, getRectangle().h));
    al_set_target_bitmap(getBitmap());
    al_clear_to_color(al_map_rgba(0, 0, 0, 0));
    al_draw_multiline_text(font, al_map_rgb(LIGHT_ORANGE), 0, 0, getRectangle().w, 16, 0, text);
    al_draw_line(text_len*8, 0, text_len * 8, 16, al_map_rgba(LIGHT_ORANGE, active ? 255: 50), 2);
}

TextInput::TextInput() {
    // TODO path
    font = al_load_ttf_font("/Users/digal/CLionProjects/PixelGame/data/ui/clacon2.ttf", 16, 0);
}

int TextInput::getCursor() const {
    return cursor;
}

void TextInput::setCursor(int cursor) {
    int text_len = strlen(text);
    if (cursor > text_len) cursor = text_len;
    TextInput::cursor = cursor;
    updateBitmap();
}

void TextInput::addChar(char c) {
    int text_len = strlen(text);
    char* new_text = new char[text_len];
    for (int i = 0; i < cursor; i++) new_text[i] = text[i];
    new_text[cursor] = c;
    for (int i = cursor + 1; i < text_len + 1; i++) new_text[i] = text[i - 1];
    updateBitmap();
}

void TextInput::onSend(std::function<void(char*)> function) {
    onSendFunction = function;
}

void TextInput::send() {
    onSendFunction(strdup(text));
}

int TextInput::getActive() const {
    return active;
}

void TextInput::setActive(int active) {
    TextInput::active = active;
    updateBitmap();
}
