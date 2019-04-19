//
// Created by Mark David on 26/03/2019.
//

#ifndef TETRISVS_GAMEVIEW_H
#define TETRISVS_GAMEVIEW_H

#include "abstractview.h"
#include "../controllers/abstractcontroller.h"
#include "../keyboard.h"
#include "../model/game.h"
#include <map>

class GameView : public AbstractView {

public:

    explicit GameView(std::vector<Game*> games); // +

    void Update() override; // +

    void InitialDraw() override; // +

    void Draw() override; // +

private:

    std::vector<Game*> games;

    void DrawBoard();

    void DrawShape();

    void DrawShadow();

    void DrawHold();

    void DrawNext();

    void DrawScore();
};


#endif //TETRISVS_GAMEVIEW_H
