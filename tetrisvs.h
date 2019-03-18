//
// Created by Mark David on 13/03/2019.
//

#ifndef TERM_WORK_TETRISVS_TETRISVS_H
#define TERM_WORK_TETRISVS_TETRISVS_H

#include "lib/tge/gameengine.h"
#include "src/board.h"
#include "src/game.h"

class TetrisVS : public GameEngine {
private:
    float tick_time = 1.0f;
    float current_tick_time = 0.0f;
    Game *game;
    bool Start() override;
    bool Update(float delta_time) override;
    bool Exit() override;

public:
    TetrisVS();
};


#endif //TERM_WORK_TETRISVS_TETRISVS_H
