#include "UIEngine.h"

UIEngine::UIEngine(double w, double h):layout(w, h), displayWidth(w), displayHeight(h) {
    layout.updateBitmap();
    layout.setId(0);
    widgets.push_back(&layout);
    for (int i = 0; i < ALLEGRO_KEY_MAX + 1; i++) keyDownFunctions[i] = []{};
    for (int i = 0; i < ALLEGRO_KEY_MAX + 1; i++) keyUpFunctions[i] = []{};
    for (int i = 0; i < 10 + 1; i++) mouseButtonDownFunctions[i] = [](int, int, int){};
    for (int i = 0; i < 10 + 1; i++) mouseButtonUpFunctions[i] = [](int, int, int){};
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
    textInput->onMouseButtonDown([this, textInput](int,int,int){ this->activeInput=textInput; textInput->setActive(1);}, 1);
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
        return;
    }

    if (event.type == ALLEGRO_EVENT_KEY_DOWN) {
        keysDown[event.keyboard.keycode] = 1;
        keyDownFunctions[event.keyboard.keycode]();
    }

    if (event.type == ALLEGRO_EVENT_KEY_UP) {
        keysDown[event.keyboard.keycode] = 0;
        keyUpFunctions[event.keyboard.keycode]();
    }

}

void UIEngine::mouseEvent(ALLEGRO_EVENT event) {
    // TODO
    if (event.type == ALLEGRO_EVENT_MOUSE_AXES) {
        mouseX = event.mouse.x;
        mouseY = event.mouse.y;
        if (layout.mouseMove(mouseX, mouseY)) mouseMoveFunction(mouseX, mouseY);
    } else if (event.type == ALLEGRO_EVENT_MOUSE_BUTTON_DOWN) {
        if (event.mouse.button == 1 && activeInput) {
            printf("unactive");
            activeInput->setActive(0);
            activeInput = NULL;
        }

        if (layout.mouseButtonDown(event.mouse.button, mouseX, mouseY)) {
            mouseButtonDownFunctions[event.mouse.button](event.mouse.button, mouseX, mouseY);
        }
    } else if (event.type == ALLEGRO_EVENT_MOUSE_BUTTON_UP) {
        if (layout.mouseButtonUp(event.mouse.button, mouseX, mouseY)) mouseButtonUpFunctions[event.mouse.button](event.mouse.button, mouseX, mouseY);
    }
}

void UIEngine::onKeyUp(std::function<void()> function, int keycode) {
    keyUpFunctions[keycode] = function;
}

void UIEngine::onKeyDown(std::function<void()> function, int keycode) {
    keyDownFunctions[keycode] = function;
}

int UIEngine::isKeyDown(int keycode) {
    return keysDown[keycode];
}

void UIEngine::onMouseButtonUp(std::function<void(int, int, int)> function, int keycode) {
    mouseButtonUpFunctions[keycode] = function;
}

void UIEngine::onMouseButtonDown(std::function<void(int, int, int)> function, int keycode) {
    mouseButtonUpFunctions[keycode] = function;
}

void UIEngine::onMouseMove(std::function<void(int, int)> function) {
    mouseMoveFunction = function;
}

int UIEngine::isMouseButtonDown(int keycode) {
    return mouseButtonsDown[keycode];
}




