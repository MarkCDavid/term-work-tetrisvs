//
// Created by Mark David on 26/03/2019.
//

#ifndef TETRISVS_GAMEVIEW_H
#define TETRISVS_GAMEVIEW_H

#include "abstractview.h"
#include "../keyboard.h"
#include "game.h"
#include <map>

class GameView : public AbstractView {

public:

    GameView(bool bot, bool hard = false); // -

    ~GameView() override;

    void Update(float delta_time) override; // +

    void InitialDraw() override; // +

    void Draw() override; // +

    void GetScore(std::map<int, int> &lscore, std::map<int, int> &rscore); // +/-

private:
    Game **games;
    bool bot = false;
    bool hard = false;
    float c_tick_timer = 0.0f;
    float tick = 1000.0f;

    void DrawBoard();

    void DrawShape();

    void DrawShadow();

    void DrawHold();

    void DrawNext();

    void DrawScore();

    void DropShape(int board);

    void MoveShape(int board, Shape::Movement move);

    void RotateShape(int board, Shape::Rotation rotation);
};


#endif //TETRISVS_GAMEVIEW_H
