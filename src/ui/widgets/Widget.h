#ifndef PIXELGAME_WIDGET_H
#define PIXELGAME_WIDGET_H
#include <functional>

class Widget {
private:
    int id;
    std::function<void()> onClickFunction = []{};
public:
    int getId() const;
    void onClick(std::function<void()>&);
};


#endif //PIXELGAME_WIDGET_H
