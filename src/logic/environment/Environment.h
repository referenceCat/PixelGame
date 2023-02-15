#ifndef PIXELGAME_ENVIRONMENT_H
#define PIXELGAME_ENVIRONMENT_H
#include "Chunk.h"
#include "ChunkGenerator.h"

class Environment {
private:
    const static int wInChunks = 2, hInChunks = 2;
    int generatedChunks[hInChunks][wInChunks];
    Chunk chunks[hInChunks][wInChunks];

public:
        Chunk& getChunk(int x, int y);
        void generateChunk(int x, int y, ChunkGenerator& chunkGenerator);
        int isChunkGenerated(int x, int y);
        void deleteChunk(int x, int y);
        Environment();
};


#endif //PIXELGAME_ENVIRONMENT_H
