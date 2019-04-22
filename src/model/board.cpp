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


void Board::Place(const Shape &shape) {
    for (int row = 0; row < shape.Size(); row++)
        for (int col = 0; col < shape.Size(); col++)
            if (shape.GetSymbolAt(row, col) != Symbols::EMPTY)
                Put(shape.X() + row, shape.Y() + col, shape.GetSymbolAt(row, col));
}

int Board::Clear() {
    int cleared = 0;
    for (int row = 0; row < Board::Height; row++)
        for (int col = 0; col < Board::Width; col++)
            if (IsClear(row)) {
                ClearRow(row);
                cleared++;
            }
    return cleared;
}

void Board::Cascade() {
    for (int row = Height - 1; row > 0; row--) {
        int offset = 0;
        if (IsEmpty(row))
            do offset++;
            while (IsEmpty(row - offset));
        if (offset > 0)
            CascadeSymbols(row, offset);
    }
}

int Board::Coordinate(int x, int y) const {
    return x + y * Width;
}

char Board::Get(int x, int y) const {
    return board[Coordinate(x, y)];
}

void Board::Put(int x, int y, char s) {
    updated = true;
    board[Coordinate(x, y)] = s;
}

char Board::GetSymbolAt(int x, int y) const {
    if (x < 0 || x >= Width || y >= Height) return Symbols::OOB;
    return Get(x, y);
}

bool Board::IsClear(int row) const {
    for (int col = 0; col < 10; col++)
        if (GetSymbolAt(col, row) == Symbols::EMPTY)
            return false;
    return true;
}

void Board::ClearRow(int row) {
    for (int col = 0; col < 10; col++)
        Put(col, row, Symbols::EMPTY);
}

bool Board::IsEmpty(int row) const {
    for (int col = 0; col < 10; col++)
        if (GetSymbolAt(col, row) != Symbols::EMPTY)
            return false;
    return true;
}

void Board::CascadeSymbols(int row, int offset) {
    for (int i = 0; i > -(row - offset); i--) {

        int to = row + i;
        int from = row - offset + i;

        for (int col = 0; col < 10; col++) {
            Put(col, to, GetSymbolAt(col, from));
            Put(col, from, Symbols::EMPTY);
        }
    }
}

bool Board::IsUpdated() {
    return updated;
}
void Board::ResetUpdate()
{
    updated = false;
}


