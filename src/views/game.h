//
// Created by Mark David on 26/03/2019.
//

#ifndef TETRISVS_GAME_H
#define TETRISVS_GAME_H

#include "../model/board.h"
#include "../model/shape.h"
#include "../shapefactory.h"
#include "../symbols.h"
#include "../random.h"
#include <queue>
#include <map>

class Game {
public:
    int xOff, yOff;
    int xHOff, yHOff;
    int xNOff, yNOff;
    bool scored = false;
    float score = -1e9f;
    Board board; // +
    Shape current_shape; // +
    Shape best_move; // -
    Shape repr_shape; // +
    Shape next_shape; // +
    Shape hold_shape; // +

    std::queue<Shape> garbage_shapes;  // +

    Game(int xOffset, int yOffset);  // +

    void NextShape(); // +

    void PutGarbage(int level); // +

    void HoldShape(); // +

    bool IncreaseTick(float max, float delta_time); // +/-

    void AddLineClear(int clear); // +

    int SpeedModifier(); // +

    int ClearedLines(); // +

    float GetScore(Board &cboard); // -

    std::map<int, int> GetLineClears(); // +

private:

    static std::pair<int, int> AggregateHeightAndBumpiness(Board &cboard); // -

    static int CompleteLines(Board &cboard); // -

    static int HoleCount(Board &cboard); // -

    bool hold_changed = false; // +
    int cleared = 0; // +
    float tick = 0.0f; // +

    std::vector<int> game_speed = {12, 25, 39, 54, 70, 85, 99, 112, 124, 135};  // +/-
    std::map<int, int> line_clears; // +
};


#endif //TETRISVS_GAME_H
