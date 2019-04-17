//
// Created by Mark David on 17/04/2019.
//

#ifndef TETRISVS_ABSTRACTSCORING_H
#define TETRISVS_ABSTRACTSCORING_H

#include "../board.h"

class AbstractScoring {
public:
    virtual float GetScore(Board &board) const = 0;
};


#endif //TETRISVS_ABSTRACTSCORING_H
