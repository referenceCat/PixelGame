#ifndef PIXELGAME_TESTCHUNKGENERATOR_H
#define PIXELGAME_TESTCHUNKGENERATOR_H
#include "ChunkGenerator.h"
#include "Chunk.h"
class TestChunkGenerator: virtual public ChunkGenerator{
public:
    virtual void generateChunk(int x, int y, Chunk& chunk);
};


#endif //PIXELGAME_TESTCHUNKGENERATOR_H
