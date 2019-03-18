//
// Created by Mark David on 17/03/2019.
//

#ifndef TETRISVS_BOARD_H
#define TETRISVS_BOARD_H
#include <queue>
#include "shape.h"

class Board {
private:
    char *board = new char[Width * Height];
    std::queue<Shape *> regular_queue;
    std::queue<Shape *> garbage_queue;
public:
    Shape *current_shape;
    static constexpr int Width = 10;
    static constexpr int Height = 24;
    const int root_x;
    const int root_y;
    Board(int root_x, int root_y);

    char Get(int x, int y) const;

    void Put(int x, int y, char s);
};


#endif //TETRISVS_BOARD_H
