//
// Created by Mark David on 26/03/2019.
//

#ifndef TETRISVS_BOARD_H
#define TETRISVS_BOARD_H

#include "shape.h"

class Board {
public:
    static const int Width = 10;
    static const int Height = 24;

    Board();

    bool IsUpdated();

    bool IsValidPosition(const Shape &shape) const;

    char GetSymbolAt(int x, int y) const;

    void Place(const Shape &shape);

    void Cascade();

    int Clear();
private:

    char Get(int x, int y) const;

    void Put(int x, int y, char s);

    int Coordinate(int x, int y) const;

    bool IsClear(int row) const;

    bool IsEmpty(int row) const;

    void ClearRow(int row);

    void CascadeSymbols(int row, int offset);

    bool updated = false;

    char board[Width * Height]{};
};


#endif //TETRISVS_BOARD_H
