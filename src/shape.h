//
// Created by Mark David on 17/03/2019.
//

#ifndef TETRISVS_SHAPE_H
#define TETRISVS_SHAPE_H

#include "board.h"

class Shape {
private:
    bool IsValidPosition(Board const *const board);

    int Modulo(int value, int min, int max);

protected:
    const char *const shape;
    int pos_x;
    int pos_y;
    int rotation;
public:

    static constexpr int ShapeSize = 5;

    virtual void Draw() = 0;

    void Rotate(Board const *const board, int dir);

    void Move(Board const *const board, int dir);

    char GetCharAt(int x, int y);
};


#endif //TETRISVS_SHAPE_H
