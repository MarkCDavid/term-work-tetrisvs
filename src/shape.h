//
// Created by Mark David on 17/03/2019.
//

#ifndef TETRISVS_SHAPE_H
#define TETRISVS_SHAPE_H

#include "../lib/tge/terminal/color.h"

class Board;

class Shape {
private:
    bool IsValidPosition(Board const *const board) const;

    int Modulo(int value, int min, int max);

    int Clamp(int value, int min, int max);

protected:
    char *shape;
    int pos_x;
    int pos_y;
    int rotation = 0;
public:
    Shape() : shape(nullptr), shape_size(0), pos_x(5), pos_y(0), color(BG_COLOR::WHITE) {}

    Shape(BG_COLOR color, int shape_size, char *shape);

    Shape(const Shape &other) : shape(other.shape), shape_size(other.shape_size), pos_x(other.pos_x),
                                pos_y(other.pos_y), color(other.color) {}

    Shape &operator=(const Shape &other) {
        this->shape = other.shape;
        this->shape_size = other.shape_size;
        this->pos_x = other.pos_x;
        this->pos_y = other.pos_y;
        this->color = other.color;
        return *this;
    }

    int shape_size;

    BG_COLOR color;

    int X() const { return pos_x; }

    int Y() const { return pos_y; }

    void Rotate(Board const *const board, int dir);

    void Move(Board const *const board, int dir);

    bool MoveDown(Board *const board);

    void DropDown(Board *const board);

    void PlaceShape(Board *const board);

    char GetCharAt(int x, int y) const;
};


#endif //TETRISVS_SHAPE_H
