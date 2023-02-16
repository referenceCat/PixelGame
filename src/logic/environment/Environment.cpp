#include "Environment.h"


Chunk& Environment::getChunk(int x, int y) {
    return chunks[y][x];
}

void Environment::generateChunk(int x, int y, ChunkGenerator& chunkGenerator) {
    chunkGenerator.generateChunk(x, y, getChunk(x, y));
    generatedChunks[y][x] = 1;
}

void Environment::deleteChunk(int x, int y) {
    getChunk(x, y).clear();
}

Environment::Environment() {
    for (int i = 0; i < WORLD_HEIGHT_IN_CHUNKS; i++) for (int j = 0; j < WORLD_WIDTH_IN_CHUNKS; j++) {
        this->generatedChunks[i][j] = 0;
    }
}

int Environment::isChunkGenerated(int x, int y) {
    return generatedChunks[y][x];
}
