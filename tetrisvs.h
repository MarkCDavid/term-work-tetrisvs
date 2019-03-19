//
// Created by Mark David on 13/03/2019.
//

#ifndef TERM_WORK_TETRISVS_TETRISVS_H
#define TERM_WORK_TETRISVS_TETRISVS_H

#include "lib/tge/gameengine.h"
#include "src/board.h"
#include "src/views/game.h"
#include "src/views/menu.h"
#include "src/views/controls.h"
#include "src/views/endgame.h"


class TetrisVS : public GameEngine {
private:
    AbstractView *current_view;
    bool Start() override;
    bool Update(float delta_time) override;
    bool Exit() override;

public:
    TetrisVS();
};


#endif //TERM_WORK_TETRISVS_TETRISVS_H
