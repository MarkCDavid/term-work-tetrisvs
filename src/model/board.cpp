//
// Created by Mark David on 26/03/2019.
//

#include "board.h"
#include "../symbols.h"

Board::Board() {
    for (char &i : board)
        i = Symbols::EMPTY;
}

bool Board::IsValidPosition(const Shape &shape) const {
    for (int row = 0; row < shape.Size(); row++)
        for (int col = 0; col < shape.Size(); col++) {
            char b_char = GetSymbolAt(shape.X() + row, shape.Y() + col);
            char s_char = shape.GetSymbolAt(row, col);
            if (s_char != Symbols::EMPTY && b_char != Symbols::EMPTY) return false;
        }
    return true;
}



int Board::Place(const Shape &shape) {
    for (int row = 0; row < shape.Size(); row++)
        for (int col = 0; col < shape.Size(); col++) {
            char s_char = shape.GetSymbolAt(row, col);
            if (s_char != Symbols::EMPTY)
                Put(shape.X() + row, shape.Y() + col, shape.GetSymbolAt(row, col));
        }
    int cleared = Clear(shape);
    if (cleared > 0) Cascade(shape);
    return cleared;
}



int Board::Clear(const Shape &shape) {
    int cleared = 0;
    for (int row = shape.Y(); row < shape.Y() + shape.Size() && row < Height; row++) {
        bool clear = true;
        for (int col = 0; col < 10; col++)
            if (GetSymbolAt(col, row) == Symbols::EMPTY) {
                clear = false;
                break;
            }
        if (clear) {
            for (int col = 0; col < 10; col++) Put(col, row, Symbols::EMPTY);
            cleared++;
        }
    }
    return cleared;
}

void Board::Cascade(const Shape &shape) {
    for (int row = Height - 1; row > 0; row--) {
        bool empty = true;
        for (int col = 0; col < 10; col++)
            if (GetSymbolAt(col, row) != Symbols::EMPTY) {
                empty = false;
                break;
            }
        if (empty) {
            int next_row = row;
            bool next_row_empty = true;
            while (next_row_empty) {
                next_row--;
                for (int col = 0; col < 10; col++)
                    if (GetSymbolAt(col, next_row) != Symbols::EMPTY)
                        next_row_empty = false;

            }
            for (int offset = 0; next_row - offset > 0; offset++) {
                for (int col = 0; col < 10; col++) {
                    Put(col, row - offset, GetSymbolAt(col, next_row - offset));
                    Put(col, next_row - offset, ' ');
                }
            }
        }
    }
}

int Board::Coordinate(int x, int y) const {
    return x + y * Width;
}

char Board::Get(int x, int y) const {
    return board[Coordinate(x, y)];
}

void Board::Put(int x, int y, char s) {
    board[Coordinate(x, y)] = s;
}

char Board::GetSymbolAt(int x, int y) const {
    if (x < 0 || x >= Width || y >= Height) return Symbols::OOB;
    return Get(x, y);
}