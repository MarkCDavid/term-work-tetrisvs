//
// Created by Mark David on 18/03/2019.
//

#ifndef TETRISVS_GAME_H
#define TETRISVS_GAME_H

#include "../board.h"
#include "../shapefactory.h"
#include "../controllers/abstractcontroller.h"
#include "abstractview.h"
#include "terminal/abstractterminal.h"
#include "input/abstractinput.h"


class Game : public AbstractView {
public:
    explicit Game(AbstractInput *input);

    void Update(float delta_time) override;

    void InitialDraw(AbstractTerminal *terminal) override;

    void Draw(AbstractTerminal *terminal) override;

private:
    float tick_time = 1.0f;
    float c_tick_time = 0.0f;
    ShapeFactory *shape_factory;
    AbstractController *l_controller;
    AbstractController *r_controller;
    Board *l_board;
    Board *r_board;

    BG_COLOR GetColor(const char symbol) const;

    void DrawBorders(AbstractTerminal *terminal, Board const *const board);

    void DrawUpcomingBox(AbstractTerminal *terminal, Board const *const board);

    void DrawSeparatingLine(AbstractTerminal *terminal);

    void DrawBoard(AbstractTerminal *terminal, Board const *const board);

    void ClearBoard(AbstractTerminal *terminal, Board const *const board);

    void DrawShape(AbstractTerminal *terminal, Board const *const board);

};


#endif //TETRISVS_GAME_H
