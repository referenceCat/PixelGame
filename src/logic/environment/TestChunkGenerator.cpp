#include "TestChunkGenerator.h"

void TestChunkGenerator::generateChunk(int x, int y, Chunk &chunk) {
    Material materialMap[Chunk::SIZE][Chunk::SIZE];
    Material air{0};
    Material stone{1};
    for (int i = 0; i < Chunk::SIZE; i++) for (int j = 0; j < Chunk::SIZE; j++) {
            materialMap[i][j] = (i < 100 && j < 100 && i >= 28 && j >= 28) ? stone : air;
    }
    chunk.applyMaterialMap(materialMap);
}
