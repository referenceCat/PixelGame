#include "UIEngine.h"

UIEngine::UIEngine(double w, double h):layout(w, h), displayWidth(w), displayHeight(h) {
    layout.updateBitmap();
    layout.setId(0);
    widgets.push_back(&layout);
}

void UIEngine::keyCLick(int keyId) {
    if (activeInput && keyId == ALLEGRO_KEY_ENTER) activeInput->send();
    else if (activeInput) activeInput->addChar('a');
    else {
        switch (keyId) {
            case ALLEGRO_KEY_W:
                upPressed = 1;
                onUpClickFunction();
                break;
            case ALLEGRO_KEY_S:
                downPressed = 1;
                onDownClickFunction();
                break;
            case ALLEGRO_KEY_A:
                leftPressed = 1;
                onLeftClickFunction();
                break;
            case ALLEGRO_KEY_D:
                rightPressed = 1;
                onRightClickFunction();
                break;
            case ALLEGRO_KEY_EQUALS:
                zoomInPressed = 1;
                onZoomInClickFunction();
                break;
            case ALLEGRO_KEY_MINUS:
                zoomOutPressed = 1;
                onZoomOutClickFunction();
                break;
        }
    }
}

void UIEngine::keyRealise(int keyId) {
    switch (keyId) {
        case ALLEGRO_KEY_W:
            upPressed = 0;
            break;
        case ALLEGRO_KEY_S:
            downPressed = 0;
            break;
        case ALLEGRO_KEY_A:
            leftPressed = 0;
            break;
        case ALLEGRO_KEY_D:
            rightPressed = 0;
            break;
        case ALLEGRO_KEY_EQUALS:
            zoomInPressed = 0;
            break;
        case ALLEGRO_KEY_MINUS:
            zoomOutPressed = 0;
            break;
    }
}

void UIEngine::mouseMove(int x, int y) {
    mouseX = x;
    mouseY = y;
    if (layout.mouseMove(mouseX, mouseY)) onMouseMoveFunction(x, y);
}

void UIEngine::mouseClick(int mouseKeyId) {
    switch (mouseKeyId) {
        case 1:
            mouseLeftPressed = 1;
            if (activeInput) {
                activeInput->setActive(0);
                activeInput = NULL;
            }
            if (layout.clickMouseLeft(mouseX, mouseY)) onMouseLeftClickFunction(mouseX, mouseY);
            break;
        case 2:
            mouseMiddlePressed = 1;
            if (layout.clickMouseMiddle(mouseX, mouseY)) onMouseMiddleClickFunction(mouseX, mouseY);
            break;
        case 3:
            mouseRightPressed = 1;
            if (layout.clickMouseRight(mouseX, mouseY)) onMouseRightClickFunction(mouseX, mouseY);
            break;
    }
}

void UIEngine::mouseRealise(int mouseKeyId) {
    switch (mouseKeyId) {
        case 1:
            mouseLeftPressed = 0;
            layout.realiseMouseLeft(mouseX, mouseY);
            break;
        case 2:
            mouseMiddlePressed = 0;
            layout.realiseMouseMiddle(mouseX, mouseY);
            break;
        case 3:
            mouseRightPressed = 0;
            layout.realiseMouseRight(mouseX, mouseY);
            break;
    }
}

void UIEngine::onUpClick(std::function<void()> function) {
    this->onUpClickFunction = function;
}

void UIEngine::onDownClick(std::function<void()> function) {
    this->onDownClickFunction = function;
}

void UIEngine::onLeftClick(std::function<void()> function) {
    this->onLeftClickFunction = function;
}

void UIEngine::onRightClick(std::function<void()> function) {
    this->onRightClickFunction = function;
}

void UIEngine::onZoomInClick(std::function<void()> function) {
    this->onZoomInClickFunction = function;
}

void UIEngine::onZoomOutClick(std::function<void()> function) {
    this->onZoomOutClickFunction = function;
}

void UIEngine::onMouseLeftClick(std::function<void(int, int)> function) {
    this->onMouseLeftClickFunction = function;
}

void UIEngine::onMouseRightClick(std::function<void(int, int)> function) {
    this->onMouseRightClickFunction = function;
}

void UIEngine::onMouseMiddleClick(std::function<void(int, int)> function) {
    this->onMouseMiddleClickFunction = function;
}

void UIEngine::onMouseMove(std::function<void(int, int)> function) {
    this->onMouseMoveFunction = function;
}

int UIEngine::isUpPressed() const {
    return upPressed;
}
int UIEngine::isDownPressed() const {
    return downPressed;
}
int UIEngine::isLeftPressed() const {
    return leftPressed;
}
int UIEngine::isRightPressed() const {
    return rightPressed;
}
int UIEngine::isMouseLeftPressed() const {
    return mouseLeftPressed;
}
int UIEngine::isMouseRightPressed() const {
    return mouseRightPressed;
}
int UIEngine::isMouseMiddlePressed() const {
    return mouseMiddlePressed;
}
int UIEngine::isZoomOutPressed() const {
    return zoomOutPressed;
}
int UIEngine::isZoomInPressed() const {
    return zoomInPressed;
}

