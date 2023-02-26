#include "TextInput.h"
#include "../../../data/ui/colors.h"

char *TextInput::getText() const {
    return strdup(text);
}

void TextInput::setText(char *text) {
    printf("\n");
    TextInput::text = text;
    updateBitmap();
}

void TextInput::updateBitmap() {
    int text_len = strlen(text);
    setBitmap(al_create_bitmap(getRectangle().w, getRectangle().h));
    al_set_target_bitmap(getBitmap());
    al_clear_to_color(al_map_rgba(0, 0, 0, 0));
    al_draw_text(font, al_map_rgb(LIGHT_ORANGE), 4, 2, 0, text);
    if (active) al_draw_line(cursor*8 + 4, 0 + 2, cursor * 8 + 4, 16 + 2, al_map_rgba(LIGHT_ORANGE, active ? 255: 50), 2);
    al_draw_rectangle(1, 0, getRectangle().w, getRectangle().h - 1, al_map_rgb(LIGHT_ORANGE), 1);
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
    if (cursor < 0) cursor = 0;
    TextInput::cursor = cursor;
    updateBitmap();
}

void TextInput::addChar(char c) {
    int text_len = strlen(text);
    char* new_text = new char[text_len + 1];
    for (int i = 0; i < cursor; i++) new_text[i] = text[i];
    new_text[cursor] = c;
    for (int i = cursor + 1; i < text_len + 1; i++) new_text[i] = text[i - 1];
    new_text[text_len + 1] = '\0';
    setText(new_text);
    setCursor(getCursor() + 1);
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
    if (!TextInput::active) setCursor(strlen(text));
    TextInput::active = active;
    updateBitmap();
}

void TextInput::deleteChar() {
    if (cursor == 0) return;
    int text_len = strlen(text);
    char* new_text = new char[text_len - 1];
    for (int i = 0; i < cursor - 1; i++) new_text[i] = text[i];
    for (int i = cursor; i < text_len + 1; i++) new_text[i - 1] = text[i];
    new_text[text_len - 1] = '\0';
    setCursor(getCursor() - 1);
    setText(new_text);
}
