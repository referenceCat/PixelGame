#ifndef PIXELGAME_UIENGINE_H
#define PIXELGAME_UIENGINE_H
#include "widgets/Widget.h"
#include <list>
#include <allegro5/allegro.h>
#include <allegro5/allegro_primitives.h>
#include "constans.h"
#include "widgets/Layout.h"
#include "widgets/Window.h"
#include "widgets/Label.h"
#include "widgets/TextInput.h"

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
private:
    int upPressed = 0,
            downPressed = 0,
            leftPressed = 0,
            rightPressed = 0,
            mouseLeftPressed = 0,
            mouseRightPressed = 0,
            mouseMiddlePressed = 0,
            zoomOutPressed = 0,
            zoomInPressed = 0;

    int largeCrosshair = 1;
    std::function<void()> onUpClickFunction = []{},
    onDownClickFunction = []{},
    onLeftClickFunction = []{},
    onRightClickFunction = []{},
    onZoomInClickFunction = []{},
    onZoomOutClickFunction = []{};
    std::function<void(double, double)> onMouseMoveFunction = [](int x, int y){},
    onMouseLeftClickFunction = [](int x, int y){},
    onMouseRightClickFunction = [](int x, int y){},
    onMouseMiddleClickFunction = [](int x, int y){};

public:
    void keyCLick(int keyId);
    void keyRealise(int keyId);
    void mouseMove(int x, int y);
    void mouseClick(int mouseKeyId);
    void mouseRealise(int mouseKeyId);
    void onUpClick(std::function<void()>);
    void onDownClick(std::function<void()>);
    void onLeftClick(std::function<void()>);
    void onRightClick(std::function<void()>);
    void onZoomInClick(std::function<void()>);
    void onZoomOutClick(std::function<void()>);
    void onMouseLeftClick(std::function<void(int, int)>);
    void onMouseRightClick(std::function<void(int, int)>);
    void onMouseMiddleClick(std::function<void(int, int)>);
    void onMouseMove(std::function<void(int, int)>);
    int isUpPressed() const;
    int isDownPressed() const;
    int isLeftPressed() const;
    int isRightPressed() const;
    int isMouseLeftPressed() const;
    int isMouseRightPressed() const;
    int isMouseMiddlePressed() const;
    int isZoomOutPressed() const;
    int isZoomInPressed() const;
    void draw();
    void drawWidget(Widget *widget, int x, int y);
};


#endif //PIXELGAME_UIENGINE_H