void UIEngine::draw() {
    drawWidget(&layout, 0, 0);
    al_set_target_backbuffer(al_get_current_display());
    if (largeCrosshair) {
        al_draw_line(0, mouseY, displayWidth, mouseY, al_map_rgb(LIGHT_ORANGE), 2);
        al_draw_line(mouseX, 0, mouseX, displayHeight, al_map_rgb(LIGHT_ORANGE), 2);
        // std::cout << mouseX << " " << mouseY << "\n";
    }
}

void UIEngine::drawWidget(Widget* widget, int x, int y) {
    al_set_target_backbuffer(al_get_current_display());
    if (widget->isVisible()) {
        ALLEGRO_BITMAP * bitmap = widget->getBitmap();
        al_draw_scaled_bitmap(bitmap,
                              0,
                              0,
                              al_get_bitmap_width(bitmap),
                              al_get_bitmap_height(bitmap),
                              x * GUIScale + widget->getRectangle().x * GUIScale,
                              y  * GUIScale + widget->getRectangle().y * GUIScale ,
                              widget->getRectangle().w * GUIScale,
                              widget->getRectangle().h * GUIScale,
                              0);
    }
    for (Widget* subWidget: widget->getSubWidgets()) drawWidget(subWidget, (x + widget->getRectangle().x  + widget->getContentX()) * 1, (y + widget->getRectangle().y  + widget->getContentY()) * 1);
}
void UIEngine::addWidget(Widget *widget, Widget* parent) {
    widget->updateBitmap();
    widgets.push_back(widget);
    parent->addSubWidget(widget);
}

Window *UIEngine::addWindow(Widget *parent) {
    auto* window = new Window;
    addWidget(window, parent);
    window->onClose([this, window]{destroyWidget(window);});
    return window;
}

int UIEngine::getGuiScale() const {
    return GUIScale;
}

void UIEngine::setGuiScale(int guiScale) {
    GUIScale = guiScale;
}

//Widget* UIEngine::getWidgetById(int id) {
//    std::list<Widget*> queue;
//    queue.push_back(&layout);
//    for (Widget* widget: queue) {
//        if (widget->getId() == id) {return widget;}
//        for (Widget* subWidget: widget->getSubWidgets()) queue.push_back(subWidget);
//    }
//    return NULL;
//}

Widget* UIEngine::getWidgetById(int id) {
    for (Widget* widget: widgets) if (widget->getId() == id) return widget;
    return NULL;
}

void UIEngine::destroyWidget(Widget *widget) {
    layout.removeSubWidget(widget);
    std::list<Widget*> queue;
    queue.push_back(widget);
    for (Widget* widget: queue) {
        for (Widget* subWidget: widget->getSubWidgets()) queue.push_back(subWidget);
        widgets.remove(widget);
        delete widget;
    }
}

Label *UIEngine::addLabel(Widget *parent) {
    auto* label = new Label;
    addWidget(label, parent);
    return label;
}

TextInput *UIEngine::addTextInput(Widget *parent) {
    auto* textInput = new TextInput;
    addWidget(textInput, parent);
    textInput->onClick([this, textInput]{ this->activeInput=textInput; textInput->setActive(1);});
    return textInput;
}

void UIEngine::keyEvent(ALLEGRO_EVENT event) {
    // TODO
    if (activeInput) {
        if (event.type == ALLEGRO_EVENT_KEY_DOWN) {
            switch (event.keyboard.keycode) {
                case ALLEGRO_KEY_ENTER:
                    activeInput->send();
                    activeInput->setActive(0);
                    activeInput = NULL;
                    break;
                case ALLEGRO_KEY_BACKSPACE:
                    activeInput->deleteChar();
                    break;
                case ALLEGRO_KEY_RIGHT:
                    activeInput->setCursor(activeInput->getCursor()+1);
                    break;
                case ALLEGRO_KEY_LEFT:
                    activeInput->setCursor(activeInput->getCursor()-1);
                    break;
            }
        } else if (event.type == ALLEGRO_EVENT_KEY_CHAR && event.keyboard.unichar < 127 && event.keyboard.unichar != 13 && event.keyboard.unichar != 0) {
            // printf("%i", event.keyboard.unichar);
            activeInput->addChar((char) event.keyboard.unichar);
        }
    }

}

void UIEngine::mouseEvent(ALLEGRO_EVENT event) {
    // TODO
    if (event.type == ALLEGRO_EVENT_MOUSE_BUTTON_DOWN) {
        mouseClick(event.mouse.button);
    } else if (event.type == ALLEGRO_EVENT_MOUSE_AXES) {
        mouseMove(event.mouse.x, event.mouse.y);
    } else if (event.type == ALLEGRO_EVENT_MOUSE_BUTTON_UP) {
        mouseRealise(event.mouse.button);
    }
}




