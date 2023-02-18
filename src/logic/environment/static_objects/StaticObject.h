#ifndef PIXELGAME_STATICOBJECT_H
#define PIXELGAME_STATICOBJECT_H

#include "../../../stuff/Rectangle.h"

class StaticObject {
private:
    RectangleInt rectangle;
    int id = -1, spriteId, needToBeDestroyed = 0;
public:
    int getId() const;

    void setId(int id);

public:
    int getSpriteId() const;
    void setSpriteId(int spriteId);
    const RectangleInt &getRectangle() const;
    void setRectangle(const RectangleInt &rectangle);
    virtual char* getImageFile();
};


#endif //PIXELGAME_STATICOBJECT_H
