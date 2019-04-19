//
// Created by Mark David on 18/03/2019.
//

#ifndef TETRISVS_ABSTRACTVIEW_H
#define TETRISVS_ABSTRACTVIEW_H

#include "../model/game.h"

class AbstractView {
public:
    AbstractView() = default;

    virtual void Update() = 0;

    virtual void InitialDraw() = 0;

    virtual void Draw() = 0;

    virtual ~AbstractView() = default;

};


#endif //TETRISVS_ABSTRACTVIEW_H