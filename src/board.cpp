//
// Created by Mark David on 17/03/2019.
//

#include "board.h"

Board::Board(int root_x, int root_y): root_x(root_x), root_y(root_y) {
    for (int i = 0; i < Width * Height; i++) {
        board[i] = ' ';
    }
}

char Board::Get(int x, int y) const {
    int index = x + y * Width;
    if (index < 0 || index >= Width * Height || x <= 0 || x > Width) return 'X';
    return board[index];
}

void Board::Put(int x, int y) {
    int index = x + y * Width;
    if (index < 0 || index >= Width * Height) return;
    board[index] = 'P';
}
