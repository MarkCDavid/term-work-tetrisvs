//
// Created by Mark David on 26/03/2019.
//

#ifndef TETRISVS_GAME_H
#define TETRISVS_GAME_H

#include "board.h"
#include "shape.h"
#include "../shapefactory.h"
#include "../symbols.h"
#include "../random.h"
#include "../gametime.h"
#include <queue>
#include <map>

class Game {
public:
    Game(char player_repr);

    void NextShape();

    void PutGarbage(int level);

    void HoldShape();

    bool IncreaseTick();

    void AddLineClear(int clear);

    void ResetTick();

    int ClearedLines();

    std::map<int, int> GetLineClears();

    const char player_repr = ' ';
    Board board;
    Shape current_shape;
    Shape repr_shape;
    Shape next_shape;
    Shape hold_shape;
    std::queue<Shape> garbage_shapes;

private:
    float CurrentTickLength();

    Shape GetNextShape();

    Shape GetRegular();

    Shape GetGarbage();

    bool hold_changed = false;
    int cleared = 0;
    float tick = 0.0f;
    const std::vector<std::pair<int, float>> game_speed = {{12, 1.0f}, {25, 0.9f}, {39, 0.8f},
                                                     {54, 0.7f}, {70, 0.6f}, {85, 0.5f},
                                                     {99, 0.45f}, {112, 0.4f}, {135, 0.35f}};

    std::map<int, int> line_clears;
};


#endif //TETRISVS_GAME_H
