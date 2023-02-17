#ifndef PIXELGAME_ENVIRONMENT_H
#define PIXELGAME_ENVIRONMENT_H
#include "Chunks/Chunk.h"
#include "Chunks/ChunkGenerator.h"

class Environment {private:
    Chunk chunks[WORLD_HEIGHT_IN_CHUNKS][WORLD_WIDTH_IN_CHUNKS];
    int generatedChunks[WORLD_HEIGHT_IN_CHUNKS][WORLD_WIDTH_IN_CHUNKS];

public:
        Chunk& getChunk(int x, int y);
        void generateChunk(int x, int y, ChunkGenerator& chunkGenerator);
        int isChunkGenerated(int x, int y);
        void deleteChunk(int x, int y);
        Environment();
};


#endif //PIXELGAME_ENVIRONMENT_H
