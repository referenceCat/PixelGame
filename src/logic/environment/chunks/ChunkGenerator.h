#ifndef PIXELGAME_CHUNKGENERATOR_H
#define PIXELGAME_CHUNKGENERATOR_H
#include "Chunk.h"

class ChunkGenerator {
public:
    virtual void generateChunk(int x, int y, Chunk& chunk) {};
};


#endif //PIXELGAME_CHUNKGENERATOR_H
