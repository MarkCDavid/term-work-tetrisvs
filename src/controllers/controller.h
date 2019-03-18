//
// Created by Mark David on 18/03/2019.
//

#ifndef TETRISVS_CONTROLLER_H
#define TETRISVS_CONTROLLER_H

#include "../board.h"

class AbstractController {
public:
    virtual oid Apply(Board const *const board) = 0;
};


#endif //TETRISVS_CONTROLLER_H
