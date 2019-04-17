//
// Created by Mark David on 17/04/2019.
//

#ifndef TETRISVS_ABSTRACTCONTROLLER_H
#define TETRISVS_ABSTRACTCONTROLLER_H

#include "../model/game.h"

class AbstractController {
private:
    Game *game;

    void DropShape(Board &board);

    void MoveShape(Board &board, Shape::Movement move);

    void RotateShape(Board &board, Shape::Rotation rotation);

    void TryRevert();
};


#endif //TETRISVS_ABSTRACTCONTROLLER_H
