//
// Created by Mark David on 13/03/2019.
//

#ifndef TERM_WORK_TETRISVS_TETRISVS_H
#define TERM_WORK_TETRISVS_TETRISVS_H

#include "src/color.h"
#include "src/views/abstractview.h"
#include <chrono>

class TetrisVS {
public:
    static TetrisVS *Instance();

    void Update();

    bool GameRunning();

    void StopGame();

    void Switch(AbstractView *new_view);

protected:
    TetrisVS();

    ~TetrisVS();

private:
    static TetrisVS *instance;
    bool game_running = true;
    AbstractView *view;
    std::chrono::system_clock::time_point current_time = std::chrono::system_clock::now();
    std::chrono::system_clock::time_point previous_time = std::chrono::system_clock::now();
};




#endif //TERM_WORK_TETRISVS_TETRISVS_H
