#ifndef PIXELGAME_TESTCHUNKGENERATOR_H
#define PIXELGAME_TESTCHUNKGENERATOR_H
#include "ChunkGenerator.h"
#include "Chunk.h"
class TestChunkGenerator: virtual public ChunkGenerator{
private:
    double randomSinFunction(int x);
public:
    virtual void generateChunk(int x, int y, Chunk& chunk);
};


#endif //PIXELGAME_TESTCHUNKGENERATOR_H
