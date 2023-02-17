#ifndef PIXELGAME_CHUNK_H
#define PIXELGAME_CHUNK_H
#include "Material.h"
#include <list>
#include "../constans.h"
#include "../../../stuff/Rectangle.h"

class Chunk {
private:
    void operator=(const Chunk&);

private:
    struct MaterialRect {
        RectangleInt rectangle;
        Material material;
    };

    std::list<MaterialRect> materialRects;

public:
    Chunk();
    Material getMaterial(int x, int y);
    void getMaterialMap(Material materialMapPointer[][128]);
    void applyMaterialMap(Material materialMap [CHUNK_SIZE][CHUNK_SIZE]);
    void clear();
};


#endif //PIXELGAME_CHUNK_H
