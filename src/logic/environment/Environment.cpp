#include "Environment.h"


Chunk& Environment::getChunk(int x, int y) {
    return chunks[y][x];
}

void Environment::generateChunk(int x, int y, ChunkGenerator& chunkGenerator) {
    chunkGenerator.generateChunk(x, y, getChunk(x, y));
    generatedChunks[y][x] = 1;
}

int Environment::isChunkGenerated(int x, int y) {
    return generatedChunks[y][x];
}

void Environment::deleteChunk(int x, int y) {

}

Environment::Environment() {
    for (int i = 0; i < hInChunks; i++) for (int j = 0; j < wInChunks; j++) {
        this->generatedChunks[i][j] = 0;
    }
}
