#ifndef PIXELGAME_UIENGINE_H
#define PIXELGAME_UIENGINE_H
#include "widgets/Widget.h"
#include <list>
#include <allegro5/allegro.h>
class UIEngine {
private:
    double mouseX, mouseY;
    int displayWidth, displayHeight;
    int upPressed = 0,
            downPressed = 0,
            leftPressed = 0,
            rightPressed = 0,
            mouseLeftPressed = 0,
            mouseRightPressed = 0,
            mouseMiddlePressed = 0,
            zoomOutPressed = 0,
            zoomInPressed = 0;
public:
    UIEngine(double w, double h);
    int isUpPressed() const;

    int isDownPressed() const;

    int isLeftPressed() const;

    int isRightPressed() const;

    int isMouseLeftPressed() const;

    int isMouseRightPressed() const;

    int isMouseMiddlePressed() const;

    int isZoomOutPressed() const;

    int isZoomInPressed() const;

private:
    std::list<Widget> widgets;
    std::function<void()> onUpClickFunction = []{},
    onDownClickFunction = []{},
    onLeftClickFunction = []{},
    onRightClickFunction = []{},
    onZoomInClickFunction = []{},
    onZoomOutClickFunction = []{},
    onMouseLeftClickFunction = []{},
    onMouseRightClickFunction = []{},
    onMouseMiddleClickFunction = []{};
    std::function<void(double, double)> onMouseMoveFunction = [](int x, int y){};

public:
    void keyCLick(int keyId);
    void keyRealise(int keyId);
    void mouseMove(int x, int y);
    void mouseClick(int mouseKeyId);
    void mouseRealise(int mouseKeyId);
    void onUpClick(std::function<void()>&);
    void onDownClick(std::function<void()>&);
    void onLeftClick(std::function<void()>&);
    void onRightClick(std::function<void()>&);
    void onZoomInClick(std::function<void()>&);
    void onZoomOutClick(std::function<void()>&);
    void onMouseLeftClick(std::function<void()>&);
    void onMouseRightClick(std::function<void()>&);
    void onMouseMiddleClick(std::function<void()>&);
    void onMouseMove(std::function<void(int, int)>&);
    void draw();


};


#endif //PIXELGAME_UIENGINE_H
