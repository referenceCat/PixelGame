#include "TestChunkGenerator.h"

void TestChunkGenerator::generateChunk(int x, int y, Chunk &chunk) {
    Material materialMap[CHUNK_SIZE][CHUNK_SIZE];
    Material air{0};
    Material chunkMain{1};
    Material chunkBorder{2};
    if (y > WORLD_HEIGHT_IN_CHUNKS / 2) for (int i = 0; i < CHUNK_SIZE; i++) for (int j = 0; j < CHUNK_SIZE; j++) {materialMap[i][j] = air;}
    else for (int i = 0; i < CHUNK_SIZE; i++) for (int j = 0; j < CHUNK_SIZE; j++) {
            materialMap[i][j] = (i < 127 && j < 127 && i >= 1 && j >= 1) ? chunkMain : chunkBorder;
    }
    chunk.applyMaterialMap(materialMap);
}
