//
// Created by Mark David on 13/03/2019.
//

#ifndef TERM_WORK_TETRISVS_TETRISVS_H
#define TERM_WORK_TETRISVS_TETRISVS_H

#include "lib/tge/gameengine.h"
#include "src/board.h"

class TetrisVS : public GameEngine {
private:
    float tick_time = 1.0f;
    float current_tick_time = 0.0f;
    Board * left_board;
    Board * right_board;
    bool Start() override;
    bool Update(float delta_time) override;
    bool Exit() override;

    void DrawBorders(Board const *const board);
    void DrawUpcomingBox(Board const * const board);
    void DrawSeparatingLine();

    void DrawBoard(Board const *const board);

    void DrawShape(Board const *const board);

    void ClearShape(Board const *const board);
public:
    int x = 0, y = 0;
    TetrisVS();
};


#endif //TERM_WORK_TETRISVS_TETRISVS_H
