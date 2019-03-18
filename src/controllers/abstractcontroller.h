//
// Created by Mark David on 18/03/2019.
//

#ifndef TETRISVS_CONTROLLER_H
#define TETRISVS_CONTROLLER_H

#include "../board.h"
#include "../../lib/tge/input/abstractinput.h"

class AbstractController {
public:
    explicit AbstractController(AbstractInput *input) { this->input = input; }

    virtual void Apply(Board *const board) = 0;

protected:
    AbstractInput *input;

    void RMove(Board *const board);

    void LMove(Board *const board);

    void RRotate(Board *const board);

    void LRotate(Board *const board);

    void Lower(Board *const board);

    void Drop(Board *const board);

    void Hold(Board *const board);
};


#endif //TETRISVS_CONTROLLER_H
