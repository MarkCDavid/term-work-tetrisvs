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
#include <queue>
#include <map>

class Game {
public:
    Game(int xOffset, int yOffset);

    void NextShape();

    void PutGarbage(int level);

    void HoldShape();

    bool IncreaseTick(float max, float delta_time); // +/-
    void AddLineClear(int clear);

    int SpeedModifier();

    int ClearedLines();

    std::map<int, int> GetLineClears();

    int xOff, yOff; // - TODO: VISUAL VARIABLES, SHOULD NOT BE IN A MODEL
    int xHOff, yHOff; // - TODO: VISUAL VARIABLES, SHOULD NOT BE IN A MODEL
    int xNOff, yNOff; // - TODO: VISUAL VARIABLES, SHOULD NOT BE IN A MODEL
    Board board;
    Shape current_shape;
    Shape repr_shape;
    Shape next_shape;
    Shape hold_shape;
    std::queue<Shape> garbage_shapes;

private:
    Shape GetNextShape();

    Shape GetRegular();

    Shape GetGarbage();

    bool hold_changed = false;
    int cleared = 0;
    float tick = 0.0f;
    std::vector<int> game_speed = {12, 25, 39, 54, 70, 85, 99, 112, 124, 135};
    std::map<int, int> line_clears;
};


#endif //TETRISVS_GAME_H
