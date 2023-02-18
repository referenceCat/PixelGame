#ifndef PIXELGAME_SERVER_H
#define PIXELGAME_SERVER_H
#include "../StaticObject.h"

class Server: public StaticObject {
public:
    virtual char* getImageFile();
};


#endif //PIXELGAME_SERVER_H
