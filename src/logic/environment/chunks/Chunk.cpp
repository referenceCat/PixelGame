#include "Chunk.h"

Chunk::Chunk() {}

Material Chunk::getMaterial(int x, int y) {
    for (MaterialRect materialRect: materialRects) {
        if (materialRect.rectangle.x <= x && x <=materialRect.rectangle.x + materialRect.rectangle.w && materialRect.rectangle.y <= y && y <=materialRect.rectangle.y + materialRect.rectangle.h) {
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
        for (int i = materialRect.rectangle.y; i < materialRect.rectangle.y + materialRect.rectangle.h; i++)
            for (int j = materialRect.rectangle.x; j < materialRect.rectangle.x + materialRect.rectangle.w; j++)
                materialMapPointer[i][j] = materialRect.material;
}

void Chunk::applyMaterialMap(Material (*materialMap)[128]) {
    // TODO bad algorithm
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
            materialRects.push_back(MaterialRect{RectangleInt{j, i, w, h}, material});
        }
    }
}

void Chunk::clear() {
    materialRects.clear();
}
