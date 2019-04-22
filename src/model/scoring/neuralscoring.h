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
    NeuralScoring(float pAggregate, float pLines, float pHoles, float pBumpiness);
    float GetScore(Board &board) const override;

private:

    // The source of values for the parameters of these heuristics
    // https://codemyroad.wordpress.com/2013/04/14/tetris-ai-the-near-perfect-player/
    const float pAggregate;
    const float pLines;
    const float pHoles;
    const float pBumpiness;

    int CompleteLineCount(Board &board) const;

    int HoleCount(Board &board) const;

    int AggregateHeight(std::vector<int> &heights) const;

    int Bumpiness(std::vector<int> &heights) const;

    bool NonEmptyOnTop(Board &board, int row, int col) const;

    bool IsClear(Board &board, int row) const;

    std::vector<int> CalculateHeights(Board &board) const;
};


#endif //TETRISVS_NEURALSCORING_H
