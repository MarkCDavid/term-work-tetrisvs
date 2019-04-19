//
// Created by Mark David on 18/04/2019.
//

#ifndef TETRISVS_CONTROLLERPAIR_H
#define TETRISVS_CONTROLLERPAIR_H

#include "game.h"
#include "../controllers/abstractcontroller.h"

template<class T>
struct ControllerPair {
    T* paired;
    AbstractController* abstractController;
};

#endif //TETRISVS_CONTROLLERPAIR_H
