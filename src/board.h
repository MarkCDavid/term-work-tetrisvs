//
// Created by Mark David on 17/03/2019.
//

#ifndef TETRISVS_BOARD_H
#define TETRISVS_BOARD_H
#include <queue>
#include "shape.h"

class Board {
private:
    std::queue<Shape> regular_queue;
    std::queue<Shape> garbage_queue;
public:
    static constexpr int Width = 10;
    static constexpr int Height = 24;
    const int root_x;
    const int root_y;
    Board(int root_x, int root_y);
};


#endif //TETRISVS_BOARD_H
