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
    float score = -1e9;
    Board board;
    Shape current_shape;
    Shape best_move;
    Shape repr_shape;
    Shape next_shape;
    Shape hold_shape;

    std::queue<Shape> garbage_shapes;

    Game(int xOffset, int yOffset, ShapeFactory *shapeFactory);

    void NextShape();

    void PutGarbage(int level);

    void HoldShape();

    bool IncreaseTick(float max, float delta_time);

    void AddScore(int clear);

    int SpeedModifier();

    int ClearedLines();

    float GetScore(Board &cboard);
    std::map<int, int> GetLineClears();
private:


    std::pair<int, int> AggregateHeightAndBumpiness(Board &cboard);

    int CompleteLines(Board &cboard);

    int HoleCount(Board &cboard);
    int game_speed[10] = {12, 25, 39, 54, 70, 85, 99, 112, 124, 135};
    ShapeFactory *shapeFactory;
    bool hold_changed = false;
    int cleared = 0;
    std::map<int, int> line_clears;
    float tick = 0.0f;
};


#endif //TETRISVS_GAME_H
