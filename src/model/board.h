//
// Created by Mark David on 26/03/2019.
//

#ifndef TETRISVS_BOARD_H
#define TETRISVS_BOARD_H

#include "shape.h"


class Board {
public:
    static const char EMPTY = ' ';
    static const char OOB = 'X';
    static const int Width = 10;
    static const int Height = 24;

    Board();

    bool IsValidPosition(const Shape &shape) const;

    char GetSymbolAt(int x, int y) const;

    int Place(const Shape &shape);

private:
    char Get(int x, int y) const;

    void Put(int x, int y, char s);

    int Clear(const Shape &shape);

    void Cascade(const Shape &shape);

    char board[Width * Height];
};


#endif //TETRISVS_BOARD_H
