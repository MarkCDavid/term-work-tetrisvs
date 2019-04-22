//
// Created by Mark David on 13/03/2019.
//

#ifndef TERM_WORK_TETRISVS_TETRISVS_H
#define TERM_WORK_TETRISVS_TETRISVS_H

#include "lib/curses.h"
#include "src/color.h"
#include "src/views/abstractview.h"
#include "src/managers/abstractmanager.h"

class TetrisVS {
public:
    static TetrisVS *Instance();

    void Update();

    bool GameRunning();

    void StopGame();

    void Switch(AbstractManager* new_manager, AbstractView* new_view);

protected:
    TetrisVS();

    ~TetrisVS();

private:
    static TetrisVS *instance;
    bool game_running = true;
    AbstractView* view = nullptr;
    AbstractManager* manager = nullptr;
};




#endif //TERM_WORK_TETRISVS_TETRISVS_H
