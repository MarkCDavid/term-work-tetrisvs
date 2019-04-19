//
// Created by Mark David on 17/04/2019.
//

#include "neuralscoring.h"

float NeuralScoring::GetScore(Board &board) const {
    auto heights = CalculateHeights(board);
    float value = pAggregate*AggregateHeight(heights)+
            pLines*CompleteLineCount(board)+
            pHoles*HoleCount(board)+
            pBumpiness*Bumpiness(heights);
    return value;
}

int NeuralScoring::CompleteLineCount(Board &board) const {
    int clear = 0;
    for (int row = 0; row < Board::Height; row++)
        clear += IsClear(board, row);
    return clear;
}

int NeuralScoring::HoleCount(Board &board) const {
    int hole_count = 0;
    for (int row = 0; row < Board::Height; row++)
        for (int col = 0; col < 10; col++)
            if (board.GetSymbolAt(col, row) == Symbols::EMPTY)
                hole_count += NonEmptyOnTop(board, row, col);
    return hole_count;
}

int NeuralScoring::AggregateHeight(std::vector<int> &heights) const {
    int aggregateHeight = 0;
    for (auto height: heights)
        aggregateHeight += height;
    return aggregateHeight;
}

int NeuralScoring::Bumpiness(std::vector<int> &heights) const {
    int bumpiness = 0;
    for (int i = 0; i < heights.size() - 1; i++)
        bumpiness += std::abs(heights[i] - heights[i + 1]);
    return bumpiness;
}

bool NeuralScoring::NonEmptyOnTop(Board &board, int row, int col) const {
    for (int i = row; i > 0; i--)
        if (board.GetSymbolAt(col, i) != Symbols::EMPTY)
            return true;
    return false;
}

bool NeuralScoring::IsClear(Board &board, int row) const {
    for (int col = 0; col < 10; col++)
        if (board.GetSymbolAt(col, row) == Symbols::EMPTY)
            return false;
    return true;
}

std::vector<int> NeuralScoring::CalculateHeights(Board &board) const {
    std::vector<int> heights(10);
    for (int col = 0; col < 10; col++)
        for (int row = 0; row < Board::Height; row++)
            if (board.GetSymbolAt(col, row)!=Symbols::EMPTY) {
                heights[col] = Board::Height-row;
                break;
            }
    return heights;
}

