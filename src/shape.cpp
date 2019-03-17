//
// Created by Mark David on 17/03/2019.
//

#include "shape.h"

bool Shape::IsValidPosition(Board const *const board) {
    return false;
}

void Shape::Rotate(Board const *const board, int dir) {
    int old_rotation = rotation;
    rotation = Modulo(rotation + dir, 0, 4);
    if (!IsValidPosition(board))
        rotation = old_rotation;
}

void Shape::Move(Board const *const board, int dir) {
    int old_pos_x = pos_x;
    pos_x = Modulo(pos_x + dir, 0, 10);
    if (!IsValidPosition(board))
        pos_x = old_pos_x;
}

int Shape::Modulo(int value, int min, int max) {
    if (value < min) return value + max;
    else if (value > max) return value - max;
    else return value;
}

char Shape::GetCharAt(int x, int y) {
    switch (rotation) {
        case 0:
            return shape[x + y * ShapeSize];
        case 1:
            return shape[((x + 1) * ShapeSize) - (y + 1)];
        case 2:
            return shape[((ShapeSize * ShapeSize) - 1) - x - y * ShapeSize];
        case 3:
            return shape[(ShapeSize * (ShapeSize - 1)) - (x * ShapeSize) + y];
    }
}

