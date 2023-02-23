#ifndef PIXELGAME_TEXTINPUT_H
#define PIXELGAME_TEXTINPUT_H
#include "Widget.h"
#include "allegro5/allegro_font.h"
#include "allegro5/allegro_ttf.h"
#include "string.h"
#include "allegro5/allegro_primitives.h"
class TextInput: public Widget {
private:
    const char* text = "default text";
    ALLEGRO_FONT* font;
    int cursor = 0;
    std::function<void(char*)> onSendFunction = [](char*){};
    int active = 0;
public:
    int getActive() const;

    void setActive(int active);

public:
    int getCursor() const;

    void setCursor(int cursor);

public:
    TextInput();

    char* getText() const;

    void setText(char *text);

    void updateBitmap() override;

    void addChar(char c);

    void deleteChar();

    void onSend(std::function<void(char*)>);

    void send();
};


#endif
