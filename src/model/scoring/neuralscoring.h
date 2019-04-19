//
// Created by Mark David on 17/04/2019.
//

#ifndef TETRISVS_NEURALSCORING_H
#define TETRISVS_NEURALSCORING_H

#include "abstractscoring.h"
#include "../../symbols.h"
#include <vector>
#include <cmath>

class NeuralScoring : public AbstractScoring {
public:
    float GetScore(Board &board) const override;

private:

    // The source of values for the parameters of these heuristics
    // https://codemyroad.wordpress.com/2013/04/14/tetris-ai-the-near-perfect-player/
    const float pAggregate = -0.510066f;
    const float pLines = 0.760666f;
    const float pHoles = -0.356630f;
    const float pBumpiness = -0.184483f;

    int CompleteLineCount(Board &board) const;

    int HoleCount(Board &board) const;

    int AggregateHeight(std::vector<int> &heights) const;

    int Bumpiness(std::vector<int> &heights) const;

    bool NonEmptyOnTop(Board &board, int row, int col) const;

    bool IsClear(Board &board, int row) const;

    std::vector<int> CalculateHeights(Board &board) const;
};


#endif //TETRISVS_NEURALSCORING_H
