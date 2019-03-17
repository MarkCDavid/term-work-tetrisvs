//
// Created by Mark David on 17/03/2019.
//
#include "shape.h"
#include "board.h"

bool Shape::IsValidPosition(Board const *const board) const {
    for (int i = 0; i < ShapeSize; i++)
        for (int j = 0; j < ShapeSize; j++) {
            char board_char = board->Get(pos_x + i, pos_y + j);
            char shape_char = GetCharAt(i, j);
            if (board_char != ' ' && shape_char != ' ') return false;
        }
    return true;
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

char Shape::GetCharAt(int x, int y) const {
    switch (rotation) {
        case 0:
            return shape[x + y * ShapeSize];
        case 1:
            return shape[((x + 1) * ShapeSize) - (y + 1)];
        case 2:
            return shape[((ShapeSize * ShapeSize) - 1) - x - y * ShapeSize];
        case 3:
            return shape[(ShapeSize * (ShapeSize - 1)) - (x * ShapeSize) + y];
        default:
            return ' ';
    }
}

bool Shape::MoveDown(Board *const board) {
    if (pos_y == Board::Height) {
        PlaceShape(board);
        return true;
    }
    ++pos_y;
    if (!IsValidPosition(board)) {
        --pos_y;
        PlaceShape(board);
        return true;
    }
    return false;
}

void Shape::PlaceShape(Board *const board) {
    for (int i = 0; i < ShapeSize; i++)
        for (int j = 0; j < ShapeSize; j++)
            if (GetCharAt(i, j) != ' ') board->Put(pos_x + i, pos_y + j, repr);
}

Shape::Shape(char repr, int x, int y, const char *const shape) : repr(repr), pos_x(x), pos_y(y), shape(shape) {

}

