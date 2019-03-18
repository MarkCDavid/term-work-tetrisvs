//
// Created by Mark David on 18/03/2019.
//

#ifndef TETRISVS_ABSTRACTVIEW_H
#define TETRISVS_ABSTRACTVIEW_H

#include "terminal/abstractterminal.h"

class AbstractView {
public:
    AbstractView(AbstractTerminal *terminal) : terminal(terminal) {}

    virtual void Update(float delta_time) = 0;

    virtual void InitialDraw() = 0;

    virtual void Draw() = 0;

protected:
    AbstractTerminal *terminal;
};


#endif //TETRISVS_ABSTRACTVIEW_H
