//
// Created by Mark David on 19/04/2019.
//

#ifndef TETRISVS_COMPUTERCONTROLLER_H
#define TETRISVS_COMPUTERCONTROLLER_H

#include "../model/scoring/abstractscoring.h"
#include "abstractcontroller.h"
#include <vector>

class ComputerController: public AbstractController {
public:
    ComputerController(AbstractScoring* scoring, bool look_ahead);
    ~ComputerController();
    void Update(Game* game) override;
private:

    std::vector<Shape> GeneratePermutations(Shape shape);
    bool AlreadyScored(Shape* shape);
    void Score(Game* game);
    Board PlaceInBoard(Board board, const Shape& shape);
    void UpdateBestScore(Shape shape, float score);

    bool look_ahead = false;
    float best_score;
    AbstractScoring* scoring;
    Shape best_move;
    Shape* last_scored = nullptr;
};

#endif //TETRISVS_COMPUTERCONTROLLER_H
