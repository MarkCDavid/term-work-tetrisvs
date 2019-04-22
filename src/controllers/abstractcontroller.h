//
// Created by Mark David on 17/04/2019.
//

#ifndef TETRISVS_ABSTRACTCONTROLLER_H
#define TETRISVS_ABSTRACTCONTROLLER_H

#include "../model/game.h"

class AbstractController {
public:
    virtual void Update(Game* game) = 0;
protected:
    void DropShape(Game* game);

    void MoveShape(Game* game, Shape::Movement move);

    void RotateShape(Game* game, Shape::Rotation rotation);

    void HoldShape(Game* game);

    void TryRevert(Game* game);

};

#endif //TETRISVS_ABSTRACTCONTROLLER_H
