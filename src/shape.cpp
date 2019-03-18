//
// Created by Mark David on 17/03/2019.
//
#include "shape.h"
#include "board.h"

bool Shape::IsValidPosition(Board const *const board) const {
    for (int i = 0; i < shape_size; i++)
        for (int j = 0; j < shape_size; j++) {
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
    pos_x = Clamp(pos_x + dir, 0, 10);
    if (!IsValidPosition(board))
        pos_x = old_pos_x;
}

int Shape::Modulo(int value, int min, int max) {
    if (value < min) return value + max;
    else if (value >= max) return value - max;
    else return value;
}

int Shape::Clamp(int value, int min, int max) {
    if (value < min) return min;
    else if (value >= max) return max;
    else return value;
}

char Shape::GetCharAt(int x, int y) const {
    switch (rotation) {
        case 0:
            return shape[x + y * shape_size];
        case 1:
            return shape[((x + 1) * shape_size) - (y + 1)];
        case 2:
            return shape[((shape_size * shape_size) - 1) - x - y * shape_size];
        case 3:
            return shape[(shape_size * (shape_size - 1)) - (x * shape_size) + y];
        default:
            return ' ';
    }
}

bool Shape::MoveDown(Board *const board) {
    ++pos_y;
    if (!IsValidPosition(board)) {
        --pos_y;
        PlaceShape(board);
        return true;
    }
    return false;
}


void Shape::DropDown(Board *const board) {
    while (!board->current_shape->MoveDown(board));
}

void Shape::PlaceShape(Board *const board) {
    for (int i = 0; i < shape_size; i++)
        for (int j = 0; j < shape_size; j++)
            if (GetCharAt(i, j) != ' ') board->Put(pos_x + i, pos_y + j);
}

Shape::Shape(BG_COLOR color, int shape_size, const char *const shape) :
        color(color), pos_x(5), pos_y(0), shape_size(shape_size), shape(shape) {
}

