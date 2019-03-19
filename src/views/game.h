//
// Created by Mark David on 18/03/2019.
//

#ifndef TETRISVS_GAME_H
#define TETRISVS_GAME_H

#include "../board.h"
#include "../shapefactory.h"
#include "../controllers/abstractcontroller.h"
#include "abstractview.h"
#include <queue>

class Game : public AbstractView {
public:
    Game(AbstractTerminal *terminal, AbstractInput *input);

    int Update(float delta_time) override;

    void InitialDraw() override;

    void Draw() override;

private:
    Shape *l_hold;
    Shape *r_hold;
    std::queue<Shape> l_shapes;
    std::queue<Shape> r_shapes;
    float tick_time = 1.0f;
    float c_tick_time = 0.0f;
    ShapeFactory *shape_factory;
    AbstractController *l_controller;
    AbstractController *r_controller;
    Board *l_board;
    Board *r_board;

    BG_COLOR GetColor(const char symbol) const;

    void DrawBorders(Board const *const board);

    void DrawUpcomingBox(Board const *const board);

    void DrawUpcoming(Board const *const board, Shape &next);

    void DrawHoldBox(Board const *const board);

    void DrawHold(Board const *const board);

    void DrawSeparatingLine();

    void DrawBoard(Board const *const board);

    void ClearBoard(Board const *const board);

    void DrawShape(Board const *const board);

    int RemoveRows(Board *board);

    Shape GetNext(std::queue<Shape> &shape_queue);

    void PutGarbage(std::queue<Shape> &shape_queue, int level);


};


#endif //TETRISVS_GAME_H
