#ifndef PIXELGAME_ENVIRONMENT_H
#define PIXELGAME_ENVIRONMENT_H
#include "chunks/Chunk.h"
#include "chunks/ChunkGenerator.h"
#include "static_objects/StaticObject.h"

class Environment {
private:
    Chunk chunks[WORLD_HEIGHT_IN_CHUNKS][WORLD_WIDTH_IN_CHUNKS];
    int generatedChunks[WORLD_HEIGHT_IN_CHUNKS][WORLD_WIDTH_IN_CHUNKS];

    std::list<StaticObject> staticObjects;
    int staticObjectsNewId = 0;


public:
        Chunk& getChunk(int x, int y);
        void generateChunk(int x, int y, ChunkGenerator& chunkGenerator);
        int isChunkGenerated(int x, int y);
        void deleteChunk(int x, int y);
        Environment();
        int addStaticObject(StaticObject staticObject);
        StaticObject getStaticObjectById(int id);
};


#endif //PIXELGAME_ENVIRONMENT_H
