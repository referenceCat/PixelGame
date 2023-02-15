#include "Chunk.h"

Chunk::Chunk() {}

Material Chunk::getMaterial(int x, int y) {
    for (MaterialRect materialRect: materialRects) {
        if (materialRect.x <= x && x <=materialRect.x + materialRect.w && materialRect.y <= y && y <=materialRect.y + materialRect.h) {
            return materialRect.material;
        }
    }
    Material air;
    air.id = 0;
    return air;
}

void Chunk::getMaterialMap(Material (*materialMapPointer)[128]) {
    Material air{0};
    for (int i = 0; i < SIZE; i++) for (int j = 0; j < SIZE; j++) if (i + j <= SIZE) materialMapPointer[i][j] = air;
    for (MaterialRect materialRect: materialRects)
        for (int i = materialRect.y; i < materialRect.y + materialRect.h; i++)
            for (int j = materialRect.x; j < materialRect.x + materialRect.w; j++)
                materialMapPointer[i][j] = materialRect.material;
}

void Chunk::applyMaterialMap(Material (*materialMap)[128]) {
    // todo proto
    materialRects.clear();
    for (int i = 0; i < SIZE; i++) for (int j = 0; j < SIZE; j++) {
            MaterialRect materialRect;
            materialRect.x = j;
            materialRect.y = i;
            materialRect.w = 1;
            materialRect.h = 1;
            materialRect.material = materialMap[i][j];
            materialRects.push_back(materialRect);
        }
}
