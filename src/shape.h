//
// Created by Mark David on 17/03/2019.
//

#ifndef TETRISVS_SHAPE_H
#define TETRISVS_SHAPE_H

class Board;

class Shape {
private:
    bool IsValidPosition(Board const *const board) const;

    int Modulo(int value, int min, int max);

protected:
    const char *const shape;
    const char repr;
    int pos_x;
    int pos_y;
    int rotation;
public:

    static constexpr int ShapeSize = 5;

    void Rotate(Board const *const board, int dir);

    void Move(Board const *const board, int dir);

    void MoveDown(Board *const board);

    void PlaceShape(Board *const board);

    char GetCharAt(int x, int y) const;
};


#endif //TETRISVS_SHAPE_H
