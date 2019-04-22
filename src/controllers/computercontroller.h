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
    ComputerController(float click_speed, AbstractScoring* scoring, bool look_ahead);
    ~ComputerController();
    void Update(Game* game) override;
private:

    std::vector<Shape> GeneratePermutations(Shape shape);
    bool AlreadyScored(Shape shape);
    bool ClickTimeSurpassed();
    void Score(Game* game);
    Board PlaceInBoard(Board board, Shape& shape);
    void UpdateBestScore(Shape shape, float score);


    bool look_ahead = false;
    float best_score;
    AbstractScoring* scoring;
    Shape best_move;
    float click_speed = 0.0f;
    float click_time = 0.0f;
    float click_time_max = 1.0f;
};

#endif //TETRISVS_COMPUTERCONTROLLER_H
