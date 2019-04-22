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

struct BoardOffsets {
    BoardOffsets(int xOffset, int yOffset)
            :xOff(xOffset), yOff(yOffset), xNOff(xOffset+14),
             yNOff(yOff), xHOff(xOffset-9), yHOff(yOff)
    {
    }
    const int xOff, yOff;
    const int xHOff, yHOff;
    const int xNOff, yNOff;
};


class GameView : public AbstractView {

public:

    explicit GameView(std::vector<Game*> games); // +

    void Update() override; // +

    void InitialDraw() override; // +

    void Draw() override; // +

private:

    std::vector<std::pair<Game*, BoardOffsets>> gameboards;

    void DrawBoard();

    void CoverShape();

    void DrawShape();

    void CoverShadow();

    void DrawShadow();

    void DrawHold();

    void DrawNext();

    void DrawScore();

    void ResetUpdated();

};


#endif //TETRISVS_GAMEVIEW_H
