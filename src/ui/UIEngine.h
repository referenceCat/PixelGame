#ifndef PIXELGAME_UIENGINE_H
#define PIXELGAME_UIENGINE_H
#include "widgets/Widget.h"
#include <list>
#include <allegro5/allegro.h>
#include <allegro5/allegro_primitives.h>
#include "../../data/ui/colors.h"
#include "widgets/Layout.h"
#include "widgets/Window.h"
#include "widgets/Label.h"
#include "widgets/TextInput.h"
#include "FunctionalKey.h"
#include "algorithm"
#include "widgets/Button.h"

// TODO setGUIScale();

class UIEngine {
private:
    void operator=(const UIEngine&);

private:
    double mouseX, mouseY;
    int displayWidth, displayHeight, GUIScale = 1;
public:
    int getGuiScale() const;

    void setGuiScale(int guiScale);

private:
    std::list<Widget*> widgets;
    void addWidget(Widget* widget, Widget* parent);
    TextInput* activeInput = NULL;

public:
    Layout layout;
    UIEngine(double w, double h);
    void destroyWidget(Widget *widget);
    Widget *getWidgetById(int id);
    Window* addWindow(Widget* parent);
    Label* addLabel(Widget* parent);
    TextInput* addTextInput(Widget* parent);
    Button* addButton(Widget* parent);
private:
    int keysDown[ALLEGRO_KEY_MAX] = {};
    std::function<void()> keyDownFunctions[ALLEGRO_KEY_MAX] = {};
    std::function<void()> keyUpFunctions[ALLEGRO_KEY_MAX] = {};

    int mouseButtonsDown[10] = {};
    std::function<void(int, int, int)> mouseButtonDownFunctions[10] = {};
    std::function<void(int, int, int)> mouseButtonUpFunctions[10] = {};
    std::function<void(int, int)> mouseMoveFunction = [](int, int){};

    int largeCrosshair = 1;

public:
    void keyEvent(ALLEGRO_EVENT event);
    void onKeyUp(std::function<void()>, int);
    void onKeyDown(std::function<void()>, int);
    int isKeyDown(int keycode);
    void mouseEvent(ALLEGRO_EVENT event);
    void onMouseButtonUp(std::function<void(int, int, int)>, int);
    void onMouseButtonDown(std::function<void(int, int, int)>, int);
    void onMouseMove(std::function<void(int, int)>);
    int isMouseButtonDown(int);

    void draw();
    void drawWidget(Widget *widget, int x, int y);
};


#endif //PIXELGAME_UIENGINE_H
