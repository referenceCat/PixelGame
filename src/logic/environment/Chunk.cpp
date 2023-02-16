#include "Chunk.h"

Chunk::Chunk() {}

Material Chunk::getMaterial(int x, int y) {
    for (MaterialRect materialRect: materialRects) {
        if (materialRect.x <= x && x <=materialRect.x + materialRect.w && materialRect.y <= y && y <=materialRect.y + materialRect.h) {
            return materialRect.material;
        }
    }
    Material air{0};
    return air;
}

void Chunk::getMaterialMap(Material (*materialMapPointer)[128]) {
    Material air{0};
    for (int i = 0; i < CHUNK_SIZE; i++) for (int j = 0; j < CHUNK_SIZE; j++) materialMapPointer[i][j] = air;
    for (MaterialRect materialRect: materialRects)
        for (int i = materialRect.y; i < materialRect.y + materialRect.h; i++)
            for (int j = materialRect.x; j < materialRect.x + materialRect.w; j++)
                materialMapPointer[i][j] = materialRect.material;
}

void Chunk::applyMaterialMap(Material (*materialMap)[128]) {
    // todo proto
    materialRects.clear();
    //for (int i = 0; i < CHUNK_SIZE; i++) for (int j = 0; j < CHUNK_SIZE; j++) {
    //        MaterialRect materialRect;
    //        materialRect.x = j;
    //        materialRect.y = i;
    //        materialRect.w = 1;
    //        materialRect.h = 1;
    //        materialRect.material = materialMap[i][j];
    //        materialRects.push_back(materialRect);
    //    }

    for (int i = 0; i < CHUNK_SIZE; i++) for (int j = 0; j < CHUNK_SIZE; j++) {
        Material air{0};
        if (materialMap[i][j].id) {
            Material material = materialMap[i][j];
            int w = 0, h = 1;
            int x = j;
            for (; x < CHUNK_SIZE && materialMap[i][x].id == material.id; x++) {
                materialMap[i][x] = air;
                w++;
            }
            x;
            int flag = 1;
            for (int y = i + 1; y < CHUNK_SIZE; y++) {
                for (int x_test = j; x_test < x; x_test++) {
                    if (materialMap[y][x_test].id != material.id) {
                        flag = 0;
                        break;
                    }
                }
                if (!flag) break;
                h++;
                for (int x_clear = j; x_clear < x; x_clear++) {
                    materialMap[y][x_clear] = air;
                }
            }
            materialRects.push_back(MaterialRect{j, i, w, h, material});
        }
    }
}

void Chunk::clear() {
    materialRects.clear();
}
