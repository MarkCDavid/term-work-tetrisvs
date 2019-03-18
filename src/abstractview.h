//
// Created by Mark David on 18/03/2019.
//

#ifndef TETRISVS_ABSTRACTVIEW_H
#define TETRISVS_ABSTRACTVIEW_H

#include "../lib/tge/terminal/abstractterminal.h"

class AbstractView {
public:
    virtual void Update(float delta_time) = 0;

    virtual void InitialDraw(AbstractTerminal *terminal) = 0;

    virtual void Draw(AbstractTerminal *terminal) = 0;
};


#endif //TETRISVS_ABSTRACTVIEW_H
